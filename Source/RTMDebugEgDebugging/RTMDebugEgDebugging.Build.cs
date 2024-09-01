// Copyright (c) Richard Meredith AB. All Rights Reserved

using UnrealBuildTool;

public class RTMDebugEgDebugging : ModuleRules
{
	public RTMDebugEgDebugging(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		CppStandard = CppStandardVersion.Latest;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"GameplayDebugger",
			});
	}
}