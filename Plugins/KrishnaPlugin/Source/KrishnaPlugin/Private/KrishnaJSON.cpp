//
// By Sid Krishna
//

#include "KrishnaPluginPrivatePCH.h"

UKrishnaJSON::UKrishnaJSON(const class FObjectInitializer& PCIP)
  : Super(PCIP) {
  Reset();
}

UKrishnaJSON* UKrishnaJSON::Create() {
  UKrishnaJSON* json = NewObject<UKrishnaJSON>();

  return json;
}

void UKrishnaJSON::WriteObject(TSharedRef<TJsonWriter<TCHAR>> writer, FString key, FJsonValue* value) {
  if (value->Type == EJson::String) {
    if (key.Len() > 0) {
      writer->WriteValue(key, value->AsString());
    }
    else {
      writer->WriteValue(value->AsString());
    }
  }
  else if (value->Type == EJson::Object) {
    if (key.Len() > 0) {
      writer->WriteObjectStart(key);
    }
    else {
      writer->WriteObjectStart();
    }

    TSharedPtr<FJsonObject> objectData = value->AsObject();
    for (auto objectValue = objectData->Values.CreateIterator(); objectValue; ++objectValue) {
      WriteObject(writer, objectValue.Key(), objectValue.Value().Get());
    }

    writer->WriteObjectEnd();
  }
  else if (value->Type == EJson::Array) {
    writer->WriteArrayStart(key);

    TArray<TSharedPtr<FJsonValue>> objectArray = value->AsArray();
    for (int32 i = 0; i < objectArray.Num(); i++) {
      WriteObject(writer, "", objectArray[i].Get());
    }

    writer->WriteArrayEnd();
  }
}

UKrishnaJSON* UKrishnaJSON::SetString(const FString& key, const FString& value) {
  Data->SetStringField(*key, *value);
  return this;
}

UKrishnaJSON* UKrishnaJSON::SetInteger(const FString& key, const int32 value) {
  Data->SetNumberField(*key, value);
  return this;
}

UKrishnaJSON* UKrishnaJSON::SetFloat(const FString& key, const float value) {
  Data->SetNumberField(*key, value);
  return this;
}

UKrishnaJSON* UKrishnaJSON::SetObject(const FString& key, const UKrishnaJSON* objectData) {
  Data->SetObjectField(*key, objectData->Data);
  return this;
}

UKrishnaJSON* UKrishnaJSON::SetObjectArray(const FString& key, const TArray<UKrishnaJSON*> objectData) {
  TArray<TSharedPtr<FJsonValue>> *dataArray = new TArray<TSharedPtr<FJsonValue>>();

  for (int32 i = 0; i < objectData.Num(); i++) {
    dataArray->Add(MakeShareable(new FJsonValueObject(objectData[i]->Data)));
  }

  Data->SetArrayField(*key, *dataArray);
  return this;
}

UKrishnaJSON* UKrishnaJSON::SetStringArray(const FString& key, const TArray<FString> stringData) {
  TArray<TSharedPtr<FJsonValue>> *dataArray = new TArray<TSharedPtr<FJsonValue>>();

  for (int32 i = 0; i < stringData.Num(); i++) {
    dataArray->Add(MakeShareable(new FJsonValueString(stringData[i])));
  }

  Data->SetArrayField(*key, *dataArray);
  return this;
}

UKrishnaJSON* UKrishnaJSON::GetObject(const FString& key) {
  UKrishnaJSON* fieldObj = NULL;

  const TSharedPtr<FJsonObject> *outPtr;
  if (!Data->TryGetObjectField(*key, outPtr)) {
    return NULL;
  }

  fieldObj = UKrishnaJSON::Create();
  fieldObj->Data = *outPtr;

  return fieldObj;
}

TArray<FString> UKrishnaJSON::GetStringArray(const FString& key) {
  TArray<FString> stringArray;

  const TArray<TSharedPtr<FJsonValue>> *arrayPtr;
  if (Data->TryGetArrayField(*key, arrayPtr)) {
    for (int32 i = 0; i < arrayPtr->Num(); i++) {
      stringArray.Add((*arrayPtr)[i]->AsString());
    }
  }

  return stringArray;
}

TArray<UKrishnaJSON*> UKrishnaJSON::GetObjectArray(const FString& key) {
  TArray<UKrishnaJSON*> objectArray;

  const TArray<TSharedPtr<FJsonValue>> *arrayPtr;
  if (Data->TryGetArrayField(*key, arrayPtr)) {
    for (int32 i = 0; i < arrayPtr->Num(); i++) {
      UKrishnaJSON* pageData = Create();
      pageData->Data = (*arrayPtr)[i]->AsObject();
      objectArray.Add(pageData);
    }
  }

  return objectArray;
}

FString UKrishnaJSON::GetString(const FString& key, bool& IsValid) const {
  FString outString;
  IsValid = false;
  if (!Data->TryGetStringField(*key, outString)) {
    return "";
  }
  IsValid = true;
  return outString;
}

int32 UKrishnaJSON::GetInteger(const FString& key, bool& IsValid) const {
  int32 outInt;
  IsValid = false;

  if (!Data->TryGetNumberField(*key, outInt)) {
    return 0;
  }
  IsValid = true;

  return outInt;
}

float UKrishnaJSON::GetFloat(const FString& key, bool& IsValid) const {
  double outDouble;
  IsValid = false;

  if (!Data->TryGetNumberField(*key, outDouble)) {
    return 0;
  }
  IsValid = true;

  return (float)outDouble;
}

UKrishnaJSON* UKrishnaJSON::ParseJson(const FString& fileContents) {
  FString responseData = fileContents;
  TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(responseData);

  FJsonSerializer::Deserialize(JsonReader, Data);

  return this;
}

bool UKrishnaJSON::ToJsonString(FString& OutStr) {
  TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutStr);
  bool result = FJsonSerializer::Serialize(Data.ToSharedRef(), Writer);
  Writer->Close();

  return result;
}

void UKrishnaJSON::Reset() {
  if (Data.IsValid()) {
    Data.Reset();
  }

  Data = MakeShareable(new FJsonObject());
}

void UKrishnaJSON::GetKeys(TArray<FString>& OutKeys) {
  OutKeys.Empty();

  Data->Values.GetKeys(OutKeys);
}