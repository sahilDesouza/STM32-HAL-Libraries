/*
 * uart.h
 *
 *  Created on: Oct 7, 2025
 *      Author: sahil
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx_hal.h"

//UART_HandleTypeDef UART2_handle_init = {0};
extern GPIO_InitTypeDef GPIO_init;
extern UART_HandleTypeDef UART2_handle_init;

void usart_init(GPIO_InitTypeDef * GPIO_init, UART_HandleTypeDef * UART2_handle_init);

#endif /* UART_H_ */
