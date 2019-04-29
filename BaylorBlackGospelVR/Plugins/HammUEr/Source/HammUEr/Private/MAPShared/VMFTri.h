// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once
#include "MAPVector.h"

class VMFTri
{
public:
	MAPVector v1;
	MAPVector v2;
	MAPVector v3;
	MAPVector2D uv1;
	MAPVector2D uv2;
	MAPVector2D uv3;
	MAPVector n1;
	MAPVector n2;
	MAPVector n3;
	MAPColor c1;
	MAPColor c2;
	MAPColor c3;
	int matId;

	MAPVector tangentX;
	MAPVector tangentY;
	MAPVector normal;

	VMFTri();
	VMFTri(MAPVector p1, MAPVector p2, MAPVector p3, MAPVector2D u1, MAPVector2D u2, MAPVector2D u3, MAPColor col1, MAPColor col2, MAPColor col3, int id=0);
	VMFTri(MAPVector p1, MAPVector p2, MAPVector p3, MAPVector2D u1, MAPVector2D u2, MAPVector2D u3, MAPVector in1, MAPVector in2, MAPVector in3, MAPColor col1, MAPColor col2, MAPColor col3, int id = 0);
};