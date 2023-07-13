// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Gamemode/ArcTeamComponent_Gamemode.h"
#include "ArcTeamsExamplePlayerController.generated.h"

class UArcTeam;

/**
 * 
 */
UCLASS()
class ARCTEAMSEXAMPLE_API AArcTeamsExamplePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AArcTeamsExamplePlayerController();

	UPROPERTY(EditDefaultsOnly, Category = "Team")
	FArcTeamConstructionInfo SubteamConstructionInfo;

	UFUNCTION(BlueprintCallable)
	void JoinPrimaryTeam(UArcTeam* Team);

	UFUNCTION(Server, WithValidation, Reliable)
	void Server_JoinTeam(UArcTeam* Team);
	void Server_JoinTeam_Implementation(UArcTeam* Team);
	bool Server_JoinTeam_Validate(UArcTeam* Team);

	UFUNCTION(BlueprintCallable)
	void LeavePrimaryTeam();

	UFUNCTION(Server, WithValidation, Reliable)
	void Server_LeaveTeam();
	void Server_LeaveTeam_Implementation();
	bool Server_LeaveTeam_Validate();

	UFUNCTION(BlueprintCallable)
	void CreateAndJoinSubTeam();

	UFUNCTION(Server, WithValidation, Reliable)
	void Server_CreateAndJoinSubTeam();
	void Server_CreateAndJoinSubTeam_Implementation();
	bool Server_CreateAndJoinSubTeam_Validate();

	UFUNCTION(BlueprintCallable)
	void JoinSubTeam(UArcTeam* Team);

	UFUNCTION(Server, WithValidation, Reliable)
		void Server_JoinSubTeam(UArcTeam* Team);
	void Server_JoinSubTeam_Implementation(UArcTeam* Team);
	bool Server_JoinSubTeam_Validate(UArcTeam* Team);

	UFUNCTION(BlueprintCallable)
	void LeaveSubTeam(UArcTeam* Team);

	UFUNCTION(Server, WithValidation, Reliable)
		void Server_LeaveSubTeam(UArcTeam* Team);
	void Server_LeaveSubTeam_Implementation(UArcTeam* Team);
	bool Server_LeaveSubTeam_Validate(UArcTeam* Team);
};
