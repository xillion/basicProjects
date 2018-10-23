/**
*   @file      metroTask.c
*   @author    STMicroelectronics
*   @version   V1.0
*   @date      17 May 2016
*   @brief     This source code includes Metrology legal task related functions
*   @note      (C) COPYRIGHT 2013 STMicroelectronics
*
* @attention
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
#include "metroTask.h"
#include "metrology.h"
#include "handler_metrology.h"
#include <stdint.h>
#include "st_device.h"

/** @addtogroup LEGAL
  * @{
  */

/*******************************************************************************
* CONSTANTS & MACROS:
*******************************************************************************/

#define FACTOR_POWER_ON_ENERGY      (858)   // (3600 * 16000000 / 0x4000000) = 858.3...



/*******************************************************************************
* TYPES:
*******************************************************************************/

/*******************************************************************************
* GLOBAL VARIABLES:
*******************************************************************************/
metroData_t metroData;
METRO_Device_Config_t Tab_METRO_Global_Devices_Config[NB_MAX_DEVICE];

extern METRO_Device_Config_t Tab_METRO_internal_Devices_Config[NB_MAX_DEVICE];
uint32_t Active_power_ch1 = 0;
uint32_t Active_power_ch2 = 0;
/*******************************************************************************
* LOCAL FUNCTION PROTOTYPES:
*******************************************************************************/
//static void METRO_UnlockMnsh(void);
//
//static void METRO_HandleMetroDevice(uint32_t *pData);
//static void METRO_HandleMetroSetup(uint32_t *pData);
//static void METRO_HandleMetroMetro(uint32_t *pData);
//static void METRO_HandleMetroCal(uint32_t *pData);
//static void METRO_HandleMetroIRQ(uint32_t *pData);
//static void METRO_HandleMetroSagSwell(uint32_t *pData);

/*******************************************************************************
* LOCAL VARIABLES:
*******************************************************************************/
char text[100];

/*******************************************************************************
*
*                       IMPLEMENTATION: Public functions
*
*******************************************************************************/


/*******************************************************************************
*
*                       IMPLEMENTATION: Private functions
*
*******************************************************************************/

/**
  * @brief  This function implements the Metrology init
  * @param  None
  * @retval None
  */
void METRO_Init()
{

  MET_Conf();
  
  /* initialization device type and number of channel */
  Metro_Setup(metroData.nvm->config[0],metroData.nvm->config[1]);
  
  /* initialization device communication port */ 
  Metro_com_port_device();
  
  /* Enable for STPM device */
  Metro_power_up_device();
  
  /* initialization steps for STPM device */
  Metro_Init();

#ifdef UART_XFER_STPM3X /* UART MODE */   
  /* Change UART speed for STPM communication between Host and EXT1*/
  Metro_UartSpeed(USART_SPEED); 
#endif
  
  MET_RestoreConfigFromNVM();

  /* Initialize the factors for the computation */
  for(int i=0;i<NB_MAX_CHANNEL;i++)
  {
  //Metro_Set_Hardware_Factors( (METRO_Channel_t)(CHANNEL_1+i), metroData.nvm->powerFact[i], metroData.nvm->powerFact[i]/ FACTOR_POWER_ON_ENERGY,metroData.nvm->voltageFact[i],metroData.nvm->currentFact[i]);

	  Metro_Set_Hardware_Factors((METRO_Channel_t)(CHANNEL_1+i), 35443 ,35443/FACTOR_POWER_ON_ENERGY,116274,100);
	  Metro_Set_Current_gain((METRO_Channel_t)(CHANNEL_1+i), X2);

	  Metro_Set_Current_HP_Filter((METRO_Channel_t)(CHANNEL_1+i), DEVICE_DISABLE);
	  Metro_Set_Voltage_HP_Filter((METRO_Channel_t)(CHANNEL_1+i), DEVICE_DISABLE);

	  Metro_Set_Led_Power_Config(EXT1, LED1,LED_W_ACTIVE);
	  Metro_Set_Led_Channel_Config(EXT1, LED1,PRIMARY);
	  Metro_Set_Led_Speed_divisor(EXT1, LED1,15);
	  Metro_Set_Led_On_Off(EXT1, LED1,DEVICE_ENABLE);

  }
  
  for (int i=EXT1;i<(NB_MAX_DEVICE);i++)
  {
    if(Tab_METRO_internal_Devices_Config[i].device != 0)
    {
      /* Set default latch device type inside Metro struct for Ext chips */
      Metro_Register_Latch_device_Config_type((METRO_NB_Device_t)i, LATCH_SYN_SCS);
    }
  }
}


