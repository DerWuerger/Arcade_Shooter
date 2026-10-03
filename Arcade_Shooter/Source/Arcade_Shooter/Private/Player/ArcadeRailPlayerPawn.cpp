#include "Player/ArcadeRailPlayerPawn.h"

#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SplineComponent.h"
#include "GameFramework/PlayerController.h"
#include "Rail/ArcadeRailPath.h"

AArcadeRailPlayerPawn::AArcadeRailPlayerPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SceneRoot);
	CameraComponent->bUsePawnControlRotation = false;
}

FVector2D AArcadeRailPlayerPawn::GetAimScreenPositionNormalized() const
{
	return AimScreenPositionNormalized;
}

bool AArcadeRailPlayerPawn::GetAimScreenPositionPixels(FVector2D& OutAimScreenPositionPixels) const
{
	const UWorld* World = GetWorld();
	if (!IsValid(World))
	{
		return false;
	}

	const APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!IsValid(PlayerController))
	{
		return false;
	}

	int32 ViewportSizeX = 0;
	int32 ViewportSizeY = 0;
	PlayerController->GetViewportSize(ViewportSizeX, ViewportSizeY);
	if (ViewportSizeX <= 0 || ViewportSizeY <= 0)
	{
		return false;
	}

	OutAimScreenPositionPixels = FVector2D(
		AimScreenPositionNormalized.X * static_cast<float>(ViewportSizeX),
		AimScreenPositionNormalized.Y * static_cast<float>(ViewportSizeY));
	return true;
}

bool AArcadeRailPlayerPawn::GetAimWorldRay(FVector& OutWorldOrigin, FVector& OutWorldDirection) const
{
	FVector2D AimScreenPositionPixels;
	if (!GetAimScreenPositionPixels(AimScreenPositionPixels))
	{
		return false;
	}

	const UWorld* World = GetWorld();
	if (!IsValid(World))
	{
		return false;
	}

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!IsValid(PlayerController))
	{
		return false;
	}

	return PlayerController->DeprojectScreenPositionToWorld(
		AimScreenPositionPixels.X,
		AimScreenPositionPixels.Y,
		OutWorldOrigin,
		OutWorldDirection);
}

void AArcadeRailPlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	UpdateRailTransform(0.0f);
	UpdateCameraLook();
	ClampAimPosition();
}

void AArcadeRailPlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateRailTransform(DeltaTime);
	ApplyGamepadLook(DeltaTime);
	ApplyGamepadAim(DeltaTime);
	UpdateCameraLook();
}

void AArcadeRailPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName(TEXT("ArcadeRail_MouseAimX")), this, &AArcadeRailPlayerPawn::HandleMouseAimX);
	PlayerInputComponent->BindAxis(FName(TEXT("ArcadeRail_MouseAimY")), this, &AArcadeRailPlayerPawn::HandleMouseAimY);
	PlayerInputComponent->BindAxis(FName(TEXT("ArcadeRail_GamepadAimX")), this, &AArcadeRailPlayerPawn::HandleGamepadAimX);
	PlayerInputComponent->BindAxis(FName(TEXT("ArcadeRail_GamepadAimY")), this, &AArcadeRailPlayerPawn::HandleGamepadAimY);
}

void AArcadeRailPlayerPawn::UpdateRailTransform(float DeltaTime)
{
	if (!IsValid(RailPath))
	{
		return;
	}

	USplineComponent* SplineComponent = RailPath->GetSplineComponent();
	if (!IsValid(SplineComponent))
	{
		return;
	}

	const float SplineLength = SplineComponent->GetSplineLength();
	CurrentDistance += MoveSpeed * DeltaTime;
	CurrentDistance = FMath::Clamp(CurrentDistance, 0.0f, SplineLength);

	const FVector Location = SplineComponent->GetLocationAtDistanceAlongSpline(
		CurrentDistance,
		ESplineCoordinateSpace::World);
	const FRotator RailRotation = SplineComponent->GetRotationAtDistanceAlongSpline(
		CurrentDistance,
		ESplineCoordinateSpace::World);
	const FRotator PawnRotation(RailRotation.Pitch, RailRotation.Yaw, 0.0f);

	SetActorLocationAndRotation(Location, PawnRotation);
}

