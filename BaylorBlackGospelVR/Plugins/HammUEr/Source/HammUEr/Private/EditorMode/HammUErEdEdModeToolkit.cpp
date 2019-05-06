// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#include "../HammUErPrivatePCH.h"
#include "HammUErEdEdMode.h"
#include "HammUErEdEdModeToolkit.h"

#define LOCTEXT_NAMESPACE "FHammUErEdEdModeToolkit"

FHammUErEdEdModeToolkit::FHammUErEdEdModeToolkit()
{
	SAssignNew(ToolkitWidget, SBorder)
		.HAlign(HAlign_Center)
		.Padding(25)
		[
				SNew(STextBlock)
				.AutoWrapText(true)
				.Text(LOCTEXT("HelperLabel", "This doesn't do anything at the moment"))
			
		];
}

FName FHammUErEdEdModeToolkit::GetToolkitFName() const
{
	return FName("HammUErEdEdMode");
}

FText FHammUErEdEdModeToolkit::GetBaseToolkitName() const
{
	return NSLOCTEXT("HammUErEdEdModeToolkit", "DisplayName", "HammUErEdEdMode Tool");
}

class FEdMode* FHammUErEdEdModeToolkit::GetEditorMode() const
{
	return GLevelEditorModeTools().GetActiveMode(FHammUErEdEdMode::EM_HammUErEdEdModeId);
}

#undef LOCTEXT_NAMESPACE
