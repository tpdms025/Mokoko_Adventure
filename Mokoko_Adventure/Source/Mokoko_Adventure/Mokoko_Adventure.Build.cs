// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Mokoko_Adventure : ModuleRules
{
	public Mokoko_Adventure(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG", "LevelSequence", "MovieScene" });
	}
}
