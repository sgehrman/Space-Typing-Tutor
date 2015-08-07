// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class AKrishnaKeyCatcherActor;

/**
 *
 */
class SKrishnaKeyCatcherWidget : public SCompoundWidget
{
public:
  SLATE_BEGIN_ARGS(SKrishnaKeyCatcherWidget){}
  SLATE_ARGUMENT(AActor*, ActorOwner)
    SLATE_END_ARGS()

    /** Constructs this widget with InArgs */
    void Construct(const FArguments& InArgs);

  virtual FReply OnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& InCharacterEvent) override;

  virtual FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent);
  virtual FReply OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent);

  virtual bool SupportsKeyboardFocus() const override { return true; }

  virtual FReply OnFocusReceived(const FGeometry& MyGeometry, const FFocusEvent& InFocusEvent);
  virtual void OnFocusLost(const FFocusEvent& InFocusEvent);

private:
  bool IgnoreKeyEvent(const FKeyEvent& InKeyEvent);

private:
  AActor* Owner;

  AKrishnaKeyCatcherActor* FindKeyActor();
  AKrishnaKeyCatcherActor* KeyActor;
};
