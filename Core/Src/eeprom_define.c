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

/* Defines -------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
extern PSAStruct PSA;

/* Private Function definition -----------------------------------------------*/
void EEPROM_DEFINE_UpdatePage00WithDefaultValue()
{
	uint16_t firmware_major_version = VERSION_MAJOR;
	uint16_t firmware_minor_version = VERSION_MINOR;
	uint16_t firmware_patch_version = VERSION_PATCH;

	uint16_t date_year = 2022;
	uint16_t date_month = 12;
	uint16_t date_day = 15;

	uint16_t number_machine_type = 0;
	uint16_t number_module = 2;
	uint16_t number_valveblock = 1;

	EEPROM_Update(E2_0__FIRMWARE_VERSION_MAJOR, &firmware_major_version, 2);
	EEPROM_Update(E2_0__FIRMWARE_VERSION_MINOR, &firmware_minor_version, 2);
	EEPROM_Update(E2_0__FIRMWARE_VERSION_PATCH, &firmware_patch_version, 2);

	EEPROM_Update(E2_0__DATE_YEAR,  &date_year,  2);
	EEPROM_Update(E2_0__DATE_MONTH, &date_month, 2);
	EEPROM_Update(E2_0__DATE_DAY,   &date_day,   2);

	EEPROM_Update(E2_0__NUMBER_MACHINE_TYPE, &number_machine_type, 2);
	EEPROM_Update(E2_0__NUMBER_MODULE, &number_module, 2);
	EEPROM_Update(E2_0__NUMBER_VALVEBLOCK, &number_valveblock, 2);
}

