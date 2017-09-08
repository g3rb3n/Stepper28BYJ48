#include "Stepper28BYJ48.h"
#include "StepperPositional.h"

Stepper28BYJ48 stepper(D1, D2, D3, D4, 1000);
StepperPositional positional(&stepper);

int positions[] = {60,30,90,60,120,90,150,120,0};
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
    idx %= 9;
    positional.setPosition(positions[idx]);
  }
}
