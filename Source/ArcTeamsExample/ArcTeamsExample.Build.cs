// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ArcTeamsExample : ModuleRules
{
	public ArcTeamsExample(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"HeadMountedDisplay", 
			"EnhancedInput",
			"ArcTeams",
		});
	}
}