void EEPROM_DEFINE_UpdatePage01WithDefaultValue()
{
	uint16_t time_startup = 80;

	uint16_t time_first_adsorption = 55;
	uint16_t time_adsorption = 55;

	uint16_t time_compensation_0 = 1;
	uint16_t time_compensation_1 = 1;
	uint16_t time_compensation_2 = 1;

	uint16_t time_prestandby_1 = 5;
	uint16_t time_prestandby_2 = 5;

	EEPROM_Update(E2_1__TIME_STARTUP, &time_startup, 2);

	EEPROM_Update(E2_1__TIME_FIRST_ADSORPTION, &time_first_adsorption, 2);
	EEPROM_Update(E2_1__TIME_ADSORPTION, &time_adsorption, 2);

	EEPROM_Update(E2_1__TIME_COMPENSATION_0, &time_compensation_0, 2);
	EEPROM_Update(E2_1__TIME_COMPENSATION_1, &time_compensation_1, 2);
	EEPROM_Update(E2_1__TIME_COMPENSATION_2, &time_compensation_2, 2);

	EEPROM_Update(E2_1__TIME_PRESTANDBY_1, &time_prestandby_1, 2);
	EEPROM_Update(E2_1__TIME_PRESTANDBY_2, &time_prestandby_2, 2);
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
	uint16_t b1_lowerthreshold = 500;
	uint16_t b1_upperthreshold = 700;
	uint16_t b1_lowerlimit = 0;
	uint16_t b1_upperlimit = 10000;

	uint16_t b2_lowerthreshold = 500;
	uint16_t b2_upperthreshold = 700;
	uint16_t b2_lowerlimit = 0;
	uint16_t b2_upperlimit = 10000;

	uint16_t b3_lowerthreshold = 500;
	uint16_t b3_upperthreshold = 700;
	uint16_t b3_lowerlimit = 0;
	uint16_t b3_upperlimit = 10000;

	uint16_t b4_lowerthreshold = 500;
	uint16_t b4_upperthreshold = 700;
	uint16_t b4_lowerlimit = 0;
	uint16_t b4_upperlimit = 10000;

	uint16_t ifm_lowerthreshold = 500;
	uint16_t ifm_upperthreshold = 700;
	uint16_t ifm_lowerlimit = 0;
	uint16_t ifm_upperlimit = 10000;

	uint16_t dew_lowerthreshold = 500;
	uint16_t dew_upperthreshold = 700;
	uint16_t dew_lowerlimit = 0;
	uint16_t dew_upperlimit = 10000;

	uint16_t ke25_1_lowerthreshold = 500;
	uint16_t ke25_1_upperthreshold = 700;
	uint16_t ke25_1_lowerlimit = 0;
	uint16_t ke25_1_upperlimit = 10000;

	uint16_t ke25_2_lowerthreshold = 500;
	uint16_t ke25_2_upperthreshold = 700;
	uint16_t ke25_2_lowerlimit = 0;
	uint16_t ke25_2_upperlimit = 10000;

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

	EEPROM_Update(E2_4__IFM_LOWERTHRESHOLD, &ifm_lowerthreshold, 2);
	EEPROM_Update(E2_4__IFM_UPPERTHRESHOLD, &ifm_upperthreshold, 2);
	EEPROM_Update(E2_4__IFM_LOWERLIMIT, &ifm_lowerlimit, 2);
	EEPROM_Update(E2_4__IFM_UPPERLIMIT, &ifm_upperlimit, 2);

	EEPROM_Update(E2_4__DEW_LOWERTHRESHOLD, &dew_lowerthreshold, 2);
	EEPROM_Update(E2_4__DEW_UPPERTHRESHOLD, &dew_upperthreshold, 2);
	EEPROM_Update(E2_4__DEW_LOWERLIMIT, &dew_lowerlimit, 2);
	EEPROM_Update(E2_4__DEW_UPPERLIMIT, &dew_upperlimit, 2);

	EEPROM_Update(E2_4__KE25_1_LOWERLIMIT, &ke25_1_lowerthreshold, 2);
	EEPROM_Update(E2_4__KE25_1_UPPERTHRESHOLD, &ke25_1_upperthreshold, 2);
	EEPROM_Update(E2_4__KE25_1_LOWERLIMIT, &ke25_1_lowerlimit, 2);
	EEPROM_Update(E2_4__KE25_1_UPPERLIMIT, &ke25_1_upperlimit, 2);

	EEPROM_Update(E2_4__KE25_2_LOWERTHRESHOLD, &ke25_2_lowerthreshold, 2);
	EEPROM_Update(E2_4__KE25_2_UPPERTHRESHOLD, &ke25_2_upperthreshold, 2);
	EEPROM_Update(E2_4__KE25_2_LOWERLIMIT, &ke25_2_lowerlimit, 2);
	EEPROM_Update(E2_4__KE25_2_UPPERLIMIT, &ke25_2_upperlimit, 2);
}

void EEPROM_DEFINE_UpdatePage05WithDefaultValue()
{
	uint16_t can1_identifier = 0;
	uint16_t can2_identifier = 0;
	uint16_t can1_baudrate = 0;
	uint16_t can2_baudrate = 0;

	EEPROM_Update(E2_5__CAN_1_IDENTIFIER, &can1_identifier, 2);
	EEPROM_Update(E2_5__CAN_2_IDENTIFIER, &can2_identifier, 2);
	EEPROM_Update(E2_5__CAN_1_BAUDRATE, &can1_baudrate, 2);
	EEPROM_Update(E2_5__CAN_2_BAUDRATE, &can2_baudrate, 2);
}

void EEPROM_DEFINE_UpdatePage06WithDefaultValue()
{
	uint16_t out_priority = 1;
	uint16_t out1_enable = 1;
	uint16_t out2_enable = 1;

	EEPROM_Update(E2_6__OUT_PRIORITY, &out_priority, 2);
	EEPROM_Update(E2_6__OUT1_ENABLE, &out1_enable, 2);
	EEPROM_Update(E2_6__OUT2_ENABLE, &out2_enable, 2);
}
/* Public Function -----------------------------------------------------------*/
/*
 * @brief
 * @author William Favaro
 * @date
 * @note
 */
