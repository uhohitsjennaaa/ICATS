#ifndef BALL_H
#define BALL_H

#include "phys_obj.h"

class Ball : public PhysicalObject {
 public:
  Ball();
  //void handle_input();
  //void show();
  virtual void move(void);
 private:
  int radius;
  int xVel, yVel;
};

#endif
