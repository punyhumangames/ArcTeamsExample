// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "ArcTeamsExamplePlayerState.generated.h"

class UArcTeamComponent_PlayerState;

/**
 * 
 */
UCLASS()
class ARCTEAMSEXAMPLE_API AArcTeamsExamplePlayerState : public APlayerState
{
	GENERATED_BODY()
public:

	AArcTeamsExamplePlayerState();

	UArcTeamComponent_PlayerState* GetTeamComponent() const { return TeamComponent; }
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UArcTeamComponent_PlayerState* TeamComponent;
};
