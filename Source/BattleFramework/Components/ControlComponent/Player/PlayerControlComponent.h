// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BattleFramework/Components/ControlComponent/ControlComponentBase.h"
#include "Data/EnumTypes.h"
#include "PlayerControlComponent.generated.h"

class UPlayerControlState;
class UPlayerControlStateDecoratorBase;

DECLARE_DELEGATE(FOnStateComponentReady);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BATTLEFRAMEWORK_API UPlayerControlComponent : public UControlComponentBase
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPlayerControlComponent();

	FOnStateComponentReady OnStateComponentReady;
	bool bIsComponentReady;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Effect")
	TMap<EControlEffectType, UPlayerControlStateDecoratorBase*> ControlEffectMapper;

	void Initialize();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPlayerControlState> PlayerControlState;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	FORCEINLINE UPlayerControlState* GetPlayerControlState() const { return PlayerControlState; };
	FORCEINLINE void SetPlayerControlState(UPlayerControlState* NewState) { PlayerControlState = NewState; };

	virtual void ActivateControlEffect(EControlEffectType ControlEffectType) override;
	virtual void ActivateControlEffectWithDuration(EControlEffectType ControlEffectType, float Duration) override;
	virtual void DeactivateControlEffect(EControlEffectType ControlEffectType) override;
};
