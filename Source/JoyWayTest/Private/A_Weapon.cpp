// Fill out your copyright notice in the Description page of Project Settings.


#include "A_Weapon.h"

#include "AC_PickableGun.h"
#include "AC_HitscanDamage.h"

#include "Components/SkeletalMeshComponent.h"


// Sets default values
AA_Weapon::AA_Weapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	m_gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("mesh"));
	m_gun->SetupAttachment(RootComponent);
	m_gun->SetRelativeLocation(FVector(0, 0, 0));

	m_pickable_item = CreateDefaultSubobject<UAC_PickableGun>(TEXT("pickable"));
	m_pickable_item->SetupAttachment(RootComponent);

	m_hitscan_damage = CreateDefaultSubobject<UAC_HitscanDamage>(TEXT("damage"));
}

void AA_Weapon::ApplyDamage_Implementation()
{
	II_Gun::Execute_ApplyDamage(m_hitscan_damage);
}
