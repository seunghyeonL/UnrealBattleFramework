// Fill out your copyright notice in the Description page of Project Settings.


#include "ConfusedEffect.h"
#include "InputActionValue.h"

UConfusedEffect::UConfusedEffect()
{
	ControlEffectTag = EffectTags::Confused;
	bIsActive = false;
	OuterState = nullptr;
	InnerState = nullptr;
}

void UConfusedEffect::Activate()
{
	Super::Activate();
}

void UConfusedEffect::Activate(float Duration)
{
	Super::Activate(Duration);
}

void UConfusedEffect::Deactivate()
{
	Super::Deactivate();
}

void UConfusedEffect::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	FVector2D InvertedMovementVector = { -MovementVector.X, -MovementVector.Y };
	
	Super::Move(FInputActionValue(InvertedMovementVector));
}

void UConfusedEffect::Look(const FInputActionValue& Value)
{
	Super::Look(Value);
}

void UConfusedEffect::Dash()
{
	Super::Dash();
}

void UConfusedEffect::Sprint()
{
	Super::Sprint();
}

void UConfusedEffect::Parry()
{
	Super::Parry();
}

void UConfusedEffect::BaseAttack()
{
	Super::BaseAttack();
}

void UConfusedEffect::WeaponSkill()
{
	Super::WeaponSkill();
}

void UConfusedEffect::MagicSkill()
{
	Super::MagicSkill();
}
