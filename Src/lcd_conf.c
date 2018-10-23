/*
 * lcd_conf.c
 *
 *  Created on: Jul 31, 2018
 *      Author: z1rex
 */
#include "lcd_conf.h"
/* Includes ------------------------------------------------------------------*/
#include "rtc.h"

HD44780 lcd;
HD44780_STM32L4XX_GPIO_Driver lcd_pindriver;


extern volatile uint32_t systick_ms;
extern RTC_TimeTypeDef _TIME_;
extern RTC_DateTypeDef _DATE_;

void init_lcd(void)
{
  const HD44780_STM32L4XX_Pinout lcd_pinout =
  {
    {
#ifdef BOARD_REV_1
      /* RS        */  { GPIOB, LCD_RS_Pin },
      /* ENABLE    */  { GPIOB, LCD_E_Pin },
      /* RW        */  { GPIOB, LCD_RW_Pin },
      /* Backlight */  { NULL, 0 },
      /* DP0       */  { NULL, 0 },
      /* DP1       */  { NULL, 0 },
      /* DP2       */  { NULL, 0 },
      /* DP3       */  { NULL, 0 },
      /* DP4       */  { GPIOD, LCD_DB4_Pin },
      /* DP5       */  { GPIOD, LCD_DB5_Pin },
      /* DP6       */  { GPIOD, LCD_DB6_Pin },
      /* DP7       */  { GPIOD, LCD_DB7_Pin }
#endif

#ifdef BOARD_REV_2
      /* RS        */  { GPIOB, LCD_RS_Pin },
      /* ENABLE    */  { GPIOB, LCD_E_Pin },
      /* RW        */  { GPIOB, LCD_RW_Pin },
      /* Backlight */  { NULL, 0 },
      /* DP0       */  { NULL, 0 },
      /* DP1       */  { NULL, 0 },
      /* DP2       */  { NULL, 0 },
      /* DP3       */  { NULL, 0 },
      /* DP4       */  { GPIOD, LCD_DB4_Pin },
      /* DP5       */  { GPIOD, LCD_DB5_Pin },
      /* DP6       */  { GPIOD, LCD_DB6_Pin },
      /* DP7       */  { GPIOD, LCD_DB7_Pin }
#endif
    }
  };
  lcd_pindriver.interface = HD44780_STM32L4XX_PINDRIVER_INTERFACE;
  //lcd_pindriver.interface.configure = NULL;
  lcd_pindriver.pinout = lcd_pinout;
  //lcd_pindriver.assert_failure_handler = hd44780_assert_failure_handler;
  lcd_pindriver.assert_failure_handler = _Error_Handler;
  const HD44780_Config lcd_config =
  {
    (HD44780_GPIO_Interface*)&lcd_pindriver,
	//Metro_HAL_WaitMicroSecond,
	delay_microseconds,
    hd44780_assert_failure_handler,
    HD44780_OPT_USE_RW
  };
  hd44780_init(&lcd, HD44780_MODE_4BIT, &lcd_config, 8, 2, HD44780_CHARSIZE_5x8);
}

uint32_t uint32_time_diff(uint32_t now, uint32_t before)
{
  return (now >= before) ? (now - before) : (UINT32_MAX - before + now);
}


void delay_microseconds(uint32_t us)
{
  SysTick->VAL = SysTick->LOAD;
  const uint32_t systick_ms_start = systick_ms;
  while (1)
  {
    uint32_t diff = uint32_time_diff(systick_ms, systick_ms_start);
    if (diff >= ((uint32_t)us / 1000) + (us % 1000 ? 1 : 0))
    {
      break;
    }
  }
}



void hd44780_assert_failure_handler(const char *filename, unsigned long line)
{
   while (1)
   {
   }
}

void displayTime(void)
{
  HAL_RTC_GetTime(&hrtc, &_TIME_, RTC_FORMAT_BIN);
  HAL_RTC_GetDate(&hrtc, &_DATE_, RTC_FORMAT_BIN);

  const size_t buf_size = lcd.columns_amount + 1;
  char buf[buf_size];
  hd44780_clear(&lcd);
  snprintf(buf, buf_size, "%02d:%02d:%02d", _TIME_.Hours, _TIME_.Minutes, _TIME_.Seconds);
  hd44780_write_string(&lcd, buf);
  snprintf(buf, buf_size, "%02d:%02d:%02d", _DATE_.Date, _DATE_.Month, _DATE_.Year);
  hd44780_move_cursor(&lcd, 0, 1);
  hd44780_write_string(&lcd, buf);
  HAL_Delay(100);
}
