// HammUEr
// Map loader base class
// Copyright 2015-2016 NT Entertainment

#pragma once
//#include "HammUErPrivatePCH.h"
#include "VMFTri.h"
#include "BaseEntity.h"
#include "MapArrayStructs.h"

class MapLoaderBase
{
public:
	MapLoaderBase()
	{}

	virtual ~MapLoaderBase()
	{}

	virtual void Open(std::string fileName)
	{}

	virtual bool PhaseOne()
	{
		return true;
	}

	virtual void PhaseTwo(std::vector<int> tws, std::vector<int> ths, std::vector<bool> tnd)
	{}

	int GetNumEntities();
	
	int GetEntityID(int index);

	MapEntityType GetEntityType(int index);
	BaseEntity* GetEntity(int index);
	std::string GetEntityName(int index);

	int GetNumBrushes();

	MapBrush* GetBrush(int index);

	std::vector<std::string> GetMaterials();
	
	void SetConversion(float value);

	void SetDontSmooth(bool value);
	
	void SetSmoothingAngle(float value);
	
	void SetSmoothingWeldRange(float value);
	
	std::string GetStageName();

	float GetStagePercentage();

	std::string importDirectory; // temporary

	protected:
	std::vector<std::string> materialNames;
	float convertUE;

	std::string stageName = "none";
	float stagePercentage = 0.f;

	// our data brushes, entities, etc
	std::vector<MapBrush*> brushes;
	std::vector<BaseEntity*> entities;

	bool doNotUseSmoother;
	float smoothWeldRange;
	float smoothingAngle;

	std::string mapType = "default";

	void CheckAdjacencies(int work, std::vector<VMFTri*> &inTriangles, std::vector<int> &visited, std::vector<MAPInt32Array> &adjacencies, std::vector<MAPInt32Array> &smoothingGroups);
	void SmoothTriangles(std::vector<VMFTri*> &trianglesToEdit, bool swapTwoThree);
};
