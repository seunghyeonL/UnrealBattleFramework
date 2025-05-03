// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Data/EnumTypes.h"
#include "ControlComponentBase.generated.h"

// DECLARE_DELEGATE(FOnStateComponentReady);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BATTLEFRAMEWORK_API UControlComponentBase : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UControlComponentBase();

	// FOnStateComponentReady OnStateComponentReady;
	// bool bIsComponentReady;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State")
	TArray<EControlEffectType> ActiveBehaviorEffects;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
