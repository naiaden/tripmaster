#ifndef SCREEN_H
#define SCREEN_H

#include <LiquidCrystal_I2C.h>

class Screen {




private:
  LiquidCrystal_I2C lcd;

  double printedTrip1Distance;
  double printedTrip2Distance;
  double printedTankDistance;
  
  Function screenFunction;

public:
  Screen() : lcd(LiquidCrystal_I2C(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE)), printedTrip1Distance(0), printedTrip2Distance(0), printedTankDistance(0), screenFunction(boot) {
    
  }

  void setupScreen() {

    lcd.begin(20, 4); 

    lcd.setCursor(0,0);
    lcd.print("Crappy Tripmaster");

  }



/*



  void formatScreen() {

  }



  void updateScreenDirection() {
    bool up = false;
    bool down = false;

    if(currentDirection == forward) { 
      up = true; 
    }
    else if(currentDirection == backward) { 
      down  = true; 
    }

    lcd.setCursor(0,0); 
    up ? lcd.print("X") : lcd.print(".");
    lcd.setCursor(0,1); 
    down ? lcd.print("X") : lcd.print(".");
  }

  void updateScreenTrips() {
    if(trip1Distance - printedTrip1Distance > 0.1 || printedTrip1Distance - trip1Distance > 0.1)
    {
      int printableTrip1_pre = (int) trip1Distance;
      int printableTrip1_after = (int) ((trip1Distance - printableTrip1_pre)*10);


      lcd.setCursor(0,2);
      lcd.print(printableTrip1_pre);
      lcd.setCursor(0,5);
      lcd.print(".");
      lcd.setCursor(0,6);
      lcd.print(printableTrip1_after);
    }

    if(trip2Distance - printedTrip2Distance > 0.1 || printedTrip2Distance - trip2Distance > 0.1)
    {
      int printableTrip2_pre = (int) trip2Distance;
      int printableTrip2_after = (int) ((trip2Distance - printableTrip2_pre)*10);

      lcd.setCursor(0,14);
      lcd.print(printableTrip2_pre);
      lcd.setCursor(0,17);
      lcd.print(".");
      lcd.setCursor(0,18);
      lcd.print(printableTrip2_after);
    }

    if(tankDistance - printedTankDistance > 0.1 || printedTankDistance - tankDistance > 0.1)
    {
      int printableTank_pre = (int) tankDistance;
      int printableTank_after = (int) ((tankDistance - printableTank_pre)*10);

      lcd.setCursor(3,8);
      lcd.print(printableTank_pre);
      lcd.setCursor(3,11);
      lcd.print(".");
      lcd.setCursor(3,12);
      lcd.print(printableTank_after);
    }
  }

  void updateTime() {
    //time_t t = now()

    //if(minute(t) == printedTime)
    //{
    //}

    lcd.setCursor(3,14);
    lcd.print("HH");
    lcd.setCursor(3,16);
    lcd.print(":");
    lcd.setCursor(3,17);
    lcd.print("MM"); 
  }

  void clearScreen() {

  }

  void updateScreenShowTrip() {
    updateTime();
    updateScreenTrips();
    updateScreenDirection();
  }

  void updateScreenShowMenu() {
    lcd.setCursor(0,0);
    lcd.print("THIS IS THE MENU");
    lcd.setCursor(3,0);
    lcd.print("NOTHING MUCH BUT W/E") ;
  }

  void updateScreenMenu() {
    switch(screenFunction) {
    case boot:

      break;
    case riding:
      screenFunction = menu;
      updateScreenShowMenu();
      break;
    case menu:
      screenFunction = riding;
      updateScreenShowTrip();
      break;
    default:
      updateScreenShowTrip(); 
    }
  }

  void updateScreen(Event e) {
    switch(e) {
    case updatedirection:
      updateScreenDirection();
      break;
    case updatetrip:
      updateScreenTrips();
      break;
    case togglemenu:
      updateScreenMenu();
      break;
    case initdone:
      clearScreen();
      updateScreenShowTrip();
      break;
    default: 
      ;
    }
  }
  */
};

#endif
