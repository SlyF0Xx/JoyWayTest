// Fill out your copyright notice in the Description page of Project Settings.


#include "JoyWayPlayerController.h"

#include "Kismet/GameplayStatics.h" 	
#include "Engine/World.h" 	
#include "Containers/Array.h"
#include "GameFramework/Character.h"

#include <iostream>

void AJoyWayPlayerController::GetSeamlessTravelActorList(bool bToEntry, TArray<class AActor*>& ActorList)
{
	auto character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	ActorList.Add(character);

	TArray<AActor*> actors;
	character->GetAttachedActors(actors);
	ActorList.Append(actors);
}
