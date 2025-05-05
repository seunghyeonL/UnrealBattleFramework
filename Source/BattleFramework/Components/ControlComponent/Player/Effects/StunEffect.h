﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerControlEffectBase.h"
#include "StunEffect.generated.h"

/**
 * 
 */
UCLASS()
class BATTLEFRAMEWORK_API UStunEffect : public UPlayerControlEffectBase
{
	GENERATED_BODY()

public:
	UStunEffect();
	
	virtual void Activate() override;
	virtual void Activate(float Duration) override;
	virtual void Deactivate() override;
	
	virtual void Move(const FInputActionValue& Value) override;
	virtual void Look(const FInputActionValue& Value) override;
	virtual void Dash() override;
	virtual void Sprint() override;
	virtual void Parry() override;
	virtual void BaseAttack() override;
	virtual void WeaponSkill() override;
	virtual void MagicSkill() override;
};
