#include "stm32f0xx_hal.h"
/* Private variables ---------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

//defines:
#define TIMx TIM6 // Set enabled TIMer
#define HTIMx htim6 // Set enabled TIMer
#define TIM_F 50000000 //Set timer frequency
#define DAC_CH DAC_CHANNEL_1 //DAC_CHANNEL_2
//end defines
//variables start here
typedef enum{
    DAC_SineWave = 0x01,
    DAC_TriWave = 0x02,
    DAC_SawWave = 0x03,
    DAC_SqrWave = 0x04
}DAC_Waveform_t;

//variables end here
extern uint16_t freq;
extern TIM_HandleTypeDef HTIMx;
extern DAC_HandleTypeDef hdac1;
extern DAC_Waveform_t current_waveform;
//functions go here:
void DAC_Osc_Init(void);
void DAC_Set_Wave(DAC_Waveform_t waveform);
void DAC_Change_Frequency(uint16_t f);
