// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Util/GameTagList.h"
#include "ControlComponentBase.generated.h"

// DECLARE_DELEGATE(FOnStateComponentReady);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BATTLEFRAMEWORK_API UControlComponentBase : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UControlComponentBase();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State")
	FGameplayTagContainer ActiveControlEffectTags;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Effects")
	FORCEINLINE FGameplayTagContainer& GetActiveControlEffects() { return ActiveControlEffectTags; };

	UFUNCTION(BlueprintCallable, Category = "Effects")
	virtual void ActivateControlEffect(const FGameplayTag& ControlEffectTag);
	UFUNCTION(BlueprintCallable, Category = "Effects")
	virtual void ActivateControlEffectWithDuration(const FGameplayTag& ControlEffectTag, float Duration);
	UFUNCTION(BlueprintCallable, Category = "Effects")
	virtual void DeactivateControlEffect(const FGameplayTag& ControlEffectTag);
};
