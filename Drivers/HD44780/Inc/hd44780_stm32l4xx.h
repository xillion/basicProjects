#ifndef HD44780_STM32L4XX_H_
#define HD44780_STM32L4XX_H_

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "stm32l4xx_hal.h"
#include "hd44780.h"

typedef struct
{
  GPIO_TypeDef *gpio;
  uint16_t pinmask;
} HD44780_STM32L4XX_Pin;

typedef struct
{
  HD44780_STM32L4XX_Pin pins[HD44780_PINS_AMOUNT];
} HD44780_STM32L4XX_Pinout;

typedef struct
{
  HD44780_GPIO_Interface interface;
  HD44780_STM32L4XX_Pinout pinout;
  HD44780_AssertFn assert_failure_handler;
} HD44780_STM32L4XX_GPIO_Driver;

extern const HD44780_GPIO_Interface HD44780_STM32L4XX_PINDRIVER_INTERFACE;

#ifdef __cplusplus
}
#endif

#endif /* HD44780_STM32L4XX_H_ */
