// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathEffect.h"

UDeathEffect::UDeathEffect()
{
	ControlEffectTag = EffectTags::Death;
	bIsActive = false;
	OuterState = nullptr;
	InnerState = nullptr;
}

void UDeathEffect::Activate()
{
	Super::Activate();
}

void UDeathEffect::Activate(float Duration)
{
	Super::Activate(Duration);
}

void UDeathEffect::Deactivate()
{
	Super::Deactivate();
}

void UDeathEffect::Move(const FInputActionValue& Value)
{
	// Super::Move(Value);
}

void UDeathEffect::Look(const FInputActionValue& Value)
{
	// Super::Look(Value);
}

void UDeathEffect::Dash()
{
	// Super::Dash();
}

void UDeathEffect::Sprint()
{
	// Super::Sprint();
}

void UDeathEffect::Parry()
{
	// Super::Parry();
}

void UDeathEffect::BaseAttack()
{
	// Super::BaseAttack();
}

void UDeathEffect::WeaponSkill()
{
	// Super::WeaponSkill();
}

void UDeathEffect::MagicSkill()
{
	// Super::MagicSkill();
}
