using System.IO;

namespace UnrealBuildTool.Rules
{
	public class LowEntryXmlParser : ModuleRules
	{
		public LowEntryXmlParser(ReadOnlyTargetRules Target) : base(Target)
        {
            PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

            PublicIncludePaths.AddRange(
				new string[] {
                    Path.Combine(ModuleDirectory, "Public/Module"),
                    Path.Combine(ModuleDirectory, "Public/Classes"),
				}
			);

			PrivateIncludePaths.AddRange(
				new string[] {
                    Path.Combine(ModuleDirectory, "Private/Module"),
                    Path.Combine(ModuleDirectory, "Private/Classes"),
				}
			);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Engine",
					"Core",
					"CoreUObject",
                    "XmlParser",
				}
			);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
				}
			);

			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
				}
			);
		}
	}
}
