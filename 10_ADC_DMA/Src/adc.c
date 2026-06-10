/*
 * adc.c
 *
 *  Created on: Oct 7, 2025
 *      Author: sahil
 */


#include "stm32f4xx_hal.h"
#include "adc.h"

//prototype
static void adc_pa0_continuose_conv_init(void);


//global
extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;

uint32_t pa0_adc_read(void)
{
	return HAL_ADC_GetValue(&hadc1);
}

void adc_init_start(void)
{
	adc_pa0_continuose_conv_init();
	HAL_ADC_Start(&hadc1);
}

void adc_pa0_continuose_conv_init(void)
{
	//config pa0 as analog pin
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	ADC_ChannelConfTypeDef sConfig = {0};
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	//init pin 0of port a to analog
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	//config adc module for cont conversion
	__HAL_RCC_ADC1_CLK_ENABLE();

	hadc1.Instance = ADC1;
	hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
	hadc1.Init.Resolution = ADC_RESOLUTION_12B;
	hadc1.Init.ContinuousConvMode = ENABLE;
	hadc1.Init.DiscontinuousConvMode = DISABLE;
	hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	hadc1.Init.NbrOfConversion = 1;
	hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	hadc1.Init.DMAContinuousRequests = DISABLE;
	hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;

	HAL_ADC_Init(&hadc1);
	sConfig.Channel = ADC_CHANNEL_0;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;
	HAL_ADC_ConfigChannel(&hadc1, &sConfig);

}

void adc_pa0_single_conv_init(void)
{
	//config pa0 as analog pin
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	ADC_ChannelConfTypeDef sConfig = {0};
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	//init pin 0of port a to analog
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	//config adc module for cont conversion
	__HAL_RCC_ADC1_CLK_ENABLE();

	hadc1.Instance = ADC1;
	hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
	hadc1.Init.Resolution = ADC_RESOLUTION_12B;
	hadc1.Init.ContinuousConvMode = DISABLE;
	hadc1.Init.DiscontinuousConvMode = DISABLE;
	hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	hadc1.Init.NbrOfConversion = 1;
	hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	hadc1.Init.DMAContinuousRequests = DISABLE;
	hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;

	HAL_ADC_Init(&hadc1);
	sConfig.Channel = ADC_CHANNEL_0;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;
	HAL_ADC_ConfigChannel(&hadc1, &sConfig);

}

void adc_pa0_interrupt_init(void)
{
	//config pa0 as analog pin
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	ADC_ChannelConfTypeDef sConfig = {0};
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	//init pin0 of port a to analog
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	//config adc module for cont conversion
	__HAL_RCC_ADC1_CLK_ENABLE();

	hadc1.Instance = ADC1;
	hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
	hadc1.Init.Resolution = ADC_RESOLUTION_12B;
	hadc1.Init.ContinuousConvMode = ENABLE;
	hadc1.Init.DiscontinuousConvMode = DISABLE;
	hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	hadc1.Init.NbrOfConversion = 1;
	hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	hadc1.Init.DMAContinuousRequests = DISABLE;
	hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;

	HAL_ADC_Init(&hadc1);
	sConfig.Channel = ADC_CHANNEL_0;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;
	HAL_ADC_ConfigChannel(&hadc1, &sConfig);
	HAL_NVIC_SetPriority(ADC_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(ADC_IRQn);

}

void adc_pa0_dma_init(void)
{
	//config pa0 as analog pin
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	ADC_ChannelConfTypeDef sConfig = {0};
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	//init pin 0of port a to analog
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	//config adc module for cont conversion
	__HAL_RCC_ADC1_CLK_ENABLE();

	hadc1.Instance = ADC1;
	hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
	hadc1.Init.Resolution = ADC_RESOLUTION_12B;
	hadc1.Init.ContinuousConvMode = ENABLE;
	hadc1.Init.DiscontinuousConvMode = DISABLE;
	hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	hadc1.Init.NbrOfConversion = 1;
	hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	hadc1.Init.DMAContinuousRequests = ENABLE;
	hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;

	HAL_ADC_Init(&hadc1);
	sConfig.Channel = ADC_CHANNEL_0;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;
	HAL_ADC_ConfigChannel(&hadc1, &sConfig);
	// HAL_NVIC_SetPriority(ADC_IRQn, 0, 0);
	// HAL_NVIC_EnableIRQ(ADC_IRQn);

	__HAL_RCC_DMA2_CLK_ENABLE();
	HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);


	hdma_adc1.Instance = DMA2_Stream0;
	hdma_adc1.Init.Channel = DMA_CHANNEL_0;
	hdma_adc1.Init.Direction = DMA_PERIPH_TO_MEMORY;
	hdma_adc1.Init.PeriphInc = DMA_PINC_DISABLE; //not increment peripheral address since no peripheral to increment
	hdma_adc1.Init.MemInc = DMA_MINC_ENABLE; //increment memory address because once we have an array we want it to be incremented automatically	
	hdma_adc1.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD; //(16 bits)
	hdma_adc1.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD; //(16 bits)
	hdma_adc1.Init.Mode = DMA_CIRCULAR; //circular mode since we want to continuously read adc values and store in array
	hdma_adc1.Init.Priority = DMA_PRIORITY_LOW;
	hdma_adc1.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
	hdma_adc1.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_FULL;
	hdma_adc1.Init.MemBurst = DMA_MBURST_SINGLE;
	hdma_adc1.Init.PeriphBurst = DMA_PBURST_SINGLE;
	HAL_DMA_Init(&hdma_adc1);

	//link dma handle to adc handle
	//__HAL_LINKDMA(&hadc1, DMA_Handle, hdma_adc1);
	hadc1.DMA_Handle = &hdma_adc1;



}

void DMA2_Stream0_IRQHandler(void)
{
	HAL_DMA_IRQHandler(&hdma_adc1);
}



void ADC_IRQHandler(void)
{
	HAL_ADC_IRQHandler(&hadc1);
}
