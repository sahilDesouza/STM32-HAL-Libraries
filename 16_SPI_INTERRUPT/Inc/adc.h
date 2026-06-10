/*
 * adc.h
 *
 *  Created on: Oct 7, 2025
 *      Author: sahil
 */

#ifndef ADC_H_
#define ADC_H_

#include "stm32f4xx_hal.h"
#include <stdint.h>

// extern ADC_HandleTypeDef hadc1;

void adc_init_start(void);
uint32_t pa0_adc_read(void);
void adc_pa0_single_conv_init(void);
void adc_pa0_interrupt_init(void);

#endif /* ADC_H_ */
