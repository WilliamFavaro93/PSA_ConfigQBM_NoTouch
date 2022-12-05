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
/* Defines -------------------------------------------------------------------*/
#define E2_PAGE_0														0x0000
#define E2_PAGE_1														0x0020
#define E2_PAGE_2														0x0040
#define E2_PAGE_3														0x0060
#define E2_PAGE_4														0x0080
#define E2_PAGE_5														0x00A0
#define E2_PAGE_6														0x00C0
#define E2_PAGE_7														0x00E0
#define E2_PAGE_8														0x0100

/* Defines: Page 00 ----------------------------------------------------------*/
/* Informazioni generali -----------------------------------------------------*/
#define E2_0__NUMBER_RESTART								E2_PAGE_0 + 0x0000
#define E2_0__DEVICE_TYPE									E2_PAGE_0 + 0x0001

/*!< The version is described as A.B.C, where FIRMWARE_VERSION is A.B */
/*!< The version is described as A.B.C, where FIRMWARE_VERSION_FIX is C */
#define E2_0__FIRMWARE_VERSION								E2_PAGE_0 + 0x0002
#define E2_0__FIRMWARE_VERSION_FIX							E2_PAGE_0 + 0x0003

/*!< Date */
#define E2_0__DATE_YEAR										E2_PAGE_0 + 0x0004
#define E2_0__DATE_MONTH									E2_PAGE_0 + 0x0005
#define E2_0__DATE_DAY										E2_PAGE_0 + 0x0006

/*!<  */
#define E2_0__MACHINE_TYPE									E2_PAGE_0 + 0x0007
#define E2_0__NUMBER_MODULE									E2_PAGE_0 + 0x0008
#define E2_0__NUMBER_VALVEBLOCK     						E2_PAGE_0 + 0x0009

/* Defines: Page 01 ----------------------------------------------------------*/
/* Tempi di Lavoro dei Stati -------------------------------------------------*/
#define E2_1__TIME_STARTUP         							E2_PAGE_1 + 0x0000
#define E2_1__TIME_FIRST_ADSORPTION 						E2_PAGE_1 + 0x0001
#define E2_1__TIME_ADSORPTION_TIME      					E2_PAGE_1 + 0x0002
#define E2_1__TIME_COMPENSATION_0    						E2_PAGE_1 + 0x0003
#define E2_1__TIME_COMPENSATION_1    						E2_PAGE_1 + 0x0004
#define E2_1__TIME_COMPENSATION_2     						E2_PAGE_1 + 0x0005
#define E2_1__TIME_PRESTANDBY_1   							E2_PAGE_1 + 0x0006
#define E2_1__TIME_PRESTANDBY_2   							E2_PAGE_1 + 0x0007

/* Defines: Page 02 ----------------------------------------------------------*/
/* Tempi di Refresh dei Allarmi ----------------------------------------------*/
#define E2_2__ALARM_AL01_REFRESH_TIME_ON					E2_PAGE_2 + 0x0000
#define E2_2__ALARM_AL01_REFRESH_TIME_OFF					E2_PAGE_2 + 0x0001
#define E2_2__ALARM_AL02_REFRESH_TIME_ON					E2_PAGE_2 + 0x0002
#define E2_2__ALARM_AL02_REFRESH_TIME_OFF					E2_PAGE_2 + 0x0003
#define E2_2__ALARM_AL05_REFRESH_TIME_ON					E2_PAGE_2 + 0x0004
#define E2_2__ALARM_AL05_REFRESH_TIME_OFF					E2_PAGE_2 + 0x0005
#define E2_2__ALARM_AL11_REFRESH_TIME_ON					E2_PAGE_2 + 0x0006
#define E2_2__ALARM_AL11_REFRESH_TIME_OFF					E2_PAGE_2 + 0x0007
#define E2_2__ALARM_AL16_REFRESH_TIME_ON					E2_PAGE_2 + 0x0008
#define E2_2__ALARM_AL16_REFRESH_TIME_OFF					E2_PAGE_2 + 0x0009
#define E2_2__ALARM_AL17_REFRESH_TIME_ON					E2_PAGE_2 + 0x000A
#define E2_2__ALARM_AL17_REFRESH_TIME_OFF					E2_PAGE_2 + 0x000B
#define E2_2__ALARM_AL18_REFRESH_TIME_ON					E2_PAGE_2 + 0x000C
#define E2_2__ALARM_AL18_REFRESH_TIME_OFF					E2_PAGE_2 + 0x000D
#define E2_2__ALARM_AL19_REFRESH_TIME_ON					E2_PAGE_2 + 0x000E
#define E2_2__ALARM_AL19_REFRESH_TIME_OFF					E2_PAGE_2 + 0x000F
#define E2_2__ALARM_AL20_REFRESH_TIME_ON					E2_PAGE_2 + 0x0010
#define E2_2__ALARM_AL20_REFRESH_TIME_OFF					E2_PAGE_2 + 0x0011

