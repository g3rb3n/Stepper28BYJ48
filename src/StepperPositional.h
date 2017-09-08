#ifndef StepperPotitional_h
#define StepperPotitional_h

#include "Stepper.h"

class StepperPositional
{
  public:
    StepperPositional(Stepper* stepper);
    void setPosition(float pos);
    
    void handle();
    bool done();
    
  private:
    Stepper* stepper;
    float position;
};

#endif
