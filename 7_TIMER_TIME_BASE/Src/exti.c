/**
 * @file exti.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-10
 * 
 * @copyright Copyright (c) 2026
 * 
*/

#include "stm32f4xx_hal.h"
#include "exti.h"

/**********MACROS*********************/
#define BTN_PORT		GPIOC
#define BTN_PIN			GPIO_PIN_13
/************************************/


void gpio_pc13_interrupt_callback_init(void)
{
	GPIO_InitTypeDef gpio_port_init = {0};
	
	//CONFIGURE BUTTON PIN PC13 AS INPUT WITH EXTI INTERRUPT
	__HAL_RCC_GPIOC_CLK_ENABLE();
	gpio_port_init.Pin = BTN_PIN;
	gpio_port_init.Mode = GPIO_MODE_IT_RISING;
	gpio_port_init.Pull = GPIO_NOPULL;
	gpio_port_init.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(BTN_PORT, &gpio_port_init);


	//configure and enable EXTI line 15 to 10 interrupt in NVIC
	//since button is connected to PC13 use EXTI15_10_IRQn
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == BTN_PIN)
	{
		//
	}

}

//EXTI15_10_IRQHandler name is in the vector table in startup_stm32f4xx.s
void EXTI15_10_IRQHandler(void)
{

	HAL_GPIO_EXTI_IRQHandler(BTN_PIN);

}