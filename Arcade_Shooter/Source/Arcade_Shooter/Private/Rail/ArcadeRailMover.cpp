#include "Rail/ArcadeRailMover.h"

#include "Components/SceneComponent.h"
#include "Components/SplineComponent.h"
#include "Rail/ArcadeRailPath.h"

AArcadeRailMover::AArcadeRailMover()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	USceneComponent* SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
}

void AArcadeRailMover::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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
	const FRotator Rotation = SplineComponent->GetRotationAtDistanceAlongSpline(
		CurrentDistance,
		ESplineCoordinateSpace::World);

	SetActorLocationAndRotation(Location, Rotation);
}
