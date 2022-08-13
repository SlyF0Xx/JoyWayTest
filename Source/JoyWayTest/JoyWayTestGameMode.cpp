// Copyright Epic Games, Inc. All Rights Reserved.

#include "JoyWayTestGameMode.h"
#include "JoyWayTestHUD.h"
#include "JoyWayTestCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "JoyWayPlayerController.h"
#include "Public/JoyWayGameInstance.h"

#include "Kismet/GameplayStatics.h" 	 	
#include "Camera/CameraActor.h"
#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"

AJoyWayTestGameMode::AJoyWayTestGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AJoyWayTestHUD::StaticClass();

	PlayerControllerClass = AJoyWayPlayerController::StaticClass();

	bUseSeamlessTravel = true;
}

void AJoyWayTestGameMode::GetSeamlessTravelActorList(bool bToEntry, TArray<class AActor*>& ActorList)
{
	AGameModeBase::GetSeamlessTravelActorList(bToEntry, ActorList);
	auto character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	auto instance = Cast<UJoyWayGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	if (character) {
		TArray<AActor*> actors;
		character->GetAttachedActors(actors);
		ActorList.Append(actors);

		instance->set_character(character);
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->UnPossess();
	}
	else {
		TArray<AActor*> actors;

		instance->get_character()->GetAttachedActors(actors);
		ActorList.Append(actors);
	}

	ActorList.Add(instance->get_character());
}

void AJoyWayTestGameMode::PostSeamlessTravel()
{
	AGameModeBase::PostSeamlessTravel();

	auto instance = Cast<UJoyWayGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->Possess(instance->get_character());
}
