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
	uint16_t ed_number_fix = EEPROM_DEFINE_NUMBER_FIX;
	uint16_t ed_device_type = 0;

	uint16_t ed_firmware_major_version = 1;
	uint16_t ed_firmware_minor_version = 2;
	uint16_t ed_firmware_patch_version = 63;

	uint16_t ed_date_year = 2022;
	uint16_t ed_date_month = 12;
	uint16_t ed_date_day = 15;

	uint16_t ed_machine_type = 0;
	uint16_t ed_number_module = 0;
	uint16_t ed_number_valveblock = 0;

	EEPROM_Update(E2_0__NUMBER_FIX,  &ed_number_fix,  2);
	EEPROM_Update(E2_0__DEVICE_TYPE, &ed_device_type, 2);

	EEPROM_Update(E2_0__FIRMWARE_MAJOR_VERSION, &ed_firmware_major_version, 2);
	EEPROM_Update(E2_0__FIRMWARE_MINOR_VERSION, &ed_firmware_minor_version, 2);
	EEPROM_Update(E2_0__FIRMWARE_MINOR_VERSION, &ed_firmware_patch_version, 2);

	EEPROM_Update(E2_0__DATE_YEAR,  &ed_date_year,  2);
	EEPROM_Update(E2_0__DATE_MONTH, &ed_date_month, 2);
	EEPROM_Update(E2_0__DATE_DAY,   &ed_date_day,   2);

	EEPROM_Update(E2_0__MACHINE_TYPE, &ed_machine_type, 2);
	EEPROM_Update(E2_0__NUMBER_MODULE, &ed_number_module, 2);
	EEPROM_Update(E2_0__NUMBER_VALVEBLOCK, &ed_number_valveblock, 2);
}

void EEPROM_DEFINE_UpdatePage01WithDefaultValue()
{
	uint16_t ed_time_startup = 0;

	uint16_t ed_time_first_adsorption = 0;
	uint16_t ed_time_adsorption = 0;

	uint16_t ed_time_compensation_0 = 0;
	uint16_t ed_time_compensation_1 = 0;
	uint16_t ed_time_compensation_2 = 0;

	uint16_t ed_time_prestandby_1 = 0;
	uint16_t ed_time_prestandby_2 = 0;

	EEPROM_Update(E2_1__TIME_STARTUP, &ed_time_startup, 2);

	EEPROM_Update(E2_1__TIME_FIRST_ADSORPTION, &ed_time_first_adsorption, 2);
	EEPROM_Update(E2_1__TIME_ADSORPTION, &ed_time_adsorption, 2);

	EEPROM_Update(E2_1__TIME_COMPENSATION_0, &ed_time_compensation_0, 2);
	EEPROM_Update(E2_1__TIME_COMPENSATION_1, &ed_time_compensation_1, 2);
	EEPROM_Update(E2_1__TIME_COMPENSATION_2, &ed_time_compensation_2, 2);

	EEPROM_Update(E2_1__TIME_PRESTANDBY_1, &ed_time_prestandby_1, 2);
	EEPROM_Update(E2_1__TIME_PRESTANDBY_2, &ed_time_prestandby_2, 2);
}

