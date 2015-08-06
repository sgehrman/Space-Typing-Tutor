// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceTypingTutor.h"
#include "SKeyHijackWidget.h"
#include "KeyInterceptorActor.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SKeyHijackWidget::Construct(const FArguments& InArgs)
{
  Owner = InArgs._ActorOwner;
  KeyActor = nullptr;  // c++ doesn't zero out vars?

  ChildSlot
    .VAlign(VAlign_Fill)
    .HAlign(HAlign_Fill);
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SKeyHijackWidget::OnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& InCharacterEvent)
{
  if (InCharacterEvent.GetCharacter() == 27) // ignore escape key
    return FReply::Unhandled();

  // print(FString::FromInt((int32)InCharacterEvent.GetCharacter()));

  AKeyInterceptorActor* theActor = FindKeyActor();
  if (theActor)
  {
    theActor->SendKeyEvent(InCharacterEvent.GetCharacter(), InCharacterEvent.IsLeftShiftDown(), InCharacterEvent.IsRightShiftDown());
  }

  return FReply::Handled();
}

FReply SKeyHijackWidget::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
  bool debug = false;

  if (debug) {
    print("OnKeyDown");
    print("key: " + InKeyEvent.GetKey().GetDisplayName().ToString());
    print("code: " + FString::FromInt(InKeyEvent.GetKeyCode()));
    print("char: " + FString::FromInt(InKeyEvent.GetCharacter()));
  }

  if (IgnoreKeyEvent(InKeyEvent))
    return FReply::Unhandled();

  AKeyInterceptorActor* theActor = FindKeyActor();
  if (theActor)
  {
    if (InKeyEvent.GetCharacter() == 0)
    {
      // left or right shift
      if (InKeyEvent.GetKeyCode() == 160 || InKeyEvent.GetKeyCode() == 161)
      {
        theActor->OnInterceptedShiftPress(InKeyEvent.GetKeyCode() == 160, InKeyEvent.GetKeyCode() == 161);

        // always return unhandled for just shift key.  shift-f1 needed this
        return FReply::Unhandled();
      }
    }
  }

  return FReply::Handled();
}

FReply SKeyHijackWidget::OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
  bool debug = false;

  if (debug) {
    print("OnKeyUp");
    print("key: " + InKeyEvent.GetKey().GetDisplayName().ToString());
    print("code: " + FString::FromInt(InKeyEvent.GetKeyCode()));
    print("char: " + FString::FromInt(InKeyEvent.GetCharacter()));
  }

  if (IgnoreKeyEvent(InKeyEvent))
    return FReply::Unhandled();

  AKeyInterceptorActor* theActor = FindKeyActor();
  if (theActor)
  {
    if (InKeyEvent.GetCharacter() == 0)
    {
      // left or right shift
      if (InKeyEvent.GetKeyCode() == 160 || InKeyEvent.GetKeyCode() == 161)
      {
        // passing false since this is keyup and shift should be up now
        theActor->OnInterceptedShiftPress(false, false);
      }
    }
  }

  return FReply::Handled();
}

AKeyInterceptorActor* SKeyHijackWidget::FindKeyActor()
{
  if (!KeyActor)
  {
    ULevel* CurLevel = Owner->GetWorld()->GetCurrentLevel();
    for (int32 ActorIndex = 0; ActorIndex < CurLevel->Actors.Num(); ++ActorIndex)
    {
      AKeyInterceptorActor* theActor = Cast<AKeyInterceptorActor>(CurLevel->Actors[ActorIndex]);
      if (theActor)
      {
        KeyActor = theActor;

        break;
      }
    }
  }

  return KeyActor;
}

FReply SKeyHijackWidget::OnFocusReceived(const FGeometry& MyGeometry, const FFocusEvent& InFocusEvent)
{
  return FReply::Unhandled();
}

void SKeyHijackWidget::OnFocusLost(const FFocusEvent& InFocusEvent)
{
  AKeyInterceptorActor* theActor = FindKeyActor();
  if (theActor)
  {
    theActor->OnLostWidgetFocus();
  }
}

bool SKeyHijackWidget::IgnoreKeyEvent(const FKeyEvent& InKeyEvent)
{
  if (InKeyEvent.GetCharacter() == 27) // ignore escape key
    return true;

  else if (InKeyEvent.GetKey().IsGamepadKey()) // ignore gamepad keys
    return true;

  else if (InKeyEvent.GetKeyCode() >= 112 && InKeyEvent.GetKeyCode() <= 123) // ignore Function keys
    return true;

  // debug only, enable the Tilde for console access
  //  else if (InKeyEvent.GetCharacter() == '`') // ignore Tilde
  //  return true;

  return false;
}