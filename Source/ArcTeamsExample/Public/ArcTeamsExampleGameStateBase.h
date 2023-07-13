// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Interfaces/ArcTeamInterface_GameState.h"
#include "ArcTeamsExampleGameStateBase.generated.h"

class UArcTeamComponent_GameState;

/**
 * 
 */
UCLASS()
class ARCTEAMSEXAMPLE_API AArcTeamsExampleGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UArcTeamComponent_GameState* TeamComponent;

public:
	AArcTeamsExampleGameStateBase();

	UArcTeamComponent_GameState* GetTeamComponent() const { return TeamComponent; }

};
