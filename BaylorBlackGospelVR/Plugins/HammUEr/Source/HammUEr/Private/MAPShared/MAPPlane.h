// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once
#include "MAPVector.h"

class MAPPlane
{
public:
	MAPVector normal;
	float d;

	MAPPlane();
	MAPPlane(MAPVector inNormal, float inD);
	MAPPlane(MAPVector a, MAPVector b, MAPVector c);
};