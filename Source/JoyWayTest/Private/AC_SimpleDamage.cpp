// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_SimpleDamage.h"

UAC_SimpleDamage::UAC_SimpleDamage()
{
	bCausedByWorld = false;
	bScaleMomentumByMass = false;
	bRadialDamageVelChange = false;
	DamageImpulse = 0.0f;
	DestructibleImpulse = 0.0f;
	DestructibleDamageSpreadScale = 0.0f;
	DamageFalloff = 0.0f;
}
