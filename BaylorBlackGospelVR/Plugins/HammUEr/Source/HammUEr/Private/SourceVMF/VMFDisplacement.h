// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once
#include "../MapShared/MAPNode.h"
#include "../MapShared/VMFTri.h"
#include "../MapShared/MapArrayStructs.h"

class VMFDisplacement
{
public:
	int power = 4;				
	MAPVector startPosition;	
	float elevation;			
	bool subdiv;				

	int rowCount;
	int columnCount;

	MAPVector lowerLeft;
	MAPVector lowerRight;
	MAPVector topLeft;
	MAPVector topRight;

	MAPVector UAxis;
	float UAxisTrans;
	float UAxisScale;

	MAPVector VAxis;
	float VAxisTrans;
	float VAxisScale;

	int textureWidth;
	int textureHeight;

	int materialId;

	int debugId;

	std::vector<MAPVectorArray> normals; 
	std::vector<MAPFloatArray> distances;
	std::vector<MAPVectorArray> offsets;
	std::vector<MAPVectorArray> offset_normals;
	std::vector<MAPFloatArray> alphas;
	std::vector<MAPInt32Array> triangle_tags;
	std::vector<int> allowed_verts;

	std::vector<VMFTri*> generatedTris;
	std::vector<MAPVectorArray> calculatedVertices;
	std::vector<MAPVector2DArray> calculatedUVs;

	VMFDisplacement();
	void Parse(MAPNode* inputNode);
	void Generate(std::vector<MAPVector> cornerpoints, float conversion, MAPQuat rotateQuat);

private:
	MAPColor BuildColor(int alphaValue);

	void ParseVertexArray(MAPNode* inputNode, std::vector<MAPVectorArray>& outArray);
	void ParseFloatArray(MAPNode* inputNode, std::vector<MAPFloatArray>& outArray);
	void ParseIntArray(MAPNode* inputNode, std::vector<MAPInt32Array>& outArray);
};