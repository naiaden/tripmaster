#ifndef TRIP_H
#define TRIP_H

#include "whatever.h"
#include "tripmaster.h"

class Trip {
private:
  double tripDistance;
  
  TripMaster* tripMaster;
public:

void registerTripMaster(TripMaster* _tripMaster);

  void adjustTrip(Direction dir, int step);

  void adjustTrip(Direction dir);

  void increaseTrip();

  void decreaseTrip();

  ///////////

  void resetTrip();

  void changeTrips(Direction dir, double amount);
};

#endif
