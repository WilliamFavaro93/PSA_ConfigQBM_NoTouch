/**
  ******************************************************************************
  * @file   datetime.h
  * @author William Favaro
  * @date	13/07/2022
  * @brief  datetime structure definition
  *
  * 		This file defines the structure datetime that manage date and time
  *
  ******************************************************************************
  * @note
  *
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef INC_DATETIME_H_
#define INC_DATETIME_H_

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include "string.h"

/* Defines -------------------------------------------------------------------*/
/* Typedef struct definition -------------------------------------------------*/
/**
  * @brief  datetime structure definition
  */
typedef struct
{
	/* Date */
	uint16_t Year;						/**< year number 	*/
	uint8_t Month;						/**< month number	*/
	uint8_t Day;						/**< day number		*/

	/* Time */
	uint8_t Hours;						/**< hour number	*/
	uint8_t Minutes;					/**< minute number	*/
	uint8_t Seconds;					/**< second number	*/

	uint8_t Deciseconds;				/**< decisecond number	*/

	uint8_t DailyLight;					/**< define if it's daily light	*/
	uint8_t Enable;						/**< define if it's enable */

	char DateString[9];					/**< array of char that identifies the date.
										Example: "20220829" 							*/
	char DateString_withSeparator[12];		/**< array of char that identifies the date.
										Example: "2022/08/29" where '/' is the separator*/
	char TimeString[7];					/**< array of char that identifies the time.
										Example: "102300"  								*/
	char TimeString_withSeparator[10];		/**< array of char that identifies the date.
										Example: "10:23:00" where ':' is the separator	*/
} DateTime;

/* Public Function definition ------------------------------------------------*/
void DATETIME_Init(uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, uint8_t seconds);
void DATETIME_AddSecond();
void DATETIME_AddDeciSecond();
uint16_t DATETIME_GetYear();
uint8_t DATETIME_GetMonth();
uint8_t DATETIME_GetDay();
uint8_t DATETIME_GetHours();
uint8_t DATETIME_GetMinutes();
uint8_t DATETIME_GetSeconds();
uint8_t DATETIME_GetDeciseconds();
uint8_t DATETIME_GetDailyLight();
uint8_t DATETIME_GetEnable();
void DATETIME_MemcpyDateString(char * PointerToStringToCopy, uint16_t StringToCopy_length);
void DATETIME_MemcpyDateString_withSeparator(char * PointerToStringToCopy, uint16_t StringToCopy_length);
void DATETIME_MemcpyTimeString(char * PointerToStringToCopy, uint16_t StringToCopy_length);
void DATETIME_MemcpyTimeString_withSeparator(char * PointerToStringToCopy, uint16_t StringToCopy_length);

/* Public Automated Testing Function -----------------------------------------*/
#ifdef DEBUG
void DATETIME_test_all();
#endif /* DEBUG */
#endif /* INC_DATETIME_H_ */
