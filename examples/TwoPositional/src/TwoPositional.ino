#include "Stepper28BYJ48.h"
#include "StepperPositional.h"

Stepper28BYJ48 stepper[] = {
  {D1, D2, D3, D4, 1500},
  {D5, D6, D7, D8, 1200}
};

StepperPositional positional[] = {
  &stepper[0],
  &stepper[1]
};

uint8_t numSteppers = 2;
uint8_t idx[] = {0, 0};
uint8_t numPositions[] = {9,9};
int positions[][9] = {
  { 60,30,90,60,120,90,150,120,0 },
  { 60,30,90,60,120,90,150,120,0 }
};

void setup() 
{
  Serial.begin(230400);
  Serial.println();
}

void handle(uint8_t s)
{
  stepper[s].handle();
  if(stepper[s].done())
  {
    idx[s]++;
    idx[s] %= numPositions[s];
    positional[s].setPosition(positions[s][idx[s]]);
  }
}

void loop()
{
  for (uint8_t s ; s < numSteppers ; ++s)
    handle(s);
}