void EEPROM_DEFINE_DateTimeInit()
{
	uint16_t date_year;
	uint16_t date_month;
	uint16_t date_day;

	EEPROM_Read(E2_0__DATE_YEAR,  &date_year,  2);
	EEPROM_Read(E2_0__DATE_MONTH, &date_month, 2);
	EEPROM_Read(E2_0__DATE_DAY,   &date_day,   2);

	DateTime_Init(date_year, date_month, date_day, 0, 0, 0);
}

void EEPROM_DEFINE_AlarmInit()
{
	uint16_t alarm_AL01_refreshtime_on;
	uint16_t alarm_AL01_refreshtime_off;

	uint16_t alarm_AL02_refreshtime_on;
	uint16_t alarm_AL02_refreshtime_off;

	uint16_t alarm_AL05_refreshtime_on;
	uint16_t alarm_AL05_refreshtime_off;

	uint16_t alarm_AL11_refreshtime_on;
	uint16_t alarm_AL11_refreshtime_off;

	uint16_t alarm_AL16_refreshtime_on;
	uint16_t alarm_AL16_refreshtime_off;

	uint16_t alarm_AL17_refreshtime_on;
	uint16_t alarm_AL17_refreshtime_off;

	uint16_t alarm_AL18_refreshtime_on;
	uint16_t alarm_AL18_refreshtime_off;

	uint16_t alarm_AL19_refreshtime_on;
	uint16_t alarm_AL19_refreshtime_off;

	uint16_t alarm_AL20_refreshtime_on;
	uint16_t alarm_AL20_refreshtime_off;

	EEPROM_Read(E2_2__ALARM_AL01_REFRESH_TIME_ON, &alarm_AL01_refreshtime_on, 2);
	EEPROM_Read(E2_2__ALARM_AL01_REFRESH_TIME_OFF, &alarm_AL01_refreshtime_off, 2);
	EEPROM_Read(E2_2__ALARM_AL02_REFRESH_TIME_ON, &alarm_AL02_refreshtime_on, 2);
	EEPROM_Read(E2_2__ALARM_AL02_REFRESH_TIME_OFF, &alarm_AL02_refreshtime_off, 2);
	EEPROM_Read(E2_2__ALARM_AL05_REFRESH_TIME_ON, &alarm_AL05_refreshtime_on, 2);
	EEPROM_Read(E2_2__ALARM_AL05_REFRESH_TIME_OFF, &alarm_AL05_refreshtime_off, 2);
	EEPROM_Read(E2_2__ALARM_AL11_REFRESH_TIME_ON, &alarm_AL11_refreshtime_on, 2);
	EEPROM_Read(E2_2__ALARM_AL11_REFRESH_TIME_OFF, &alarm_AL11_refreshtime_off, 2);
	EEPROM_Read(E2_2__ALARM_AL16_REFRESH_TIME_ON, &alarm_AL16_refreshtime_on, 2);
	EEPROM_Read(E2_2__ALARM_AL16_REFRESH_TIME_OFF, &alarm_AL16_refreshtime_off, 2);
	EEPROM_Read(E2_2__ALARM_AL17_REFRESH_TIME_ON, &alarm_AL17_refreshtime_on, 2);
	EEPROM_Read(E2_2__ALARM_AL17_REFRESH_TIME_OFF, &alarm_AL17_refreshtime_off, 2);
	EEPROM_Read(E2_2__ALARM_AL18_REFRESH_TIME_ON, &alarm_AL18_refreshtime_on, 2);
	EEPROM_Read(E2_2__ALARM_AL18_REFRESH_TIME_OFF, &alarm_AL18_refreshtime_off, 2);
	EEPROM_Read(E2_2__ALARM_AL19_REFRESH_TIME_ON, &alarm_AL19_refreshtime_on, 2);
	EEPROM_Read(E2_2__ALARM_AL19_REFRESH_TIME_OFF, &alarm_AL19_refreshtime_off, 2);
	EEPROM_Read(E2_2__ALARM_AL20_REFRESH_TIME_ON, &alarm_AL20_refreshtime_on, 2);
	EEPROM_Read(E2_2__ALARM_AL20_REFRESH_TIME_OFF, &alarm_AL20_refreshtime_off, 2);

	Alarm_Init(&PSA.Alarm.AL01_CANbusError, alarm_AL01_refreshtime_on, alarm_AL01_refreshtime_off);
	Alarm_Init(&PSA.Alarm.AL02_LowInputAirPressure, alarm_AL02_refreshtime_on, alarm_AL02_refreshtime_off);
	Alarm_Init(&PSA.Alarm.AL05_LowProcessTankPressure, alarm_AL05_refreshtime_on, alarm_AL05_refreshtime_off);
	Alarm_Init(&PSA.Alarm.AL11_External, alarm_AL11_refreshtime_on, alarm_AL11_refreshtime_off);
	Alarm_Init(&PSA.Alarm.AL16_HighOut2Pressure, alarm_AL16_refreshtime_on, alarm_AL16_refreshtime_off);
	Alarm_Init(&PSA.Alarm.AL17_HighDewpoint, alarm_AL17_refreshtime_on, alarm_AL17_refreshtime_off);
	Alarm_Init(&PSA.Alarm.AL18_HighDewpoint, alarm_AL18_refreshtime_on, alarm_AL18_refreshtime_off);
	Alarm_Init(&PSA.Alarm.AL19_HighOut1Pressure, alarm_AL19_refreshtime_on, alarm_AL19_refreshtime_off);
	Alarm_Init(&PSA.Alarm.AL20_PCComunicationFault, alarm_AL20_refreshtime_on, alarm_AL20_refreshtime_off);
}

