/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f0xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f0xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ssd1306.h"
#include "oscillator.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */
uint16_t State, LastState=1;
int16_t counter, counterr, ccounter;
char cnt[12];
int8_t menu_state, last_menu_state=0;
uint8_t hold, hold1;

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
 
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_dac1_ch1;
extern DAC_HandleTypeDef hdac1;
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim14;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M0 Processor Interruption and Exception Handlers          */ 
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVC_IRQn 0 */

  /* USER CODE END SVC_IRQn 0 */
  /* USER CODE BEGIN SVC_IRQn 1 */

  /* USER CODE END SVC_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F0xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f0xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles DMA1 channel 2 and 3 interrupts.
  */
void DMA1_Channel2_3_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel2_3_IRQn 0 */

  /* USER CODE END DMA1_Channel2_3_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_dac1_ch1);
  /* USER CODE BEGIN DMA1_Channel2_3_IRQn 1 */

  /* USER CODE END DMA1_Channel2_3_IRQn 1 */
}

/**
  * @brief This function handles TIM6 global and DAC underrun error interrupts.
  */
void TIM6_DAC_IRQHandler(void)
{
  /* USER CODE BEGIN TIM6_DAC_IRQn 0 */

  /* USER CODE END TIM6_DAC_IRQn 0 */
  HAL_TIM_IRQHandler(&htim6);
  HAL_DAC_IRQHandler(&hdac1);
  /* USER CODE BEGIN TIM6_DAC_IRQn 1 */

  /* USER CODE END TIM6_DAC_IRQn 1 */
}

/**
  * @brief This function handles TIM14 global interrupt.
  */
void TIM14_IRQHandler(void)
{
  /* USER CODE BEGIN TIM14_IRQn 0 */
	if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_11)==GPIO_PIN_RESET&&hold!=1){menu_state++;
	hold=1;}else if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_11)==GPIO_PIN_SET)hold=0;
	if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_12)==GPIO_PIN_RESET&&hold1!=1){menu_state--;
	hold1=1;}else if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_12)==GPIO_PIN_SET) hold1 = 0;
	if(menu_state!=last_menu_state){
		if(menu_state>2)menu_state=0;
		if(menu_state<0)menu_state=2;
		last_menu_state=menu_state;
switch (menu_state)
		{
		case 0:
			DAC_Set_Wave(DAC_SineWave);
			ssd1306_Fill(0);
			ssd1306_SetCursor(5, 10);
		ssd1306_WriteString("Sinus:",Font_7x10, White);
				ssd1306_SetCursor(10, 30);
		sprintf(cnt, "%d", freq);
		ssd1306_WriteString(cnt, Font_16x26, White);
		ssd1306_SetCursor(110, 40);
		ssd1306_WriteString("Hz", Font_7x10, White);
					ssd1306_UpdateScreen();
			break;

		case 1:
			DAC_Set_Wave(DAC_TriWave);
			ssd1306_Fill(0);
			ssd1306_SetCursor(5, 10);
		ssd1306_WriteString("Triangle:",Font_7x10, White);
				ssd1306_SetCursor(10, 30);
		sprintf(cnt, "%d", freq);
		ssd1306_WriteString(cnt, Font_16x26, White);
		ssd1306_SetCursor(110, 40);
		ssd1306_WriteString("Hz", Font_7x10, White);
					ssd1306_UpdateScreen();
			break;
		case 2:
			DAC_Set_Wave(DAC_SawWave);
			ssd1306_Fill(0);
			ssd1306_SetCursor(5, 10);
		ssd1306_WriteString("Saw:",Font_7x10, White);
				ssd1306_SetCursor(10, 30);
		sprintf(cnt, "%d", freq);
		ssd1306_WriteString(cnt, Font_16x26, White);
		ssd1306_SetCursor(110, 40);
		ssd1306_WriteString("Hz", Font_7x10, White);
					ssd1306_UpdateScreen();
			break;
		
		default:
			
			break;
	}
}
	
State = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5);
	if (State!=LastState){
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4)!=State){
			counter++;
			if(counter==2){
				counterr++;
				counter=0;
			}
		}
		else {
			counter --;
			if (counter == -2) {
				counterr--;
				counter = 0;
			}
		}
		DAC_Change_Frequency(freq+10*(counterr-ccounter));
		
		switch (menu_state)
		{
		case 0:
			ssd1306_Fill(0);
			ssd1306_SetCursor(5, 10);
		ssd1306_WriteString("Sinus:",Font_7x10, White);
				ssd1306_SetCursor(10, 30);
		sprintf(cnt, "%d", freq);
		ssd1306_WriteString(cnt, Font_16x26, White);
		ssd1306_SetCursor(110, 40);
		ssd1306_WriteString("Hz", Font_7x10, White);
					ssd1306_UpdateScreen();
			break;

		case 1:
			ssd1306_Fill(0);
			ssd1306_SetCursor(5, 10);
		ssd1306_WriteString("Triangle:",Font_7x10, White);
				ssd1306_SetCursor(10, 30);
		sprintf(cnt, "%d", freq);
		ssd1306_WriteString(cnt, Font_16x26, White);
		ssd1306_SetCursor(110, 40);
		ssd1306_WriteString("Hz", Font_7x10, White);
					ssd1306_UpdateScreen();
			break;
		case 2:
			ssd1306_Fill(0);
			ssd1306_SetCursor(5, 10);
		ssd1306_WriteString("Saw:",Font_7x10, White);
				ssd1306_SetCursor(10, 30);
		sprintf(cnt, "%d", freq);
		ssd1306_WriteString(cnt, Font_16x26, White);
		ssd1306_SetCursor(110, 40);
		ssd1306_WriteString("Hz", Font_7x10, White);
					ssd1306_UpdateScreen();
			break;
		
		default:
			
			break;
	}
		ccounter=counterr;
	}
	LastState = State;
  /* USER CODE END TIM14_IRQn 0 */
  HAL_TIM_IRQHandler(&htim14);
  /* USER CODE BEGIN TIM14_IRQn 1 */

  /* USER CODE END TIM14_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
