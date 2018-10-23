/*
 * lcd_conf.h
 *
 *  Created on: Jul 31, 2018
 *      Author: z1rex
 */

#ifndef LCD_CONF_H_
#define LCD_CONF_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "main.h"
#include "hd44780_stm32l4xx.h"

extern HD44780 lcd;
extern HD44780_STM32L4XX_GPIO_Driver lcd_pindriver;

void init_lcd(void);
void delay_microseconds(uint32_t us);
void hd44780_assert_failure_handler(const char *filename, unsigned long line);
uint32_t uint32_time_diff(uint32_t now, uint32_t before);



#ifdef __cplusplus
}
#endif

#endif /* LCD_CONF_H_ */
