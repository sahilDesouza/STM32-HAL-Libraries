
#ifndef I2C_H
#define I2C_H


#include "stm32f4xx_hal.h"
#include <stdint.h>

//address of adxl345 registers and other constants
#define DEVICE_R				0x00
#define POWER_CNTRL_REG  		0x2D
#define DATA_FORMAT_REG 		0x31
#define ADXL345_ADDR 			0x53<<1
#define FOUR_G					0x01
#define RESET					0x00
#define SET_MEASURE_BIT			0x08
#define DATA_START_ADDR			0x32
#define FOUR_G_SCALE_FACTOR 	0.0078125		//scale factor for converting raw data to g unit. For +/- 4g, the scale factor is 4/512 because the raw data is represented in 10 bits (2^10 = 1024) and the range is from -512 to +511.

//address for SSD1306 OLED display
#define SSD1306_OLED_ADDR				0x3C<<1


extern uint8_t datarec[6];

void i2c_init(void);
void adxl345_write(uint8_t reg_addr, uint8_t data);
void adxl345_read(uint8_t reg_addr, uint8_t *data);
void adxl345_init(void);
void adxl345_read_values(uint8_t reg_addr);
void adxl345_read_address(uint8_t reg_addr);


void ssd1306_init(void);
void ssd1306_write(uint8_t reg_addr, uint8_t data);
void ssd1306_data(uint8_t data);
void ssd1306_clear(void);

void ssd1306_char(int8_t character);
void ssd1306_setpos(uint8_t position, uint8_t page);
void ssd1306_set_string(int8_t *string);

#endif /* I2C_H */