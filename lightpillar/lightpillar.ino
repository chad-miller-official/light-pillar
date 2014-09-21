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
{ 
  float sound = (float) analogRead(A0) / 1023;
  int level = (int) (LED_PARALLEL_LENGTH * sound);
  Set_LED_Array_Parallel(level, height, GREEN);
  Refresh();
  Clear_LED_Parallel(level);
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

