// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once
#include "../MapShared/BaseEntity.h"

class MAPLight :public BaseEntity
{
public:
	MAPColor lightColor;
	int intensity;
	float pitch;
	bool isMobile;

	bool useIntensity = true;

	MAPLight();
};