/**
 * @file tim.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-16
 * 
 * @copyright Copyright (c) 2026
 * 
 */


#include "stm32f4xx_hal.h"
#include "tim.h"
#include "uart.h"

static TIM_HandleTypeDef tim_handle = {0};

/**
 * @brief Timer to timeout every 1 sec meaning 1Hz
 * Default PCLK1, PLCK2 = 16MHz for TIM3, TIM2, TIM5
 */
void timx_base_init(void)
{
    //enable clock for TIM3
    TIMx_CLK_ENABLE();

    //configure TIMx base parameters
    tim_handle.Instance = TIMx;
    tim_handle.Init.Prescaler = 1600 - 1; //16Mhz/1600 = 10KHz timer clock
    tim_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
    tim_handle.Init.Period = 10000 - 1; //Timer Period = 10KHz/10K = 1Hz (1 sec)
    tim_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    tim_handle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    HAL_TIM_Base_Init(&tim_handle);

    //configure and enable TIM3 interrupt in NVIC
    HAL_NVIC_SetPriority(TIMx_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIMx_IRQn);

    // //start the timer in interrupt mode
    HAL_TIM_Base_Start_IT(&tim_handle);
}

void TIMx_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&tim_handle);
}

/**
 * @brief callback function called when TIM3 period elapsed interrupt occurs
 * 
 * @param htim 
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim->Instance == TIMx)
    {
        //toggle the LED pin
        //HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
        printf("Timer Interrupt Occurred 1 second elapsed! \n");
    }
}

