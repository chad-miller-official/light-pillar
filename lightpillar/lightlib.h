#ifndef LIGHTLIB_H_INCLUDED
#define LIGHTLIB_H_INCLUDED

#include "LPD8806.h"

/* DEFINES */

#define MAX_RGB 0xFFFFFF

#define IS_VALID_RGB(c) (((c) & (0x80 << 16)) || ((c) & (0x80 << 8)) || ((c) & 0x80))

#define LED_START 0
#define LED_END 169
#define LED_LENGTH (LED_END - LED_START)
#define LED_PARALLEL_LENGTH 58

#define OFF 0x0
#define WHITE RGB(127, 127, 127)
#define RED RGB(127, 0, 0)
#define GREEN RGB(0, 127, 0)
#define BLUE RGB(0, 0, 127)
#define YELLOW RGB(127, 127, 0)
#define MAGENTA RGB(127, 0, 127)
#define CYAN RGB(0, 127, 127)

#define DATA_PIN 2
#define CLOCK_PIN 3

#define STRIP2_HEAD_OFFSET(x) (113 - (x))
#define STRIP3_HEAD_OFFSET(x) (112 + (x))

/* TYPEDEF */
typedef void (*input_func)(int);

/* VARIABLES */

extern LPD8806 strip;

/* FUNCTIONS */

void Lights_Init(void);

inline uint32_t RGB(byte r, byte g, byte b) { return strip.Color(r, g, b); }
inline void Refresh() { strip.show(); }

uint32_t Random_RGB(void);

void Set_LED(uint16_t index, uint32_t rgb);
void Clear_LED(uint16_t index);
void Set_LED_Parallel(uint16_t index, uint32_t rgb);
void Clear_LED_Parallel(uint16_t index);

void Set_LED_All(uint32_t rgb);
void Clear_LED_All(void);

void Set_LED_Array(uint16_t start, uint16_t end, uint32_t rgb);
void Clear_LED_Array(uint16_t start, uint16_t end);
void Set_LED_Array_Parallel(uint16_t start, uint16_t end, uint32_t rgb);
void Clear_LED_Array_Parallel(uint16_t start, uint16_t end);

void On_Button_Input(input_func func, int signal);
void On_Light_Input(input_func func, int signal);
void On_Rotary_Input(input_func func, int signal);
void On_Sound_Input(input_func func, int signal);
void On_Temperature_Input(input_func func, int signal);
void On_Touch_Input(input_func func, int signal);

#endif //LIGHTLIB_H_INCLUDED
