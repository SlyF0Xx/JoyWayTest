// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "JoyWayTestGameMode.generated.h"

UCLASS(minimalapi)
class AJoyWayTestGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AJoyWayTestGameMode();

	void GetSeamlessTravelActorList(bool bToEntry, TArray<class AActor*>& ActorList) override;

	/**
	 * Called after a seamless level transition has been completed on the *new* GameMode.
	 * Used to reinitialize players already in the game as they won't have *Login() called on them
	 */
	void PostSeamlessTravel() override;

private:
	ACharacter* m_character;
};



