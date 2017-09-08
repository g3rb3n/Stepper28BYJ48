#ifndef Stepper28BYJ48_h
#define Stepper28BYJ48_h

#include "Stepper.h"

class Stepper28BYJ48 : public Stepper
{
  public:
    Stepper28BYJ48(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4);
    Stepper28BYJ48(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4, uint16_t stepDurationMicros);

    void setStepDuration(uint16_t duration);
    void setSteps(int steps);
    void handle();
    bool done();

    uint16_t stepsPerCircle() const
    {
      return 4096;
    }

    uint16_t minimalStepMicros() const
    {
      return 900;
    }
    
  private:
    uint8_t pins[4];

    //The documentation specifies the following sequence for driving the stepper
    int sequenceLength = 8;
    char sequence[8] = 
    {
      0b0001,
      0b0011,
      0b0010,
      0b0110,
      0b0100,
      0b1100,
      0b1000,
      0b1001
    };
    uint8_t pos = 0;

    //state variables used in handle()
    uint16_t stepDuration;
    bool reverse;
    uint16_t steps;
    uint32_t nextStep;
};

#endif
