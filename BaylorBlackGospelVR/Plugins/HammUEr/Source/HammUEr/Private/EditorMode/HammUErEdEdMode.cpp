// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

// Hell, this code does nothing at the moment anyway.

#include "../HammUErPrivatePCH.h"
#include "HammUErEdEdMode.h"
#include "HammUErEdEdModeToolkit.h"
#include "Toolkits/ToolkitManager.h"

const FEditorModeID FHammUErEdEdMode::EM_HammUErEdEdModeId = TEXT("EM_Hammuer");

FHammUErEdEdMode::FHammUErEdEdMode()
{

}

FHammUErEdEdMode::~FHammUErEdEdMode()
{
	watchDog->Shutdown();
	delete watchDog;
}

void FHammUErEdEdMode::Enter()
{
	FEdMode::Enter();
	if (!Toolkit.IsValid() && UsesToolkits())
	{
		Toolkit = MakeShareable(new FHammUErEdEdModeToolkit);
		Toolkit->Init(Owner->GetToolkitHost());
	}
	startTime = GEditor->GetEditorWorldContext().World()->GetTimeSeconds();
	FEditorModeInfo test = GetModeInfo();
	UE_LOG(LogTemp, Log, TEXT("%s"), *(((FName)test.ID).ToString()));
}

void FHammUErEdEdMode::Exit()
{
	if (Toolkit.IsValid())
	{
		FToolkitManager::Get().CloseToolkit(Toolkit.ToSharedRef());
		Toolkit.Reset();
	}

	// Call base Exit method to ensure proper cleanup
	FEdMode::Exit();
}

bool FHammUErEdEdMode::UsesToolkits() const
{
	return true;
}

void FHammUErEdEdMode::Tick(FEditorViewportClient* ViewportClient, float DeltaTime)
{
	if (!threadStarted)
		if (GEditor->GetEditorWorldContext().World()->GetTimeSeconds() - startTime > 1.0f)
		{
			watchDog = new BackgroundTickTester();
			watchDog->Init();
			threadStarted = true;
		}
}


BackgroundTickTester::BackgroundTickTester()
{
	Thread = FRunnableThread::Create(this, TEXT("BackTick"));
}

BackgroundTickTester::~BackgroundTickTester()
{
	delete Thread;
	Thread = NULL;
}

bool BackgroundTickTester::Init()
{
	originalTimestamp = FPlatformFileManager::Get().GetPlatformFile().GetTimeStamp(*filename);
	return true;
}

uint32 BackgroundTickTester::Run()
{
	IPlatformFile& platformFile = FPlatformFileManager::Get().GetPlatformFile();
	while (StopTaskCounter.GetValue() == 0)
	{
		FPlatformProcess::Sleep(2.f);
	//	UE_LOG(LogTemp, Warning, TEXT("TICK TOCK %i FROM THREAD"), currentTickCounter++);
		FDateTime currentTimestamp = platformFile.GetTimeStamp(*filename);
		if (currentTimestamp != originalTimestamp)
			if (FMessageDialog::Open(EAppMsgType::OkCancel, FText::FromString("Timestamps do not match!\r\nDo you want to recheck the file?")) == EAppReturnType::Ok)
			{
				// THIS IS BROKEN. UE-30522
			//	FEditorDelegates::ChangeEditorMode.Broadcast(FHammUErEdEdMode::EM_HammUErEdEdModeId);
				//GEditor->DeferredCommands.Add(TEXT("MODE EM_Landscape"));
				/*

				TArray<FEdMode*> ActiveModes;
				GLevelEditorModeTools().GetActiveModes(ActiveModes);
				for (FEdMode* Mode : ActiveModes)
				{
					if (Mode->GetID() != FHammUErEdEdMode::EM_HammUErEdEdModeId && Mode->GetModeInfo().bVisible)
					{
						GLevelEditorModeTools().DeactivateMode(Mode->GetID());
					}
				}*/
			
				originalTimestamp = FPlatformFileManager::Get().GetPlatformFile().GetTimeStamp(*filename);
			}
	}

	return 0;
}

void BackgroundTickTester::Stop()
{
	StopTaskCounter.Increment();
}

void BackgroundTickTester::EnsureCompletion()
{
	Stop();
	Thread->WaitForCompletion();
}

void BackgroundTickTester::Shutdown()
{
	EnsureCompletion();
}

bool BackgroundTickTester::IsThreadFinished()
{
/*	if (Runnable) return false;
	return true;*/
	return false;
};