#include "lightlib.h"

LPD8806 strip = LPD8806(LED_LENGTH);

extern void analog_to_digital();

void Lights_Init(void)
{		
	strip.begin();
}

uint32_t Random_RGB()
{
	srand(millis());
	return RGB(rand() % 127, rand() % 127, rand() % 127);
}

void Set_LED(uint16_t index, uint32_t rgb)
{
	if(index < 0)
		index = 0;
	else if(index > LED_END)
		index = LED_END;
		
	strip.setPixelColor(index, rgb);
}

void Clear_LED(uint16_t index)
{
	if(index < 0)
		index = 0;
	else if(index > LED_END)
		index = LED_END;
		
	strip.setPixelColor(index, OFF);
}

void Set_LED_Parallel(uint16_t index, uint32_t rgb)
{
	if(index < 0)
		index = 0;
	else if(index > LED_PARALLEL_LENGTH)
		index = LED_PARALLEL_LENGTH;
		
	strip.setPixelColor(index, rgb);
	strip.setPixelColor(STRIP2_HEAD_OFFSET(index), rgb);
	strip.setPixelColor(STRIP3_HEAD_OFFSET(index), rgb);
}

void Clear_LED_Parallel(uint16_t index)
{
	if(index < 0)
		index = 0;
	else if(index > LED_PARALLEL_LENGTH)
		index = LED_PARALLEL_LENGTH;
		
	strip.setPixelColor(index, OFF);
	strip.setPixelColor(STRIP2_HEAD_OFFSET(index), OFF);
	strip.setPixelColor(STRIP3_HEAD_OFFSET(index), OFF);
}

void Set_LED_All(uint32_t rgb)
{
	for(int i = LED_START; i < LED_END; i++)
		strip.setPixelColor(i, rgb);
	
}

void Clear_LED_All(void)
{
	for(int i = LED_START; i < LED_END; i++)
		strip.setPixelColor(i, OFF);

}

void Set_LED_Array(uint16_t start, uint16_t end, uint32_t rgb)
{
	if(start < 0)
		start = 0;
	
	if(end > LED_END)
		end = LED_END;
	
	for(int i = start; i < end; i++)
		strip.setPixelColor(i, rgb);

}

void Clear_LED_Array(uint16_t start, uint16_t end)
{
	if(start < 0)
		start = 0;
	
	if(end > LED_END)
		end = LED_END;
		
	for(int i = start; i < end; i++)
		strip.setPixelColor(i, OFF);

}

void Set_LED_Array_Parallel(uint16_t start, uint16_t end, uint32_t rgb)
{
	if(start < 0)
		start = 0;
		
	if(end > LED_PARALLEL_LENGTH)
		end = LED_PARALLEL_LENGTH;
		
	for(int i = start; i < end; i++)
	{
		strip.setPixelColor(i, rgb);		
		strip.setPixelColor(STRIP2_HEAD_OFFSET(i), rgb);
		strip.setPixelColor(STRIP3_HEAD_OFFSET(i), rgb);
	}
	
}

void Clear_LED_Array_Parallel(uint16_t start, uint16_t end)
{
	if(start < 0)
		start = 0;
	
	if(end > LED_PARALLEL_LENGTH)
		end = LED_PARALLEL_LENGTH;
		
	for(int i = start; i < end; i++)
	{
		strip.setPixelColor(i, OFF);
		strip.setPixelColor(STRIP2_HEAD_OFFSET(i), OFF);
		strip.setPixelColor(STRIP3_HEAD_OFFSET(i), OFF);
	}
	
}

void On_Button_Input(input_func func, int signal)
{
	func(signal);
}

void On_Light_Input(input_func func, int signal)
{
	func(signal);
}

void On_Rotary_Input(input_func func, int signal)
{
	func(signal);
}

void On_Sound_Input(input_func func, int signal)
{
	func(signal);
}

void On_Temperature_Input(input_func func, int signal)
{
	func(signal);
}

void On_Touch_Input(input_func func, int signal)
{
	func(signal);
}

short Get_Analog_Input()
{
	analog_to_digital();
	return (short) ((*(char*) (0x12)) | ((*(char*) (0x13)) << 0x8));
}
