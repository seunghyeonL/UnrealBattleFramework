// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PlayerControlStateBase.generated.h"

struct FInputActionValue;
/**
 * 
 */
UCLASS()
class BATTLEFRAMEWORK_API UPlayerControlStateBase : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = State, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPlayerControlStateBase> OuterState;

public:
	// Input Binding Functions
	virtual void Move(const FInputActionValue& Value) {}
	virtual void Look(const FInputActionValue& Value) {}
	virtual void Dash() {}
	virtual void Sprint() {}
	virtual void Parry() {}
	virtual void BaseAttack() {}
	virtual void WeaponSkill() {}
	virtual void MagicSkill() {}

	// OuterState Getter/Setter
	FORCEINLINE virtual UPlayerControlStateBase* GetOuterState() const { return OuterState; }
	FORCEINLINE void SetOuterState(UPlayerControlStateBase* NewOuterState) { OuterState = NewOuterState; }
};
