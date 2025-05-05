#pragma once

#include "CoreMinimal.h"
#include "EnumTypes.generated.h"

UENUM(BlueprintType)
enum class EControlEffectType : uint8
{
	Stiffness,
	Stun,
	Silence,
	Confused,

	UsingSkill,
	Death,
	Max
};

UENUM(BlueprintType)
enum class EStatusEffectType : uint8
{
	// Soft CC
	Slow,
	AttackDown,

	// Dot Effect
	Burn,
	Freeze,
	Poison,
	Max
};

UENUM(BlueprintType)
enum class EPawnStatType : uint8
{
	MaxHealth,
	MaxStamina,
	AttackPower,
	Defense,
	StaggerGauge,
};