void EEPROM_DEFINE_UpdatePage02WithDefaultValue()
{
	uint16_t alarm_AL01_refreshtime_on  = 5;
	uint16_t alarm_AL01_refreshtime_off = 5;

	uint16_t alarm_AL02_refreshtime_on  = 5;
	uint16_t alarm_AL02_refreshtime_off = 5;

	uint16_t alarm_AL05_refreshtime_on  = 5;
	uint16_t alarm_AL05_refreshtime_off = 5;

	uint16_t alarm_AL11_refreshtime_on  = 5;
	uint16_t alarm_AL11_refreshtime_off = 5;

	uint16_t alarm_AL16_refreshtime_on  = 5;
	uint16_t alarm_AL16_refreshtime_off = 5;

	uint16_t alarm_AL17_refreshtime_on  = 5;
	uint16_t alarm_AL17_refreshtime_off = 5;

	uint16_t alarm_AL18_refreshtime_on  = 5;
	uint16_t alarm_AL18_refreshtime_off = 5;

	uint16_t alarm_AL19_refreshtime_on  = 5;
	uint16_t alarm_AL19_refreshtime_off = 5;

	uint16_t alarm_AL20_refreshtime_on  = 5;
	uint16_t alarm_AL20_refreshtime_off = 5;

	EEPROM_Update(E2_2__ALARM_AL01_REFRESH_TIME_ON, &alarm_AL01_refreshtime_on, 2);
	EEPROM_Update(E2_2__ALARM_AL01_REFRESH_TIME_OFF, &alarm_AL01_refreshtime_off, 2);

	EEPROM_Update(E2_2__ALARM_AL02_REFRESH_TIME_ON, &alarm_AL02_refreshtime_on, 2);
	EEPROM_Update(E2_2__ALARM_AL02_REFRESH_TIME_OFF, &alarm_AL02_refreshtime_off, 2);

	EEPROM_Update(E2_2__ALARM_AL05_REFRESH_TIME_ON, &alarm_AL05_refreshtime_on, 2);
	EEPROM_Update(E2_2__ALARM_AL05_REFRESH_TIME_OFF, &alarm_AL05_refreshtime_off, 2);

	EEPROM_Update(E2_2__ALARM_AL11_REFRESH_TIME_ON, &alarm_AL11_refreshtime_on, 2);
	EEPROM_Update(E2_2__ALARM_AL11_REFRESH_TIME_OFF, &alarm_AL11_refreshtime_off, 2);

	EEPROM_Update(E2_2__ALARM_AL16_REFRESH_TIME_ON, &alarm_AL16_refreshtime_on, 2);
	EEPROM_Update(E2_2__ALARM_AL16_REFRESH_TIME_OFF, &alarm_AL16_refreshtime_off, 2);

	EEPROM_Update(E2_2__ALARM_AL17_REFRESH_TIME_ON, &alarm_AL17_refreshtime_on, 2);
	EEPROM_Update(E2_2__ALARM_AL17_REFRESH_TIME_OFF, &alarm_AL17_refreshtime_off, 2);

	EEPROM_Update(E2_2__ALARM_AL18_REFRESH_TIME_ON, &alarm_AL18_refreshtime_on, 2);
	EEPROM_Update(E2_2__ALARM_AL18_REFRESH_TIME_OFF, &alarm_AL18_refreshtime_off, 2);

	EEPROM_Update(E2_2__ALARM_AL19_REFRESH_TIME_ON, &alarm_AL19_refreshtime_on, 2);
	EEPROM_Update(E2_2__ALARM_AL19_REFRESH_TIME_OFF, &alarm_AL19_refreshtime_off, 2);

	EEPROM_Update(E2_2__ALARM_AL20_REFRESH_TIME_ON, &alarm_AL20_refreshtime_on, 2);
	EEPROM_Update(E2_2__ALARM_AL20_REFRESH_TIME_OFF, &alarm_AL20_refreshtime_off, 2);
}

void EEPROM_DEFINE_UpdatePage03WithDefaultValue()
{
	uint16_t alarm_AL31_refreshtime_on  = 5;
	uint16_t alarm_AL31_refreshtime_off = 5;

	uint16_t alarm_AL32_refreshtime_on  = 5;
	uint16_t alarm_AL32_refreshtime_off = 5;

	uint16_t alarm_AL33_refreshtime_on  = 5;
	uint16_t alarm_AL33_refreshtime_off = 5;

	uint16_t alarm_AL34_refreshtime_on  = 5;
	uint16_t alarm_AL34_refreshtime_off = 5;

	uint16_t alarm_AL35_refreshtime_on  = 5;
	uint16_t alarm_AL35_refreshtime_off = 5;

	uint16_t alarm_AL36_refreshtime_on  = 5;
	uint16_t alarm_AL36_refreshtime_off = 5;

	uint16_t alarm_AL37_refreshtime_on  = 5;
	uint16_t alarm_AL37_refreshtime_off = 5;

	uint16_t alarm_AL40_refreshtime_on  = 5;
	uint16_t alarm_AL40_refreshtime_off = 5;

	uint16_t alarm_MSDC_refreshtime_on  = 5;
	uint16_t alarm_MSDC_refreshtime_off = 5;

	EEPROM_Update(E2_3__ALARM_AL31_REFRESH_TIME_ON, &alarm_AL31_refreshtime_on, 2);
	EEPROM_Update(E2_3__ALARM_AL31_REFRESH_TIME_OFF, &alarm_AL31_refreshtime_off, 2);

	EEPROM_Update(E2_3__ALARM_AL32_REFRESH_TIME_ON, &alarm_AL32_refreshtime_on, 2);
	EEPROM_Update(E2_3__ALARM_AL32_REFRESH_TIME_OFF, &alarm_AL32_refreshtime_off, 2);

	EEPROM_Update(E2_3__ALARM_AL33_REFRESH_TIME_ON, &alarm_AL33_refreshtime_on, 2);
	EEPROM_Update(E2_3__ALARM_AL33_REFRESH_TIME_OFF, &alarm_AL33_refreshtime_off, 2);

	EEPROM_Update(E2_3__ALARM_AL34_REFRESH_TIME_ON, &alarm_AL34_refreshtime_on, 2);
	EEPROM_Update(E2_3__ALARM_AL34_REFRESH_TIME_OFF, &alarm_AL34_refreshtime_off, 2);

	EEPROM_Update(E2_3__ALARM_AL35_REFRESH_TIME_ON, &alarm_AL35_refreshtime_on, 2);
	EEPROM_Update(E2_3__ALARM_AL35_REFRESH_TIME_OFF, &alarm_AL35_refreshtime_off, 2);;

	EEPROM_Update(E2_3__ALARM_AL36_REFRESH_TIME_ON, &alarm_AL36_refreshtime_on, 2);
	EEPROM_Update(E2_3__ALARM_AL36_REFRESH_TIME_OFF, &alarm_AL36_refreshtime_off, 2);

	EEPROM_Update(E2_3__ALARM_AL37_REFRESH_TIME_ON, &alarm_AL37_refreshtime_on, 2);
	EEPROM_Update(E2_3__ALARM_AL37_REFRESH_TIME_OFF, &alarm_AL37_refreshtime_off, 2);

	EEPROM_Update(E2_3__ALARM_AL40_REFRESH_TIME_ON, &alarm_AL40_refreshtime_on, 2);
	EEPROM_Update(E2_3__ALARM_AL40_REFRESH_TIME_OFF, &alarm_AL40_refreshtime_off, 2);

	EEPROM_Update(E2_3__ALARM_MSDC_REFRESH_TIME_ON, &alarm_MSDC_refreshtime_on, 2);
	EEPROM_Update(E2_3__ALARM_MSDC_REFRESH_TIME_OFF, &alarm_MSDC_refreshtime_off, 2);
}

