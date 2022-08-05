// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "I_Gun.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h" 	
#include "Containers/Array.h"

#include "AC_GunInventory.generated.h"


UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class JOYWAYTEST_API UAC_GunInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_GunInventory();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	int32 AddGun(AActor* owned_actor);

	UFUNCTION(BlueprintCallable)
	AActor* GetGun(int32 index);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SelectGun(int32 index);

	UFUNCTION(BlueprintCallable)
	AActor* GetCurrentGun();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void RemoveGun(AActor* gun);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void RemoveGunByIndex(int32 index);

private:
	int32 m_current_index = 0;

	UPROPERTY()
	TArray<AActor*> m_guns;
};
