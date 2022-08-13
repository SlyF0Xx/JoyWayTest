// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_ProjectileDamage.h"

#include "../JoyWayTestProjectile.h"

#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h" 	
#include "Engine/World.h"
#include "Components/SceneComponent.h"

// Sets default values for this component's properties
UAC_ProjectileDamage::UAC_ProjectileDamage()
{
	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 0.0f, 10.0f);
}

void UAC_ProjectileDamage::ApplyDamage_Implementation()
{
	AActor* owner = GetOwner();

	// try and fire a projectile
	if (ProjectileClass != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			const FRotator SpawnRotation = UGameplayStatics::GetPlayerCharacter(World, 0)->GetControlRotation();
			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			const FVector SpawnLocation = owner->GetActorLocation() + SpawnRotation.RotateVector(GunOffset);

			//Set Spawn Collision Handling Override
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

			// spawn the projectile at the muzzle
			auto projectile = World->SpawnActor<AJoyWayTestProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
			if (projectile) {
				projectile->set_damage(get_base_damage());
			}
		}
	}

	// try and play the sound if specified
	if (get_fire_sound() != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, get_fire_sound(), owner->GetActorLocation());
	}
}
