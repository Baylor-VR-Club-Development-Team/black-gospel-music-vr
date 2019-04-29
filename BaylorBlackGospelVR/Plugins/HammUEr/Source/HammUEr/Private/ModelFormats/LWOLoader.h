// HammUEr
// Basic LWO2 loader
// No support for older LWOB and LWLO format
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once
#include "BaseModelLoader.h"

class LWOLoader:public BaseModelLoader
{
	public:
	bool Open(std::string inFileName) override;
	void Import() override;
	
	private:
	std::vector<uint8_t> LWOData;
	int readData;
	uint8_t* LWOPtr;
	uint8_t* LWOhead;

};