/**
  * @brief  This function implements the Metrology latch device
  *         Set the HW latch for next update
  * @param  None
  * @retval None
  */
void METRO_Latch_Measures()
{
  METRO_NB_Device_t i;

  for (i=EXT1;i<(NB_MAX_DEVICE);i++)
  {
    if(Tab_METRO_internal_Devices_Config[i].device != 0)
    {
      Metro_Set_Latch_device_type(i,LATCH_SYN_SCS);
    }
  }
}

/**
  * @brief  This function implements the Metrology get DSP data inside device
  * @param  None
  * @retval None
  */
void METRO_Get_Measures()
{
  METRO_NB_Device_t i;

  for (i=EXT1;i<(NB_MAX_DEVICE);i++)
  {
    if(Tab_METRO_internal_Devices_Config[i].device != 0)
    {
      Metro_Get_Data_device(i);
    }
  }

}

/**
  * @brief  This function unlock minishell after message treatment
  * @param  None
  * @retval None
  */

/**
  * @brief  This function updates the Metro measurements values
  * @param  None
  * @retval None
  */
void METRO_UpdateData(void)
{
  metroData.powerActive    = 0;
  metroData.powerReactive  = 0;
  metroData.powerApparent  = 0;

  for(int i=0;i<metroData.nbPhase;i++)
  {
    if(Metro_Read_energy((METRO_Channel_t)(CHANNEL_1+i), E_W_ACTIVE)!=0){
    	metroData.rawEnergyExt[METRO_DATA_ACTIVE  ][METRO_PHASE_1+i] = Metro_Read_energy((METRO_Channel_t)(CHANNEL_1+i), E_W_ACTIVE);
    }
    metroData.rawEnergyExt[METRO_DATA_REACTIVE  ][METRO_PHASE_1+i] = Metro_Read_energy((METRO_Channel_t)(CHANNEL_1+i), E_REACTIVE);
    metroData.rawEnergyExt[METRO_DATA_APPARENT  ][METRO_PHASE_1+i] = Metro_Read_energy((METRO_Channel_t)(CHANNEL_1+i), E_APPARENT);

    metroData.chanPower[METRO_DATA_ACTIVE  ][METRO_PHASE_1+i] = Metro_Read_Power((METRO_Channel_t)(CHANNEL_1+i), W_ACTIVE);
    metroData.chanPower[METRO_DATA_REACTIVE][METRO_PHASE_1+i] = Metro_Read_Power((METRO_Channel_t)(CHANNEL_1+i), REACTIVE);
    metroData.chanPower[METRO_DATA_APPARENT][METRO_PHASE_1+i] = Metro_Read_Power((METRO_Channel_t)(CHANNEL_1+i), APPARENT_RMS);

//    metroData.powerActive    = metroData.chanPower[METRO_DATA_ACTIVE  ][METRO_PHASE_1+i];
//    metroData.powerReactive  = metroData.chanPower[METRO_DATA_REACTIVE][METRO_PHASE_1+i];
//    metroData.powerApparent  = metroData.chanPower[METRO_DATA_APPARENT][METRO_PHASE_1+i];
//
//    metroData.energyActive   += metroData.rawEnergyExt[METRO_DATA_ACTIVE  ][METRO_PHASE_1+i];
//	  metroData.energyReactive += metroData.rawEnergyExt[METRO_DATA_REACTIVE  ][METRO_PHASE_1+i];
//	  metroData.energyApparent += metroData.rawEnergyExt[METRO_DATA_APPARENT  ][METRO_PHASE_1+i];

	Active_power_ch1 += metroData.rawEnergyExt[METRO_DATA_ACTIVE  ][METRO_PHASE_1];
	Active_power_ch2 += metroData.rawEnergyExt[METRO_DATA_ACTIVE  ][METRO_PHASE_2];

  }
}



/**
  * @}
  */

/* End Of File */
