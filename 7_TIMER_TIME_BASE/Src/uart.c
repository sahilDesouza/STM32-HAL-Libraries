/*
 * uart.c
 *
 *  Created on: Oct 7, 2025
 *      Author: sahil
 */

#include "uart.h"

#define MAIN_GPIOA						GPIOA
#define MAIN_UART2_TX_PIN				GPIO_PIN_2
#define MAIN_UART2_RX_PIN				GPIO_PIN_3
#define MAIN_UART2_BAUD_RATE 			115200
#define MAIN_UART2_STOP_BIT 			UART_STOPBITS_2
#define MAIN_UART2_START_BIT 			1
#define MAIN_USART2_INSTANCE 			USART2
#define MAIN_UART2_WORD_LENGTH 			UART_WORDLENGTH_8B
#define MAIN_UART2_PARITY 				UART_PARITY_NONE
#define MAIN_UART2_MODE					UART_MODE_TX_RX
#define MAIN_UART2_HARDWARE_CONTROL		UART_HWCONTROL_NONE
#define MAIN_UART2_OVER_SAMPLING		UART_OVERSAMPLING_16
#define MAIN_BUFFER_SIZE				20
#define MAIN_UART_TIMEOUT				20
#define MAIN_DELAY_TIME_MS				500	


int __io_putchar(int ch)
{
	HAL_UART_Transmit(&UART2_handle_init, (uint8_t *)&ch, 1, MAIN_UART_TIMEOUT);
	HAL_Delay(MAIN_DELAY_TIME_MS);
}


void usart_init(GPIO_InitTypeDef * GPIO_init, UART_HandleTypeDef * UART2_handle_init)
{
	__HAL_RCC_GPIOA_IS_CLK_ENABLED();
	__HAL_RCC_USART2_CLK_ENABLE();

	GPIO_init->Mode = GPIO_MODE_AF_PP;
	GPIO_init->Pin = GPIO_PIN_2 | GPIO_PIN_3;
	GPIO_init->Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_init->Pull = GPIO_NOPULL;
	GPIO_init->Alternate = GPIO_AF7_USART2;

	HAL_GPIO_Init(MAIN_GPIOA, GPIO_init);
	
	UART2_handle_init->Instance = MAIN_USART2_INSTANCE;
	UART2_handle_init->Init.BaudRate = MAIN_UART2_BAUD_RATE;
	UART2_handle_init->Init.StopBits = MAIN_UART2_STOP_BIT;
	UART2_handle_init->Init.WordLength = MAIN_UART2_WORD_LENGTH;
	UART2_handle_init->Init.Parity = MAIN_UART2_PARITY;
	UART2_handle_init->Init.Mode = MAIN_UART2_MODE;
	UART2_handle_init->Init.HwFlowCtl = MAIN_UART2_HARDWARE_CONTROL;
	UART2_handle_init->Init.OverSampling = MAIN_UART2_OVER_SAMPLING;

	HAL_UART_Init(UART2_handle_init);

}