void EEPROM_DEFINE_FaultInit()
{
	uint16_t alarm_AL31_refreshtime_on;
	uint16_t alarm_AL31_refreshtime_off;

	uint16_t alarm_AL32_refreshtime_on;
	uint16_t alarm_AL32_refreshtime_off;

	uint16_t alarm_AL33_refreshtime_on;
	uint16_t alarm_AL33_refreshtime_off;

	uint16_t alarm_AL34_refreshtime_on;
	uint16_t alarm_AL34_refreshtime_off;

	uint16_t alarm_AL35_refreshtime_on;
	uint16_t alarm_AL35_refreshtime_off;

	uint16_t alarm_AL36_refreshtime_on;
	uint16_t alarm_AL36_refreshtime_off;

	uint16_t alarm_AL37_refreshtime_on;
	uint16_t alarm_AL37_refreshtime_off;

	uint16_t alarm_AL40_refreshtime_on;
	uint16_t alarm_AL40_refreshtime_off;

	uint16_t alarm_MSDC_refreshtime_on;
	uint16_t alarm_MSDC_refreshtime_off;

	EEPROM_Read(E2_3__ALARM_AL31_REFRESH_TIME_ON, &alarm_AL31_refreshtime_on, 2);
	EEPROM_Read(E2_3__ALARM_AL31_REFRESH_TIME_OFF, &alarm_AL31_refreshtime_off, 2);
	EEPROM_Read(E2_3__ALARM_AL32_REFRESH_TIME_ON, &alarm_AL32_refreshtime_on, 2);
	EEPROM_Read(E2_3__ALARM_AL32_REFRESH_TIME_OFF, &alarm_AL32_refreshtime_off, 2);
	EEPROM_Read(E2_3__ALARM_AL33_REFRESH_TIME_ON, &alarm_AL33_refreshtime_on, 2);
	EEPROM_Read(E2_3__ALARM_AL33_REFRESH_TIME_OFF, &alarm_AL33_refreshtime_off, 2);
	EEPROM_Read(E2_3__ALARM_AL34_REFRESH_TIME_ON, &alarm_AL34_refreshtime_on, 2);
	EEPROM_Read(E2_3__ALARM_AL34_REFRESH_TIME_OFF, &alarm_AL34_refreshtime_off, 2);
	EEPROM_Read(E2_3__ALARM_AL35_REFRESH_TIME_ON, &alarm_AL35_refreshtime_on, 2);
	EEPROM_Read(E2_3__ALARM_AL35_REFRESH_TIME_OFF, &alarm_AL35_refreshtime_off, 2);;
	EEPROM_Read(E2_3__ALARM_AL36_REFRESH_TIME_ON, &alarm_AL36_refreshtime_on, 2);
	EEPROM_Read(E2_3__ALARM_AL36_REFRESH_TIME_OFF, &alarm_AL36_refreshtime_off, 2);
	EEPROM_Read(E2_3__ALARM_AL37_REFRESH_TIME_ON, &alarm_AL37_refreshtime_on, 2);
	EEPROM_Read(E2_3__ALARM_AL37_REFRESH_TIME_OFF, &alarm_AL37_refreshtime_off, 2);
	EEPROM_Read(E2_3__ALARM_AL40_REFRESH_TIME_ON, &alarm_AL40_refreshtime_on, 2);
	EEPROM_Read(E2_3__ALARM_AL40_REFRESH_TIME_OFF, &alarm_AL40_refreshtime_off, 2);
	EEPROM_Read(E2_3__ALARM_MSDC_REFRESH_TIME_ON, &alarm_MSDC_refreshtime_on, 2);
	EEPROM_Read(E2_3__ALARM_MSDC_REFRESH_TIME_OFF, &alarm_MSDC_refreshtime_off, 2);

	Alarm_Init(&PSA.Alarm.AL31_B1ProbeFault, alarm_AL31_refreshtime_on, alarm_AL31_refreshtime_off);
	Alarm_Init(&PSA.Alarm.AL32_B2ProbeFault, alarm_AL32_refreshtime_on, alarm_AL32_refreshtime_off);
	Alarm_Init(&PSA.Alarm.AL33_B3ProbeFault, alarm_AL33_refreshtime_on, alarm_AL33_refreshtime_off);
	Alarm_Init(&PSA.Alarm.AL34_B4ProbeFault, alarm_AL34_refreshtime_on, alarm_AL34_refreshtime_off);
	Alarm_Init(&PSA.Alarm.AL35_IFWProbeFault, alarm_AL35_refreshtime_on, alarm_AL35_refreshtime_off);
	Alarm_Init(&PSA.Alarm.AL36_DEWProbeFault, alarm_AL36_refreshtime_on, alarm_AL36_refreshtime_off);
	Alarm_Init(&PSA.Alarm.AL37_KE25ProbeFault, alarm_AL37_refreshtime_on, alarm_AL37_refreshtime_off);
	Alarm_Init(&PSA.Alarm.AL40_PsaDischanging, alarm_AL40_refreshtime_on, alarm_AL40_refreshtime_off);
	Alarm_Init(&PSA.Alarm.MissingSDCard, alarm_MSDC_refreshtime_on, alarm_MSDC_refreshtime_off);
}

