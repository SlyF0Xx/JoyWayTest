// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "I_Gun.h"

#include "AC_HitscanDamage.generated.h"


UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class JOYWAYTEST_API UAC_HitscanDamage : public UActorComponent, public II_Gun
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_HitscanDamage();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	void ApplyDamage_Implementation() override;

	float get_base_damage()
	{
		return m_base_damage;
	}

	USoundBase* get_fire_sound()
	{
		return m_fire_sound;
	}

private:
	UPROPERTY(EditAnywhere, Category = Gameplay)
	float m_base_damage = 10;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, Category = Gameplay)
	USoundBase* m_fire_sound;
};
