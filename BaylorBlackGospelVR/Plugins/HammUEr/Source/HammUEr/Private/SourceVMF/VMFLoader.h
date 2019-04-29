// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once
#include "VMFSolid.h"
#include "../MapShared/MapArrayStructs.h"
#include "../MapShared/BaseEntity.h"
#include "../MapShared/MAPNode.h"
#include "../MapShared/VMFLogic.h"
#include "../MapShared/MapLoaderBase.h"

struct FHammerOutput
{
	std::string inputName;
	std::string OutputName;
	std::string TargetEntity;
	std::string TargetInput;
	std::string Parameter;
	float Delay;
	bool OnlyOnce;
};

enum class EVMFStage :int
{
	Idle,
	Read,
	Parse,
	Building,
	Done
};

struct VMFGroup
{
	int id;
	int parent;
};

class VMFLoader:public MapLoaderBase
{
public:
	void Open(std::string fName) override;

	bool PhaseOne() override;

	void PhaseTwo(std::vector<int> tws,std::vector<int> ths, std::vector<bool> tnd) override;
	
private:
	std::string myPath;
	std::string VMFName = "nonameyet";

	MAPNode* fileRootNode;
	MAPNode* activeNode;

	std::vector<std::string> VMFileLines;

	bool createDebugMaterials = true;
	bool recenterMeshes = false;

	// read stage
	int numLines;
	int currentLine;

	// parse stage
	int numNodes;
	int currentNode;

	std::vector<VMFSolid*> solids;
	std::vector<bool> materialNoDraw;
	int nodrawIndex = -1;
	int entityCounter = 0; 

	std::vector<int> groupList;
	std::vector<MAPInt32Array> groupSolids;
	std::map<int, VMFGroup> groupParser;
	std::map<int, MAPInt32Array> topGroupSolids;
	std::vector<int> topGroupList;

	std::vector<int> entityList;
	std::vector<MAPInt32Array> entitySolids;

	std::vector<int> textureWidths;
	std::vector<int> textureHeights;
	std::vector<bool> textureNoDraws;

	void ParseWorld(MAPNode* thisNode, bool quick = false);
	void ParseGroup(MAPNode* thisNode, bool quick = false);
	VMFSolid* ParseSolid(MAPNode* thisNode, bool quick = false, bool knownEntityType = false);
	void ParseEntity(MAPNode* thisNode, bool quick = false);
	void ParseTree(MAPNode* thisNode, bool quick=false);
	void RearrangeGroups();
	void BuildBrushes();

	int propCount; 

	void AddOutputs(MAPNode* thisNode, VMFLogic* newLogic);
};


