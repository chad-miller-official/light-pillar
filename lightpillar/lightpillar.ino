#include "lightlib.h"
#include "SPI.h"

#define PIN_IN_ROTARY A0
#define PIN_IN_MIC A1

void setup()
{
  Lights_Init();
  Clear_LED_All();
}

void loop()
{
  demo1();
}

int demo1_delta = (int) ((20.0 / (analogRead(PIN_IN_ROTARY) + 2.0)) + 1.0);

void demo1()
{
  for (int j = 0; j < 384; j += demo1_delta)
    for (int q = 0; q < 1; q++)
    {
      for (int i = 0; i < LED_PARALLEL_LENGTH; i++)
      {
        demo1_delta = (int) ((32.0 / (analogRead(PIN_IN_ROTARY) + 2.0)) + 1.0);
        Set_LED_Parallel(i + q, wheel((i + j) % 384));    //turn every third pixel on
      }

      Refresh();
    }
}

void demo1b()
{
  for (int j = 0; j < 384; j += demo1_delta)
    for (int q = 0; q < 1; q++)
    {
      for (int i = 0; i < LED_PARALLEL_LENGTH; i++)
      {
        demo1_delta = (int) ((32.0 / (analogRead(PIN_IN_ROTARY) + 2.0)) + 1.0);
        Set_LED_Parallel(i + q, wheel((i * j) % 384));    //turn every third pixel on
      }

      Refresh();
    }
}

#define DEMO2_THRESHOLD 750

int demo2_ambient = analogRead(PIN_IN_MIC);
int demo2_baseline = LED_PARALLEL_LENGTH / 2;

void demo2()
{
  int amp = analogRead(PIN_IN_MIC);
  int top = demo2_baseline;
  
  if(amp > demo2_ambient + DEMO2_THRESHOLD || amp < demo2_ambient - DEMO2_THRESHOLD)
    top += (amp - demo2_ambient);
  
  Set_LED_Array_Parallel(0, top, GREEN);
  Refresh();
  Clear_LED_Array_Parallel(0, amp);
}

uint32_t wheel(uint16_t wheelPos)
{
  byte r, g, b;

  switch(wheelPos / 128)
  {
  case 0:
    r = 127 - wheelPos % 128;   //Red down
    g = wheelPos % 128;      // Green up
    b = 0;                  //blue off
    break; 
  case 1:
    g = 127 - wheelPos % 128;  //green down
    b = wheelPos % 128;      //blue up
    r = 0;                  //red off
    break; 
  case 2:
    b = 127 - wheelPos % 128;  //blue down 
    r = wheelPos % 128;      //red up
    g = 0;                  //green off
    break; 
  }

  return(RGB(r, g, b));
}

