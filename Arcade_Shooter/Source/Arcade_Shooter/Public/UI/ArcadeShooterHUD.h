#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ArcadeShooterHUD.generated.h"

UCLASS()
class ARCADE_SHOOTER_API AArcadeShooterHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void DrawHUD() override;

private:
	void DrawCrosshair(const FVector2D& Center);
};