/*
 * @brief
 * @author William Favaro
 * @date
 * @note
 */
void EEPROM_DEFINE_Alarm_B1Init()
{
	EEPROM_Read(E2_4__B1__LOWERTHRESHOLD, &PSA.B1_InputAirPressure.LowerThreshold, 2);
	EEPROM_Read(E2_4__B1__UPPERTHRESHOLD, &PSA.B1_InputAirPressure.UpperThreshold, 2);
	EEPROM_Read(E2_4__B1__LOWERLIMIT, &PSA.B1_InputAirPressure.LowerLimit, 2);
	EEPROM_Read(E2_4__B1__UPPERLIMIT, &PSA.B1_InputAirPressure.UpperLimit, 2);
}

/*
 * @brief
 * @author William Favaro
 * @date
 * @note
 */
void EEPROM_DEFINE_Alarm_B2Init()
{
	EEPROM_Read(E2_4__B2__LOWERTHRESHOLD, &PSA.B2_OutputAirPressure_1.LowerThreshold, 2);
	EEPROM_Read(E2_4__B2__UPPERTHRESHOLD, &PSA.B2_OutputAirPressure_1.UpperThreshold, 2);
	EEPROM_Read(E2_4__B2__LOWERLIMIT, &PSA.B2_OutputAirPressure_1.LowerLimit, 2);
	EEPROM_Read(E2_4__B2__UPPERLIMIT, &PSA.B2_OutputAirPressure_1.UpperLimit, 2);
}

