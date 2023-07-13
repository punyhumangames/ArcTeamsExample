// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Interfaces/ArcTeamInterface_Gamemode.h"
#include "ArcTeamsExampleGameMode.generated.h"

class UArcTeamComponent_Gamemode;


UCLASS(minimalapi)
class AArcTeamsExampleGameMode : public AGameModeBase, public IArcTeamInterface_Gamemode
{
	GENERATED_BODY()

public:
	AArcTeamsExampleGameMode();

	virtual UArcTeamComponent_Gamemode* GetTeamComponent() const override
	{
		return TeamComponent;
	}

	virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;

	virtual bool ShouldSpawnAtStartSpot(AController* Player) override;



private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UArcTeamComponent_Gamemode* TeamComponent;

};



