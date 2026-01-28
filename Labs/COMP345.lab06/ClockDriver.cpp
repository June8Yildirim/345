#include "ClockTimer.h"
#include "DigitalClock.h"
#include"ClockController.h"

int main(void) {
  //Create a ClockTimer to be observed
  ClockTimer *model = new ClockTimer;

  //Create a DigitalClock that is connected to the ClockTimer  
  DigitalClock *view = new DigitalClock(model); 

  // Create a clock controller and connect everyting together
  ClockController* controller = new ClockController(view, model);

  controller->controlClock();

  delete view;
  delete model;
  delete controller;

  return 0;
}