/*
 * @brief
 * @author William Favaro
 * @date
 * @note
 */
void EEPROM_DEFINE_Alarm_B3Init()
{
	EEPROM_Read(E2_4__B3__LOWERTHRESHOLD, &PSA.B3_ProcessTankAirPressure.LowerThreshold, 2);
	EEPROM_Read(E2_4__B3__UPPERTHRESHOLD, &PSA.B3_ProcessTankAirPressure.UpperThreshold, 2);
	EEPROM_Read(E2_4__B3__LOWERLIMIT, &PSA.B3_ProcessTankAirPressure.LowerLimit, 2);
	EEPROM_Read(E2_4__B3__UPPERLIMIT, &PSA.B3_ProcessTankAirPressure.UpperLimit, 2);
}

/*
 * @brief
 * @author William Favaro
 * @date
 * @note
 */
void EEPROM_DEFINE_Alarm_B4Init()
{
	EEPROM_Read(E2_4__B4__LOWERTHRESHOLD, &PSA.B4_OutputAirPressure_2.LowerThreshold, 2);
	EEPROM_Read(E2_4__B4__UPPERTHRESHOLD, &PSA.B4_OutputAirPressure_2.UpperThreshold, 2);
	EEPROM_Read(E2_4__B4__LOWERLIMIT, &PSA.B4_OutputAirPressure_2.LowerLimit, 2);
	EEPROM_Read(E2_4__B4__UPPERLIMIT, &PSA.B4_OutputAirPressure_2.UpperLimit, 2);
}

/*
 * @brief
 * @author William Favaro
 * @date
 * @note
 */
void EEPROM_DEFINE_Alarm_IFMInit()
{
	EEPROM_Read(E2_4__IFM_LOWERTHRESHOLD, &PSA.IFM_AirFlowmeter.LowerThreshold, 2);
	EEPROM_Read(E2_4__IFM_UPPERTHRESHOLD, &PSA.IFM_AirFlowmeter.UpperThreshold, 2);
	EEPROM_Read(E2_4__IFM_LOWERLIMIT, &PSA.IFM_AirFlowmeter.LowerLimit, 2);
	EEPROM_Read(E2_4__IFM_UPPERLIMIT, &PSA.IFM_AirFlowmeter.UpperLimit, 2);
}

/*
 * @brief
 * @author William Favaro
 * @date
 * @note
 */
void EEPROM_DEFINE_Alarm_DEWInit()
{
	EEPROM_Read(E2_4__DEW_LOWERTHRESHOLD, &PSA.DEW_InputAirDewpoint.LowerThreshold, 2);
	EEPROM_Read(E2_4__DEW_UPPERTHRESHOLD, &PSA.DEW_InputAirDewpoint.UpperThreshold, 2);
	EEPROM_Read(E2_4__DEW_LOWERLIMIT, &PSA.DEW_InputAirDewpoint.LowerLimit, 2);
	EEPROM_Read(E2_4__DEW_UPPERLIMIT, &PSA.DEW_InputAirDewpoint.UpperLimit, 2);
}

/*
 * @brief
 * @author William Favaro
 * @date
 * @note
 */
void EEPROM_DEFINE_Alarm_KE25_1Init()
{
	EEPROM_Read(E2_4__KE25_1_LOWERTHRESHOLD, &PSA.KE25_OxygenSensor_1.LowerThreshold, 2);
	EEPROM_Read(E2_4__KE25_1_UPPERTHRESHOLD, &PSA.KE25_OxygenSensor_1.UpperThreshold, 2);
	EEPROM_Read(E2_4__KE25_1_LOWERLIMIT, &PSA.KE25_OxygenSensor_1.LowerLimit, 2);
	EEPROM_Read(E2_4__KE25_1_UPPERLIMIT, &PSA.KE25_OxygenSensor_1.UpperLimit, 2);
}

