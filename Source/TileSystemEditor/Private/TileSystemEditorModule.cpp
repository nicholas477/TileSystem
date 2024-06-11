// Copyright Epic Games, Inc. All Rights Reserved.

#include "TileSystemEditorModule.h"

#include "EditorModeRegistry.h"
#include "TileSystemEdMode.h"

#define LOCTEXT_NAMESPACE "FTileSystemEditorModule"

void FTileSystemEditorModule::StartupModule()
{
	FEditorModeRegistry::Get().RegisterMode<FTileSystemEdMode>(FName(TEXT("TileSystemEditorMode")), FText::FromString("Tile System Editor Mode"), FSlateIcon(), true);
}

void FTileSystemEditorModule::ShutdownModule()
{
	FEditorModeRegistry::Get().UnregisterMode(FName(TEXT("TileSystemEditorMode")));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTileSystemEditorModule, TileSystemEditor)