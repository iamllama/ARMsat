/**
  ******************************************************************************
  * File Name          : ADC.c
  * Description        : This file provides code for the configuration
  *                      of the ADC instances.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "adc.h"

#include "gpio.h"

/* USER CODE BEGIN 0 */
adc_ring_buffer_t adcx = {{0}, 0, 0};
volatile uint16_t adc_val = 0;
volatile uint32_t adc_chan = ADC_CHANNEL_VREFINT;
/* USER CODE END 0 */

ADC_HandleTypeDef hadc1;

/* ADC1 init function */
void MX_ADC1_Init(void)
{
  ADC_ChannelConfTypeDef sConfig;

    /**Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion) 
    */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

    /**Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time. 
    */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_ADC_MspInit(ADC_HandleTypeDef* adcHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct;
  if(adcHandle->Instance==ADC1)
  {
  /* USER CODE BEGIN ADC1_MspInit 0 */

  /* USER CODE END ADC1_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_ADC1_CLK_ENABLE();
  
    /**ADC1 GPIO Configuration    
    PC0     ------> ADC1_IN10
    PC1     ------> ADC1_IN11
    PA0-WKUP     ------> ADC1_IN0
    PA1     ------> ADC1_IN1
    PA4     ------> ADC1_IN4
    PA6     ------> ADC1_IN6
    PA7     ------> ADC1_IN7
    PC4     ------> ADC1_IN14
    PC5     ------> ADC1_IN15
    PB0     ------> ADC1_IN8
    PB1     ------> ADC1_IN9 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_6 
                          |GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* Peripheral interrupt init */
    HAL_NVIC_SetPriority(ADC_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(ADC_IRQn);
  /* USER CODE BEGIN ADC1_MspInit 1 */

  /* USER CODE END ADC1_MspInit 1 */
  }
}

void HAL_ADC_MspDeInit(ADC_HandleTypeDef* adcHandle)
{

  if(adcHandle->Instance==ADC1)
  {
  /* USER CODE BEGIN ADC1_MspDeInit 0 */

  /* USER CODE END ADC1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_ADC1_CLK_DISABLE();
  
    /**ADC1 GPIO Configuration    
    PC0     ------> ADC1_IN10
    PC1     ------> ADC1_IN11
    PA0-WKUP     ------> ADC1_IN0
    PA1     ------> ADC1_IN1
    PA4     ------> ADC1_IN4
    PA6     ------> ADC1_IN6
    PA7     ------> ADC1_IN7
    PC4     ------> ADC1_IN14
    PC5     ------> ADC1_IN15
    PB0     ------> ADC1_IN8
    PB1     ------> ADC1_IN9 
    */
    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5);

    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_6 
                          |GPIO_PIN_7);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_0|GPIO_PIN_1);

    /* Peripheral interrupt Deinit*/
    HAL_NVIC_DisableIRQ(ADC_IRQn);

  }
  /* USER CODE BEGIN ADC1_MspDeInit 1 */

  /* USER CODE END ADC1_MspDeInit 1 */
} 

/* USER CODE BEGIN 1 */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	adc_val = HAL_ADC_GetValue(hadc);
	int i = (unsigned int) (adcx.head + 1) & ADC_BUF_SIZEOP;
	if (i != adcx.tail) {
		adcx.buffer[adcx.head] = adc_chan;
		adcx.buffer[adcx.head] <<= 32;
		adcx.buffer[adcx.head] |= adc_val&0xfff;
		adcx.head = i;
	}
	switch(adc_chan) {
		case ADC_CHANNEL_VREFINT:
			adc_chan = ADC_CHANNEL_0;
			break;
		case ADC_CHANNEL_0:
			adc_chan = ADC_CHANNEL_1;
			break;
		case ADC_CHANNEL_1:
			adc_chan = ADC_CHANNEL_4;
			break;
		case ADC_CHANNEL_4:
			adc_chan = ADC_CHANNEL_6;
			break;
		case ADC_CHANNEL_6:
			adc_chan = ADC_CHANNEL_7;
			break;
		case ADC_CHANNEL_7:
			adc_chan = ADC_CHANNEL_8;
			break;
		case ADC_CHANNEL_8:
			adc_chan = ADC_CHANNEL_9;
			break;
		case ADC_CHANNEL_9:
			adc_chan = ADC_CHANNEL_10;
			break;
		case ADC_CHANNEL_10:
			adc_chan = ADC_CHANNEL_11;
			break;
		case ADC_CHANNEL_11:
			adc_chan = ADC_CHANNEL_14;
			break;
		case ADC_CHANNEL_14:
			adc_chan = ADC_CHANNEL_15;
			break;
		default:
		case ADC_CHANNEL_15:
			adc_chan = ADC_CHANNEL_VREFINT;
			break;
	}
	ADC_ChannelConfTypeDef c = {adc_chan,1,ADC_SAMPLETIME_3CYCLES,0};
	HAL_ADC_ConfigChannel(hadc, &c);
	HAL_ADC_Start_IT(hadc);
}

uint16_t adc_read(uint64_t *buf) {
	// if the head isn't ahead of the tail, we don't have any characters
	if (adcx.head == adcx.tail) return ADC_BUF_EMPTY;
	*buf = adcx.buffer[adcx.tail];
	adcx.tail = (unsigned int) (adcx.tail + 1) & ADC_BUF_SIZEOP; //fixed bug where & was somehow turned to %... thats why 1023 became 0... @11.21pm 24/5/2013
	return 0;
}
/* USER CODE END 1 */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
