// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_Teleport.h"
#include "Kismet/GameplayStatics.h" 	
#include "GameFramework/Character.h"
#include "Engine/World.h" 	

// Sets default values for this component's properties
UAC_Teleport::UAC_Teleport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UAC_Teleport::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UAC_Teleport::Teleport()
{
	//GetWorld()->ServerTravel(TEXT("/Game/FirstPersonCPP/Maps/FirstPersonExampleMap2"), true, false);
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->ClientTravel(TEXT("/Game/FirstPersonCPP/Maps/FirstPersonExampleMap2"), ETravelType::TRAVEL_Relative, true);

	auto character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	//UGameplayStatics::GetPlayerController(GetWorld(), 0)->UnPossess();
	//UGameplayStatics::GetPlayerController(GetWorld(), 0)->Possess(character);


	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetViewTarget(character);

	//FirstPersonCameraComponent

	//auto character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	//UGameplayStatics::GetPlayerController(GetWorld(), 0)->UnPossess();
	//UGameplayStatics::GetPlayerController(GetWorld(), 0)->Possess(character);

}
