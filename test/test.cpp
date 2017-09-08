#include <Arduino.h>
#include <unity.h>
#include "Stepper28BYJ48.h"
#include "StepperPositional.h"

#ifdef UNIT_TEST

Stepper28BYJ48 stepper(D1, D2, D3, D4, 1000);
StepperPositional positional(&stepper);

int positions[] = {60,30,90,60,120,90,150,120,0};
uint8_t idx = 0;


void setPosition()
{
  positional.setPosition(positions[idx]);
  bool done = positional.done();
  TEST_ASSERT_FALSE(done);
}

void step1()
{
  bool done;

  stepper.setSteps(1);

  done = positional.done();
  TEST_ASSERT_FALSE(done);

  long end = micros() + 1000;
  while(micros() > end);
  done = positional.done();
  TEST_ASSERT_TRUE(done);
}

void setup() 
{
  // NOTE!!! Wait for >2 secs
  // if board doesn't support software reset via Serial.DTR/RTS
  delay(2000);
  UNITY_BEGIN();
}

void loop()
{
  RUN_TEST(setPosition);

  uint32_t count = 100000;
  while(--count)
  {
    stepper.handle();
    if(stepper.done())
    {
      idx++;
      idx %= 9;
      RUN_TEST(setPosition);
    }
    delayMicroseconds(1);
  }
  UNITY_END();
}

#endif
