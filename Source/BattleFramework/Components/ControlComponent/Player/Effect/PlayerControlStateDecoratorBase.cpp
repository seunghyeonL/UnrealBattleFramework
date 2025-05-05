// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControlStateDecoratorBase.h"
#include "Util/DebugHelper.h"
#include "../State/PlayerControlState.h"
#include "Components/ControlComponent/Player/PlayerControlComponent.h"

void UPlayerControlStateDecoratorBase::Activate()
{
	if (bIsActive)
	{
		return;
	}

	auto ControlComponent = Cast<UPlayerControlComponent>(GetOuter());
	if (!IsValid(ControlComponent))
	{
		Debug::PrintError(TEXT("UPlayerControlStateDecoratorBase::Activate : Invalid ControlComponent"));
		return;
	}

	bIsActive = true;
	SetInnerState(ControlComponent->GetPlayerControlState());
}

void UPlayerControlStateDecoratorBase::Activate(float Duration)
{
}

void UPlayerControlStateDecoratorBase::Deactivate()
{
}

void UPlayerControlStateDecoratorBase::Tick(float DeltaTime)
{
}

void UPlayerControlStateDecoratorBase::Move(const FInputActionValue& Value)
{
	Super::Move(Value);
}

void UPlayerControlStateDecoratorBase::Look(const FInputActionValue& Value)
{
	Super::Look(Value);
}

void UPlayerControlStateDecoratorBase::Dash()
{
	Super::Dash();
}

void UPlayerControlStateDecoratorBase::Sprint()
{
	Super::Sprint();
}

void UPlayerControlStateDecoratorBase::Parry()
{
	Super::Parry();
}

void UPlayerControlStateDecoratorBase::BaseAttack()
{
	Super::BaseAttack();
}

void UPlayerControlStateDecoratorBase::WeaponSkill()
{
	Super::WeaponSkill();
}

void UPlayerControlStateDecoratorBase::MagicSkill()
{
	Super::MagicSkill();
}
