#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArcadeRailMover.generated.h"

class AArcadeRailPath;

UCLASS()
class ARCADE_SHOOTER_API AArcadeRailMover : public AActor
{
	GENERATED_BODY()

public:
	AArcadeRailMover();

protected:
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditInstanceOnly, Category = "Rail")
	AArcadeRailPath* RailPath = nullptr;

	UPROPERTY(EditAnywhere, Category = "Rail", meta = (ClampMin = "0.0", Units = "cm/s"))
	float MoveSpeed = 300.0f;

	float CurrentDistance = 0.0f;
};
