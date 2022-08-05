// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "I_Gun.h"

#include "A_Weapon.generated.h"

class UAC_PickableGun;
class UAC_HitscanDamage;

UCLASS()
class JOYWAYTEST_API AA_Weapon : public AActor, public II_Gun
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AA_Weapon();

	void ApplyDamage_Implementation() override;

private:
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	USkeletalMeshComponent* m_gun;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	UAC_PickableGun* m_pickable_item;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	UAC_HitscanDamage* m_hitscan_damage;
};
