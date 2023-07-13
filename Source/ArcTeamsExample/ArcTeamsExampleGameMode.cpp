// Copyright Epic Games, Inc. All Rights Reserved.

#include "ArcTeamsExampleGameMode.h"
#include "ArcTeamsExampleCharacter.h"
#include "UObject/ConstructorHelpers.h"

AArcTeamsExampleGameMode::AArcTeamsExampleGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
