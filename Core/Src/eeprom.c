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


/* Includes ------------------------------------------------------------------*/
#include "eeprom.h"
#include "string.h"
/* Defines -------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
extern I2C_HandleTypeDef hi2c1;
/* Private Function definition -----------------------------------------------*/
/* Public Function -----------------------------------------------------------*/
void EEPROM_Read(uint16_t MemoryAddress, void* PointerToValue, uint16_t ValueSizeInByte)
{
	HAL_I2C_Mem_Read(
			&hi2c1,
			(84<<1),
			MemoryAddress,
			I2C_MEMADD_SIZE_16BIT,
			PointerToValue,
			ValueSizeInByte,
			ValueSizeInByte * 1000);
}

void EEPROM_Write(uint16_t MemoryAddress, void* PointerToValue, uint16_t ValueSizeInByte)
{
	HAL_I2C_Mem_Write(
			&hi2c1,
			(84<<1),
			MemoryAddress,
			I2C_MEMADD_SIZE_16BIT,
			PointerToValue,
			ValueSizeInByte,
			ValueSizeInByte * 1000);

	HAL_Delay(5);
}

void EEPROM_Update(uint16_t MemoryAddress, void* PointerToValueToUpdate, uint16_t ValueSizeInByte)
{
	uint16_t PointerToValueToRead;
	EEPROM_Read(MemoryAddress, &PointerToValueToRead, ValueSizeInByte);

	if(memcmp(PointerToValueToUpdate, &PointerToValueToRead, ValueSizeInByte))
	{
		EEPROM_Write(MemoryAddress, PointerToValueToUpdate, ValueSizeInByte);
	}
}
/* Private Function ----------------------------------------------------------*/
/* End of the file -----------------------------------------------------------*/
