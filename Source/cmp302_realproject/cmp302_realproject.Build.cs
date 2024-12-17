// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class cmp302_realproject : ModuleRules
{
	public cmp302_realproject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"GameplayTasks",
			"NavigationSystem"


		});
	}
}
