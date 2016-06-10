#ifndef TRIP_H
#define TRIP_H

class Trip {
private:
  double tripDistance;



public:

  void adjustTrip(Direction dir, int step)
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

  void adjustTrip(Direction dir) {
    adjustTrip(dir, 0);
  }

  void increaseTrip() {

      adjustTrip(forward);  

  }

  void decreaseTrip() {

      adjustTrip(backward);  

  }

  ///////////


  void resetTrip(bool trip1, bool trip2) {
      tripDistance = 0.0; 

    //updateScreen(updatetrip);
  }

  void resetTrip() {
    resetTrip(true, false);
  }

  void changeTrips(Direction dir, double amount) {
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
};

#endif
