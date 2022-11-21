/**
  ******************************************************************************
  * @file
  * @author
  * @date
  * @brief
  *
  ******************************************************************************
  * @note
  *
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Defines -------------------------------------------------------------------*/
/* Typedef Struct definition -------------------------------------------------*/
/* Public Function definition ------------------------------------------------*/
void EEPROM_Write(uint16_t MemoryAddress, void* Value);
void EEPROM_Read(uint16_t MemoryAddress, void* Value);
#endif /* INC_EEPROM_H_ */
