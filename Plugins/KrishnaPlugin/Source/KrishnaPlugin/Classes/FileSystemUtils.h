// Copyright 1998-2013 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "FileSystemUtils.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFileSystemUtils : public UObject
{
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintPure, Category = "FileSystemUtils")
    static bool LoadFileToString(const FString& InFilePath, FString& OutString);

  UFUNCTION(BlueprintPure, Category = "FileSystemUtils")
    static FString CreateUniqueFilename(const FString& Directory, const FString& Prefix, const FString& Extension);
};