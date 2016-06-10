#include "screen.h"

Screen::Screen() : 
lcd(LiquidCrystal_I2C(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE)), printedTrip1Distance(0), printedTrip2Distance(0), printedTankDistance(0) {

}


void Screen::setupScreen() {

  lcd.begin(20, 4); 

  lcd.setCursor(0,0);
  lcd.print("Crappy Tripmaster");

}

void Screen::registerTripMaster(TripMaster* _tripMaster) {
  tripMaster = _tripMaster; 
}

void Screen::updateScreenDirection() {
  bool up = false;
  bool down = false;

  if(tripMaster->currentDirection == forward) { 
    up = true; 
  }   
  else if(tripMaster->currentDirection == backward) { 
    down  = true; 
  }

  lcd.setCursor(0,0); 
  up ? lcd.print("X") : lcd.print(".");
  lcd.setCursor(0,1); 
  down ? lcd.print("X") : lcd.print(".");
}

void Screen::updateScreenTrips() {
  if(tripMaster->trip1->tripDistance - printedTrip1Distance > 0.1 || printedTrip1Distance - tripMaster->trip1->tripDistance > 0.1)
  {
    int printableTrip1_pre = (int) tripMaster->trip1->tripDistance;
    int printableTrip1_after = (int) ((tripMaster->trip1->tripDistance - printableTrip1_pre)*10);

    lcd.setCursor(0,2);
    lcd.print(printableTrip1_pre);
    lcd.setCursor(0,5);
    lcd.print(".");
    lcd.setCursor(0,6);
    lcd.print(printableTrip1_after);
  }

  if(tripMaster->trip2->tripDistance - printedTrip2Distance > 0.1 || printedTrip2Distance - tripMaster->trip2->tripDistance > 0.1)
  {
    int printableTrip2_pre = (int) tripMaster->trip2->tripDistance;
    int printableTrip2_after = (int) ((tripMaster->trip2->tripDistance - printableTrip2_pre)*10);

    lcd.setCursor(0,14);
    lcd.print(printableTrip2_pre);
    lcd.setCursor(0,17);
    lcd.print(".");
    lcd.setCursor(0,18);
    lcd.print(printableTrip2_after);
  }

  if(tripMaster->tank->tripDistance - printedTankDistance > 0.1 || printedTankDistance - tripMaster->tank->tripDistance > 0.1)
  {
    int printableTank_pre = (int) tripMaster->tank->tripDistance;
    int printableTank_after = (int) ((tripMaster->tank->tripDistance - printableTank_pre)*10);

    lcd.setCursor(3,8);
    lcd.print(printableTank_pre);
    lcd.setCursor(3,11);
    lcd.print(".");
    lcd.setCursor(3,12);
    lcd.print(printableTank_after);
  }
}

void Screen::updateTime() {
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

void Screen::updateScreenShowTrip() {
  updateTime();
  updateScreenTrips();
  updateScreenDirection();
}

void Screen::updateScreenShowMenu() {
  lcd.setCursor(0,0);
  lcd.print("THIS IS THE MENU");
  lcd.setCursor(3,0);
  lcd.print("NOTHING MUCH BUT W/E") ;
}

void Screen::updateScreen(Event e) {
  switch(e) {
  case updatedirection:
    updateScreenDirection();
    break;
  case updatetrip:
    updateScreenTrips();
    break;
  case togglemenu:
    updateScreenShowMenu();
    break;
  case initdone:
    //clearScreen();
    updateScreenShowTrip();
    break;
  default: 
    ;
  }
}

