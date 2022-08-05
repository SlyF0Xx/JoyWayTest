// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_PickableGun.h"

#include "AC_HitscanDamage.h"
#include "AC_Picker.h"
#include "AC_GunInventory.h"

void UAC_PickableGun::OnPicked_Implementation(UAC_Picker* picker)
{
	auto inventory_component = picker->GetOwner()->GetComponentByClass(UAC_GunInventory::StaticClass());

	if (inventory_component) {
		static_cast<UAC_GunInventory *>(inventory_component)->AddGun(GetOwner());
	}
}
