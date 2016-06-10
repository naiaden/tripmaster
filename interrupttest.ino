#include "whatever.h"
#include "compass.h"
#include "pinlayout.h"
#include "screen.h"
#include "trip.h"
#include "tripmaster.h"
#include "wheel.h"
#include "buttons.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "Adafruit_Sensor.h"
#include "Adafruit_HMC5883_U.h"

Wheel wheel;

Trip trip1;
Trip trip2;
Trip tank;

Buttons buttons;

PinLayout pinLayout;
Screen screen;
Compass compass;

void setup() {
  TripMaster::registerWheel(&wheel);
  TripMaster::registerTrip1(&trip1);
  TripMaster::registerTrip2(&trip2);
  TripMaster::registerTank(&tank);
  TripMaster::registerButtons(&buttons);
  TripMaster::registerPinLayout(&pinLayout);
  TripMaster::registerScreen(&screen);
  TripMaster::registerCompass(&compass);
}

void loop() {
  /*
  checkDirectionChange();
   checkMenuChange();
   checkCompass();
   */
}



