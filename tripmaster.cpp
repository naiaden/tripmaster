#include "tripmaster.h"

TripMaster *TripMaster::instance = 0;
Direction TripMaster::currentDirection = forward;
Function TripMaster::currentFunction = boot;

Wheel* TripMaster::wheel = 0;
PinLayout* TripMaster::pinLayout = 0;
Screen* TripMaster::screen = 0;
Compass* TripMaster::compass = 0;
Buttons* TripMaster::buttons = 0;

Trip* TripMaster::trip1 = 0;
Trip* TripMaster::trip2 = 0;
Trip* TripMaster::tank = 0;

void TripMaster::registerWheel(Wheel* _wheel) { 
  wheel = _wheel;
  wheel->registerTripMaster(instance); 
}
void TripMaster::registerPinLayout(PinLayout* _pinLayout) { 
  pinLayout = _pinLayout; 
}
void TripMaster::registerScreen(Screen* _screen) { 
  screen = _screen; 
  screen->registerTripMaster(instance); 
}
void TripMaster::registerCompass(Compass* _compass) { 
  compass = _compass; 
  compass->registerTripMaster(instance); 
}
void TripMaster::registerButtons(Buttons* _buttons) { 
  buttons = _buttons;
  buttons->registerTripMaster(instance); 
}
void TripMaster::registerTrip1(Trip* _trip1) { 
  trip1 = _trip1; 
  trip1->registerTripMaster(instance); 
}
void TripMaster::registerTrip2(Trip* _trip2) { 
  trip2 = _trip2; 
  trip2->registerTripMaster(instance); 
}
void TripMaster::registerTank(Trip* _tank) { 
  tank = _tank; 
  tank->registerTripMaster(instance); 
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
  // screen update
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
  switch(currentFunction) {
  case riding:
    currentFunction = menu;
    break;
  case menu:
    currentFunction = riding;
    break;
  default: 
    ; 
  }
  
  // screen update
}

void TripMaster::toggleDirection() {
  switch(currentDirection) {
  case forward:
    currentDirection = neutral;
    break;
  case neutral:
    currentDirection = backward;
    break;
  case backward:
    currentDirection = forward;
    break;
  default: 
    ;
  }

  // screen update
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
  setupPins();
}



