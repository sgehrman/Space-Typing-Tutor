//
// By Sid Krishna
//

#pragma once

#include "KrishnaMapMap.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UKrishnaMapMap : public UObject
{
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintPure, Category = "KrishnaMapMap")
    static UKrishnaMapMap* Create();

  // add
  UFUNCTION(BlueprintCallable, Category = "KrishnaMapMap")
    void AddString(FString Key, FString SecondKey, FString Value);

  UFUNCTION(BlueprintCallable, Category = "KrishnaMapMap")
    void AddInt(FString Key, FString SecondKey, int32 Value);

  UFUNCTION(BlueprintCallable, Category = "KrishnaMapMap")
    void AddFloat(FString Key, FString SecondKey, float Value);

  // get
  UFUNCTION(BlueprintPure, Category = "KrishnaMapMap")
    FString GetString(FString Key, FString SecondKey, bool& IsValid);

  UFUNCTION(BlueprintPure, Category = "KrishnaMapMap")
    int32 GetInt(FString Key, FString SecondKey, bool& IsValid);

  UFUNCTION(BlueprintPure, Category = "KrishnaMapMap")
    float GetFloat(FString Key, FString SecondKey, bool& IsValid);

  // remove
  UFUNCTION(BlueprintCallable, Category = "KrishnaMapMap")
    void Remove(FString Key);

  // clear
  UFUNCTION(BlueprintCallable, Category = "KrishnaMapMap")
    void Clear();

  // keys
  UFUNCTION(BlueprintPure, Category = "KrishnaMapMap")
    void GetStringKeys(TArray<FString>& OutKeys);

  UFUNCTION(BlueprintPure, Category = "KrishnaMapMap")
    void GetIntKeys(TArray<FString>& OutKeys);

  UFUNCTION(BlueprintPure, Category = "KrishnaMapMap")
    void GetFloatKeys(TArray<FString>& OutKeys);

  UFUNCTION(BlueprintPure, Category = "KrishnaMapMap")
    void GetStringKeysForKey(FString Key, TArray<FString>& OutKeys);

  UFUNCTION(BlueprintPure, Category = "KrishnaMapMap")
    void GetIntKeysForKey(FString Key, TArray<FString>& OutKeys);

  UFUNCTION(BlueprintPure, Category = "KrishnaMapMap")
    void GetFloatKeysForKey(FString Key, TArray<FString>& OutKeys);

public:
  TMap<FString, TMap<FString, FString>> StringMap;
  TMap<FString, TMap<FString, int32>> IntMap;
  TMap<FString, TMap<FString, float>> FloatMap;
};


