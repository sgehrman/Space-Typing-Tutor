// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "KeyInterceptorActor.generated.h"


UENUM(BlueprintType)
enum class ESpecialKeyEnum : uint8
{
  Key_Other 	    UMETA(DisplayName = "Other"),
  Key_Backspace 	UMETA(DisplayName = "Backspace"),
  Key_Enter 	    UMETA(DisplayName = "Enter"),
  Key_Tab 	      UMETA(DisplayName = "Tab"),
  Key_LeftShift   UMETA(DisplayName = "Left Shift"),
  Key_RightShift  UMETA(DisplayName = "Right Shift"),
};


UCLASS()
class SPACETYPINGTUTOR_API AKeyInterceptorActor : public AActor
{
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  AKeyInterceptorActor();

  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

  void SendKeyEvent(TCHAR theChar, bool leftShiftDown, bool rightShiftDown);

  UFUNCTION(BlueprintImplementableEvent)
    void OnInterceptedKeyPress(ESpecialKeyEnum keyEnum, int32 CharacterCode, const FString& Character);

  UFUNCTION(BlueprintImplementableEvent)
    void OnInterceptedShiftPress(bool leftShiftDown, bool rightShiftDown);

  UFUNCTION(BlueprintImplementableEvent)
    void OnLostWidgetFocus();

  UFUNCTION(BlueprintCallable, Category = "Key Interceptor Actor")
    void SetWidgetFocus(bool focus);

private:
  void AddSlateWidget();
  TSharedPtr<class SKeyHijackWidget> w;

};
