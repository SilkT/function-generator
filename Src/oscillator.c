#include "stm32f0xx_hal.h"
#include "oscillator.h"
#include "wavetables.h"
uint16_t freq;
DAC_Waveform_t current_waveform;
void DAC_Osc_Init() {
	HAL_TIM_Base_Start(&HTIMx);
	HAL_DAC_Start_DMA(&hdac1, DAC_CH, (uint32_t*)sine_table_32, 32, DAC_ALIGN_12B_R);
	TIMx->ARR = TIM_F / (32*1000);
    current_waveform = DAC_SineWave;
    freq=1000;
}
void DAC_Set_Wave(DAC_Waveform_t waveform) {
	if (waveform != current_waveform){
	current_waveform = waveform;
	switch (current_waveform)
		{
		case DAC_SineWave:
			HAL_DAC_Stop_DMA(&hdac1, DAC_CH);
			HAL_DAC_Start_DMA(&hdac1, DAC_CH, (uint32_t*)sine_table_32, 32, DAC_ALIGN_12B_R);
			break;

		case DAC_TriWave:
			HAL_DAC_Stop_DMA(&hdac1, DAC_CH);
			HAL_DAC_Start_DMA(&hdac1, DAC_CH, (uint32_t*)triangle_table_32, 32, DAC_ALIGN_12B_R);
			break;

		case DAC_SawWave:
			HAL_DAC_Stop_DMA(&hdac1, DAC_CH);
			HAL_DAC_Start_DMA(&hdac1, DAC_CH, (uint32_t*)saw_table_32, 32, DAC_ALIGN_12B_R);
			break;

		default:
			HAL_DAC_Stop_DMA(&hdac1, DAC_CH);
			HAL_DAC_Start_DMA(&hdac1, DAC_CH, (uint32_t*)sine_table_32, 32, DAC_ALIGN_12B_R);
			break;
		}
	}
}

void DAC_Change_Frequency(uint16_t f){
	freq = f;
    if(current_waveform!=DAC_SqrWave){
        TIMx->ARR = TIM_F / (32*freq);
    }
}
