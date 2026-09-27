using UnrealBuildTool;
using System.Collections.Generic;

public class Arcade_ShooterTarget : TargetRules
{
	public Arcade_ShooterTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V7;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_8;
		ExtraModuleNames.Add("Arcade_Shooter");
	}
}
