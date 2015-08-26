// Fill out your copyright notice in the Description page of Project Settings.

#include "KrishnaPluginPrivatePCH.h"

#include "KrishnaKeyCatcherWidget.h"
#include "KrishnaKeyCatcherActor.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SKrishnaKeyCatcherWidget::Construct(const FArguments& InArgs)
{
  Owner = InArgs._ActorOwner;
  KeyActor = nullptr;  // c++ doesn't zero out vars?

  ChildSlot
    .VAlign(VAlign_Fill)
    .HAlign(HAlign_Fill);
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SKrishnaKeyCatcherWidget::OnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& InCharacterEvent)
{
  if (InCharacterEvent.GetCharacter() == 27) // ignore escape key
    return FReply::Unhandled();

  // print(FString::FromInt((int32)InCharacterEvent.GetCharacter()));

  AKrishnaKeyCatcherActor* theActor = FindKeyActor();
  if (theActor)
  {
    theActor->SendKeyEvent(InCharacterEvent.GetCharacter());
  }

  return FReply::Handled();
}

FReply SKrishnaKeyCatcherWidget::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
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

  AKrishnaKeyCatcherActor* theActor = FindKeyActor();
  if (theActor)
  {
    if (InKeyEvent.GetCharacter() == 0)
    {
      // left or right shift
      switch (InKeyEvent.GetKeyCode())
      {
      case 160:
      case 161:
        theActor->InterceptedShiftPress(InKeyEvent.GetKeyCode() == 160, InKeyEvent.GetKeyCode() == 161);

        // always return unhandled for just shift key.  shift-f1 needed this
        return FReply::Unhandled();
        break;
      case 38: // UP
      case 39: // Right
      case 37: // Left
      case 40: // Down
        theActor->SendKeyEvent(InKeyEvent.GetKeyCode());
        break;
      case 46: // Delete
        theActor->SendKeyEvent(InKeyEvent.GetKeyCode());
        break;
      default:
        break;
      }
    }
  }

  return FReply::Handled();
}

FReply SKrishnaKeyCatcherWidget::OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
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

  AKrishnaKeyCatcherActor* theActor = FindKeyActor();
  if (theActor)
  {
    if (InKeyEvent.GetCharacter() == 0)
    {
      // left or right shift
      if (InKeyEvent.GetKeyCode() == 160 || InKeyEvent.GetKeyCode() == 161)
      {
        // passing false since this is keyup and shift should be up now
        theActor->InterceptedShiftPress(false, false);
      }
    }
  }

  return FReply::Handled();
}

AKrishnaKeyCatcherActor* SKrishnaKeyCatcherWidget::FindKeyActor()
{
  if (!KeyActor)
  {
    ULevel* CurLevel = Owner->GetWorld()->GetCurrentLevel();
    for (int32 ActorIndex = 0; ActorIndex < CurLevel->Actors.Num(); ++ActorIndex)
    {
      AKrishnaKeyCatcherActor* theActor = Cast<AKrishnaKeyCatcherActor>(CurLevel->Actors[ActorIndex]);
      if (theActor)
      {
        KeyActor = theActor;

        break;
      }
    }
  }

  return KeyActor;
}

FReply SKrishnaKeyCatcherWidget::OnFocusReceived(const FGeometry& MyGeometry, const FFocusEvent& InFocusEvent)
{
  return FReply::Unhandled();
}

void SKrishnaKeyCatcherWidget::OnFocusLost(const FFocusEvent& InFocusEvent)
{
  AKrishnaKeyCatcherActor* theActor = FindKeyActor();
  if (theActor)
  {
    theActor->LostWidgetFocus();
  }
}

bool SKrishnaKeyCatcherWidget::IgnoreKeyEvent(const FKeyEvent& InKeyEvent)
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