/**
  ******************************************************************************
  * @file    metrology_hal.h
  * @author  STMicroelectronics
  * @version V1.0
  * @date    11-March-2016
  * @brief   This file contains all the functions prototypes for the Metrology
  *          firmware library, module comet_metrology.c.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __METROLOGY_HAL_H
#define __METROLOGY_HAL_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/


/* Exported types ------------------------------------------------------------*/

#define   STPM_WAIT     1
#define   STPM_NO_WAIT  2

#if !defined (CS_PIN_ACTIVE)
#error NOT defined next definitions: CS_PIN_ACTIVE CS_PIN_INACTIVE EN_PIN_ACTIVE EN_PIN_INACTIVE SYN_PIN_ACTIVE SYN_PIN_INACTIVE
#endif
/* Exported macro ------------------------------------------------------------*/


/* Exported functions --------------------------------------------------------*/

/* Device functions */
void Metro_HAL_init_device(METRO_NB_Device_t in_Metro_Device_Id);
void Metro_HAL_reset_device(METRO_ResetType_t in_MetroResetType,METRO_NB_Device_t in_Metro_Device_Id);
uint8_t Metro_HAL_Setup(METRO_Device_Config_t * in_p_Metro_Config);
void Metro_HAL_Set_Latch_device_type(METRO_NB_Device_t in_Metro_Device_Id, METRO_Latch_Device_Type_t in_Metro_Latch_Device_Type);
void Metro_HAL_Get_Data_device(METRO_NB_Device_t in_Metro_Device_Id);
void Metro_HAL_power_up_device(METRO_NB_Device_t in_Metro_Device_Id);

/* Read measure functions */
uint16_t Metro_HAL_read_period(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);
int32_t Metro_HAL_read_power(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel,METRO_Power_selection_t in_Metro_Power_Selection);
int64_t Metro_HAL_read_energy(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel,METRO_Energy_selection_t in_Metro_Energy_Selection);
void Metro_HAL_Set_Gain(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel, METRO_Gain_t in_Metro_Gain);
METRO_Gain_t Metro_HAL_Get_Gain(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);
int32_t Metro_HAL_read_Momentary_Voltage(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel,METRO_Voltage_type_t in_Metro_V_type);
int32_t Metro_HAL_read_Momentary_Current(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel,METRO_Current_type_t in_Metro_C_type);

uint32_t Metro_HAL_read_RMS_Voltage(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);
uint32_t Metro_HAL_read_RMS_Current(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);
int32_t Metro_HAL_read_PHI(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);
int32_t Metro_HAL_Read_AH_Acc(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);

void Metro_HAL_Set_Temperature_Compensation(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel, uint8_t in_Metro_TC_Value);
uint8_t Metro_HAL_Get_Temperature_Compensation(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);
void Metro_HAL_Set_Tamper(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel, METRO_Tamper_Tolerance_t in_Metro_Tamper_Tolerance,METRO_CMD_Device_t in_Metro_CMD);
METRO_CMD_Device_t  Metro_HAL_Get_Tamper(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel, METRO_Tamper_Tolerance_t * out_p_Tamper_Tolerance);
void Metro_HAL_Set_Vref(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel, METRO_Vref_t in_Metro_Vref);
METRO_Vref_t Metro_HAL_Get_Vref(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);
void Metro_HAL_Set_Current_HP_Filter(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel, METRO_CMD_Device_t in_Metro_CMD);
void Metro_HAL_Set_Voltage_HP_Filter(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel, METRO_CMD_Device_t in_Metro_CMD);
METRO_CMD_Device_t Metro_HAL_Get_Current_HP_Filter(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);
METRO_CMD_Device_t Metro_HAL_Get_Voltage_HP_Filter(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);
void Metro_HAL_Set_Coil_integrator(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel, METRO_CMD_Device_t in_Metro_CMD);
METRO_CMD_Device_t Metro_HAL_Get_Coil_integrator(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);
uint16_t Metro_HAL_Get_Ah_Accumulation_Down_Threshold(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);
uint16_t Metro_HAL_Get_Ah_Accumulation_Up_Threshold(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);
void Metro_HAL_Set_Ah_Accumulation_Down_Threshold(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel,uint16_t in_Metro_Ah_Down_Threshold);
void Metro_HAL_Set_Ah_Accumulation_Up_Threshold(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel,uint16_t in_Metro_Ah_Up_Threshold);
int16_t Metro_HAL_Get_Power_Offset_Compensation(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel,METRO_Power_selection_t in_Metro_Power_Selection);
void Metro_HAL_Set_Power_Offset_Compensation(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel,METRO_Power_selection_t in_Metro_Power_Selection, int16_t in_Metro_Power_Offset);

