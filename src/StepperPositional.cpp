#include "StepperPositional.h"

#include <Arduino.h>

StepperPositional::StepperPositional(Stepper* stepper)
:
stepper(stepper)
{}

void StepperPositional::handle()
{
  stepper->handle();
}

bool StepperPositional::done()
{
  return stepper->done();
}

void StepperPositional::setPosition(float pos)
{
  float degreesPerStep = 360. / stepper->stepsPerCircle();
  float delta = pos - position;
  int steps = (delta / degreesPerStep) + .5; //Rounded
  stepper->setSteps(steps);
  delta = steps * degreesPerStep; //The actual position to avoid accumulative rounding errors
  position += delta;
}
