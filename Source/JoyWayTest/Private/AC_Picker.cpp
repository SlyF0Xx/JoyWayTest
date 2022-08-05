// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_Picker.h"

#include "PickableItem.h"

#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Kismet/KismetMathLibrary.h"
#include "Camera/CameraComponent.h"
#include "Templates/Decay.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UAC_Picker::UAC_Picker()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// declare overlap events
	OnComponentBeginOverlap.AddDynamic(this, &UAC_Picker::OnOverlapBegin);
	OnComponentEndOverlap.AddDynamic(this, &UAC_Picker::OnOverlapEnd);

	SetCollisionObjectType(s_collision_channel);
	SetCollisionProfileName(TEXT("Picker"));

	SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	SetCollisionResponseToChannel(UPickableItem::s_collision_channel, ECollisionResponse::ECR_Overlap);
}

void UAC_Picker::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Call RepeatingFunction once per second, starting two seconds from now.
	GetOwner()->GetWorldTimerManager().SetTimer(m_inside_ollision_timer, this, &UAC_Picker::OnPickableTimerInsideCollision, 0.5f, true);
}

void UAC_Picker::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (does_all_pickable_items_gone()) {
		GetOwner()->GetWorldTimerManager().ClearTimer(m_inside_ollision_timer);
		if (m_selected) {
			OnDeselected();
		}
	}
}

bool UAC_Picker::does_all_pickable_items_gone()
{
	TSet<UPrimitiveComponent*> actor_compnents;
	GetOverlappingComponents(actor_compnents);

	for (auto& component : actor_compnents) {
		if (Cast<UPickableItem>(component)) {
			return false;
		}
	}

	return true;
}

void UAC_Picker::OnPickableTimerInsideCollision()
{
	FVector location;
	FRotator rotation;
	GetOwner()->GetActorEyesViewPoint(location, rotation);

	auto camera = GetOwner()->GetComponentByClass(UCameraComponent::StaticClass());

	FCollisionResponseParams query;
	query.CollisionResponse.SetAllChannels(ECollisionResponse::ECR_Ignore);
	query.CollisionResponse.SetResponse(UPickableItem::s_collision_channel, ECollisionResponse::ECR_Block);


	/*
	FHitResult OutHit;
	GetWorld()->LineTraceSingleByChannel(
		OutHit,
		static_cast<UCameraComponent*>(camera)->GetRelativeLocation() + location,
		static_cast<UCameraComponent*>(camera)->GetRelativeLocation() + location + (UKismetMathLibrary::GetForwardVector(rotation) * GetScaledSphereRadius()),
		s_collision_channel,
		FCollisionQueryParams::DefaultQueryParam,
		FCollisionResponseParams(query));

	*/

	FHitResult OutHit;

	int32 SizeX;
	int32 SizeY;
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetViewportSize(SizeX, SizeY);
	//UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHitResultAtScreenPosition(FVector2D(SizeX / 2, SizeY / 2), {UEngineTypes::ConvertToObjectType(UPickableItem::s_collision_channel)}, false, OutHit);
		
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHitResultAtScreenPosition(
		FVector2D(SizeX / 2, SizeY / 2),
		//ECollisionChannel::ECC_Visibility,
		
		
		
		UPickableItem::s_collision_channel,
		FCollisionQueryParams::DefaultQueryParam,



		//{ EObjectTypeQuery::ObjectTypeQuery2 },
		//false,
		
		//s_collision_channel,
		OutHit);

	//UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHitResultUnderCursorForObjects({ UEngineTypes::ConvertToObjectType(s_collision_channel) }, false, OutHit);
	//UPickableItem::s_collision_channel

	//UPickableItem::s_collision_channel, 
	//GetHitResultUnderCursorForObjects
	//GetHitResultUnderCursorByChannel

	if (OutHit.bBlockingHit) {
		if (auto pickable_item = Cast<UPickableItem>(OutHit.Component)) {
			OnPickableItemSelected(pickable_item);
		}
		m_selected = true;
	}
	else if (m_selected) {
		OnDeselected();
	}
}

void UAC_Picker::OnPickableItemSelected_Implementation(UPickableItem* selected_item)
{
	selected_item->OnPicked(this);
}

void UAC_Picker::OnDeselected_Implementation()
{
	m_selected = false;
}