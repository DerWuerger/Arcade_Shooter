#include "Rail/ArcadeRailPath.h"

#include "Components/SplineComponent.h"

AArcadeRailPath::AArcadeRailPath()
{
	PrimaryActorTick.bCanEverTick = false;

	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	SetRootComponent(SplineComponent);
}

USplineComponent* AArcadeRailPath::GetSplineComponent() const
{
	return SplineComponent;
}

float AArcadeRailPath::GetSplineLength() const
{
	return SplineComponent->GetSplineLength();
}
