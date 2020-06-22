// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;
[SupportedPlatforms(UnrealPlatformClass.Server)]
public class MyProject2ServerTarget : TargetRules
{
	public MyProject2ServerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("MyProject2");
	}
}
