// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System;
using System.IO;

public class CaffeTest : ModuleRules
{
    protected string ModulePath
    {
        get { return Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name)); }
    }

    protected string ThirdPartyPath
    {
        get { return Path.GetFullPath(Path.Combine(ModulePath, "..", "..", "ThirdParty")); }
    }

    protected string CUDAPath
    {
        get { return "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v7.5"; }
    }
    protected string CoffeetrayPath
    {
        get { return "C:\\app\\caffe\\coffeetray"; }
    }

    public CaffeTest(TargetInfo Target)
	{
        PrivateIncludePaths.AddRange(new string[]
        {
            Path.Combine(CoffeetrayPath)
        });

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] { "V8" });

        LoadCaffe(Target);

        PublicLibraryPaths.Add(Path.Combine(CoffeetrayPath, "x64", "Release"));
    }

    private bool LoadCaffe(TargetInfo Target)
    {
        if ((Target.Platform == UnrealTargetPlatform.Win64) || (Target.Platform == UnrealTargetPlatform.Win32))
        {
            string LibrariesPath = Path.Combine(CoffeetrayPath, "x64", "Release");

            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "coffeetray.lib"));
            
            Definitions.Add(string.Format("WITH_COFFEETRAY=1"));

            return true;
        }

        Definitions.Add(string.Format("WITH_COFFEETRAY=0"));
        return false;
    }
}
