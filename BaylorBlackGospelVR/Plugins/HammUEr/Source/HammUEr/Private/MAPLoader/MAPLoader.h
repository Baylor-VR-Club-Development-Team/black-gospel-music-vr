// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once
#include "../MapShared/BaseEntity.h"
#include "../MapShared/MAPNode.h"
#include "../MapShared/MapArrayStructs.h"
#include "MAPSolid.h"
#include "../MapShared/MapLoaderBase.h"

enum class EMAPStage :int
{
	Idle,
	Read,
	Parse,
	Building,
	Done
};

struct MAPGroup
{
	int id;
	int parent;
};

class MAPLoader:public MapLoaderBase
{
public:

	void Open(std::string fName) override;

	bool PhaseOne() override;

	void PhaseTwo(std::vector<int> tws, std::vector<int> ths, std::vector<bool> tnd) override;
	
private:
	std::string myPath;
	std::string MAPName = "nonameyet";

	MAPNode* fileRootNode;
	MAPNode* activeNode;

	std::vector<std::string> MAPileLines;

	bool createDebugMaterials = true;
	bool recenterMeshes = false;

	// read stage
	int numLines;
	int currentLine;

	// parse stage
	int numNodes;
	int currentNode;

	std::vector<MAPSolid*> solids;
	std::vector<bool> materialNoDraw;
	int nodrawIndex = -1;
	int entityCounter = 0; 

	std::vector<int> groupList;
	std::vector<MAPInt32Array> groupSolids;
	std::map<int, MAPGroup> groupParser;
	std::map<int, MAPInt32Array> topGroupSolids;
	std::vector<int> topGroupList;

	std::vector<int> entityList;
	std::vector<MAPInt32Array> entitySolids;

	std::vector<int> textureWidths;
	std::vector<int> textureHeights;
	std::vector<bool> textureNoDraws;

	void ParseWorld(MAPNode* thisNode, bool quick = false);
	void ParseGroup(MAPNode* thisNode, bool quick = false);
	MAPSolid* ParseSolid(MAPNode* thisNode, bool quick = false, bool knownEntityType = false);
	MAPSolid* ParsePatch(MAPNode* thisNode, bool quick = false);
	void ParseEntity(MAPNode* thisNode, bool quick = false);
	void ParseTree(MAPNode* thisNode, bool quick=false);
	void RearrangeGroups();
	void BuildBrushes();

	int propCount; 

	int ReadDoom3Primitive();
	int ReadPatch(bool PatchDef3);

	int patchID = 0;

	bool isQuakeMap = false;
	bool isQuake3 = false;
	bool isDoom3 = false;

};


