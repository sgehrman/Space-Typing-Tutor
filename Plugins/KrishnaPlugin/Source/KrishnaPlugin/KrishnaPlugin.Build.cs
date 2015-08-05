// Copyright 1998-2013 Epic Games, Inc. All Rights Reserved.
using UnrealBuildTool;

public class KrishnaPlugin : ModuleRules
{
  public KrishnaPlugin(TargetInfo Target)
  {
    PublicDependencyModuleNames.AddRange(
  new string[] { 
				"Core", 
				"CoreUObject",
				"Engine",
        "Json"
			}
);
  }
}
