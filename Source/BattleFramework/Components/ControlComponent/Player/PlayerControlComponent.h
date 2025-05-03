// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BattleFramework/Components/ControlComponent/ControlComponentBase.h"
#include "PlayerControlComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BATTLEFRAMEWORK_API UPlayerControlComponent : public UControlComponentBase
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPlayerControlComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
