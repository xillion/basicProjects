#include <stdint.h>
#include <stdlib.h>
#include "stm32l4xx_hal.h"
#include "hd44780_stm32l4xx.h"


#ifndef NDEBUG
  #define HD44780_STM32l4XX_ASSERT(x) \
    { \
      if (!(x)) \
      { \
        HD44780_STM32L4XX_GPIO_Driver *driver = ((HD44780_STM32L4XX_GPIO_Driver*)interface); \
        if (driver->assert_failure_handler != NULL) \
          driver->assert_failure_handler(__FILE__, __LINE__); \
      } \
    }

  #define HD44780_STM32l4XX_RETURN_ASSERT(x,ret) \
    do { \
      int condition = (x); \
      HD44780_STM32l4XX_ASSERT(condition) \
      if (!condition) \
        return (ret); \
    } while (0)
#else
  #define HD44780_STM32L4XX_ASSERT(x)
  #define HD44780_STM32L4XX_RETURN_ASSERT(x,ret)
#endif


static HD44780_Result STM32L4XX_default_pin_configure(
  HD44780_GPIO_Interface *interface, HD44780_Pin pin, HD44780_PinMode mode)
{
  HD44780_STM32L4XX_RETURN_ASSERT(interface != NULL, HD44780_RESULT_ERROR);

  HD44780_STM32L4XX_GPIO_Driver *driver = (HD44780_STM32L4XX_GPIO_Driver*)interface;
  HD44780_STM32L4XX_Pin *hw_pin = &driver->pinout.pins[pin];

  HD44780_STM32L4XX_RETURN_ASSERT(hw_pin != NULL, HD44780_RESULT_ERROR);
  HD44780_STM32L4XX_RETURN_ASSERT(hw_pin->gpio != NULL, HD44780_RESULT_ERROR);

  GPIO_InitTypeDef gpio_config;
  //GPIO_StructInit(&gpio_config);
  //HAL_GPIO_DeInit(gpio_config, hw_pin->pinmask);

  switch (mode)
  {
    case HD44780_PINMODE_OUTPUT:
      gpio_config.Mode = GPIO_MODE_OUTPUT_PP;
      break;

    case HD44780_PINMODE_INPUT:
      gpio_config.Mode = GPIO_MODE_INPUT;
      break;

    default:
      HD44780_STM32L4XX_ASSERT(0);
      break;
  }

  gpio_config.Pin = hw_pin->pinmask;

  if (hw_pin->gpio != NULL)
    HAL_GPIO_Init(hw_pin->gpio, &gpio_config);

  return HD44780_RESULT_OK;
}

static HD44780_Result STM32L4XX_default_pin_write(
  HD44780_GPIO_Interface *interface, HD44780_Pin pin, HD44780_PinState value)
{
  HD44780_STM32L4XX_RETURN_ASSERT(interface != NULL, HD44780_RESULT_ERROR);

  HD44780_STM32L4XX_GPIO_Driver *driver = (HD44780_STM32L4XX_GPIO_Driver*)interface;
  HD44780_STM32L4XX_Pin *hw_pin = &driver->pinout.pins[pin];

  HD44780_STM32L4XX_RETURN_ASSERT(hw_pin != NULL, HD44780_RESULT_ERROR);
  HD44780_STM32L4XX_RETURN_ASSERT(hw_pin->gpio != NULL, HD44780_RESULT_ERROR);

  HAL_GPIO_WritePin(hw_pin->gpio, hw_pin->pinmask,
    (value == HD44780_PINSTATE_LOW ? GPIO_PIN_RESET : GPIO_PIN_SET));

  return HD44780_RESULT_OK;
}

static HD44780_Result STM32L4XX_default_pin_read(
  HD44780_GPIO_Interface *interface, HD44780_Pin pin, HD44780_PinState *value)
{
  HD44780_STM32L4XX_RETURN_ASSERT(interface != NULL, HD44780_RESULT_ERROR);
  HD44780_STM32L4XX_RETURN_ASSERT(value != NULL, HD44780_RESULT_ERROR);

  HD44780_STM32L4XX_GPIO_Driver *driver = (HD44780_STM32L4XX_GPIO_Driver*)interface;
  HD44780_STM32L4XX_Pin *hw_pin = &driver->pinout.pins[pin];

  HD44780_STM32L4XX_RETURN_ASSERT(hw_pin != NULL, HD44780_RESULT_ERROR);
  HD44780_STM32L4XX_RETURN_ASSERT(hw_pin->gpio != NULL, HD44780_RESULT_ERROR);

  uint8_t out_bit = HAL_GPIO_ReadPin(hw_pin->gpio, hw_pin->pinmask);
  *value = (out_bit == GPIO_PIN_RESET ? HD44780_PINSTATE_LOW : HD44780_PINSTATE_HIGH);

  return HD44780_RESULT_OK;
}

const HD44780_GPIO_Interface HD44780_STM32L4XX_PINDRIVER_INTERFACE =
{
  STM32L4XX_default_pin_configure,
  STM32L4XX_default_pin_write,
  STM32L4XX_default_pin_read
};
