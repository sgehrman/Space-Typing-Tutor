// Fill out your copyright notice in the Description page of Project Settings.

#include "KrishnaPluginPrivatePCH.h"
#include "KrishnaKeyCatcherActor.h"
#include "KrishnaKeyCatcherWidget.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)

// Sets default values
AKrishnaKeyCatcherActor::AKrishnaKeyCatcherActor()
{
  // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AKrishnaKeyCatcherActor::BeginPlay()
{
  Super::BeginPlay();

  AddSlateWidget();
}

void AKrishnaKeyCatcherActor::SendKeyEvent(TCHAR theChar)
{
  OnInterceptedKeyPress.Broadcast((int32)theChar, FString(1, &theChar));
}

void AKrishnaKeyCatcherActor::InterceptedShiftPress(bool leftShiftDown, bool rightShiftDown)
{
  OnInterceptedShiftPress.Broadcast(leftShiftDown, rightShiftDown);
}

void AKrishnaKeyCatcherActor::LostWidgetFocus()
{
  OnLostWidgetFocus.Broadcast();
}

void AKrishnaKeyCatcherActor::AddSlateWidget()
{
  SAssignNew(w, SKrishnaKeyCatcherWidget)
    .ActorOwner(this);

  if (GEngine->IsValidLowLevel())
  {
    if (w.IsValid())
    {
      if (GEngine->GameViewport != nullptr) {
        GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(w.ToSharedRef()));
      }
    }
  }

  if (w.IsValid())
  {
    w->SetVisibility(EVisibility::Visible);

    FSlateApplication::Get().SetKeyboardFocus(w);
  }
}

void AKrishnaKeyCatcherActor::SetWidgetFocus(bool focus)
{
  FSlateApplication::Get().SetKeyboardFocus(w);
}
