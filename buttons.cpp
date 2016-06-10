#include "buttons.h"

Buttons::Buttons() : 
increaseDebounceTime(0), increaseDebounceDelay(500), increaseStep(0),
decreaseDebounceTime(0), decreaseDebounceDelay(500), decreaseStep(0),
directionDebounceTime(0), directionDebounceDelay(500),
resetDebounceTime(0), resetDebounceDelay(500),
menuDebounceTime(0), menuDebounceDelay(500) {

}

void Buttons::resetTrip() {
  if((millis() - resetDebounceTime) > resetDebounceDelay) {
    Serial.println("Reset trip");

    tripMaster->resetTrip();

    resetDebounceTime = millis();
   
  }
}

void Buttons::increaseTrip() {
  if((millis() - increaseDebounceTime) > increaseDebounceDelay) {
    Serial.print("Increase ");
    Serial.print(increaseStep);
    Serial.print("\n");

    tripMaster->increaseTrip();

    increaseDebounceTime = millis();

  }
}

void Buttons::decreaseTrip() {
  if((millis() - decreaseDebounceTime) > decreaseDebounceDelay) {
    Serial.print("Decrease ");
    Serial.print(decreaseStep);
    Serial.print("\n");

    tripMaster->decreaseTrip();

    decreaseDebounceTime = millis();
  }
}

void Buttons::checkMenuChange() {
  if((millis() - menuDebounceTime) > menuDebounceDelay) {
    if(digitalRead(PinLayout::menuPin) == LOW) 
    {
      Serial.println("Menu change");
    }

    tripMaster->toggleMenu();

    menuDebounceTime = millis();

  }
}

void Buttons::checkDirectionChange() {
  if((millis() - directionDebounceTime) > directionDebounceDelay) {
    if(digitalRead(PinLayout::directionPin) == LOW) {
      /*
        Serial.print("Direction change from ");
       Serial.print(currentDirection);
       Serial.print(" to ");
       
       // F B N
       switch(currentDirection) {
       case forward:
       currentDirection = backward;
       break;
       case backward:
       currentDirection = neutral;
       break;
       case neutral:
       currentDirection = forward;
       default:
       currentDirection = forward;
       }
       Serial.print(currentDirection);
       Serial.print("\n");
       */
      Serial.println("Direction change");
      tripMaster->toggleDirection();
    } 

    directionDebounceTime = millis();
  }
}

void Buttons::registerTripMaster(TripMaster* _tripMaster) {
  tripMaster = _tripMaster; 
}

