// HammUEr
// Basic ASE loader
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once
#include "HammUErPrivatePCH.h"
#include "BaseModelLoader.h"

class ASELoader:public BaseModelLoader
{
	public:
	bool Open(std::string inFileName) override;
	void Import() override;
	
	private:
	std::vector<std::string> ASEData;

};
