// Copyright 1998-2013 Epic Games, Inc. All Rights Reserved.
#include "KrishnaPluginPrivatePCH.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)

void USystemUtils::ForceGarbageCollection(AActor* Actor)
{
  if (!Actor) {
    print("Actor is NULL - USystemUtils::ForceGarbageCollection");
  }
  else {
    print("GC - USystemUtils::ForceGarbageCollection");
    Actor->GetWorld()->ForceGarbageCollection(true);
  }
}

UReverbEffect* USystemUtils::CreateReverbEffect(
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
  float RoomRolloffFactor) {

  // UReverbEffect reverb = NewObject<UReverbEffect>(this);
  UReverbEffect* reverb = NewObject<UReverbEffect>();
  reverb->Density = Density;
  reverb->Diffusion = Diffusion;
  reverb->Gain = Gain;
  reverb->GainHF = GainHF;
  reverb->DecayTime = DecayTime;
  reverb->DecayHFRatio = DecayHFRatio;
  reverb->ReflectionsGain = ReflectionsGain;
  reverb->ReflectionsDelay = ReflectionsDelay;
  reverb->LateGain = LateGain;
  reverb->AirAbsorptionGainHF = AirAbsorptionGainHF;
  reverb->RoomRolloffFactor = RoomRolloffFactor;

  return reverb;
}

void USystemUtils::SplitReverbEffect(class UReverbEffect* reverb,
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
  float& RoomRolloffFactor) {
  Density = reverb->Density;
  Diffusion = reverb->Diffusion;
  Gain = reverb->Gain;
  GainHF = reverb->GainHF;
  DecayTime = reverb->DecayTime;
  DecayHFRatio = reverb->DecayHFRatio;
  ReflectionsGain = reverb->ReflectionsGain;
  ReflectionsDelay = reverb->ReflectionsDelay;
  LateGain = reverb->LateGain;
  LateDelay = reverb->LateDelay;
  AirAbsorptionGainHF = reverb->AirAbsorptionGainHF;
  RoomRolloffFactor = reverb->RoomRolloffFactor;
}

void USystemUtils::SetTextRendersVerticalAlign(UTextRenderComponent* TextRender) {
  TextRender->VerticalAlignment = EVRTA_TextCenter;
}