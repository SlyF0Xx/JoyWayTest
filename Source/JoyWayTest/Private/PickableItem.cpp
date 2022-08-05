// Fill out your copyright notice in the Description page of Project Settings.


#include "PickableItem.h"

#include "AC_Picker.h"

// Sets default values for this component's properties
UPickableItem::UPickableItem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;


	SetCollisionObjectType(s_collision_channel);
	SetCollisionProfileName(TEXT("Pickup"));

	SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	SetCollisionResponseToChannel(UAC_Picker::s_collision_channel, ECollisionResponse::ECR_Block);
}


// Called when the game starts
void UPickableItem::BeginPlay()
{
	Super::BeginPlay();
}

void UPickableItem::OnPicked_Implementation(UAC_Picker* picker)
{
	SetCollisionEnabled(ECollisionEnabled::NoCollision);
}