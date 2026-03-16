/**
 * @file led.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-10
 * 
 * @copyright Copyright (c) 2026
 * 
*/

#include "stm32f4xx_hal.h"
#include "led.h"


void gpio_pa5_led_init(void)
{
    GPIO_InitTypeDef gpio_port_init = {0};
    
    //CONFIGURE LED PIN PA5 AS OUTPUT
    __HAL_RCC_GPIOA_CLK_ENABLE();
    gpio_port_init.Pin = LED_PIN;
    gpio_port_init.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_port_init.Pull = GPIO_NOPULL;
    gpio_port_init.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED_PORT, &gpio_port_init);
}