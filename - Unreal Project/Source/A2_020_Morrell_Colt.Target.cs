// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class A2_020_Morrell_ColtTarget : TargetRules
{
	public A2_020_Morrell_ColtTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "A2_020_Morrell_Colt" } );
	}
}