void EEPROM_DEFINE_UpdatePage04WithDefaultValue()
{
#define E2_4__B1__LOWERTHRESHOLD     			EEPROM_ADDRESS(0x0004, 0x000)
#define E2_4__B1__UPPERTHRESHOLD     			EEPROM_ADDRESS(0x0004, 0x001)
#define E2_4__B1__LOWERLIMIT     				EEPROM_ADDRESS(0x0004, 0x002)
#define E2_4__B1__UPPERLIMIT     				EEPROM_ADDRESS(0x0004, 0x003)

#define E2_4__B2__LOWERTHRESHOLD     			EEPROM_ADDRESS(0x0004, 0x004)
#define E2_4__B2__UPPERTHRESHOLD     			EEPROM_ADDRESS(0x0004, 0x005)
#define E2_4__B2__LOWERLIMIT     				EEPROM_ADDRESS(0x0004, 0x006)
#define E2_4__B2__UPPERLIMIT     				EEPROM_ADDRESS(0x0004, 0x007)

#define E2_4__B3__LOWERTHRESHOLD     			EEPROM_ADDRESS(0x0004, 0x008)
#define E2_4__B3__UPPERTHRESHOLD     			EEPROM_ADDRESS(0x0004, 0x009)
#define E2_4__B3__LOWERLIMIT     				EEPROM_ADDRESS(0x0004, 0x00A)
#define E2_4__B3__UPPERLIMIT     				EEPROM_ADDRESS(0x0004, 0x00B)

#define E2_4__B4__LOWERTHRESHOLD     			EEPROM_ADDRESS(0x0004, 0x00C)
#define E2_4__B4__UPPERTHRESHOLD     			EEPROM_ADDRESS(0x0004, 0x00D)
#define E2_4__B4__LOWERLIMIT     				EEPROM_ADDRESS(0x0004, 0x00E)
#define E2_4__B4__UPPERLIMIT     				EEPROM_ADDRESS(0x0004, 0x00F)

#define E2_4__IFM_LOWERTHRESHOLD     			EEPROM_ADDRESS(0x0004, 0x010)
#define E2_4__IFM_UPPERTHRESHOLD     			EEPROM_ADDRESS(0x0004, 0x011)
#define E2_4__IFM_LOWERLIMIT     				EEPROM_ADDRESS(0x0004, 0x012)
#define E2_4__IFM_UPPERLIMIT     				EEPROM_ADDRESS(0x0004, 0x013)

#define E2_4__DEW_LOWERTHRESHOLD     			EEPROM_ADDRESS(0x0004, 0x014)
#define E2_4__DEW_UPPERTHRESHOLD     			EEPROM_ADDRESS(0x0004, 0x015)
#define E2_4__DEW_LOWERLIMIT     				EEPROM_ADDRESS(0x0004, 0x016)
#define E2_4__DEW_UPPERLIMIT     				EEPROM_ADDRESS(0x0004, 0x017)

#define E2_4__KE25_1_LOWERTHRESHOLD     		EEPROM_ADDRESS(0x0004, 0x018)
#define E2_4__KE25_1_UPPERTHRESHOLD     		EEPROM_ADDRESS(0x0004, 0x019)
#define E2_4__KE25_1_LOWERLIMIT     			EEPROM_ADDRESS(0x0004, 0x01A)
#define E2_4__KE25_1_UPPERLIMIT     			EEPROM_ADDRESS(0x0004, 0x01B)

#define E2_4__KE25_2_LOWERTHRESHOLD     		EEPROM_ADDRESS(0x0004, 0x01C)
#define E2_4__KE25_2_UPPERTHRESHOLD     		EEPROM_ADDRESS(0x0004, 0x01D)
#define E2_4__KE25_2_LOWERLIMIT     			EEPROM_ADDRESS(0x0004, 0x01E)
#define E2_4__KE25_2_UPPERLIMIT     			EEPROM_ADDRESS(0x0004, 0x01F)

	uint16_t b1_lowerthreshold = 0;
	uint16_t b1_upperthreshold = 0;
	uint16_t b1_lowerlimit = 0;
	uint16_t b1_upperlimit = 0;

	uint16_t b2_lowerthreshold = 0;
	uint16_t b2_upperthreshold = 0;
	uint16_t b2_lowerlimit = 0;
	uint16_t b2_upperlimit = 0;

	uint16_t b3_lowerthreshold = 0;
	uint16_t b3_upperthreshold = 0;
	uint16_t b3_lowerlimit = 0;
	uint16_t b3_upperlimit = 0;

	uint16_t b4_lowerthreshold = 0;
	uint16_t b4_upperthreshold = 0;
	uint16_t b4_lowerlimit = 0;
	uint16_t b4_upperlimit = 0;

	EEPROM_Update(E2_4__B1__LOWERTHRESHOLD, &b1_lowerthreshold, 2);
	EEPROM_Update(E2_4__B1__UPPERTHRESHOLD, &b1_upperthreshold, 2);
	EEPROM_Update(E2_4__B1__LOWERLIMIT, &b1_lowerlimit, 2);
	EEPROM_Update(E2_4__B1__UPPERLIMIT, &b1_upperlimit, 2);

	EEPROM_Update(E2_4__B2__LOWERTHRESHOLD, &b2_lowerthreshold, 2);
	EEPROM_Update(E2_4__B2__UPPERTHRESHOLD, &b2_upperthreshold, 2);
	EEPROM_Update(E2_4__B2__LOWERLIMIT, &b2_lowerlimit, 2);
	EEPROM_Update(E2_4__B2__UPPERLIMIT, &b2_upperlimit, 2);

	EEPROM_Update(E2_4__B3__LOWERTHRESHOLD, &b3_lowerthreshold, 2);
	EEPROM_Update(E2_4__B3__UPPERTHRESHOLD, &b3_upperthreshold, 2);
	EEPROM_Update(E2_4__B3__LOWERLIMIT, &b3_lowerlimit, 2);
	EEPROM_Update(E2_4__B3__UPPERLIMIT, &b3_upperlimit, 2);

	EEPROM_Update(E2_4__B4__LOWERTHRESHOLD, &b4_lowerthreshold, 2);
	EEPROM_Update(E2_4__B4__UPPERTHRESHOLD, &b4_upperthreshold, 2);
	EEPROM_Update(E2_4__B4__LOWERLIMIT, &b4_lowerlimit, 2);
	EEPROM_Update(E2_4__B4__UPPERLIMIT, &b4_upperlimit, 2);


}

