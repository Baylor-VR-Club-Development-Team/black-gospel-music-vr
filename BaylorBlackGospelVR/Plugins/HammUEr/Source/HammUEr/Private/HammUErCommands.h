// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once

#include "SlateBasics.h"
#include "HammUErStyle.h"

class FHammUErCommands : public TCommands<FHammUErCommands>
{
public:

	FHammUErCommands()
		: TCommands<FHammUErCommands>(TEXT("HammUEr"), NSLOCTEXT("Contexts", "HammUEr", "HammUEr Plugin"), NAME_None, FHammUErStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
	};