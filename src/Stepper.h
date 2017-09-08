#ifndef Stepper_h
#define Stepper_h

#include <inttypes.h>

class Stepper
{
  public:
    virtual void setStepDuration(uint16_t duration) = 0;
    virtual void setSteps(int steps) = 0;
    virtual void handle() = 0;
    virtual bool done() = 0;
    
    virtual uint16_t stepsPerCircle() const = 0;
    virtual uint16_t minimalStepMicros() const = 0;
};

#endif

