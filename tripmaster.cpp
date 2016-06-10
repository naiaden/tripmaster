#include "tripmaster.h"

TripMaster *TripMaster::instance = 0;
Direction TripMaster::currentDirection = forward;
Wheel* TripMaster::wheel = 0;
PinLayout* TripMaster::pinLayout = 0;
Screen* TripMaster::screen = 0;
Compass* TripMaster::compass = 0;
Buttons* TripMaster::buttons = 0;

Trip* TripMaster::trip1 = 0;
Trip* TripMaster::trip2 = 0;
Trip* TripMaster::tank = 0;


/*
TripMaster::TripMaster(Wheel* _wheel, PinLayout* _pinLayout, Screen* _screen, Compass* _compass, Buttons* _buttons, Trip* _trip1, Trip* _trip2, Trip* _tank) : 
 wheel(_wheel), pinLayout(_pinLayout), screen(_screen), compass(_compass), buttons(_buttons), trip1(_trip1), trip2(_trip2), tank(_tank) {
 
 wheel->registerTripMaster(this);
 
 setupPins();
 
 }
 */

void TripMaster::registerWheel(Wheel* _wheel) { 
  wheel = _wheel; 
}
void TripMaster::registerPinLayout(PinLayout* _pinLayout) { 
  pinLayout = _pinLayout; 
}
void TripMaster::registerScreen(Screen* _screen) { 
  screen = _screen; 
}
void TripMaster::registerCompass(Compass* _compass) { 
  compass = _compass; 
}
void TripMaster::registerButtons(Buttons* _buttons) { 
  buttons = _buttons; 
}
void TripMaster::registerTrip1(Trip* _trip1) { 
  trip1 = _trip1; 
}
void TripMaster::registerTrip2(Trip* _trip2) { 
  trip2 = _trip2; 
}
void TripMaster::registerTank(Trip* _tank) { 
  tank = _tank; 
}

void TripMaster::setupPins() {
  pinMode(PinLayout::ledPin, OUTPUT);

  pinMode(PinLayout::hallPin, INPUT_PULLUP);
  attachInterrupt(PinLayout::hallInterruptPin, wheelInterrupt, RISING);

  pinMode(PinLayout::increasePin, INPUT_PULLUP);
  attachInterrupt(PinLayout::increaseInterruptPin, increaseInterrupt, CHANGE);

  pinMode(PinLayout::decreasePin, INPUT_PULLUP);
  attachInterrupt(PinLayout::decreaseInterruptPin, decreaseInterrupt, RISING);

  pinMode(PinLayout::resetPin, INPUT_PULLUP);
  attachInterrupt(PinLayout::resetInterruptPin, resetInterrupt, RISING);

  pinMode(PinLayout::directionPin, INPUT_PULLUP);
  pinMode(PinLayout::menuPin, INPUT_PULLUP);
}



void TripMaster::wheelInterrupt() {
  TripMaster::getInstance()->wheel->wheelRotation();
}
void TripMaster::increaseInterrupt() {
  TripMaster::getInstance()->buttons->increaseTrip();
}
void TripMaster::decreaseInterrupt() {
  TripMaster::getInstance()->buttons->decreaseTrip();
}
void TripMaster::resetInterrupt() {
  TripMaster::getInstance()->buttons->resetTrip();
}

void TripMaster::wheelRotationDetected() {
  trip1->changeTrips(currentDirection, wheel->wheelCircumference);
  trip2->changeTrips(currentDirection, wheel->wheelCircumference);
  tank->changeTrips(currentDirection, wheel->wheelCircumference);
}

void TripMaster::increaseTrip() {
  trip1->adjustTrip(forward);
  // screen update
}

void TripMaster::decreaseTrip() {
  trip1->adjustTrip(backward);
  // screen update
}

void TripMaster::resetTrip() {
  trip1->resetTrip();
  // screen update
}

void TripMaster::toggleMenu() {

}

void TripMaster::toggleDirection() {

}

TripMaster* TripMaster::getInstance()
{
  if (!instance)
    instance = new TripMaster();
  return (instance);
}

TripMaster& TripMaster::operator=(TripMaster const &other)
{
  (void) other;
  return (*this);
}

TripMaster::TripMaster()
{

}



