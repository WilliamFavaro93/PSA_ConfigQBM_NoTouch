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
#ifndef INC_E2_PSA__H_
#define INC_E2_PSA__H_

/* Includes ------------------------------------------------------------------*/
#include "eeprom.h"
/* Defines -------------------------------------------------------------------*/
#define EEPROM_DEFINE_NUMBER_FIX				1

#define EEPROM_24LC512

#ifdef EEPROM_24LC512
	#define BYTE_PER_PAGE 						(0x0100) /* 128 bytes per page */
	#define NUMBER_OF_PAGES						(0x1000) /* 4096 pages  */
#endif

#define EEPROM_ELEMBASE							(0x0002) /* 2-bytes per element */
#define EEPROM_NUMBER_USED_PAGES				(0x0020) /* 32 pages */

#define EEPROM_ELEM(position)							((EEPROM_ELEMBASE * (position)) % BYTE_PER_PAGE)
#define EEPROM_PAGE(number)								(number * BYTE_PER_PAGE)
#define EEPROM_ADDRESS(page_number, element_position) 	(EEPROM_PAGE(page_number) + EEPROM_ELEM(element_position))

/* Defines: Page 00 ----------------------------------------------------------*/
/* Informazioni generali -----------------------------------------------------*/
#define E2_0__NUMBER_FIX						EEPROM_ADDRESS(0x0000, 0x000)
#define E2_0__DEVICE_TYPE						EEPROM_ADDRESS(0x0000, 0x001)

#define E2_0__FIRMWARE_MAJOR_VERSION			EEPROM_ADDRESS(0x0000, 0x002)
#define E2_0__FIRMWARE_MINOR_VERSION			EEPROM_ADDRESS(0x0000, 0x003)
#define E2_0__FIRMWARE_PATCH_VERSION			EEPROM_ADDRESS(0x0000, 0x004)

#define E2_0__DATE_YEAR							EEPROM_ADDRESS(0x0000, 0x005)
#define E2_0__DATE_MONTH						EEPROM_ADDRESS(0x0000, 0x006)
#define E2_0__DATE_DAY							EEPROM_ADDRESS(0x0000, 0x007)

#define E2_0__MACHINE_TYPE						EEPROM_ADDRESS(0x0000, 0x008)
#define E2_0__NUMBER_MODULE						EEPROM_ADDRESS(0x0000, 0x009)
#define E2_0__NUMBER_VALVEBLOCK     			EEPROM_ADDRESS(0x0000, 0x00A)

/* Defines: Page 01 ----------------------------------------------------------*/
/* Tempi di Lavoro dei Stati -------------------------------------------------*/
#define E2_1__TIME_STARTUP         				EEPROM_ADDRESS(0x0001, 0x000)

#define E2_1__TIME_FIRST_ADSORPTION 			EEPROM_ADDRESS(0x0001, 0x001)
#define E2_1__TIME_ADSORPTION		      		EEPROM_ADDRESS(0x0001, 0x002)

#define E2_1__TIME_COMPENSATION_0    			EEPROM_ADDRESS(0x0001, 0x003)
#define E2_1__TIME_COMPENSATION_1    			EEPROM_ADDRESS(0x0001, 0x004)
#define E2_1__TIME_COMPENSATION_2     			EEPROM_ADDRESS(0x0001, 0x005)

#define E2_1__TIME_PRESTANDBY_1   				EEPROM_ADDRESS(0x0001, 0x006)
#define E2_1__TIME_PRESTANDBY_2   				EEPROM_ADDRESS(0x0001, 0x007)

/* Defines: Page 02 ----------------------------------------------------------*/
/* Tempi di Refresh dei Allarmi ----------------------------------------------*/
#define E2_2__ALARM_AL01_REFRESH_TIME_ON		EEPROM_ADDRESS(0x0002, 0x000)
#define E2_2__ALARM_AL01_REFRESH_TIME_OFF		EEPROM_ADDRESS(0x0002, 0x001)
#define E2_2__ALARM_AL02_REFRESH_TIME_ON		EEPROM_ADDRESS(0x0002, 0x002)
#define E2_2__ALARM_AL02_REFRESH_TIME_OFF		EEPROM_ADDRESS(0x0002, 0x003)
#define E2_2__ALARM_AL05_REFRESH_TIME_ON		EEPROM_ADDRESS(0x0002, 0x004)
#define E2_2__ALARM_AL05_REFRESH_TIME_OFF		EEPROM_ADDRESS(0x0002, 0x005)
#define E2_2__ALARM_AL11_REFRESH_TIME_ON		EEPROM_ADDRESS(0x0002, 0x006)
#define E2_2__ALARM_AL11_REFRESH_TIME_OFF		EEPROM_ADDRESS(0x0002, 0x007)
#define E2_2__ALARM_AL16_REFRESH_TIME_ON		EEPROM_ADDRESS(0x0002, 0x008)
#define E2_2__ALARM_AL16_REFRESH_TIME_OFF		EEPROM_ADDRESS(0x0002, 0x009)
#define E2_2__ALARM_AL17_REFRESH_TIME_ON		EEPROM_ADDRESS(0x0002, 0x00A)
#define E2_2__ALARM_AL17_REFRESH_TIME_OFF		EEPROM_ADDRESS(0x0002, 0x00B)
#define E2_2__ALARM_AL18_REFRESH_TIME_ON		EEPROM_ADDRESS(0x0002, 0x00C)
#define E2_2__ALARM_AL18_REFRESH_TIME_OFF		EEPROM_ADDRESS(0x0002, 0x00D)
#define E2_2__ALARM_AL19_REFRESH_TIME_ON		EEPROM_ADDRESS(0x0002, 0x00E)
#define E2_2__ALARM_AL19_REFRESH_TIME_OFF		EEPROM_ADDRESS(0x0002, 0x00F)
#define E2_2__ALARM_AL20_REFRESH_TIME_ON		EEPROM_ADDRESS(0x0002, 0x010)
#define E2_2__ALARM_AL20_REFRESH_TIME_OFF		EEPROM_ADDRESS(0x0002, 0x011)

