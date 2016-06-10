#ifndef BUTTONS_H
#define BUTTONS_H

class Buttons {

private:
  unsigned long increaseDebounceTime;
  unsigned long increaseDebounceDelay;
  unsigned int increaseStep;

  unsigned long decreaseDebounceTime;
  unsigned long decreaseDebounceDelay;
  unsigned int decreaseStep;

  unsigned long directionDebounceTime;
  unsigned long directionDebounceDelay;

  unsigned long menuDebounceTime;
  unsigned long menuDebounceDelay;

public:
  Buttons() : 
    increaseDebounceTime(0), increaseDebounceDelay(500), increaseStep(0),
    decreaseDebounceTime(0), decreaseDebounceDelay(500), decreaseStep(0),
    directionDebounceTime(0), directionDebounceDelay(500),
    menuDebounceTime(0), menuDebounceDelay(500) {

  }

  void increaseTrip() {
    if((millis() - increaseDebounceTime) > increaseDebounceDelay) {
      Serial.print("Increase ");
      Serial.print(increaseStep);
      Serial.print("\n");

      increaseDebounceTime = millis();
      //adjustTrip(forward);  
    }
  }

  void decreaseTrip() {
    if((millis() - decreaseDebounceTime) > decreaseDebounceDelay) {
      Serial.print("Decrease ");
      Serial.print(decreaseStep);
      Serial.print("\n");

      decreaseDebounceTime = millis();
      //adjustTrip(backward);  
    }
  }

};

#endif
