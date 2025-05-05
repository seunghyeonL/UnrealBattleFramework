// Fill out your copyright notice in the Description page of Project Settings.


#include "StiffnessEffect.h"

UStiffnessEffect::UStiffnessEffect()
{
	ControlEffectTag = EffectTags::Stiffness;
	bIsActive = false;
	OuterState = nullptr;
	InnerState = nullptr;
}

void UStiffnessEffect::Activate()
{
	Super::Activate();
}

void UStiffnessEffect::Activate(float Duration)
{
	Super::Activate(Duration);
}

void UStiffnessEffect::Deactivate()
{
	Super::Deactivate();
}

void UStiffnessEffect::Move(const FInputActionValue& Value)
{
	// Super::Move(Value);
}

void UStiffnessEffect::Look(const FInputActionValue& Value)
{
	// Super::Look(Value);
}

void UStiffnessEffect::Dash()
{
	// Super::Dash();
}

void UStiffnessEffect::Sprint()
{
	// Super::Sprint();
}

void UStiffnessEffect::Parry()
{
	// Super::Parry();
}

void UStiffnessEffect::BaseAttack()
{
	// Super::BaseAttack();
}

void UStiffnessEffect::WeaponSkill()
{
	// Super::WeaponSkill();
}

void UStiffnessEffect::MagicSkill()
{
	// Super::MagicSkill();
}
