// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once

#include "UnrealEd.h" 
#include "Editor.h"



class BackgroundTickTester :public FRunnable
{
public:
	void Shutdown();
	bool IsThreadFinished();

	BackgroundTickTester();
	virtual ~BackgroundTickTester();

	virtual bool Init();
	virtual uint32 Run();
	virtual void Stop();

protected:
	FRunnableThread* Thread;
	FThreadSafeCounter StopTaskCounter;

	void EnsureCompletion();

	int currentTickCounter = 0;
	FDateTime originalTimestamp;
	FString filename = "F:/vmfs/testscale.vmf";
};

class FHammUErEdEdMode : public FEdMode
{
public:
	const static FEditorModeID EM_HammUErEdEdModeId;
public:
	FHammUErEdEdMode();
	virtual ~FHammUErEdEdMode();

	// FEdMode interface
	virtual void Enter() override;
	virtual void Exit() override;
	virtual void Tick(FEditorViewportClient* ViewportClient, float DeltaTime) override;
	//virtual void Render(const FSceneView* View, FViewport* Viewport, FPrimitiveDrawInterface* PDI) override;
	//virtual void ActorSelectionChangeNotify() override;
	bool UsesToolkits() const override;
	// End of FEdMode interface

	float startTime = 0;
	bool threadStarted = false;
	BackgroundTickTester* watchDog;
};
