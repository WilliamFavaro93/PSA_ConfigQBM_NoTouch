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
			1000);
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
}

void EEPROM_Update(uint16_t MemoryAddress, void* PointerToValue, uint16_t ValueSizeInByte)
{
	uint8_t PointerToReadValue;
	EEPROM_Read(MemoryAddress, &PointerToReadValue, ValueSizeInByte);

	if(!(memcmp(PointerToValue, PointerToReadValue, ValueSizeInByte)))
	{
		HAL_I2C_Mem_Write(
				&hi2c1,
				(84<<1),
				MemoryAddress,
				I2C_MEMADD_SIZE_16BIT,
				PointerToValue,
				ValueSizeInByte,
				ValueSizeInByte * 1000);
	}
}
/* Private Function ----------------------------------------------------------*/
/* End of the file -----------------------------------------------------------*/
