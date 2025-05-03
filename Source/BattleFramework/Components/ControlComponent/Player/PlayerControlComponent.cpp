// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControlComponent.h"
#include "DebugHelper.h"
#include "GameFramework/Character.h"
#include "./State/PlayerControlState.h"


// Sets default values for this component's properties
UPlayerControlComponent::UPlayerControlComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	bIsComponentReady = false;
	PlayerControlState = nullptr;
	// ...
}


void UPlayerControlComponent::Initialize()
{
	ActiveControlEffects.Empty();
	ControlEffectMapper.Empty();

	// Create ControlEffect Instances

	// ControlEffectMapper.Add(EControlEffectType::Stun, NewObject<UStunEffect>(this));
	// ControlEffectMapper.Add(EControlEffectType::Stiffness, NewObject<UStiffnessEffect>(this));   
	// ControlEffectMapper.Add(EControlEffectType::Silence, NewObject<USilenceEffect>(this));     
	// ControlEffectMapper.Add(EControlEffectType::Confused, NewObject<UConfusedEffect>(this));  
	//
	// ControlEffectMapper.Add(EControlEffectType::UsingSkill, NewObject<UUsingSkillEffect>(this));  
	// ControlEffectMapper.Add(EControlEffectType::Death, NewObject<UDeathEffect>(this));       
}

// Called when the game starts
void UPlayerControlComponent::BeginPlay()
{
	Super::BeginPlay();
	
	// Create Input State
	PlayerControlState = NewObject<UPlayerControlState>(this);
	if (!IsValid(PlayerControlState))
	{
		Debug::PrintError(TEXT("UPlayerControlComponent::BeginPlay : Invalid PlayerControlState."));
		return;
	}

	auto OwnerCharacter = Cast<ACharacter>(GetOuter());
	if (!IsValid(OwnerCharacter))
	{
		Debug::PrintError(TEXT("UPlayerControlComponent::BeginPlay : Invalid OwnerCharacter."));
		return;
	}
	PlayerControlState->SetOwnerCharacter(OwnerCharacter);
	
	
	if (OnStateComponentReady.IsBound())
	{
		OnStateComponentReady.Execute();
	}
	bIsComponentReady = true;
}


// Called every frame
void UPlayerControlComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                            FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlayerControlComponent::ActivateControlEffect(EControlEffectType ControlEffectType)
{
	Super::ActivateControlEffect(ControlEffectType);

	
}

void UPlayerControlComponent::ActivateControlEffectWithDuration(EControlEffectType ControlEffectType, float Duration)
{
	Super::ActivateControlEffectWithDuration(ControlEffectType, Duration);

	
}

void UPlayerControlComponent::DeactivateControlEffect(EControlEffectType ControlEffectType)
{
	Super::DeactivateControlEffect(ControlEffectType);

	
}

