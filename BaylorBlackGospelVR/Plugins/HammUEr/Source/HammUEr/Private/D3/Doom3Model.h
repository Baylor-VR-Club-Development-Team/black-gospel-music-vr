// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once
#include <string>
#include <vector>
#include "../MapShared/MAPVector.h"

class Doom3Vert
{
public:
	MAPVector position;
	MAPVector2D uvs;
	MAPVector normal;
};

class Doom3Surface
{
public:
	std::string matName;
	int numVerts;
	int numIndices;

	std::vector<Doom3Vert*> vertices;
	std::vector<int> indices;
};

class Doom3Model
{
public:
	std::string name;
	int numSurfaces;

	std::vector<Doom3Surface*> surfaces;
};