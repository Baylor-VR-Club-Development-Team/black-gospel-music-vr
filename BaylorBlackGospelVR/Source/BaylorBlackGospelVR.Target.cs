// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class BaylorBlackGospelVRTarget : TargetRules
{
	public BaylorBlackGospelVRTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "BaylorBlackGospelVR" } );
	}
}
