using UnrealBuildTool;
using System.Collections.Generic;

public class Arcade_ShooterEditorTarget : TargetRules
{
	public Arcade_ShooterEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V7;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_8;
		ExtraModuleNames.Add("Arcade_Shooter");
	}
}