/* Defines: Page 03 ----------------------------------------------------------*/
/* Tempi di Refresh dei Fault ------------------------------------------------*/
#define E2_3__ALARM_AL31_REFRESH_TIME_ON		EEPROM_ADDRESS(0x0003, 0x000)
#define E2_3__ALARM_AL31_REFRESH_TIME_OFF		EEPROM_ADDRESS(0x0003, 0x001)
#define E2_3__ALARM_AL32_REFRESH_TIME_ON		EEPROM_ADDRESS(0x0003, 0x002)
#define E2_3__ALARM_AL32_REFRESH_TIME_OFF		EEPROM_ADDRESS(0x0003, 0x003)
#define E2_3__ALARM_AL33_REFRESH_TIME_ON		EEPROM_ADDRESS(0x0003, 0x004)
#define E2_3__ALARM_AL33_REFRESH_TIME_OFF		EEPROM_ADDRESS(0x0003, 0x005)
#define E2_3__ALARM_AL34_REFRESH_TIME_ON		EEPROM_ADDRESS(0x0003, 0x006)
#define E2_3__ALARM_AL34_REFRESH_TIME_OFF		EEPROM_ADDRESS(0x0003, 0x007)
#define E2_3__ALARM_AL35_REFRESH_TIME_ON		EEPROM_ADDRESS(0x0003, 0x008)
#define E2_3__ALARM_AL35_REFRESH_TIME_OFF		EEPROM_ADDRESS(0x0003, 0x009)
#define E2_3__ALARM_AL36_REFRESH_TIME_ON		EEPROM_ADDRESS(0x0003, 0x00A)
#define E2_3__ALARM_AL36_REFRESH_TIME_OFF		EEPROM_ADDRESS(0x0003, 0x00B)
#define E2_3__ALARM_AL37_REFRESH_TIME_ON		EEPROM_ADDRESS(0x0003, 0x00C)
#define E2_3__ALARM_AL37_REFRESH_TIME_OFF		EEPROM_ADDRESS(0x0003, 0x00D)
#define E2_3__ALARM_AL40_REFRESH_TIME_ON		EEPROM_ADDRESS(0x0003, 0x00E)
#define E2_3__ALARM_AL40_REFRESH_TIME_OFF		EEPROM_ADDRESS(0x0003, 0x00F)
/* MSDC: Missing Secure Digital Card -----------------------------------------*/
#define E2_3__ALARM_MSDC_REFRESH_TIME_ON		EEPROM_ADDRESS(0x0003, 0x010)
#define E2_3__ALARM_MSDC_REFRESH_TIME_OFF		EEPROM_ADDRESS(0x0003, 0x011)

/* Defines: Page 04 ----------------------------------------------------------*/
/* Tempi di Refresh dei Fault ------------------------------------------------*/
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

/* Defines: Page 05 ----------------------------------------------------------*/
/* Parametri Communicazione Seriali ------------------------------------------*/
#define E2_5__CAN_1_IDENTIFIER           		EEPROM_ADDRESS(0x0005, 0x000)
#define E2_5__CAN_2_IDENTIFIER          		EEPROM_ADDRESS(0x0005, 0x001)
#define E2_5__CAN_1_BAUDRATE           			EEPROM_ADDRESS(0x0005, 0x002)
#define E2_5__CAN_2_BAUDRATE          			EEPROM_ADDRESS(0x0005, 0x003)

/* Defines: Page 06 ----------------------------------------------------------*/
/* Parametri Pulldown Mantenimento -------------------------------------------*/
#define E2_6__OUT_PRIORITY           			EEPROM_ADDRESS(0x0006, 0x000)
#define E2_6__OUT1_ENABLE           			EEPROM_ADDRESS(0x0006, 0x001)
#define E2_6__OUT2_ENABLE           			EEPROM_ADDRESS(0x0006, 0x002)

/* Defines: Page 07 ----------------------------------------------------------*/
/* Parametri Taratura --------------------------------------------------------*/
/* Typedef Struct definition -------------------------------------------------*/
/* Public Function definition ------------------------------------------------*/
void EEPROM_DEFINE_test(uint16_t * year1, uint16_t * year2, uint16_t * year3);

#endif /* INC_E2_PSA__H_ */