/*
 * @brief
 * @author William Favaro
 * @date
 * @note
 */
void EEPROM_DEFINE_Alarm_KE25_2Init()
{
	EEPROM_Read(E2_4__KE25_2_LOWERTHRESHOLD, &PSA.KE25_OxygenSensor_2.LowerThreshold, 2);
	EEPROM_Read(E2_4__KE25_2_UPPERTHRESHOLD, &PSA.KE25_OxygenSensor_2.UpperThreshold, 2);
	EEPROM_Read(E2_4__KE25_2_LOWERLIMIT, &PSA.KE25_OxygenSensor_2.LowerLimit, 2);
	EEPROM_Read(E2_4__KE25_2_UPPERLIMIT, &PSA.KE25_OxygenSensor_2.UpperLimit, 2);
}

/*
 * @brief
 * @author William Favaro
 * @date
 * @note
 */
void EEPROM_DEFINE_CAN_Init()
{
	EEPROM_Read(E2_5__CAN_1_IDENTIFIER, &PSA.CANSPI.Ide, 2);
	EEPROM_Read(E2_5__CAN_2_IDENTIFIER, &PSA.CAN_2.Ide, 2);
	EEPROM_Read(E2_5__CAN_1_BAUDRATE, NULL, 2);
	EEPROM_Read(E2_5__CAN_2_BAUDRATE, NULL, 2);
}

/*
 * @brief
 * @author William Favaro
 * @date
 * @note
 */
void EEPROM_DEFINE_OutInit()
{
	EEPROM_Read(E2_6__OUT_PRIORITY, &PSA.OutPriority, 2);
	EEPROM_Read(E2_6__OUT1_ENABLE, &PSA.Out1.Enable, 2);
	EEPROM_Read(E2_6__OUT2_ENABLE, &PSA.Out2.Enable, 2);
}

/*
 * @brief
 * @author William Favaro
 * @date
 * @note
 */
void EEPROM_DEFINE_TimeInit()
{
	EEPROM_Read(E2_1__TIME_ADSORPTION, &PSA.Time.Adsorption, 2);
	EEPROM_Read(E2_1__TIME_COMPENSATION_0, &PSA.Time.Compensation_0, 2);
	EEPROM_Read(E2_1__TIME_COMPENSATION_1, &PSA.Time.Compensation_1, 2);
	EEPROM_Read(E2_1__TIME_COMPENSATION_2, &PSA.Time.Compensation_2, 2);
	EEPROM_Read(E2_1__TIME_PRESTANDBY_1, &PSA.Time.PreStandby_1, 2);
	EEPROM_Read(E2_1__TIME_PRESTANDBY_2, &PSA.Time.PreStandby_2, 2);
}

/*
 * @brief
 * @author William Favaro
 * @date
 * @note
 */
void EEPROM_DEFINE_UpdateAllWithDefaultValue()
{
	EEPROM_DEFINE_UpdatePage00WithDefaultValue();
	EEPROM_DEFINE_UpdatePage01WithDefaultValue();
	EEPROM_DEFINE_UpdatePage02WithDefaultValue();
	EEPROM_DEFINE_UpdatePage03WithDefaultValue();
	EEPROM_DEFINE_UpdatePage04WithDefaultValue();
	EEPROM_DEFINE_UpdatePage05WithDefaultValue();
	EEPROM_DEFINE_UpdatePage06WithDefaultValue();
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
//	HAL_Delay(5);
	EEPROM_Read(0x0002, year2, 2);
//	HAL_Delay(5);
	EEPROM_Read(0x0004, year3, 2);
//	HAL_Delay(5);

	while(!(*year2 == *year1)){}
	while(!(*year3 == *year1)){}
}
/* End of the file -----------------------------------------------------------*/
