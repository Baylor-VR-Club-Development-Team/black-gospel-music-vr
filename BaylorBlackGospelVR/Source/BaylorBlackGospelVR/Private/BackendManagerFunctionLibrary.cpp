// Fill out your copyright notice in the Description page of Project Settings.

#include "BackendManagerFunctionLibrary.h"

public static void UBackendManagerFunctionLibrary::getRecord() {
    BackendManager bm = BackendManager::init();

    bm.getSong(13059);
}