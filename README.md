# tripmaster

This repository hosts the code for an arduino alternative to ICO/RNS tripmasters. It's a work in progress, and currently only implemented on a breadboard. 

## Functions

The current implementation contains 3 trip meters, a compass, an lcd screen, 5 buttons and a hall sensor.

### Trip meters
- Direction: This trip meter is used to keep track of the distance you've ridden since the last new clue from the roadbook;
- Total: This trip meter keeps track of the total distance;
- Tank: Since I've got a small tank, I also like to keep track of the mileage since refilling gas

The trip meters (direction and total) are affected by a driving direction mode, which can be forward, neutral, or backward. The direction trip meter is can also be resetted, increased or decreased with the buttons.

### Compass
- The plan is to have some sort of CAP implementation. I will have to look into that.

### LCD screen
```
D tttt.t ... TTTT.T 
D...................
....................
 sss.s GGG.G  HH:MM 
```

- D = direction indication ( a rotated representation for forward, neutral, backward: `<---`, `-><-`, `--->`)
- t = trip 1: direction trip meter
- T = trip 2: total trip meter
- s = speed
- G = mileage since gas refill
- HM = time

### Buttons
On handlebars:
- Increase direction trip meter
- Decrease direction trip meter
- Reset direction trip meter
Next to screen:
- Menu button
- Direction button

### Hall sensors
This sensor keeps track of the rotations of the front wheel. This is used to measure the distance and the speed.
