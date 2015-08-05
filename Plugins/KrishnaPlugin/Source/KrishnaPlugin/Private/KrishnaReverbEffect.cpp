
//
// By Sid Krishna
//

#include "KrishnaPluginPrivatePCH.h"
#include "KrishnaReverbEffect.h"

UKrishnaReverbEffect* UKrishnaReverbEffect::Create(class UReverbEffect* reverb) {
  UKrishnaReverbEffect* result = NewObject<UKrishnaReverbEffect>();

  result->Density = reverb->Density;
  result->Diffusion = reverb->Diffusion;
  result->Gain = reverb->Gain;
  result->GainHF = reverb->GainHF;
  result->DecayTime = reverb->DecayTime;
  result->DecayHFRatio = reverb->DecayHFRatio;
  result->ReflectionsGain = reverb->ReflectionsGain;
  result->ReflectionsDelay = reverb->ReflectionsDelay;
  result->LateGain = reverb->LateGain;
  result->AirAbsorptionGainHF = reverb->AirAbsorptionGainHF;
  result->RoomRolloffFactor = reverb->RoomRolloffFactor;

  return result;
}

UReverbEffect* UKrishnaReverbEffect::GetReverbEffect() {
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