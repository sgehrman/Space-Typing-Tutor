// Copyright 1998-2013 Epic Games, Inc. All Rights Reserved.
#include "KrishnaPluginPrivatePCH.h"

bool UFileSystemUtils::LoadFileToString(const FString& InFilePath, FString& OutString)
{
  return FFileHelper::LoadFileToString(OutString, *InFilePath);
}

FString UFileSystemUtils::CreateUniqueFilename(const FString& Directory, const FString& Prefix, const FString& Extension)
{
  FString UniqueFilename;
  int32 index = 0;

  do
  {
    index++;

    UniqueFilename = FPaths::Combine(*Directory, *FString::Printf(TEXT("%s %d.%s"), *Prefix, index, *Extension));
  } while (IFileManager::Get().FileSize(*UniqueFilename) >= 0);

  return UniqueFilename;
}

bool UFileSystemUtils::FileExists(const FString& File)
{
  return FPlatformFileManager::Get().GetPlatformFile().FileExists(*File);
}

bool UFileSystemUtils::FolderExists(const FString& Dir)
{
  return FPlatformFileManager::Get().GetPlatformFile().DirectoryExists(*Dir);
}