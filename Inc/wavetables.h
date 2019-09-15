#include "stm32f0xx_hal.h"
#ifndef __WAVETABLES_H__
#define __WAVETABLES_H__

/*
Use prettier.io for array formatting, it's awesome! but it's for web, so you gotta format your code yourself
Check matlab.txt for different matlab functions for wavetable generating
Check wavetables.xlsx for converting matlab wavetables to appropriate values for stm32's integrated DAC
*/





uint16_t sine_table_32[32] = {
2048, 2448, 2832, 3186, 3496, 3751, 3940, 4057, 4095, 4057, 3940, 3751, 3496,
3186, 2832, 2448, 2048, 1648, 1264, 910, 600, 345, 156, 39, 0, 39, 156, 345,
600, 910, 1264, 1648 };
//uint16_t sine_table_32[32] = {
//4095, 4095, 4095, 4095, 4095, 4095, 4095, 4057, 4095, 4057, 4095, 4095, 4095,
//4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095,
//4095, 4095, 4095, 4095};

/*
Saw wavetables go next
*/


uint16_t saw_table_32[32] = { 0, 128, 256, 384, 512, 640, 768, 896, 1024, 1152,
1280, 1408, 1536, 1664, 1792, 1920, 2048, 2176, 2304, 2432, 2560, 2688, 2816,
2944, 3072, 3200, 3328, 3456, 3584, 3712, 3840, 3968 };

/*
Triangle wavetable goes next
*/

uint16_t triangle_table_32[32] = {
0, 256, 512, 768, 1024, 1280, 1536, 1792, 2048, 2304, 2560, 2816, 3072, 3328,
3584, 3840, 4095, 3840, 3584, 3328, 3072, 2816, 2560, 2304, 2048, 1792, 1536,
1280, 1024, 768, 512, 256
};

#endif
