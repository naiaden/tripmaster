#ifndef TRIPMASTER_H
#define TRIPMASTER_H

#include "screen.h"
#include "wheel.h"
#include "buttons.h"
#include "whatever.h"
#include "compass.h"
#include "trip.h"

class Wheel;
class Screen;
class Compass;
class Buttons;
class Trip;

class TripMaster {
  friend class Screen;
  
private:
  static TripMaster *instance;

  TripMaster();
  TripMaster(TripMaster const &other);
  TripMaster& operator=(TripMaster const &other);



  static Wheel* wheel;
  static PinLayout* pinLayout;
  static Screen* screen;
  static Compass* compass;
  static Buttons* buttons;
  
  static Trip* trip1;
  static Trip* trip2;
  static Trip* tank;

  static Direction currentDirection;
  static Function currentFunction;

public:
  static TripMaster* getInstance();
  
  static void registerWheel(Wheel* _wheel);
  static void registerPinLayout(PinLayout* _pinLayout);
  static void registerScreen(Screen* _screen);
  static void registerCompass(Compass* _compass);
  static void registerButtons(Buttons* _buttons);
  static void registerTrip1(Trip* _trip1);
  static void registerTrip2(Trip* _trip2);
  static void registerTank(Trip* _tank);

  void setupPins();


  static void wheelInterrupt();
  static void increaseInterrupt();
  static void decreaseInterrupt();
  static void resetInterrupt();

  static void wheelRotationDetected();
  static void increaseTrip();
  static void decreaseTrip();
  static void resetTrip();
  
  static void toggleMenu();
  static void toggleDirection();

};



#endif



