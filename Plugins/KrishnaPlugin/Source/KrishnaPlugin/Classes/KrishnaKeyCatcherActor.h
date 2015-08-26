// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "KrishnaKeyCatcherActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLostWidgetFocusDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInterceptedKeyPressDelegate, int32, CharacterCode, const FString&, Character);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInterceptedShiftPressDelegate, bool, LeftShiftDown, bool, RightShiftDown);

UCLASS()
class AKrishnaKeyCatcherActor : public AActor
{
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  AKrishnaKeyCatcherActor();

  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

  // called from widget
  void SendKeyEvent(TCHAR theChar);
  void InterceptedShiftPress(bool leftShiftDown, bool rightShiftDown);
  void LostWidgetFocus();

  UFUNCTION(BlueprintCallable, Category = "Key Interceptor Actor")
    void SetWidgetFocus(bool focus);

  UPROPERTY(BlueprintAssignable, Category = "Krishna Key Catcher")
    FOnLostWidgetFocusDelegate OnLostWidgetFocus;

  UPROPERTY(BlueprintAssignable, Category = "Krishna Key Catcher")
    FOnInterceptedKeyPressDelegate OnInterceptedKeyPress;

  UPROPERTY(BlueprintAssignable, Category = "Krishna Key Catcher")
    FOnInterceptedShiftPressDelegate OnInterceptedShiftPress;

private:
  void AddSlateWidget();
  TSharedPtr<class SKrishnaKeyCatcherWidget> w;

};
