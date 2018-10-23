/**
*   @file      handler_eeprom.c
*   @author    IPC - Industrial BU
*   @date      17 May 2016
*   @brief     Implements routines to handle EEPROM
*   @note      (C) COPYRIGHT 2013 STMicroelectronics
*
* @attention
*
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*
*/

/*******************************************************************************
* INCLUDE FILES:
*******************************************************************************/
#include "handler_eeprom.h"
#include "eeprom_emul.h"
#include "st_device.h"


/** @addtogroup GENERIC
  * @{
  */

/*******************************************************************************
* TYPES:
*******************************************************************************/

/*******************************************************************************
*
*                       IMPLEMENTATION: Public functions
*
*******************************************************************************/

/**
  * @brief  This function implements EEPROM configuration
  * @param  None
  * @retval None
  */
void EEPROM_Conf(void)
{

	HAL_FLASH_Unlock();

	HAL_FLASH_lock();
}

/**
  * @brief  This function implements EEPROM Read
  * @param  buf is a pointer to destination buffer
  * @param  address is the source address in EEPROM
  * @param  size is the nulber of bytes to read
  * @retval None
  */
void EEPROM_Read(uint32_t *buf, uint16_t address, uint16_t size)
{

	HAL_FLASH_Unlock();
	for(int i=0; i<size; i++){
		WriteVariable(address, (EE_DATA_TYPE)buf[i]);
	}
	HAL_FLASH_lock();
}

/**
  * @brief  This function implements EEPROM write
  * @param  address is the destination address in EEPROM
  * @param  buf is a pointer to source buffer
  * @param  size is the nulber of bytes to write
  * @retval None
  */
void EEPROM_Write(uint16_t address, uint32_t *buf, uint16_t size)
{

	HAL_FLASH_Unlock();
	for(int i=0; i<size; i++){
		ReadVariable(address, (EE_DATA_TYPE)(buf+i));
	}
	HAL_FLASH_lock();
}


/**
  * @}
  */

/* End Of File */
