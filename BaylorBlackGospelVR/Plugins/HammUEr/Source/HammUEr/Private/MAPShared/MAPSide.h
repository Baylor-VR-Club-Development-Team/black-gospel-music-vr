// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once
#include "MAPNode.h"
#include "MAPPlane.h"

class MAPSide
{
private:

public:

	int id;

	MAPVector planeA;
	MAPVector planeB;
	MAPVector planeC;

	int materialId;

	bool noDraw = false;

	bool displacement = false;

	MAPVector UAxis;
	float UAxisTrans;
	float UAxisScale;

	MAPVector VAxis;
	float VAxisTrans;
	float VAxisScale;

	MAPPlane plane;

	MAPSide();
	float PointAbovePlane(MAPVector point);
};
