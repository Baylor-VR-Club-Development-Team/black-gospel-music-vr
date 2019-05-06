// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once
#include "MAPLight.h"

class MAPSpotLight :public MAPLight
{
public:
	float innerCone;
	float outerCone;

	MAPSpotLight();
};