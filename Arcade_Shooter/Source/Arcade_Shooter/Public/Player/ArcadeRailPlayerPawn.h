#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ArcadeRailPlayerPawn.generated.h"

class AArcadeRailPath;
class UCameraComponent;
class UInputComponent;
class USceneComponent;

UCLASS()
class ARCADE_SHOOTER_API AArcadeRailPlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	AArcadeRailPlayerPawn();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	void UpdateRailTransform(float DeltaTime);
	void UpdateCameraLook();
	void ApplyGamepadLook(float DeltaTime);

	void HandleMouseYaw(float AxisValue);
	void HandleMousePitch(float AxisValue);
	void HandleGamepadYaw(float AxisValue);
	void HandleGamepadPitch(float AxisValue);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY(EditInstanceOnly, Category = "Rail")
	TObjectPtr<AArcadeRailPath> RailPath = nullptr;

	UPROPERTY(EditAnywhere, Category = "Rail", meta = (ClampMin = "0.0", Units = "cm/s"))
	float MoveSpeed = 300.0f;

	UPROPERTY(EditAnywhere, Category = "Look", meta = (ClampMin = "0.0", ClampMax = "179.0", Units = "deg"))
	float MaxLookYaw = 60.0f;

	UPROPERTY(EditAnywhere, Category = "Look", meta = (ClampMin = "0.0", ClampMax = "89.0", Units = "deg"))
	float MaxLookPitchUp = 35.0f;

	UPROPERTY(EditAnywhere, Category = "Look", meta = (ClampMin = "0.0", ClampMax = "89.0", Units = "deg"))
	float MaxLookPitchDown = 35.0f;

	UPROPERTY(EditAnywhere, Category = "Input", meta = (ClampMin = "0.0", ToolTip = "Degrees added per mouse input unit. Mouse input is already a delta and is not multiplied by DeltaTime."))
	float MouseLookSensitivity = 0.25f;

	UPROPERTY(EditAnywhere, Category = "Input", meta = (ClampMin = "0.0", Units = "deg/s"))
	float GamepadLookRate = 120.0f;

	UPROPERTY(EditAnywhere, Category = "Input", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float GamepadLookDeadZone = 0.15f;

	float CurrentDistance = 0.0f;
	float LookYaw = 0.0f;
	float LookPitch = 0.0f;
	float GamepadYawInput = 0.0f;
	float GamepadPitchInput = 0.0f;
};
