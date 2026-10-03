#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ArcadeShooterPlayerController.generated.h"

UCLASS()
class ARCADE_SHOOTER_API AArcadeShooterPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
};
