// Copyright 1998-2013 Epic Games, Inc. All Rights Reserved.
#include "KrishnaPluginPrivatePCH.h"

bool UFileSystemUtils::LoadFileToString(const FString& InFilePath, FString& OutString)
{
  return FFileHelper::LoadFileToString(OutString, *InFilePath);
}