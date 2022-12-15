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
void EEPROM_Read(uint16_t MemoryAddress, void* PointerToValue, uint16_t ValueSizeInByte);
void EEPROM_Write(uint16_t MemoryAddress, void* PointerToValue, uint16_t ValueSizeInByte);
void EEPROM_Update(uint16_t MemoryAddress, void* PointerToValue, uint16_t ValueSizeInByte);

#endif /* INC_EEPROM_H_ */
