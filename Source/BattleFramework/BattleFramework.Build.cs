// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BattleFramework : ModuleRules
{
	public BattleFramework(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput"
		});
		
		// 에디터에서만 UnrealEd 모듈 추가
		if (Target.bBuildEditor)
		{
			PublicDependencyModuleNames.AddRange(new string[] { "UnrealEd" });
		}
		
		PrivateIncludePaths.Add("BattleFramework");
	}
}
