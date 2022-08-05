// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Engine/EngineTypes.h"

#include "AC_Picker.generated.h"

class UPickableItem;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class JOYWAYTEST_API UAC_Picker : public USphereComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAC_Picker();

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintNativeEvent)
	void OnPickableItemSelected(UPickableItem* selected_item);

	UFUNCTION(BlueprintNativeEvent)
	void OnDeselected();

	static const ECollisionChannel s_collision_channel = ECollisionChannel::ECC_GameTraceChannel3;

private:
	bool does_all_pickable_items_gone();

	void OnPickableTimerInsideCollision();

	FTimerHandle m_inside_ollision_timer;
	bool m_selected = false;
};
