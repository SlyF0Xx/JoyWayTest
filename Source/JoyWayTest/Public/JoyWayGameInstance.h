// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameFramework/Character.h"
#include "JoyWayGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class JOYWAYTEST_API UJoyWayGameInstance : public UGameInstance
{
public:
	GENERATED_BODY()

	ACharacter* get_character()
	{
		return m_character;
	}

	void set_character(ACharacter* character)
	{
		m_character = character;
	}

private:
	ACharacter* m_character;
};
