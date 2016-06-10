#ifndef WHEEL_H
#define WHEEL_H

class Wheel {
private:
  double wheelCircumference;

  unsigned long hallDebounceTime;
  unsigned long hallDebounceDelay;

public:
  Wheel() : wheelCircumference(2.2), hallDebounceTime(0), hallDebounceDelay(500) {
  }
  
  void wheelRotation() {
    if((millis() - hallDebounceTime) > hallDebounceDelay)
    {  
      //tankDistance += wheelCircumference;
      //changeTrips();

//      Serial.print(trip1Distance);
  //    Serial.print("\n");

      hallDebounceTime = millis();
    }
  }
};

#endif
