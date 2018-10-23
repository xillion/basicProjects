/*
 * power_counter.h
 *
 *  Created on: Jul 31, 2018
 *      Author: z1rex
 */

#ifndef POWER_COUNTER_H_
#define POWER_COUNTER_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "main.h"
#include "eeprom_emul.h"

typedef enum
{
	off,
	on
}loadState_t;

typedef struct
{
	GPIO_TypeDef *port;
	uint16_t      pinmask;
}relay_t;

typedef struct
{
	uint32_t isEEPROMInited: 1;
	uint32_t reserved0: 1;
	uint32_t isTampered: 1;
	uint32_t isTimeUpdated: 1;
	uint32_t isInit: 1;
	uint32_t reserved1: 1;
	uint32_t reserved2: 1;
	uint32_t reserved3: 1;
	uint32_t reserved4: 1;
	uint32_t reserved5: 1;
	uint32_t reserved6: 1;
	uint32_t reserved7: 1;
	uint32_t reserved8: 1;
	uint32_t reserved9: 1;
	uint32_t reserved10: 1;
	uint32_t reserved11: 1;
	uint32_t reserved12: 1;
	uint32_t reserved13: 1;
	uint32_t reserved14: 1;
	uint32_t reserved15: 1;
	uint32_t reserved16: 1;
	uint32_t reserved17: 1;
	uint32_t reserved18: 1;
	uint32_t reserved19: 1;
	uint32_t reserved20: 1;
	uint32_t reserved21: 1;
	uint32_t reserved22: 1;
	uint32_t reserved23: 1;
	uint32_t reserved24: 1;
	uint32_t reserved25: 1;
	uint32_t reserved26: 1;
	uint32_t reserved27: 1;
}power_counter_flags_t;

#define eeprom_flags_addr 0x0000;

void restoreState(void);
uint32_t getHallMesure(void);

#ifdef __cplusplus
}
#endif

#endif /* POWER_COUNTER_H_ */
