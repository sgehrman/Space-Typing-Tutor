//
// By Sid Krishna
//

#pragma once

#include "KrishnaReverbEffect.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UKrishnaReverbEffect : public UObject
{
  GENERATED_BODY()

public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KrishnaReverbEffect")
    float Density;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KrishnaReverbEffect")
    float Diffusion;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KrishnaReverbEffect")
    float Gain;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KrishnaReverbEffect")
    float GainHF;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KrishnaReverbEffect")
    float DecayTime;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KrishnaReverbEffect")
    float DecayHFRatio;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KrishnaReverbEffect")
    float ReflectionsGain;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KrishnaReverbEffect")
    float ReflectionsDelay;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KrishnaReverbEffect")
    float LateGain;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KrishnaReverbEffect")
    float LateDelay;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KrishnaReverbEffect")
    float AirAbsorptionGainHF;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KrishnaReverbEffect")
    float RoomRolloffFactor;

  UFUNCTION(BlueprintPure, Category = "KrishnaReverbEffect")
    static UKrishnaReverbEffect* Create(class UReverbEffect* reverb);

  UFUNCTION(BlueprintPure, Category = "KrishnaReverbEffect")
    UReverbEffect* GetReverbEffect();

};