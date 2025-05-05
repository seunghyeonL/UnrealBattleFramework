// Fill out your copyright notice in the Description page of Project Settings.


#include "StunEffect.h"

UStunEffect::UStunEffect()
{
	ControlEffectTag = EffectTags::Stun;
	bIsActive = false;
	OuterState = nullptr;
	InnerState = nullptr;
}

void UStunEffect::Activate()
{
	Super::Activate();
}

void UStunEffect::Activate(float Duration)
{
	Super::Activate(Duration);
}

void UStunEffect::Deactivate()
{
	Super::Deactivate();
}

void UStunEffect::Move(const FInputActionValue& Value)
{
	// Super::Move(Value);
}

void UStunEffect::Look(const FInputActionValue& Value)
{
	// Super::Look(Value);
}

void UStunEffect::Dash()
{
	// Super::Dash();
}

void UStunEffect::Sprint()
{
	// Super::Sprint();
}

void UStunEffect::Parry()
{
	// Super::Parry();
}

void UStunEffect::BaseAttack()
{
	// Super::BaseAttack();
}

void UStunEffect::WeaponSkill()
{
	// Super::WeaponSkill();
}

void UStunEffect::MagicSkill()
{
	// Super::MagicSkill();
}
