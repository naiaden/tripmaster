#ifndef WHATEVER_H
#define WHATEVER_H

enum Direction {
  forward,
  neutral,
  backward 
};

enum Event {
  updatedirection,
  updatetrip,
  togglemenu,
  initdone
};

enum Function {
  riding,
  menu,
  boot 
};

enum Menu {
 stats, // max speed, total km, running hours
 circumference,
 kmormiles
};


#endif
