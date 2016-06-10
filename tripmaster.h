#ifndef TRIPMASTER_H
#define TRIPMASTER_H

#include "wheel.h"

class TripMaster {
private:
  Wheel* wheel;
  PinLayout* pinLayout;
  Screen* screen;
  Compass* compass;
  
  Direction currentDirection;

public:
  TripMaster(Wheel* _wheel, PinLayout* _pinLayout, Screen* _screen, Compass* _compass) : 
    wheel(_wheel), pinLayout(_pinLayout), screen(_screen), compass(_compass), currentDirection(forward) {

  }


  void setupPins() {
    pinMode(PinLayout::ledPin, OUTPUT);

    pinMode(PinLayout::hallPin, INPUT_PULLUP);
    attachInterrupt(PinLayout::hallInterruptPin, wheelRotation, RISING);

    pinMode(PinLayout::increasePin, INPUT_PULLUP);
    attachInterrupt(PinLayout::increaseInterruptPin, increaseTrip, CHANGE);

    pinMode(PinLayout::decreasePin, INPUT_PULLUP);
    attachInterrupt(PinLayout::decreaseInterruptPin, decreaseTrip, RISING);

    pinMode(PinLayout::resetPin, INPUT_PULLUP);
    attachInterrupt(PinLayout::resetInterruptPin, resetTrip, RISING);

    pinMode(PinLayout::directionPin, INPUT_PULLUP);
    pinMode(PinLayout::menuPin, INPUT_PULLUP);
  }

  static void wheelRotation() {
  }
  static void increaseTrip() {
  }
  static void decreaseTrip() {
  }
  static void resetTrip() {
  }


};

#endif
