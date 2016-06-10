#ifndef SCREEN_H
#define SCREEN_H

#include <LiquidCrystal_I2C.h>

#include "whatever.h"
#include "tripmaster.h"

class TripMaster;

class Screen {




private:
  LiquidCrystal_I2C lcd;

  double printedTrip1Distance;
  double printedTrip2Distance;
  double printedTankDistance;

  TripMaster* tripMaster;

public:
  Screen();

  void registerTripMaster(TripMaster* _tripMaster);

  void setupScreen();

  void updateScreenDirection();
  void updateScreenTrips();
  void updateTime();

  void updateScreenShowTrip();

  void updateScreenShowMenu();

  void updateScreen(Event e);

};

#endif