/* Defines: Page 03 ----------------------------------------------------------*/
/* Tempi di Refresh dei Fault ------------------------------------------------*/
#define E2_3__ALARM_AL31_REFRESH_TIME_ON					E2_PAGE_3 + 0x0000
#define E2_3__ALARM_AL31_REFRESH_TIME_OFF					E2_PAGE_3 + 0x0001
#define E2_3__ALARM_AL32_REFRESH_TIME_ON					E2_PAGE_3 + 0x0002
#define E2_3__ALARM_AL32_REFRESH_TIME_OFF					E2_PAGE_3 + 0x0003
#define E2_3__ALARM_AL33_REFRESH_TIME_ON					E2_PAGE_3 + 0x0004
#define E2_3__ALARM_AL33_REFRESH_TIME_OFF					E2_PAGE_3 + 0x0005
#define E2_3__ALARM_AL34_REFRESH_TIME_ON					E2_PAGE_3 + 0x0006
#define E2_3__ALARM_AL34_REFRESH_TIME_OFF					E2_PAGE_3 + 0x0007
#define E2_3__ALARM_AL35_REFRESH_TIME_ON					E2_PAGE_3 + 0x0008
#define E2_3__ALARM_AL35_REFRESH_TIME_OFF					E2_PAGE_3 + 0x0009
#define E2_3__ALARM_AL36_REFRESH_TIME_ON					E2_PAGE_3 + 0x000A
#define E2_3__ALARM_AL36_REFRESH_TIME_OFF					E2_PAGE_3 + 0x000B
#define E2_3__ALARM_AL37_REFRESH_TIME_ON					E2_PAGE_3 + 0x000C
#define E2_3__ALARM_AL37_REFRESH_TIME_OFF					E2_PAGE_3 + 0x000D
#define E2_3__ALARM_AL40_REFRESH_TIME_ON					E2_PAGE_3 + 0x000E
#define E2_3__ALARM_AL40_REFRESH_TIME_OFF					E2_PAGE_3 + 0x000F
/* MSDC: Missing Secure Digital Card -----------------------------------------*/
#define E2_3__ALARM_MSDC_REFRESH_TIME_ON					E2_PAGE_3 + 0x0010
#define E2_3__ALARM_MSDC_REFRESH_TIME_OFF					E2_PAGE_3 + 0x0011

/* Defines: Page 04 ----------------------------------------------------------*/
/* Tempi di Refresh dei Fault ------------------------------------------------*/
#define E2_4__B1__LOWERTHRESHOLD     						E2_PAGE_4 + 0x0000
#define E2_4__B1__UPPERTHRESHOLD     						E2_PAGE_4 + 0x0001
#define E2_4__B1__LOWERLIMIT     							E2_PAGE_4 + 0x0002
#define E2_4__B1__UPPERLIMIT     							E2_PAGE_4 + 0x0003

