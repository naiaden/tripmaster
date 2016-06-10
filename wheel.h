#ifndef WHEEL_H
#define WHEEL_H

#include "Arduino.h"
#include "tripmaster.h"

class TripMaster;

class Wheel {
friend class TripMaster;
  
private:
  double wheelCircumference;

  unsigned long hallDebounceTime;
  unsigned long hallDebounceDelay;

  TripMaster* tripMaster;

public:
  Wheel();

  void wheelRotation();

  void registerTripMaster(TripMaster* _tripMaster);
};

#endif


