#include "screen.h"

Screen::Screen() : 
lcd(LiquidCrystal_I2C(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE)), printedTrip1Distance(0), printedTrip2Distance(0), printedTankDistance(0), screenFunction(boot) {

}


void Screen::setupScreen() {

  lcd.begin(20, 4); 

  lcd.setCursor(0,0);
  lcd.print("Crappy Tripmaster");

}

void Screen::registerTripMaster(TripMaster* _tripMaster) {
   tripMaster = _tripMaster; 
}
