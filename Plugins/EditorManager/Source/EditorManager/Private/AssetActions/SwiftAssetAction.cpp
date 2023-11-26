// Fill out your copyright notice in the Description page of Project Settings.


#include "AssetActions/SwiftAssetAction.h"
#include "DebugHeader.h"

void USwiftAssetAction::TestFunction()
{
	Print(TEXT("It is working!"), FColor::Green);
	PrintLog(TEXT("PrintLog working!"));
}
