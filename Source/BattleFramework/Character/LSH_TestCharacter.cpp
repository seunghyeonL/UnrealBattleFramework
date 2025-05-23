﻿// Copyright Epic Games, Inc. All Rights Reserved.

#include "LSH_TestCharacter.h"
#include "Util/DebugHelper.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Components/ControlComponent/Player/PlayerControlComponent.h"
#include "Components/ControlComponent/Player/States/PlayerControlState.h"

//////////////////////////////////////////////////////////////////////////
// ALSH_TestCharacter

ALSH_TestCharacter::ALSH_TestCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Battle Components
	ControlComponent = CreateDefaultSubobject<UPlayerControlComponent>(TEXT("ControlComponent"));
	
	
	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void ALSH_TestCharacter::NotifyControllerChanged()
{
	Super::NotifyControllerChanged();

	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void ALSH_TestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	InputComponent = PlayerInputComponent;
	
	if (ControlComponent->bIsComponentReady)
	{
		BindInputFunctions();
	}
	ControlComponent->OnComponentReady.BindUObject(this, &ALSH_TestCharacter::BindInputFunctions);
}

void ALSH_TestCharacter::BindInputFunctions()
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent)) {
		// Moving
		if (IsValid(MoveAction))
		{
			EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, ControlComponent.Get(), &UPlayerControlComponent::Move);	
		}
		
		// Looking
		if (IsValid(LookAction))
		{
			EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, ControlComponent.Get(), &UPlayerControlComponent::Look);
		}

		// Dash
		if (IsValid(DashAction))
		{
			EnhancedInputComponent->BindAction(DashAction, ETriggerEvent::Started, ControlComponent.Get(), &UPlayerControlComponent::Dash);
		}

		// Dash
		if (IsValid(SprintAction))
		{
			EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, ControlComponent.Get(), &UPlayerControlComponent::Sprint);
		}

		// Parry
		if (IsValid(ParryAction))
		{
			EnhancedInputComponent->BindAction(ParryAction, ETriggerEvent::Started, ControlComponent.Get(), &UPlayerControlComponent::Parry);
		}

		// BaseAttack
		if (IsValid(BaseAttackAction))
		{
			EnhancedInputComponent->BindAction(BaseAttackAction, ETriggerEvent::Started, ControlComponent.Get(), &UPlayerControlComponent::BaseAttack);
		}

		// WeaponSkill
		if (IsValid(WeaponSkillAction))
		{
			EnhancedInputComponent->BindAction(WeaponSkillAction, ETriggerEvent::Started, ControlComponent.Get(), &UPlayerControlComponent::WeaponSkill);
		}

		// MagicSkill
		if (IsValid(MagicSkillAction))
		{
			EnhancedInputComponent->BindAction(MagicSkillAction, ETriggerEvent::Started, ControlComponent.Get(), &UPlayerControlComponent::MagicSkill);
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}
