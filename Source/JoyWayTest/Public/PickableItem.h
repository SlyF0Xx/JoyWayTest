// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"

#include "PickableItem.generated.h"

class UAC_Picker;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class JOYWAYTEST_API UPickableItem : public USphereComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPickableItem();

	UFUNCTION(BlueprintNativeEvent)
	void OnPicked(UAC_Picker* picker);

	static const ECollisionChannel s_collision_channel = ECollisionChannel::ECC_GameTraceChannel2;

protected:
	// Called when the game starts
	void BeginPlay() override;

private:
	bool m_picked = false;
};
