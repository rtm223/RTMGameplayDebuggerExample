// Copyright (c) Richard Meredith AB. All Rights Reserved

using UnrealBuildTool;

public class RTMDebugEg : ModuleRules
{
	public RTMDebugEg(ReadOnlyTargetRules Target) : base(Target)
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

		PrivateDependencyModuleNames.AddRange(new string[] { });
	}
}