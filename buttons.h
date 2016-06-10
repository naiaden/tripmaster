#ifndef BUTTONS_H
#define BUTTONS_H

#include "pinlayout.h"
#include "tripmaster.h"

class TripMaster;

class Buttons {

private:
  TripMaster* tripMaster;

  unsigned long increaseDebounceTime;
  unsigned long increaseDebounceDelay;
  unsigned int increaseStep;

  unsigned long decreaseDebounceTime;
  unsigned long decreaseDebounceDelay;
  unsigned int decreaseStep;

  unsigned long directionDebounceTime;
  unsigned long directionDebounceDelay;

  unsigned long resetDebounceTime;
  unsigned long resetDebounceDelay;

  unsigned long menuDebounceTime;
  unsigned long menuDebounceDelay;


public:
  Buttons();


  void resetTrip();
  void increaseTrip();
  void decreaseTrip();
  
  void checkMenuChange();
  void checkDirectionChange();
  
  void registerTripMaster(TripMaster* _tripMaster);

};

#endif



