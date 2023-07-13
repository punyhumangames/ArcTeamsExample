// Copyright Epic Games, Inc. All Rights Reserved.

#include "ArcTeamsExampleGameMode.h"
#include "ArcTeamsExampleCharacter.h"
#include "UObject/ConstructorHelpers.h"

#include "ArcTeamsExamplePlayerState.h"
#include "ArcTeamsExampleGameStateBase.h"
#include "ArcTeamsExamplePlayerController.h"


#include "Gamemode/ArcTeamComponent_Gamemode.h"

AArcTeamsExampleGameMode::AArcTeamsExampleGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	TeamComponent = CreateDefaultSubobject<UArcTeamComponent_Gamemode>("Team Component");

	PlayerStateClass = AArcTeamsExamplePlayerState::StaticClass();
	GameStateClass = AArcTeamsExampleGameStateBase::StaticClass();
	PlayerControllerClass = AArcTeamsExamplePlayerController::StaticClass();
}

AActor* AArcTeamsExampleGameMode::ChoosePlayerStart_Implementation(AController* Player)
{
	return ChooseTeamPlayerStart(Player);	
}

bool AArcTeamsExampleGameMode::ShouldSpawnAtStartSpot(AController* Player)
{
	return Super::ShouldSpawnAtStartSpot(Player) && GetTeamComponent()->CanUsePlayerStartForPlayer(Player, Player->StartSpot.Get());
}
