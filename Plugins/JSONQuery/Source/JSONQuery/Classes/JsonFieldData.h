// Copyright 1998-2013 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "JsonFieldData.generated.h"

// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGetResult);

UCLASS(BlueprintType, Blueprintable)
class UJsonFieldData : public UObject
{
  GENERATED_UCLASS_BODY()

private:
  /* Internal bind method for the IHTTPRequest::OnProcessRequestCompleted() event */
  void OnReady(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

  /* Resets the current post data */
  void Reset();

  /* Prefixes the input URL with http:// if needed */
  static FString CreateURL(FString inputURL);

  void WriteObject(TSharedRef<TJsonWriter<TCHAR>> writer, FString key, FJsonValue* value);
public:
  UObject* contextObject;

  /* The actual field data */
  TSharedPtr<FJsonObject> Data;

  /* Contains the actual page content, as a string */
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JSON")
    FString Content;

  /* Event which triggers when the content has been retrieved */
  UPROPERTY(BlueprintAssignable, Category = "JSON")
    FOnGetResult OnGetResult;

  /* Static constructor method */
  UFUNCTION(BlueprintPure, meta = (DisplayName = "Create JSON Data", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "JSON")
    static UJsonFieldData* Create(UObject* WorldContextObject);

  /* Sets string data to the post data */
  UFUNCTION(BlueprintPure, meta = (DisplayName = "Add String Field"), Category = "JSON")
    UJsonFieldData* SetString(const FString& key, const FString& value);

  UFUNCTION(BlueprintPure, meta = (DisplayName = "Add String Array Field"), Category = "JSON")
    UJsonFieldData* SetStringArray(const FString& key, const TArray<FString> arrayData);

  /* Sets nested object data to the post array */
  UFUNCTION(BlueprintPure, meta = (DisplayName = "Add Data Field"), Category = "JSON")
    UJsonFieldData* SetObject(const FString& key, const UJsonFieldData* objectData);

  UFUNCTION(BlueprintPure, meta = (DisplayName = "Add Object Array Field"), Category = "JSON")
    UJsonFieldData* SetObjectArray(const FString& key, const TArray<UJsonFieldData*> arrayData);

  /* Fetches string data from the post data */
  UFUNCTION(BlueprintPure, meta = (DisplayName = "Get String Field"), Category = "JSON")
    FString GetString(const FString& key) const;

  UFUNCTION(BlueprintPure, meta = (DisplayName = "Get String Array Field", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "JSON")
    TArray<FString> GetStringArray(const FString& key);

  /* Fetches nested post data from the post data */
  UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Data Field", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "JSON")
    UJsonFieldData* GetObject(const FString& key);

  UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Object Array Field", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "JSON")
    TArray<UJsonFieldData*> GetObjectArray(UObject* WorldContextObject, const FString& key);

  /* Posts a request with the supplied post data to the internets */
  UFUNCTION(BlueprintCallable, meta = (DisplayName = "Post JSON Request", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "JSON")
    void PostRequest(UObject* WorldContextObject, const FString& url);

  /* Requests a page from the internet with a JSON response */
  UFUNCTION(BlueprintPure, meta = (DisplayName = "Get JSON Request", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "JSON")
    static UJsonFieldData* GetRequest(UObject* WorldContextObject, const FString& url);
};