
//
// By Sid Krishna
//

#include "KrishnaPluginPrivatePCH.h"
#include "KrishnaMapMap.h"

UKrishnaMapMap* UKrishnaMapMap::Create() {
  UKrishnaMapMap* result = NewObject<UKrishnaMapMap>();

  return result;
}

void UKrishnaMapMap::AddString(FString Key, FString SecondKey, FString Value)
{
  TMap <FString, FString> map;

  // if already exists, use that
  if (StringMap.Contains(Key))
  {
    map = StringMap[Key];
  }

  map.Add(SecondKey, Value);

  StringMap.Add(Key, map);
}

FString UKrishnaMapMap::GetString(FString Key, FString SecondKey, bool& IsValid)
{
  IsValid = false;
  if (!StringMap.Contains(Key))
  {
    return "";
  }

  TMap <FString, FString> map = StringMap[Key];
  if (!map.Contains(SecondKey))
  {
    return "";
  }

  IsValid = true;
  return map[SecondKey];
}

void UKrishnaMapMap::AddInt(FString Key, FString SecondKey, int32 Value)
{
  TMap <FString, int32> map;

  // if already exists, use that
  if (IntMap.Contains(Key))
  {
    map = IntMap[Key];
  }

  map.Add(SecondKey, Value);

  IntMap.Add(Key, map);
}

int32 UKrishnaMapMap::GetInt(FString Key, FString SecondKey, bool& IsValid)
{
  IsValid = false;
  if (!IntMap.Contains(Key))
  {
    return 0;
  }

  TMap <FString, int32> map = IntMap[Key];
  if (!map.Contains(SecondKey))
  {
    return 0;
  }

  IsValid = true;
  return map[SecondKey];
}

void UKrishnaMapMap::AddFloat(FString Key, FString SecondKey, float Value)
{
  TMap <FString, float> map;

  // if already exists, use that
  if (FloatMap.Contains(Key))
  {
    map = FloatMap[Key];
  }

  map.Add(SecondKey, Value);

  FloatMap.Add(Key, map);
}

float UKrishnaMapMap::GetFloat(FString Key, FString SecondKey, bool& IsValid)
{
  IsValid = false;
  if (!FloatMap.Contains(Key))
  {
    return 0;
  }

  TMap <FString, float> map = FloatMap[Key];
  if (!map.Contains(SecondKey))
  {
    return 0;
  }

  IsValid = true;
  return map[SecondKey];
}

void UKrishnaMapMap::Remove(FString Key)
{
  StringMap.Remove(Key);
  IntMap.Remove(Key);
}

void UKrishnaMapMap::Clear()
{
  StringMap.Empty();
  IntMap.Empty();
}

void UKrishnaMapMap::GetStringKeys(TArray<FString>& OutKeys) {
  OutKeys.Empty();
  StringMap.GetKeys(OutKeys);
}

void UKrishnaMapMap::GetStringKeysForKey(FString Key, TArray<FString>& OutKeys) {
  OutKeys.Empty();

  if (StringMap.Contains(Key))
  {
    StringMap[Key].GetKeys(OutKeys);
  }
}

void UKrishnaMapMap::GetIntKeys(TArray<FString>& OutKeys) {
  OutKeys.Empty();
  IntMap.GetKeys(OutKeys);
}

void UKrishnaMapMap::GetIntKeysForKey(FString Key, TArray<FString>& OutKeys) {
  OutKeys.Empty();

  if (IntMap.Contains(Key))
  {
    IntMap[Key].GetKeys(OutKeys);
  }
}

void UKrishnaMapMap::GetFloatKeys(TArray<FString>& OutKeys) {
  OutKeys.Empty();
  FloatMap.GetKeys(OutKeys);
}

void UKrishnaMapMap::GetFloatKeysForKey(FString Key, TArray<FString>& OutKeys) {
  OutKeys.Empty();

  if (IntMap.Contains(Key))
  {
    FloatMap[Key].GetKeys(OutKeys);
  }
}