METRO_CMD_Device_t  Metro_HAL_Get_ZCR(METRO_NB_Device_t in_Metro_Device_Id, METRO_ZCR_Sel_t * out_p_Metro_ZCR_Sel_config);
void Metro_HAL_Set_ZCR(METRO_NB_Device_t in_Metro_Device_Id, METRO_ZCR_Sel_t in_Metro_ZCR_Sel_config,METRO_CMD_Device_t in_Metro_CMD);

METRO_CMD_Device_t  Metro_HAL_Get_CLK(METRO_NB_Device_t in_Metro_Device_Id, METRO_CLK_Sel_t * out_p_Metro_CLK_Sel_config);
void Metro_HAL_Set_CLK(METRO_NB_Device_t in_Metro_Device_Id, METRO_CLK_Sel_t in_Metro_CLK_Sel_config,METRO_CMD_Device_t in_Metro_CMD);

void Metro_HAL_Set_Led_Power_Config(METRO_NB_Device_t in_Metro_Device, METRO_LED_Selection_t in_Metro_LED_Selection,METRO_LED_Power_selection_t in_Metro_Power_Selection);
void Metro_HAL_Set_Led_Channel_Config(METRO_NB_Device_t in_Metro_Device, METRO_LED_Selection_t in_Metro_LED_Selection,METRO_LED_Channel_t in_Metro_LED_Channel);
void Metro_HAL_Set_Led_Speed_divisor(METRO_NB_Device_t in_Metro_Device, METRO_LED_Selection_t in_Metro_LED_Selection,uint8_t in_Metro_LED_Speed_divisor);
void Metro_HAL_Set_Led_On_Off(METRO_NB_Device_t in_Metro_Device, METRO_LED_Selection_t in_Metro_LED_Selection,METRO_CMD_Device_t in_Metro_CMD);

void Metro_HAL_Get_Led_Power_Config(METRO_NB_Device_t in_Metro_Device, METRO_LED_Selection_t in_Metro_LED_Selection,METRO_LED_Power_selection_t * out_p_Metro_Power_Selection);
void Metro_HAL_Get_Led_Channel_Config(METRO_NB_Device_t in_Metro_Device, METRO_LED_Selection_t in_Metro_LED_Selection,METRO_LED_Channel_t * out_p_Metro_LED_Channel);
uint8_t Metro_HAL_Get_Led_Speed_divisor(METRO_NB_Device_t in_Metro_Device,METRO_LED_Selection_t in_Metro_LED_Selection);
METRO_CMD_Device_t Metro_HAL_Get_Led_On_Off(METRO_NB_Device_t in_Metro_Device, METRO_LED_Selection_t in_Metro_LED_Selection);

/* Calibration function */
void Metro_HAL_Set_V_Calibration(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel, uint16_t in_Metro_V_calibrator_value);
uint16_t Metro_HAL_Get_V_Calibration(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);
void Metro_HAL_Set_C_Calibration(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel, uint16_t in_Metro_C_calibrator_value);
uint16_t Metro_HAL_Get_C_Calibration(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);
void Metro_HAL_Set_Phase_V_Calibration(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel, uint8_t in_Metro_Phase_V_calibrator_value);
uint8_t Metro_HAL_Get_Phase_V_Calibration(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);
void Metro_HAL_Set_Phase_C_Calibration(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel, uint16_t in_Metro_Phase_C_calibrator_value);
uint16_t Metro_HAL_Get_Phase_C_Calibration(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);

