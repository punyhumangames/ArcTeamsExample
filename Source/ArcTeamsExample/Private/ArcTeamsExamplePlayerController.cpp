// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcTeamsExamplePlayerController.h"

#include "ArcTeamsBlueprintLibrary.h"
#include "Gamemode/ArcTeamComponent_Gamemode.h"
#include "Gamemode/ArcTeamComponent_PlayerState.h"
#include "Gamemode/ArcTeamComponent_GameState.h"

#include "Data/ArcTeam.h"
#include "Data/ArcTeamDefinition.h"

AArcTeamsExamplePlayerController::AArcTeamsExamplePlayerController()
	: Super()
{
}

void AArcTeamsExamplePlayerController::JoinPrimaryTeam(UArcTeam* Team)
{
	if (!IsValid(Team))
	{
		return;
	}

	if(GetLocalRole() != ROLE_Authority)
	{
		Server_JoinTeam(Team);
		return;
	}

	UArcTeamComponent_PlayerState* TeamPS = UArcTeamsBlueprintLibrary::GetPlayerStateComponentFromPlayer(this);
	if (!IsValid(TeamPS))
	{
		return;
	}

	if (UArcTeamComponent_Gamemode* TeamGM = UArcTeamsBlueprintLibrary::GetAuthorityTeamComponent(this))
	{
		if(!TeamGM->CanPlayerJoinTeam(TeamPS, Team))
		{
			return;
		}

		if (UArcTeam* PrimaryTeam = UArcTeamsBlueprintLibrary::GetPrimaryTeamFromPlayer(this))
		{
			TeamGM->PlayerLeaveTeam(TeamPS, PrimaryTeam);
		}

		TeamGM->PlayerRequestJoinTeam(TeamPS, Team);
	}
}

void AArcTeamsExamplePlayerController::Server_JoinTeam_Implementation(UArcTeam* Team)
{
	JoinPrimaryTeam(Team);
}

bool AArcTeamsExamplePlayerController::Server_JoinTeam_Validate(UArcTeam* Team)
{
	return true;
}

void AArcTeamsExamplePlayerController::LeavePrimaryTeam()
{
	if(GetLocalRole() != ROLE_Authority)
	{
		Server_LeaveTeam();
		return;
	}

	UArcTeamComponent_PlayerState* TeamPS = UArcTeamsBlueprintLibrary::GetPlayerStateComponentFromPlayer(this);
	if (!IsValid(TeamPS))
	{
		return;
	}

	if (UArcTeamComponent_Gamemode* TeamGM = UArcTeamsBlueprintLibrary::GetAuthorityTeamComponent(this))
	{
		TeamGM->PlayerLeaveTeam(TeamPS, TeamPS->GetPrimaryTeam());
	}
}

void AArcTeamsExamplePlayerController::Server_LeaveTeam_Implementation()
{
	LeavePrimaryTeam();
}

bool AArcTeamsExamplePlayerController::Server_LeaveTeam_Validate()
{
	return true;
}

void AArcTeamsExamplePlayerController::CreateAndJoinSubTeam()
{
	if (GetLocalRole() != ROLE_Authority)
	{
		return;
	}

	UArcTeamComponent_PlayerState* TeamPS = UArcTeamsBlueprintLibrary::GetPlayerStateComponentFromPlayer(this);
	if (!IsValid(TeamPS))
	{
		return;
	}
	UArcTeam* PrimaryTeam = UArcTeamsBlueprintLibrary::GetPrimaryTeamFromPlayer(this);

	//Can't create a subteam if we don't have a primary team. 
	//This is just an example.  If you want to create subteams on a given team (like pre-create squads or something) you can certainly do so.  
	if (!IsValid(PrimaryTeam))
	{
		return;
	}

	if (UArcTeamComponent_Gamemode* TeamGM = UArcTeamsBlueprintLibrary::GetAuthorityTeamComponent(this))
	{
		UArcTeam* SubTeam = TeamGM->CreateSubTeam(SubteamConstructionInfo, PrimaryTeam);

		TeamGM->PlayerRequestJoinTeam(TeamPS, SubTeam);
	}
}



void AArcTeamsExamplePlayerController::Server_CreateAndJoinSubTeam_Implementation()
{
	CreateAndJoinSubTeam();
}

bool AArcTeamsExamplePlayerController::Server_CreateAndJoinSubTeam_Validate()
{
	return true;
}

void AArcTeamsExamplePlayerController::JoinSubTeam(UArcTeam* Team)
{
	if (!IsValid(Team))
	{
		return;
	}

	if(GetLocalRole() != ROLE_Authority)
	{
		Server_JoinSubTeam(Team);
		return;
	}

	UArcTeamComponent_PlayerState* TeamPS = UArcTeamsBlueprintLibrary::GetPlayerStateComponentFromPlayer(this);
	if (!IsValid(TeamPS))
	{
		return;
	}

	UArcTeam* PrimaryTeam = TeamPS->GetPrimaryTeam();
	if (!IsValid(PrimaryTeam))
	{
		return;
	}

	if (Team->GetParentTeam() != PrimaryTeam)
	{
		return;
	}

	if (UArcTeamComponent_Gamemode* TeamGM = UArcTeamsBlueprintLibrary::GetAuthorityTeamComponent(this))
	{
		TeamGM->PlayerRequestJoinTeam(TeamPS, PrimaryTeam);
	}

}

void AArcTeamsExamplePlayerController::Server_JoinSubTeam_Implementation(UArcTeam* Team)
{
	JoinSubTeam(Team);
}

bool AArcTeamsExamplePlayerController::Server_JoinSubTeam_Validate(UArcTeam* Team)
{
	return true;
}

void AArcTeamsExamplePlayerController::LeaveSubTeam(UArcTeam* Team)
{
	if (!IsValid(Team))
	{
		return;
	}

	if(GetLocalRole() != ROLE_Authority)
	{
		Server_LeaveSubTeam(Team);
		return;
	}

	UArcTeamComponent_PlayerState* TeamPS = UArcTeamsBlueprintLibrary::GetPlayerStateComponentFromPlayer(this);
	if (!IsValid(TeamPS))
	{
		return;
	}

	if(!Team->IsPlayerInTeam(TeamPS))
	{
		return;
	}

	if (UArcTeamComponent_Gamemode* TeamGM = UArcTeamsBlueprintLibrary::GetAuthorityTeamComponent(this))
	{
		TeamGM->PlayerLeaveTeam(TeamPS, Team);

		//If there are no more teams in this squad, destroy it.
		//You don't have to destroy subteams (perhaps they are created by the game and can't be destroyed), 
		//but for this example I want to show it off so this is a good place to do it.
		if (Team->GetNumPlayers() == 0)
		{
			TeamGM->DestroyTeam(Team);
		}
	}
}

void AArcTeamsExamplePlayerController::Server_LeaveSubTeam_Implementation(UArcTeam* Team)
{
	LeaveSubTeam(Team);
}

bool AArcTeamsExamplePlayerController::Server_LeaveSubTeam_Validate(UArcTeam* Team)
{
	return true;
}
