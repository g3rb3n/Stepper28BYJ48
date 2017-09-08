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

void loop()
{
  stepper.handle();
  if(stepper.done())
  {
    idx++;
    idx %= numSteps;
    positional.setPosition(positions[idx]);
  }
}