/* IRQ, Events, Status functions */
uint32_t Metro_HAL_Read_Live_Event_from_Channel(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel, METRO_Live_Event_Type_t in_Metro_Live_Event_requested);
uint32_t Metro_HAL_Read_Status_from_Channel(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel, METRO_Status_Type_t in_Metro_Status_requested);
void Metro_HAL_Clear_Status_for_Channel(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel, METRO_Status_Type_t in_Metro_Status_requested);
void Metro_HAL_Set_IRQ_Mask_for_Channel(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel,uint32_t in_Metro_IT_Mask);
uint32_t Metro_HAL_Get_IRQ_Mask_for_Channel(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);

void Metro_HAL_Set_IRQ_Mask_for_STPM_device( METRO_NB_Device_t in_Metro_Device_Id, uint16_t in_Metro_IT_Mask);
uint16_t Metro_HAL_Get_IRQ_Mask_from_STPM_device( METRO_NB_Device_t in_Metro_Device_Id);
uint16_t Metro_HAL_Read_Status_from_STPM_device(METRO_NB_Device_t in_Metro_Device_Id, METRO_STPM_LINK_IRQ_Status_Type_t in_Metro_Status_requested);
void Metro_HAL_Clear_Status_for_STPM_device(METRO_NB_Device_t in_Metro_Device_Id, METRO_STPM_LINK_IRQ_Status_Type_t in_Metro_Status_requested);

/* Sag and Swell function */
void Metro_HAL_Set_SAG_Config(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel,uint16_t in_Metro_SAG_Threshold,uint16_t in_Metro_SAG_detect_time);
void Metro_HAL_Set_V_SWELL_Config(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel,uint16_t in_Metro_V_SWELL_Threshold);
void Metro_HAL_Set_C_SWELL_Config(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel,uint16_t in_Metro_C_SWELL_Threshold);  

void Metro_HAL_Get_SAG_Config(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel,uint16_t * out_p_Metro_SAG_Threshold,uint16_t * out_p_Metro_SAG_detect_time);
uint16_t Metro_HAL_Get_C_SWELL_Config(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);
uint16_t  Metro_HAL_Get_V_SWELL_Config(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);

uint16_t Metro_HAL_Read_SAG_Time(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);
uint16_t Metro_HAL_Read_C_SWELL_Time(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);
uint16_t Metro_HAL_Read_V_SWELL_Time(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);

void Metro_HAL_Set_SAG_and_SWELL_Clear_Timeout(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel,uint8_t in_Metro_Sag_and_Swell_Clear_Timeout);
uint8_t Metro_HAL_Get_SAG_and_SWELL_Clear_Timeout(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);
void Metro_HAL_Clear_SAG_and_SWELL_Events(METRO_NB_Device_t in_Metro_Device_Id,METRO_internal_Channel_t in_Metro_int_Channel);

/* Elementary access to STPM */
uint32_t Metro_HAL_Stpm_Read(METRO_NB_Device_t in_Metro_Device_Id,uint8_t * in_p_data,uint8_t nb_blocks,uint32_t * out_p_read_data);
uint32_t Metro_HAL_Stpm_write(METRO_NB_Device_t in_Metro_Device_Id,uint8_t * in_p_data,uint8_t nb_blocks,uint32_t * in_p_Buffer,uint8_t in_wait_stpm);
uint8_t Metrology_HAL_ReadBlock(METRO_NB_Device_t in_Metro_Device_Id, uint8_t Offset, uint8_t BlockNum, uint32_t * out_p_Buffer);
uint8_t Metrology_HAL_WriteBlock(METRO_NB_Device_t in_Metro_Device_Id, uint8_t Offset, uint8_t BlockNum, uint32_t * in_p_Buffer);

#ifdef UART_XFER_STPM3X /* UART MODE */   
void Metro_HAL_usart_config(METRO_NB_Device_t in_Metro_Device_Id,uint32_t in_baudrate);
uint8_t Metro_HAL_baudrate_set(METRO_NB_Device_t in_Metro_Device_Id,uint32_t in_baudrate);
#endif

#ifdef SPI_XFER_STPM3X /* SPI MODE */ 
void Metro_HAL_Spi_config(METRO_NB_Device_t in_Metro_Device_Id);
#endif

#ifdef __cplusplus
}
#endif

#endif /* __METROLOGY_HAL_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2014 STMicroelectronics *****END OF FILE****/
