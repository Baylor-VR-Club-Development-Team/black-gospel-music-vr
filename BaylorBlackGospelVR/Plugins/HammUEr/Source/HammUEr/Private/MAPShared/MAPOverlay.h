// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once
#include "../MapShared/BaseEntity.h"

class MAPOverlay :public BaseEntity
{
public:
	std::vector<int> brushFaces;
	std::string materialName;
	
	float startU, endU, startV, endV;  // not actually useful?
	float minU, maxU;
	float minV, maxV;
	MAPVector basisNormal;

	MAPOverlay();
};