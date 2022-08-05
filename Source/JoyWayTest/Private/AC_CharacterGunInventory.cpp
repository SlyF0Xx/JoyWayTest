// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_CharacterGunInventory.h"

#include "../JoyWayTestCharacter.h"

int32 UAC_CharacterGunInventory::AddGun_Implementation(AActor* owned_actor)
{
	auto rc = UAC_GunInventory::AddGun_Implementation(owned_actor);

	if (rc != -1) {
		m_character->AttachGun(owned_actor);
	}
	return rc;
}

void UAC_CharacterGunInventory::SelectGun_Implementation(int32 index)
{
	UAC_GunInventory::SelectGun_Implementation(index);
	m_character->AttachGun(GetCurrentGun());
}
