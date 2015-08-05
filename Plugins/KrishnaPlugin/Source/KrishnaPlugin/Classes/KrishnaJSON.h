//
// By Sid Krishna
//

#pragma once

#include "KrishnaJSON.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UKrishnaJSON : public UObject
{
  GENERATED_UCLASS_BODY()

private:
  void WriteObject(TSharedRef<TJsonWriter<TCHAR>> writer, FString key, FJsonValue* value);
  void Reset();

public:
  TSharedPtr<FJsonObject> Data;

  UFUNCTION(BlueprintPure, meta = (DisplayName = "Create KrishnaJSON"), Category = "KrishnaJSON")
    static UKrishnaJSON* Create();

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add String Field"), Category = "KrishnaJSON")
    UKrishnaJSON* SetString(const FString& key, const FString& value);

  UFUNCTION(BlueprintCallable, Category = "KrishnaJSON")
    UKrishnaJSON* SetInteger(const FString& key, const int32 value);

  UFUNCTION(BlueprintCallable, Category = "KrishnaJSON")
    UKrishnaJSON* SetFloat(const FString& key, const float value);

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add String Array Field"), Category = "KrishnaJSON")
    UKrishnaJSON* SetStringArray(const FString& key, const TArray<FString> arrayData);

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Data Field"), Category = "KrishnaJSON")
    UKrishnaJSON* SetObject(const FString& key, const UKrishnaJSON* objectData);

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Object Array Field"), Category = "KrishnaJSON")
    UKrishnaJSON* SetObjectArray(const FString& key, const TArray<UKrishnaJSON*> arrayData);

  UFUNCTION(BlueprintPure, meta = (DisplayName = "Get String Field"), Category = "KrishnaJSON")
    FString GetString(const FString& key, bool& IsValid) const;

  UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Integer Field"), Category = "KrishnaJSON")
    int32 GetInteger(const FString& key, bool& IsValid) const;

  UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Float Field"), Category = "KrishnaJSON")
    float GetFloat(const FString& key, bool& IsValid) const;

  UFUNCTION(BlueprintPure, meta = (DisplayName = "Get String Array Field"), Category = "KrishnaJSON")
    TArray<FString> GetStringArray(const FString& key);

  UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Data Field"), Category = "KrishnaJSON")
    UKrishnaJSON* GetObject(const FString& key);

  UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Object Array Field"), Category = "KrishnaJSON")
    TArray<UKrishnaJSON*> GetObjectArray(const FString& key);

  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Parse Json String"), Category = "KrishnaJSON")
    UKrishnaJSON* ParseJson(const FString& fileContents);

  UFUNCTION(BlueprintPure, Category = "KrishnaJSON")
    bool ToJsonString(FString& OutStr);

  UFUNCTION(BlueprintPure, Category = "KrishnaJSON")
    void GetKeys(TArray<FString>& OutKeys);
};