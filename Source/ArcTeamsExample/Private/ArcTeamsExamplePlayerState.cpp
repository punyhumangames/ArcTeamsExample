// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcTeamsExamplePlayerState.h"
#include "Gamemode/ArcTeamComponent_PlayerState.h"

AArcTeamsExamplePlayerState::AArcTeamsExamplePlayerState()
	: Super()
{
	TeamComponent = CreateDefaultSubobject<UArcTeamComponent_PlayerState>("TeamComponent");
}
