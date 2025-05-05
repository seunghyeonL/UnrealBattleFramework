﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BattleFramework/Components/ControlComponent/ControlComponentBase.h"
#include "PlayerControlComponent.generated.h"

class UPlayerControlStateBase;
class UPlayerControlEffectBase;

DECLARE_DELEGATE(FOnComponentReady);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BATTLEFRAMEWORK_API UPlayerControlComponent : public UControlComponentBase
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPlayerControlComponent();

	FOnComponentReady OnComponentReady;
	bool bIsComponentReady;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPlayerControlStateBase> PlayerControlState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Effect")
	TMap<FGameplayTag, UPlayerControlEffectBase*> ControlEffectMapper;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	FORCEINLINE UPlayerControlStateBase* GetPlayerControlState() const { return PlayerControlState; };
	FORCEINLINE void SetPlayerControlState(UPlayerControlStateBase* NewState) { PlayerControlState = NewState; };

	virtual void ActivateControlEffect(const FGameplayTag& ControlEffectTag) override;
	virtual void ActivateControlEffectWithDuration(const FGameplayTag& ControlEffectTag, float Duration) override;
	virtual void DeactivateControlEffect(const FGameplayTag& ControlEffectTag) override;
};
