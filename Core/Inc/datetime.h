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
	uint16_t year;						/**< year number 	*/
	uint8_t month;						/**< month number	*/
	uint8_t day;						/**< day number		*/

	/* Time */
	uint8_t hours;						/**< hour number	*/
	uint8_t minutes;					/**< minute number	*/
	uint8_t seconds;					/**< second number	*/

	uint8_t deciseconds;				/**< decisecond number	*/

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
void DateTime_Init(uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, uint8_t seconds);
//void DateTime_Update(DateTime* DateTime, uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, uint8_t seconds);
void DateTime_AddSecond();
void DateTime_AddDeciSecond();
void ConvertNumberIntoString(uint16_t number, char * pointerToCharArray, uint8_t CharArray_length);
//void DateTime_setDateString();
//void DateTime_setDateString_withSeparator(char* separator);
//void DateTime_setTimeString();
//void DateTime_setTimeString_withSeparator(char* separator);
//uint8_t DateTime_ItsaNewDay();
/* Public Automated Testing Function -----------------------------------------*/
#ifdef DEBUG
void DateTime_test_all();
#endif /* DEBUG */
#endif /* INC_DATETIME_H_ */
