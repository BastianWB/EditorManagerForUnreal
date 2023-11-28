// Fill out your copyright notice in the Description page of Project Settings.


#include "AssetActions/SwiftAssetAction.h"
#include "EditorAssetLibrary.h"
#include "EditorUtilityLibrary.h"
#include "DebugHeader.h"


void USwiftAssetAction::DuplicateAsset(int32 NumOfDuplicates)
{
	if (NumOfDuplicates < 0)
	{
		Print(TEXT("Enter a valid number."), FColor::Red);
		return;
	}
	//Calling GetSelectedAssetData() from UEditorUtilityLibrary:: and storing it in a TArray<FAssetData> named SelectedAssetsDataArray.
	TArray<FAssetData> SelectedAssetsDataArray = UEditorUtilityLibrary::GetSelectedAssetData();
	//Initializing a uint32 Variable to store the number of Duplicated Assets
	uint32 Counter = 0; 
	//
	for(const FAssetData& SelectedAssetData:SelectedAssetsDataArray)
	{	// For Loop that will Loop as many times as the number of duplicates.
		for(int32 i = 0; i < NumOfDuplicates; i++)
		{
			//Getting Object Path as a String and storing it in a FString named SourceAssetPath. 
			const FString SourceAssetPath = SelectedAssetData.GetObjectPathString();
			//Getting New Asset Name and Storing it in NewDuplicatedAssetName Variable.
			const FString NewDuplicatedAssetName = SelectedAssetData.AssetName.ToString() + TEXT("_")+FString::FromInt(i+1);
			//Combining the NewDuplicatedAssetName with the NewPathName to complete the correct path
			const FString NewPathName = FPaths::Combine(SelectedAssetData.PackagePath.ToString(), NewDuplicatedAssetName);
			//If Duplication was successful Save the Asset and increment the counter then return to the outer for loop start. 
			if (UEditorAssetLibrary::DuplicateAsset(SourceAssetPath, NewPathName))
			{
				UEditorAssetLibrary::SaveAsset(NewPathName, false);
				++Counter;
			}
		}
	}
	//Only print this message if the counter is greater than Zero.
	if (Counter > 0)
	{
		Print(TEXT("Successfully duplicated " + FString::FromInt(Counter) + "files"), FColor::Green);	
	}
	
}
