// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_Destructable.h"

#include "Math/UnrealMathUtility.h"

#include "Kismet/GameplayStatics.h"
#include "Templates/Decay.h"

#include "Engine/World.h"


// Sets default values for this component's properties
UAC_Destructable::UAC_Destructable()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UAC_Destructable::BeginPlay()
{
	Super::BeginPlay();

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UAC_Destructable::OnDamage);
}

void UAC_Destructable::OnDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	m_hp -= Damage;

	if (m_hp <= 0) {
		OnDie();
	}
}

void UAC_Destructable::OnDie_Implementation()
{
	GetOwner()->Destroy();
}