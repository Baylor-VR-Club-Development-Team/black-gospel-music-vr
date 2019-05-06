// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once

#include "Editor/UnrealEd/Public/Toolkits/BaseToolkit.h"


class FHammUErEdEdModeToolkit : public FModeToolkit
{
public:

	FHammUErEdEdModeToolkit();

	/** IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual class FEdMode* GetEditorMode() const override;
	virtual TSharedPtr<class SWidget> GetInlineContent() const override { return ToolkitWidget; }

private:

	TSharedPtr<SWidget> ToolkitWidget;
};
