/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define RELEY2_EN_Pin GPIO_PIN_2
#define RELEY2_EN_GPIO_Port GPIOE
#define RELAY_DIR_Pin GPIO_PIN_3
#define RELAY_DIR_GPIO_Port GPIOE
#define RELAY1_EN_Pin GPIO_PIN_4
#define RELAY1_EN_GPIO_Port GPIOE

#define RFRST_Pin GPIO_PIN_15
#define RFRST_GPIO_Port GPIOE
#define RFTX_Pin GPIO_PIN_10
#define RFTX_GPIO_Port GPIOB
#define RFRX_Pin GPIO_PIN_11
#define RFRX_GPIO_Port GPIOB


#define BEEP_Pin GPIO_PIN_12
#define BEEP_GPIO_Port GPIOB


#define RS485_EN_Pin GPIO_PIN_15
#define RS485_EN_GPIO_Port GPIOA
#define RS485_TX_Pin GPIO_PIN_12
#define RS485_TX_GPIO_Port GPIOC
#define RS485_RX_Pin GPIO_PIN_2
#define RS485_RX_GPIO_Port GPIOD


#define LCD_DB6_Pin GPIO_PIN_4
#define LCD_DB6_GPIO_Port GPIOD
#define LCD_DB7_Pin GPIO_PIN_5
#define LCD_DB7_GPIO_Port GPIOD
#define LCD_DB4_Pin GPIO_PIN_6
#define LCD_DB4_GPIO_Port GPIOD
#define LCD_DB5_Pin GPIO_PIN_7
#define LCD_DB5_GPIO_Port GPIOD
#define LCD_E_Pin GPIO_PIN_3
#define LCD_E_GPIO_Port GPIOB
#define LCD_RW_Pin GPIO_PIN_4
#define LCD_RW_GPIO_Port GPIOB
#define LCD_RS_Pin GPIO_PIN_5
#define LCD_RS_GPIO_Port GPIOB


#define PLC_TX_Pin GPIO_PIN_6
#define PLC_TX_GPIO_Port GPIOB
#define PLC_RX_Pin GPIO_PIN_7
#define PLC_RX_GPIO_Port GPIOB
#define PLC_RST_Pin GPIO_PIN_8
#define PLC_RST_GPIO_Port GPIOB
#define PLC_REQ_Pin GPIO_PIN_9
#define PLC_REQ_GPIO_Port GPIOB
#define PLC_BR0_Pin GPIO_PIN_0
#define PLC_BR0_GPIO_Port GPIOE
#define PLC_BR1_Pin GPIO_PIN_1
#define PLC_BR1_GPIO_Port GPIOE


#define METER_TX_Pin GPIO_PIN_2
#define METER_TX_GPIO_Port GPIOA
#define METER_RX_Pin GPIO_PIN_3
#define METER_RX_GPIO_Port GPIOA
#define METER_USART USART2

#define METER_EN1_Pin GPIO_PIN_5
#define METER_EN1_GPIO_Port GPIOA

//#define EN_A_Pin GPIO_PIN_14
//#define EN_A_GPIO_Port GPIOE


#define METER_CS1_Pin GPIO_PIN_2
#define METER_CS1_GPIO_Port GPIOC
//#define SCS_A_Pin GPIO_PIN_2
//#define SCS_A_GPIO_Port GPIOC


#define METER_SYN1_Pin GPIO_PIN_4
#define METER_SYN1_GPIO_Port GPIOA
//#define SYN_A_Pin METER_SYN1_Pin
//#define SYN_A_GPIO_Port METER_SYN1_GPIO_Port


#define METER_INT11_Pin GPIO_PIN_13
#define METER_INT11_GPIO_Port GPIOC
#define INT1_A_GPIO_PORT GPIOC
#define INT1_A_PIN GPIO_PIN_1


#define METER_INT12_Pin GPIO_PIN_1
#define METER_INT12_GPIO_Port GPIOC
#define INT2_A_GPIO_PORT GPIOC
#define INT2_A_PIN GPIO_PIN_13







#define SCS_B_Pin            GPIO_PIN_8
#define SCS_B_GPIO_Port      GPIOD

#define METER_SYN2_Pin       GPIO_PIN_6
#define METER_SYN2_GPIO_Port GPIOA
#define SYN_B_Pin            METER_SYN2_Pin
#define SYN_B_GPIO_Port      METER_SYN2_GPIO_Port

