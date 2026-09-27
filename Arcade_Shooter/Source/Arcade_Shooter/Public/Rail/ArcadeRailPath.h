#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArcadeRailPath.generated.h"

class USplineComponent;

UCLASS(BlueprintType)
class ARCADE_SHOOTER_API AArcadeRailPath : public AActor
{
	GENERATED_BODY()

public:
	AArcadeRailPath();

	UFUNCTION(BlueprintPure, Category = "Rail Path")
	USplineComponent* GetSplineComponent() const;

	UFUNCTION(BlueprintPure, Category = "Rail Path")
	float GetSplineLength() const;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Rail Path", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USplineComponent> SplineComponent;
};
