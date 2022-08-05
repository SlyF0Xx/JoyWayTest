// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_GunInventory.h"

// Sets default values for this component's properties
UAC_GunInventory::UAC_GunInventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	m_guns.AddZeroed(2);
}


// Called when the game starts
void UAC_GunInventory::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

int32 UAC_GunInventory::AddGun_Implementation(AActor * owned_actor)
{
	for (auto i = 0; i < m_guns.Num(); i++) {
		if (!m_guns[i]) {
			m_guns[i] = owned_actor;
			return m_current_index = i;
		}
	}

	return -1;
}

AActor * UAC_GunInventory::GetGun(int32 index)
{
	if (index >= m_guns.Num()) {
		return nullptr;
	}

	return m_guns[index];
}

void UAC_GunInventory::SelectGun_Implementation(int32 index)
{
	m_current_index = index;
}

AActor* UAC_GunInventory::GetCurrentGun()
{
	return GetGun(m_current_index);
}

void UAC_GunInventory::RemoveGun_Implementation(AActor* gun)
{
	m_guns.Remove(gun);
}

void UAC_GunInventory::RemoveGunByIndex_Implementation(int32 index)
{
	m_guns.RemoveAt(index);
}
