// Copyright 1998-2013 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "SystemUtils.generated.h"

UCLASS(BlueprintType, Blueprintable)
class USystemUtils : public UObject
{
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintCallable, Category = "SystemUtils", meta = (DefaultToSelf = "Actor"))
    static void ForceGarbageCollection(AActor* Actor);

  UFUNCTION(BlueprintCallable, Category = "SystemUtils")
    static UReverbEffect* CreateReverbEffect(
    float Density,
    float Diffusion,
    float Gain,
    float GainHF,
    float DecayTime,
    float DecayHFRatio,
    float ReflectionsGain,
    float ReflectionsDelay,
    float LateGain,
    float LateDelay,
    float AirAbsorptionGainHF,
    float RoomRolloffFactor);

  UFUNCTION(BlueprintCallable, Category = "SystemUtils")
    static void SplitReverbEffect(class UReverbEffect* reverb,
    float& Density,
    float& Diffusion,
    float& Gain,
    float& GainHF,
    float& DecayTime,
    float& DecayHFRatio,
    float& ReflectionsGain,
    float& ReflectionsDelay,
    float& LateGain,
    float& LateDelay,
    float& AirAbsorptionGainHF,
    float& RoomRolloffFactor);
};

