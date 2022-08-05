// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_HitscanDamage.h"

#include "AC_SimpleDamage.h"

#include "Kismet/GameplayStatics.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UAC_HitscanDamage::UAC_HitscanDamage()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UAC_HitscanDamage::BeginPlay()
{
	Super::BeginPlay();
}

void UAC_HitscanDamage::ApplyDamage_Implementation()
{
	AActor* owner = GetOwner();

	FCollisionResponseParams query;
	query.CollisionResponse.SetAllChannels(ECollisionResponse::ECR_Ignore);
	query.CollisionResponse.SetResponse(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);

	auto parrent = GetOwner()->GetAttachParentActor();

	FCollisionQueryParams querry;
	querry.AddIgnoredActor(parrent);
	querry.AddIgnoredActor(owner);

	FHitResult OutHit;
	GetWorld()->LineTraceSingleByChannel(
		OutHit,
		parrent->GetActorLocation(),
		parrent->GetActorLocation() + parrent->GetActorForwardVector() * 1000,
		ECollisionChannel::ECC_Pawn,
		querry,
		FCollisionResponseParams(query));

	if (OutHit.bBlockingHit) {
		OutHit.Component->AddImpulseAtLocation((OutHit.TraceEnd - OutHit.TraceStart) * 100.0f, OutHit.Actor->GetActorLocation());
		UGameplayStatics::ApplyPointDamage(OutHit.Actor.Get(), m_base_damage, owner->GetActorLocation(), OutHit, UGameplayStatics::GetPlayerController(GetWorld(), 0), owner, UAC_SimpleDamage::StaticClass());
	}

	// try and play the sound if specified
	if (m_fire_sound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, m_fire_sound, owner->GetActorLocation());
	}
}
