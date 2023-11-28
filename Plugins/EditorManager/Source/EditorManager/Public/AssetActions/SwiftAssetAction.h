// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetActionUtility.h"
#include "SwiftAssetAction.generated.h"

/**
 * 
 */
UCLASS()
class EDITORMANAGER_API USwiftAssetAction : public UAssetActionUtility
{
	GENERATED_BODY()
#pragma region Public Section
public:
	//Need to create a BP class based on SwiftAssetAction to be able to see the Scripted asset action in Editor.
	UFUNCTION(CallInEditor)
	void DuplicateAsset(int32 NumOfDuplicates);
	
#pragma endregion 	
};
