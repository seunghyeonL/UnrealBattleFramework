// Fill out your copyright notice in the Description page of Project Settings.


#include "ControlComponentBase.h"


// Sets default values for this component's properties
UControlComponentBase::UControlComponentBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UControlComponentBase::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UControlComponentBase::TickComponent(float DeltaTime, ELevelTick TickType,
                                          FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UControlComponentBase::ActivateControlEffect(EControlEffectType ControlEffectType)
{
	// 하위 클래스에서 구현
}

void UControlComponentBase::ActivateControlEffectWithDuration(EControlEffectType ControlEffectType, float Duration)
{
	// 하위 클래스에서 구현
}

void UControlComponentBase::DeactivateControlEffect(EControlEffectType ControlEffectType)
{
	// 하위 클래스에서 구현
}