#define METER_EN2_Pin        GPIO_PIN_7
#define METER_EN2_GPIO_Port  GPIOA
#define EN_B_Pin             METER_EN2_Pin
#define EN_B_GPIO_Port       METER_EN2_GPIO_Port


#define EN_C_Pin             GPIO_PIN_11
#define EN_C_GPIO_Port       GPIOD
#define SCS_C_Pin            GPIO_PIN_12
#define SCS_C_GPIO_Port      GPIOD
#define SYN_C_Pin            GPIO_PIN_13
#define SYN_C_GPIO_Port      GPIOD

#define LED5_Pin             GPIO_PIN_14
#define LED5_GPIO_Port       GPIOD
#define LED6_Pin             GPIO_PIN_15
#define LED6_GPIO_Port       GPIOD

// Example of __DATE__ string: "Jul 27 2012"
//                              01234567890
// Example of __TIME__ string: "20:00:00"
//                              01234567
#define MONTH_IS_JAN (__DATE__[0] == 'J' && __DATE__[1] == 'a' && __DATE__[2] == 'n')
#define MONTH_IS_FEB (__DATE__[0] == 'F')
#define MONTH_IS_MAR (__DATE__[0] == 'M' && __DATE__[1] == 'a' && __DATE__[2] == 'r')
#define MONTH_IS_APR (__DATE__[0] == 'A' && __DATE__[1] == 'p')
#define MONTH_IS_MAY (__DATE__[0] == 'M' && __DATE__[1] == 'a' && __DATE__[2] == 'y')
#define MONTH_IS_JUN (__DATE__[0] == 'J' && __DATE__[1] == 'u' && __DATE__[2] == 'n')
#define MONTH_IS_JUL (__DATE__[0] == 'J' && __DATE__[1] == 'u' && __DATE__[2] == 'l')
#define MONTH_IS_AUG (__DATE__[0] == 'A' && __DATE__[1] == 'u')
#define MONTH_IS_SEP (__DATE__[0] == 'S')
#define MONTH_IS_OCT (__DATE__[0] == 'O')
#define MONTH_IS_NOV (__DATE__[0] == 'N')
#define MONTH_IS_DEC (__DATE__[0] == 'D')

#define MONTH_T \
    ( \
        (MONTH_IS_JAN) ? 1 : \
        (MONTH_IS_FEB) ? 2 : \
        (MONTH_IS_MAR) ? 3 : \
        (MONTH_IS_APR) ? 4 : \
        (MONTH_IS_MAY) ? 5 : \
        (MONTH_IS_JUN) ? 6 : \
        (MONTH_IS_JUL) ? 7 : \
        (MONTH_IS_AUG) ? 8 : \
        (MONTH_IS_SEP) ? 9 : \
        (MONTH_IS_OCT) ? 10 : \
        (MONTH_IS_NOV) ? 11 : \
        (MONTH_IS_DEC) ? 12 : \
        /* error default */    '?' \
    )


#define YEAR    (uint8_t)((__DATE__[9]-'0')*10 + (__DATE__[10]-'0'))
#define DAY     (uint8_t)((__DATE__[4]-'0')*10 + (__DATE__[5]-'0'))
//#define MONTH   (uint8_t)((MONTH_T[1]-'0')*10 + (MONTH_T[0]-'0'))
#define MONTH   ((uint8_t)MONTH_T)
#define HOURS   (uint8_t)((__TIME__[0]-'0')*10 + (__TIME__[1]-'0'))
#define MINUTES (uint8_t)((__TIME__[3]-'0')*10 + (__TIME__[4]-'0'))
#define SECONDS (uint8_t)((__TIME__[6]-'0')*10 + (__TIME__[7]-'0'))

// condition ? first_expression : second_expression;

#define CS_PIN_ACTIVE GPIO_PIN_RESET
#define CS_PIN_INACTIVE GPIO_PIN_SET

#define EN_PIN_ACTIVE GPIO_PIN_SET
#define EN_PIN_INACTIVE GPIO_PIN_RESET

#define SYN_PIN_ACTIVE GPIO_PIN_SET
#define SYN_PIN_INACTIVE GPIO_PIN_RESET



/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
