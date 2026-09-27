#include "Player/ArcadeRailPlayerPawn.h"

#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SplineComponent.h"
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

void AArcadeRailPlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	UpdateRailTransform(0.0f);
	UpdateCameraLook();
}

void AArcadeRailPlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateRailTransform(DeltaTime);
	ApplyGamepadLook(DeltaTime);
	UpdateCameraLook();
}

void AArcadeRailPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName(TEXT("ArcadeRail_MouseYaw")), this, &AArcadeRailPlayerPawn::HandleMouseYaw);
	PlayerInputComponent->BindAxis(FName(TEXT("ArcadeRail_MousePitch")), this, &AArcadeRailPlayerPawn::HandleMousePitch);
	PlayerInputComponent->BindAxis(FName(TEXT("ArcadeRail_GamepadYaw")), this, &AArcadeRailPlayerPawn::HandleGamepadYaw);
	PlayerInputComponent->BindAxis(FName(TEXT("ArcadeRail_GamepadPitch")), this, &AArcadeRailPlayerPawn::HandleGamepadPitch);
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
