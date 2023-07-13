// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcTeamsExampleGameStateBase.h"

#include "Gamemode/ArcTeamComponent_GameState.h"

AArcTeamsExampleGameStateBase::AArcTeamsExampleGameStateBase()
	: Super()
{
	TeamComponent = CreateDefaultSubobject<UArcTeamComponent_GameState>("Team Component");
}
