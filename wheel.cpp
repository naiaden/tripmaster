#include "wheel.h"

Wheel::Wheel() : 
wheelCircumference(2.2), hallDebounceTime(0), hallDebounceDelay(500) {
}

void Wheel::wheelRotation() {
  if((millis() - hallDebounceTime) > hallDebounceDelay)
  {  
    tripMaster->wheelRotationDetected();

    hallDebounceTime = millis();
  }
}

void Wheel::registerTripMaster(TripMaster* _tripMaster) {
  tripMaster = _tripMaster; 
}