void EEPROM_DEFINE_UpdatePage05WithDefaultValue()
{

}

void EEPROM_DEFINE_UpdatePage06WithDefaultValue()
{

}
/* Public Function -----------------------------------------------------------*/
/*
 * @brief
 * @author William Favaro
 * @date
 * @note
 */
void EEPROM_DEFINE_ReadAll()
{

}

/*
 * @brief
 * @author William Favaro
 * @date
 * @note
 */
void EEPROM_DEFINE_UpdateAllWithDefaultValue()
{
	uint16_t eeprom_define_number_fix;
	EEPROM_Update(E2_0__NUMBER_FIX, eeprom_define_number_fix, 2);

	if(eeprom_define_number_fix != EEPROM_DEFINE_NUMBER_FIX)
	{
		EEPROM_DEFINE_UpdatePage00WithDefaultValue();
		EEPROM_DEFINE_UpdatePage01WithDefaultValue();
		EEPROM_DEFINE_UpdatePage02WithDefaultValue();
		EEPROM_DEFINE_UpdatePage03WithDefaultValue();
		EEPROM_DEFINE_UpdatePage04WithDefaultValue();
		EEPROM_DEFINE_UpdatePage05WithDefaultValue();
		EEPROM_DEFINE_UpdatePage06WithDefaultValue();
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
