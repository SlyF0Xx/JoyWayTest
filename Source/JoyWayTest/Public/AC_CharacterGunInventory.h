// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AC_GunInventory.h"
#include "AC_CharacterGunInventory.generated.h"

class AJoyWayTestCharacter;

/**
 * 
 */
UCLASS()
class JOYWAYTEST_API UAC_CharacterGunInventory : public UAC_GunInventory
{
public:
	GENERATED_BODY()

	int32 AddGun_Implementation(AActor* owned_actor) override;
	void SelectGun_Implementation(int32 index) override;

	UFUNCTION(BlueprintCallable)
	void set_character(AJoyWayTestCharacter* character)
	{
		m_character = character;
	}

	UPROPERTY(BlueprintReadWrite)
	AJoyWayTestCharacter* m_character;
private:
};
