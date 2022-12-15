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
#include "eeprom_define.h"
#include "psa.h"
/* Defines -------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
extern PSAStruct PSA;
/* Private Function definition -----------------------------------------------*/
void EEPROM_DEFINE_UpdatePage00()
{
	uint16_t eeprom_define_number_fix = EEPROM_DEFINE_NUMBER_FIX;
	uint16_t eeprom_define_device_type = 0;

	uint16_t eeprom_define_firmware_major_version = 0;
	uint16_t eeprom_define_firmware_minor_version = 0;

	uint16_t eeprom_define_date_year = 2022;
	uint16_t eeprom_define_date_month = 12;
	uint16_t eeprom_define_date_day = 15;

	uint16_t eeprom_define_machine_type = 0;
	uint16_t eeprom_define_number_module = 0;
	uint16_t eeprom_define_number_valveblock = 15;

	EEPROM_Update(E2_0__NUMBER_FIX,  &eeprom_define_number_fix,  2);
	EEPROM_Update(E2_0__DEVICE_TYPE, &eeprom_define_device_type, 2);

	EEPROM_Update(E2_0__FIRMWARE_MAJOR_VERSION, &eeprom_define_firmware_major_version, 2);
	EEPROM_Update(E2_0__FIRMWARE_MINOR_VERSION, &eeprom_define_firmware_minor_version, 2);

	EEPROM_Update(E2_0__DATE_YEAR,  &eeprom_define_date_year,  2);
	EEPROM_Update(E2_0__DATE_MONTH, &eeprom_define_date_month, 2);
	EEPROM_Update(E2_0__DATE_DAY,   &eeprom_define_date_day,   2);

	EEPROM_Update(E2_0__MACHINE_TYPE, &eeprom_define_machine_type, 2);
	EEPROM_Update(E2_0__NUMBER_MODULE, &eeprom_define_number_module, 2);
	EEPROM_Update(E2_0__NUMBER_VALVEBLOCK, &eeprom_define_number_valveblock, 2);
}

void EEPROM_DEFINE_UpdatePage01()
{
//#define E2_1__TIME_STARTUP         				EEPROM_ADDRESS(0x0001, 0x000)
//#define E2_1__TIME_FIRST_ADSORPTION 			EEPROM_ADDRESS(0x0001, 0x001)
//#define E2_1__TIME_ADSORPTION_TIME      		EEPROM_ADDRESS(0x0001, 0x002)
//#define E2_1__TIME_COMPENSATION_0    			EEPROM_ADDRESS(0x0001, 0x003)
//#define E2_1__TIME_COMPENSATION_1    			EEPROM_ADDRESS(0x0001, 0x004)
//#define E2_1__TIME_COMPENSATION_2     			EEPROM_ADDRESS(0x0001, 0x005)
//#define E2_1__TIME_PRESTANDBY_1   				EEPROM_ADDRESS(0x0001, 0x006)
//#define E2_1__TIME_PRESTANDBY_2   				EEPROM_ADDRESS(0x0001, 0x007)
//
//	EEPROM_Update(E2_1__TIME_STARTUP, EEPROM_DEFINE_NUMBER_FIX, 2);
//	EEPROM_Update(E2_0__DEVICE_TYPE, 0, 2);
//	EEPROM_Update(E2_0__FIRMWARE_MAJOR_VERSION, 0, 2);
//	EEPROM_Update(E2_0__FIRMWARE_MINOR_VERSION, 0, 2);
//	EEPROM_Update(E2_0__DATE_YEAR, 2022, 2);
//	EEPROM_Update(E2_0__DATE_MONTH, 12, 2);
//	EEPROM_Update(E2_0__DATE_DAY, 15, 2);
//	EEPROM_Update(E2_0__MACHINE_TYPE, 2022, 2);
//	EEPROM_Update(E2_0__NUMBER_MODULE, 12, 2);
//	EEPROM_Update(E2_0__NUMBER_VALVEBLOCK, 15, 2);
}
/* Public Function -----------------------------------------------------------*/
void EEPROM_DEFINE_ReadAll()
{

}

void EEPROM_DEFINE_UpdateAll()
{
	uint16_t eeprom_define_number_fix;
	EEPROM_Update(E2_0__NUMBER_FIX, eeprom_define_number_fix, 2);

	if(eeprom_define_number_fix != EEPROM_DEFINE_NUMBER_FIX)
	{
		/* UpdateAll() */
	}
}

/* Private Function ----------------------------------------------------------*/
void EEPROM_DEFINE_test(uint16_t * year1, uint16_t * year2, uint16_t * year3)
{
	EEPROM_Write(0x0000, year1, 2);
	HAL_Delay(5);
	EEPROM_Write(0x0002, year1, 2);
	HAL_Delay(5);
	EEPROM_Write(0x0004, year1, 2);
	HAL_Delay(5);

	EEPROM_Read(0x0000, year1, 2);
	HAL_Delay(5);
	EEPROM_Read(0x0002, year2, 2);
	HAL_Delay(5);
	EEPROM_Read(0x0004, year3, 2);
	HAL_Delay(5);

	while(!(year2 == year1));
	while(!(year3 == year1));
}
/* End of the file -----------------------------------------------------------*/
