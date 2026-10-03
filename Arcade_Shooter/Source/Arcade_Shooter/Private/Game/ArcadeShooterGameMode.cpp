#include "Game/ArcadeShooterGameMode.h"

#include "Player/ArcadeRailPlayerPawn.h"
#include "Player/ArcadeShooterPlayerController.h"
#include "UI/ArcadeShooterHUD.h"

AArcadeShooterGameMode::AArcadeShooterGameMode()
{
	DefaultPawnClass = AArcadeRailPlayerPawn::StaticClass();
	PlayerControllerClass = AArcadeShooterPlayerController::StaticClass();
	HUDClass = AArcadeShooterHUD::StaticClass();
}
