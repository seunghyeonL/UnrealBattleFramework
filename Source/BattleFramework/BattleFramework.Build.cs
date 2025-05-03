// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BattleFramework : ModuleRules
{
	public BattleFramework(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
