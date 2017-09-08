#include <Arduino.h>
#include <Stepper28BYJ48.h>

Stepper28BYJ48::Stepper28BYJ48(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4)
:
stepDuration(1000)
{
  pins[0] = pin1;
  pins[1] = pin2;
  pins[2] = pin3;
  pins[3] = pin4;

  for(int i = 0; i < 4; i++)
    pinMode(pins[i], OUTPUT);
}

Stepper28BYJ48::Stepper28BYJ48(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4, uint16_t stepDurationMicros)
:
stepDuration(stepDurationMicros)
{
  pins[0] = pin1;
  pins[1] = pin2;
  pins[2] = pin3;
  pins[3] = pin4;

  for(int i = 0; i < 4; i++)
    pinMode(pins[i], OUTPUT);
}

void Stepper28BYJ48::setStepDuration(uint16_t _duration)
{
  stepDuration = _duration;
}

void Stepper28BYJ48::setSteps(int _steps)
{
  reverse = _steps < 0;
  steps = abs(_steps);
  nextStep = micros();
}

bool Stepper28BYJ48::done()
{
  return steps == 0;
}

void Stepper28BYJ48::handle()
{
  if(steps == 0 || micros() < nextStep)
    return;
  
  pos += 8; //Avoid underflow
  pos += reverse ? -1 : 1;
  pos %= 8;

  for(int i = 0; i < 4; i++)
    digitalWrite(pins[i], sequence[pos] >> i & 0b1);

  --steps;
  nextStep += stepDuration;
}
