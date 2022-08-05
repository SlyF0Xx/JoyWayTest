// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "I_Gun.h"
#include "AC_HitscanDamage.h"

#include "AC_ProjectileDamage.generated.h"


UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class JOYWAYTEST_API UAC_ProjectileDamage : public UAC_HitscanDamage
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_ProjectileDamage();

public:
	void ApplyDamage_Implementation() override;

public:
	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector GunOffset;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class AJoyWayTestProjectile> ProjectileClass;
};
