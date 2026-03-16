/*
 * adc.h
 *
 *  Created on: Oct 7, 2025
 *      Author: sahil
 */

#ifndef ADC_H_
#define ADC_H_
#include <stdint.h>




void adc_init_start(void);
uint32_t pa0_ac_read(void);
void adc_pa0_single_conv_init(void);

#endif /* ADC_H_ */
