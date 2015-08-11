//
// By Sid Krishna
//

#pragma once

#include "KrishnaMap.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UKrishnaMap : public UObject
{
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintPure, meta = (DisplayName = "Create KrishnaMap"), Category = "KrishnaMap")
    static UKrishnaMap* Create();

  // add
  UFUNCTION(BlueprintCallable, Category = "KrishnaMap")
    void String_String__AddPair(FString Key, FString Value);

  UFUNCTION(BlueprintCallable, Category = "KrishnaMap")
    void String_Int__AddPair(FString Key, int32 Value);

  UFUNCTION(BlueprintCallable, Category = "KrishnaMap")
    void String_Float__AddPair(FString Key, float Value);

  // get
  UFUNCTION(BlueprintPure, Category = "KrishnaMap")
    FString String_String__Get(FString Key, bool& IsValid);

  UFUNCTION(BlueprintPure, Category = "KrishnaMap")
    int32 String_Int__Get(FString Key, bool& IsValid);

  UFUNCTION(BlueprintPure, Category = "KrishnaMap")
    float String_Float__Get(FString Key, bool& IsValid);

  // remove
  UFUNCTION(BlueprintCallable, Category = "KrishnaMap")
    void String_String__Remove(FString Key);

  UFUNCTION(BlueprintCallable, Category = "KrishnaMap")
    void String_Int__Remove(FString Key);

  UFUNCTION(BlueprintCallable, Category = "KrishnaMap")
    void String_Float__Remove(FString Key);

  // IsEmpty
  UFUNCTION(BlueprintCallable, Category = "KrishnaMap")
    bool IsEmpty();

  // clear
  UFUNCTION(BlueprintCallable, Category = "KrishnaMap")
    void Clear();

  UFUNCTION(BlueprintCallable, Category = "KrishnaMap")
    void String_String__Clear();

  UFUNCTION(BlueprintCallable, Category = "KrishnaMap", meta = (Keywords = "Clear Empty Reset"))
    void String_Int__Clear();

  UFUNCTION(BlueprintCallable, Category = "KrishnaMap", meta = (Keywords = "Clear Empty Reset"))
    void String_Float__Clear();

  // keys
  UFUNCTION(BlueprintPure, Category = "KrishnaMap")
    void String_String__GetKeys(TArray<FString>& OutKeys);

  UFUNCTION(BlueprintPure, Category = "KrishnaMap")
    void String_Int__GetKeys(TArray<FString>& OutKeys);

  UFUNCTION(BlueprintPure, Category = "KrishnaMap")
    void String_Float__GetKeys(TArray<FString>& OutKeys);

public:
  TMap<FString, FString> StringAndString;
  TMap<FString, int32> 		StringInt;
  TMap<FString, float> 		StringFloat;
};


