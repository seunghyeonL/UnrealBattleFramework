// Fill out your copyright notice in the Description page of Project Settings.


#include "SilenceEffect.h"

USilenceEffect::USilenceEffect()
{
	ControlEffectTag = EffectTags::Silence;
	bIsActive = false;
	OuterState = nullptr;
	InnerState = nullptr;
}

void USilenceEffect::Activate()
{
	Super::Activate();
}

void USilenceEffect::Activate(float Duration)
{
	Super::Activate(Duration);
}

void USilenceEffect::Deactivate()
{
	Super::Deactivate();
}

void USilenceEffect::Move(const FInputActionValue& Value)
{
	Super::Move(Value);
}

void USilenceEffect::Look(const FInputActionValue& Value)
{
	Super::Look(Value);
}

void USilenceEffect::Dash()
{
	// Super::Dash();
}

void USilenceEffect::Sprint()
{
	Super::Sprint();
}

void USilenceEffect::Parry()
{
	// Super::Parry();
}

void USilenceEffect::BaseAttack()
{
	// Super::BaseAttack();
}

void USilenceEffect::WeaponSkill()
{
	// Super::WeaponSkill();
}

void USilenceEffect::MagicSkill()
{
	// Super::MagicSkill();
}
