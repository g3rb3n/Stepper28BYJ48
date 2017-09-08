# Stepper
A non blocking stepper motor driver and lib for the 28BYJ-48 stepper motor.

# Features
- Does not use delays for driving the stepper so that multiple steppers can be controlled at the same time.

# Usage
- Initialize stepper
- Set required movement, setSteps(int)
- Call handle() continuously
- Check done() before setting new movement.

# Example
```
#include "Stepper28BYJ48.h"

Stepper28BYJ48 stepper(D1, D2, D3, D4, 1000);

uint8_t numSteps = 2;
int steps[] = {60,-30};
uint8_t idx = 0;

void setup() 
{
  Serial.begin(230400);
  Serial.println();
}

int nextSteps()
{
  idx++;
  idx %= numSteps;
  return positions[idx];  
}

void loop()
{
  stepper.handle();
  if(stepper.done())
    stepper.setSteps(nextSteps());
}
```
