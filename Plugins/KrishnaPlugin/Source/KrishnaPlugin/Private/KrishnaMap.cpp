
//
// By Sid Krishna
//

#include "KrishnaPluginPrivatePCH.h"
#include "KrishnaMap.h"

UKrishnaMap* UKrishnaMap::Create() {
  UKrishnaMap* result = NewObject<UKrishnaMap>();

  return result;
}

void UKrishnaMap::String_String__AddPair(FString Key, FString Value)
{
  StringAndString.Add(Key, Value);
}

void UKrishnaMap::String_Int__AddPair(FString Key, int32 Value)
{
  StringInt.Add(Key, Value);
}

FString UKrishnaMap::String_String__Get(FString Key, bool& IsValid)
{
  IsValid = false;
  if (!StringAndString.Contains(Key))
  {
    return "";
  }
  IsValid = true;
  return StringAndString[Key];
}

int32 UKrishnaMap::String_Int__Get(FString Key, bool& IsValid)
{
  IsValid = false;
  if (!StringInt.Contains(Key))
  {
    return 0;
  }
  IsValid = true;
  return StringInt[Key];
}

void UKrishnaMap::String_String__Remove(FString Key)
{
  StringAndString.Remove(Key);
}

void UKrishnaMap::String_Int__Remove(FString Key)
{
  StringInt.Remove(Key);
}

void UKrishnaMap::Clear()
{
  String_String__Clear();
  String_Int__Clear();
}

bool UKrishnaMap::IsEmpty() {
  return ((StringInt.Num() == 0) && (StringAndString.Num() == 0));
}

void UKrishnaMap::String_String__Clear()
{
  StringAndString.Empty();
}

void UKrishnaMap::String_Int__Clear()
{
  StringInt.Empty();
}

void UKrishnaMap::String_String__GetKeys(TArray<FString>& OutKeys) {
  OutKeys.Empty();
  StringAndString.GetKeys(OutKeys);
}

void UKrishnaMap::String_Int__GetKeys(TArray<FString>& OutKeys) {
  OutKeys.Empty();
  StringInt.GetKeys(OutKeys);
}