void AArcadeRailPlayerPawn::UpdateCameraLook()
{
	LookYaw = FMath::Clamp(LookYaw, -MaxLookYaw, MaxLookYaw);
	LookPitch = FMath::Clamp(LookPitch, -MaxLookPitchDown, MaxLookPitchUp);

	CameraComponent->SetRelativeRotation(FRotator(LookPitch, LookYaw, 0.0f));
}

void AArcadeRailPlayerPawn::ApplyGamepadLook(float DeltaTime)
{
	const float EffectiveYawInput = FMath::Abs(GamepadYawInput) >= GamepadLookDeadZone ? GamepadYawInput : 0.0f;
	const float EffectivePitchInput = FMath::Abs(GamepadPitchInput) >= GamepadLookDeadZone ? GamepadPitchInput : 0.0f;

	LookYaw += EffectiveYawInput * GamepadLookRate * DeltaTime;
	LookPitch += EffectivePitchInput * GamepadLookRate * DeltaTime;
}

void AArcadeRailPlayerPawn::ApplyGamepadAim(float DeltaTime)
{
	const float EffectiveAimX = FMath::Abs(GamepadAimInput.X) >= GamepadAimDeadZone ? GamepadAimInput.X : 0.0f;
	const float EffectiveAimY = FMath::Abs(GamepadAimInput.Y) >= GamepadAimDeadZone ? GamepadAimInput.Y : 0.0f;

	AimScreenPositionNormalized.X += EffectiveAimX * GamepadAimSpeed * DeltaTime;
	AimScreenPositionNormalized.Y += EffectiveAimY * GamepadAimSpeed * DeltaTime;
	ClampAimPosition();
}

void AArcadeRailPlayerPawn::ClampAimPosition()
{
	const float MinX = FMath::Min(AimMinX, AimMaxX);
	const float MaxX = FMath::Max(AimMinX, AimMaxX);
	const float MinY = FMath::Min(AimMinY, AimMaxY);
	const float MaxY = FMath::Max(AimMinY, AimMaxY);

	AimScreenPositionNormalized.X = FMath::Clamp(AimScreenPositionNormalized.X, MinX, MaxX);
	AimScreenPositionNormalized.Y = FMath::Clamp(AimScreenPositionNormalized.Y, MinY, MaxY);
}

void AArcadeRailPlayerPawn::HandleMouseYaw(float AxisValue)
{
	LookYaw += AxisValue * MouseLookSensitivity;
	UpdateCameraLook();
}

void AArcadeRailPlayerPawn::HandleMousePitch(float AxisValue)
{
	LookPitch += AxisValue * MouseLookSensitivity;
	UpdateCameraLook();
}

void AArcadeRailPlayerPawn::HandleGamepadYaw(float AxisValue)
{
	GamepadYawInput = AxisValue;
}

void AArcadeRailPlayerPawn::HandleGamepadPitch(float AxisValue)
{
	GamepadPitchInput = AxisValue;
}

void AArcadeRailPlayerPawn::HandleMouseAimX(float AxisValue)
{
	AimScreenPositionNormalized.X += AxisValue * MouseAimSensitivity;
	ClampAimPosition();
}

void AArcadeRailPlayerPawn::HandleMouseAimY(float AxisValue)
{
	AimScreenPositionNormalized.Y -= AxisValue * MouseAimSensitivity;
	ClampAimPosition();
}

void AArcadeRailPlayerPawn::HandleGamepadAimX(float AxisValue)
{
	GamepadAimInput.X = AxisValue;
}

void AArcadeRailPlayerPawn::HandleGamepadAimY(float AxisValue)
{
	GamepadAimInput.Y = AxisValue;
}
