#include "lightlib.h"
#include "SPI.h"

int height = 1;

void setup()
{
  Lights_Init();
  Clear_LED_All();
  Serial.begin(9600);
}

void loop()
<<<<<<< HEAD
{
  demo1b();
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
=======
{ 
  float sound = (float) analogRead(A0) / 1023;
  int level = (int) (LED_PARALLEL_LENGTH * sound);
  Set_LED_Array_Parallel(level, height, GREEN);
  Refresh();
  Clear_LED_Parallel(level);
>>>>>>> parent of 1815138... Attempting a dank hax
}

/*
void loop()
{
  Set_LED_Parallel(loc, Wheel(color));
  loc += delta;
  
  if(loc > LED_PARALLEL_LENGTH)
    delta = -delta;
  
  color++;
  
  if(color > 384)
    color = 0;
}
*/

uint32_t Wheel(uint16_t WheelPos)
{
  byte r, g, b;
  switch(WheelPos / 128)
  {
    case 0:
      r = 127 - WheelPos % 128;   //Red down
      g = WheelPos % 128;      // Green up
      b = 0;                  //blue off
      break; 
    case 1:
      g = 127 - WheelPos % 128;  //green down
      b = WheelPos % 128;      //blue up
      r = 0;                  //red off
      break; 
    case 2:
      b = 127 - WheelPos % 128;  //blue down 
      r = WheelPos % 128;      //red up
      g = 0;                  //green off
      break; 
  }
  return(RGB(r, g, b));
}

