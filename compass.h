#ifndef COMPASS_H
#define COMPASS_H

#include <Wire.h>

#include "Adafruit_Sensor.h"
#include "Adafruit_HMC5883_U.h"
#include "tripmaster.h"


class Compass {
private:
  Adafruit_HMC5883_Unified compass;
  
  TripMaster* tripMaster;

public:
  Compass();

void registerTripMaster(TripMaster* _tripMaster);

  void checkCompass();
};

#endif

