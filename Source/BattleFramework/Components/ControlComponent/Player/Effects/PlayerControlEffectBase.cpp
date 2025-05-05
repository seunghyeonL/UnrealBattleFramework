﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControlEffectBase.h"
#include "Util/DebugHelper.h"
#include "Components/ControlComponent/Player/PlayerControlComponent.h"

void UPlayerControlEffectBase::Activate()
{
	if (bIsActive)
	{
		return;
	}

	auto ControlComponent = Cast<UPlayerControlComponent>(GetOuter());
	if (!IsValid(ControlComponent))
	{
		Debug::PrintError(TEXT("UPlayerControlEffectBase::Activate : Invalid ControlComponent"));
		return;
	}
	
	if (UPlayerControlStateBase* PlayerControlState = ControlComponent->GetPlayerControlState())
	{
		bIsActive = true;

		SetInnerState(PlayerControlState);
		PlayerControlState->SetOuterState(this);
		ControlComponent->SetPlayerControlState(this);
		ControlComponent->GetActiveControlEffects().AddTag(ControlEffectTag);
	}
	else
	{
		Debug::PrintError(TEXT("UPlayerControlEffectBase::Activate : Invalid ControlState"));
	}
}

void UPlayerControlEffectBase::Activate(float Duration)
{
	if (bIsActive)
	{
		GetOuter()->GetWorld()->GetTimerManager().ClearTimer(DurationTimer);
		GetOuter()->GetWorld()->GetTimerManager().SetTimer(
			DurationTimer,
			this,
			&UPlayerControlEffectBase::Deactivate,
			Duration,
			false
		);
		return;
	}

	auto ControlComponent = Cast<UPlayerControlComponent>(GetOuter());
	if (!IsValid(ControlComponent))
	{
		Debug::PrintError(TEXT("UPlayerControlEffectBase::Activate : Invalid ControlComponent"));
		return;
	}
	
	if (UPlayerControlStateBase* PlayerControlState = ControlComponent->GetPlayerControlState())
	{
		bIsActive = true;
		
		SetInnerState(PlayerControlState);
		PlayerControlState->SetOuterState(this);
		ControlComponent->SetPlayerControlState(this);
		ControlComponent->GetActiveControlEffects().AddTag(ControlEffectTag);
	}
	else
	{
		Debug::PrintError(TEXT("UPlayerControlEffectBase::Activate : Invalid ControlState"));
	}
}

void UPlayerControlEffectBase::Deactivate()
{
	if (!bIsActive)
	{
		return;
	}

	GetOuter()->GetWorld()->GetTimerManager().ClearTimer(DurationTimer);
	
	auto ControlComponent = Cast<UPlayerControlComponent>(GetOuter());
	if (!IsValid(ControlComponent))
	{
		Debug::PrintError(TEXT("UPlayerControlEffectBase::Deactivate : Invalid ControlComponent"));
		return;
	}
	
	if (!IsValid(InnerState))
	{
		Debug::PrintError(TEXT("UPlayerControlEffectBase::Deactivate : Invalid InnerState"));
		return;
	}

	// Connect OuterState and InnerState
	InnerState->SetOuterState(OuterState);
	if (auto CastedOuterState = Cast<UPlayerControlEffectBase>(OuterState))
	{
		CastedOuterState->SetInnerState(InnerState);
	}

	// Disconnect this
	SetInnerState(nullptr);
	SetOuterState(nullptr);

	bIsActive = false;

	ControlComponent->GetActiveControlEffects().RemoveTag(ControlEffectTag);
}

void UPlayerControlEffectBase::Tick(float DeltaTime)
{
}

void UPlayerControlEffectBase::Move(const FInputActionValue& Value)
{
	if (IsValid(InnerState))
	{
		InnerState->Move(Value);
	}
	else
	{
		Debug::PrintError(TEXT("UPlayerControlEffectBase::Move : Invalid InnerState"));
	}
}

void UPlayerControlEffectBase::Look(const FInputActionValue& Value)
{
	if (IsValid(InnerState))
	{
		InnerState->Look(Value);
	}
	else
	{
		Debug::PrintError(TEXT("UPlayerControlEffectBase::Look : Invalid InnerState"));
	}
}

void UPlayerControlEffectBase::Dash()
{
	if (IsValid(InnerState))
	{
		InnerState->Dash();
	}
	else
	{
		Debug::PrintError(TEXT("UPlayerControlEffectBase::Dash : Invalid InnerState"));
	}
}

void UPlayerControlEffectBase::Sprint()
{
	if (IsValid(InnerState))
	{
		InnerState->Sprint();
	}
	else
	{
		Debug::PrintError(TEXT("UPlayerControlEffectBase::Sprint : Invalid InnerState"));
	}
}

void UPlayerControlEffectBase::Parry()
{
	if (IsValid(InnerState))
	{
		InnerState->Parry();
	}
	else
	{
		Debug::PrintError(TEXT("UPlayerControlEffectBase::Parry : Invalid InnerState"));
	}
}

void UPlayerControlEffectBase::BaseAttack()
{
	if (IsValid(InnerState))
	{
		InnerState->BaseAttack();
	}
	else
	{
		Debug::PrintError(TEXT("UPlayerControlEffectBase::BaseAttack : Invalid InnerState"));
	}
}

void UPlayerControlEffectBase::WeaponSkill()
{
	if (IsValid(InnerState))
	{
		InnerState->WeaponSkill();
	}
	else
	{
		Debug::PrintError(TEXT("UPlayerControlEffectBase::WeaponSkill : Invalid InnerState"));
	}
}

void UPlayerControlEffectBase::MagicSkill()
{
	if (IsValid(InnerState))
	{
		InnerState->MagicSkill();
	}
	else
	{
		Debug::PrintError(TEXT("UPlayerControlEffectBase::MagicSkill : Invalid InnerState"));
	}
}
