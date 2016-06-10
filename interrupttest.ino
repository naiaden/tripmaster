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

////////////////////////////















/*
//////////////////

void checkDirectionChange() {
  if((millis() - directionDebounceTime) > directionDebounceDelay) {
    if(digitalRead(directionPin) == LOW) {
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
      
      updateScreen(updatedirection);
    } 
    
    directionDebounceTime = millis();
  }
}

void checkMenuChange() {
  if((millis() - menuDebounceTime) > menuDebounceDelay) {
    if(digitalRead(menuPin) == LOW) 
    {
      Serial.println("Menu change");
    }
  
    updateScreen(togglemenu);
  
    menuDebounceTime = millis();
  
  }
}
*/


///////////////////





void setup() {
  Wheel wheel;
  
  Trip trip1;
  Trip trip2;
  Trip tank;
  
  Buttons buttons;
  
  
  PinLayout pinLayout;
  Screen screen;
  Compass compass(&screen);
  TripMaster tripMaster(&wheel, &pinLayout, &screen, &compass);
  
  /*
  
  screen.setupScreen();
  
  updateScreen(togglemenu);
  */
}

void loop() {
  /*
  checkDirectionChange();
  checkMenuChange();
  checkCompass();
  */
}