#define E2_4__B2__LOWERTHRESHOLD     						E2_PAGE_4 + 0x0004
#define E2_4__B2__UPPERTHRESHOLD     						E2_PAGE_4 + 0x0005
#define E2_4__B2__LOWERLIMIT     							E2_PAGE_4 + 0x0006
#define E2_4__B2__UPPERLIMIT     							E2_PAGE_4 + 0x0007

#define E2_4__B3__LOWERTHRESHOLD     						E2_PAGE_4 + 0x0008
#define E2_4__B3__UPPERTHRESHOLD     						E2_PAGE_4 + 0x0009
#define E2_4__B3__LOWERLIMIT     							E2_PAGE_4 + 0x000A
#define E2_4__B3__UPPERLIMIT     							E2_PAGE_4 + 0x000B

#define E2_4__B4__LOWERTHRESHOLD     						E2_PAGE_4 + 0x000C
#define E2_4__B4__UPPERTHRESHOLD     						E2_PAGE_4 + 0x000D
#define E2_4__B4__LOWERLIMIT     							E2_PAGE_4 + 0x000E
#define E2_4__B4__UPPERLIMIT     							E2_PAGE_4 + 0x000F

#define E2_4__IFM_LOWERTHRESHOLD     						E2_PAGE_4 + 0x0010
#define E2_4__IFM_UPPERTHRESHOLD     						E2_PAGE_4 + 0x0011
#define E2_4__IFM_LOWERLIMIT     							E2_PAGE_4 + 0x0012
#define E2_4__IFM_UPPERLIMIT     							E2_PAGE_4 + 0x0013

#define E2_4__DEW_LOWERTHRESHOLD     						E2_PAGE_4 + 0x0014
#define E2_4__DEW_UPPERTHRESHOLD     						E2_PAGE_4 + 0x0015
#define E2_4__DEW_LOWERLIMIT     							E2_PAGE_4 + 0x0016
#define E2_4__DEW_UPPERLIMIT     							E2_PAGE_4 + 0x0017

#define E2_4__KE25_1_LOWERTHRESHOLD     					E2_PAGE_4 + 0x0018
#define E2_4__KE25_1_UPPERTHRESHOLD     					E2_PAGE_4 + 0x0019
#define E2_4__KE25_1_LOWERLIMIT     						E2_PAGE_4 + 0x001A
#define E2_4__KE25_1_UPPERLIMIT     						E2_PAGE_4 + 0x001B

#define E2_4__KE25_1_LOWERTHRESHOLD     					E2_PAGE_4 + 0x001C
#define E2_4__KE25_1_UPPERTHRESHOLD     					E2_PAGE_4 + 0x001D
#define E2_4__KE25_1_LOWERLIMIT     						E2_PAGE_4 + 0x001E
#define E2_4__KE25_1_UPPERLIMIT     						E2_PAGE_4 + 0x001F

/* Defines: Page 05 ----------------------------------------------------------*/
/* Parametri Communicazione Seriali ------------------------------------------*/
#define E2_5__CAN_1_IDENTIFIER           					E2_PAGE_5 + 0x0000
#define E2_5__CAN_2_IDENTIFIER          					E2_PAGE_5 + 0x0001
#define E2_5__CAN_1_BAUDRATE           						E2_PAGE_5 + 0x0002
#define E2_5__CAN_2_BAUDRATE          						E2_PAGE_5 + 0x0003

/* Defines: Page 06 ----------------------------------------------------------*/
/* Parametri Pulldown Mantenimento -------------------------------------------*/
#define E2_6__OUT_PRIORITY           						E2_PAGE_6 + 0x0000
#define E2_6__OUT1_ENABLE           						E2_PAGE_6 + 0x0001
#define E2_6__OUT2_ENABLE           						E2_PAGE_6 + 0x0002

/* Defines: Page 07 ----------------------------------------------------------*/
/* Parametri Taratura --------------------------------------------------------*/

/* Typedef Struct definition -------------------------------------------------*/
/* Public Function definition ------------------------------------------------*/

#endif /* INC_E2_PSA__H_ */
