#include "UI/ArcadeShooterHUD.h"

#include "Player/ArcadeRailPlayerPawn.h"

void AArcadeShooterHUD::DrawHUD()
{
	Super::DrawHUD();

	if (!IsValid(PlayerOwner))
	{
		return;
	}

	const AArcadeRailPlayerPawn* RailPlayerPawn = Cast<AArcadeRailPlayerPawn>(PlayerOwner->GetPawn());
	if (!IsValid(RailPlayerPawn))
	{
		return;
	}

	FVector2D AimScreenPositionPixels;
	if (!RailPlayerPawn->GetAimScreenPositionPixels(AimScreenPositionPixels))
	{
		return;
	}

	DrawCrosshair(AimScreenPositionPixels);
}

void AArcadeShooterHUD::DrawCrosshair(const FVector2D& Center)
{
	constexpr float ArmLength = 18.0f;
	constexpr float Gap = 5.0f;
	constexpr float ShadowThickness = 5.0f;
	constexpr float Thickness = 3.0f;
	const FLinearColor ShadowColor(0.0f, 0.0f, 0.0f, 0.85f);
	const FLinearColor CrosshairColor(0.0f, 0.95f, 1.0f, 1.0f);

	const TPair<FVector2D, FVector2D> Lines[] = {
		{ Center + FVector2D(-ArmLength, 0.0f), Center + FVector2D(-Gap, 0.0f) },
		{ Center + FVector2D(Gap, 0.0f), Center + FVector2D(ArmLength, 0.0f) },
		{ Center + FVector2D(0.0f, -ArmLength), Center + FVector2D(0.0f, -Gap) },
		{ Center + FVector2D(0.0f, Gap), Center + FVector2D(0.0f, ArmLength) },
	};

	for (const TPair<FVector2D, FVector2D>& Line : Lines)
	{
		DrawLine(Line.Key.X, Line.Key.Y, Line.Value.X, Line.Value.Y, ShadowColor, ShadowThickness);
		DrawLine(Line.Key.X, Line.Key.Y, Line.Value.X, Line.Value.Y, CrosshairColor, Thickness);
	}
}
