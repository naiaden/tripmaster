#include "trip.h"
#include "whatever.h"

void Trip::adjustTrip(Direction dir, int step)
{
  double value = 0.1;

  switch(step) {
  case 0:
    value = 0.1;
    break;
  case 1:
    value = 0.2;
    break;
  case 2:
    value = 0.5;
    break;
  case 3:
    value = 1.0;
    break;
  default:
    value = 0.1;
  }

  changeTrips(dir, value); 
}

void Trip::adjustTrip(Direction dir) {
  adjustTrip(dir, 0);
}

void Trip::increaseTrip() {
  adjustTrip(forward);  
}

void Trip::decreaseTrip() {
  adjustTrip(backward);  
}

void Trip::resetTrip() {
  tripDistance = 0.0; 
}

void Trip::changeTrips(Direction dir, double amount) {
  if(dir == forward)
  {
    tripDistance += amount;
  } 
  else if(dir == backward)
  {
    tripDistance -= amount;
  }  

  //updateScreen(updatetrip);
}

void Trip::registerTripMaster(TripMaster* _tripMaster) {
   tripMaster = _tripMaster; 
}
