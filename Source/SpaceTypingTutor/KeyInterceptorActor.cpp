// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceTypingTutor.h"
#include "KeyInterceptorActor.h"
#include "SKeyHijackWidget.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)

// Sets default values
AKeyInterceptorActor::AKeyInterceptorActor()
{
  // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AKeyInterceptorActor::BeginPlay()
{
  Super::BeginPlay();

  AddSlateWidget();
}

void AKeyInterceptorActor::SendKeyEvent(TCHAR theChar, bool leftShiftDown, bool rightShiftDown)
{
  ESpecialKeyEnum keyEnum = ESpecialKeyEnum::Key_Other;
  FString character;

  switch (theChar) {
  case 8:  // backspace
    keyEnum = ESpecialKeyEnum::Key_Backspace;
    break;
  case 9:  // tab
    keyEnum = ESpecialKeyEnum::Key_Tab;
    break;
  case 13:  // enter
    keyEnum = ESpecialKeyEnum::Key_Enter;
    break;
  default:
    character = FString(1, &theChar);
    break;
  }

  this->OnInterceptedKeyPress(keyEnum, (int32)theChar, character);
}

void AKeyInterceptorActor::AddSlateWidget()
{
  SAssignNew(w, SKeyHijackWidget)
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

void AKeyInterceptorActor::SetWidgetFocus(bool focus)
{
  FSlateApplication::Get().SetKeyboardFocus(w);
}
