// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickableItem.h"
#include "AC_PickableGun.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class JOYWAYTEST_API UAC_PickableGun : public UPickableItem
{
public:
	GENERATED_BODY()

	void OnPicked_Implementation(UAC_Picker* picker) override;
};
