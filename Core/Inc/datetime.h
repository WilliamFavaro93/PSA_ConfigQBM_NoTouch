/*
 * DateTime.h
 *
 *  Created on: 30 giu 2022
 *      Author: William.Favaro
 */

#ifndef INC_DATETIME_H_
#define INC_DATETIME_H_

#include "stdint.h"

typedef struct
{
	/* Date */
	uint16_t year;
	uint8_t month;
	uint8_t day;

	/* Time */
	uint8_t hours;
	uint8_t minutes;
	uint8_t seconds;

	char DateString[9];
	char DateString_wSeparator[12];

	char TimeString[7];
	char TimeString_wSeparator[9];
} DateTime;

void DateTime_Update(DateTime* DateTime, uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, uint8_t seconds);
void DateTime_AddSecond(DateTime* DateTime);
void DateTime_setDateString(DateTime* DateTime, char* separator);
void DateTime_setTimeString(DateTime* DateTime, char* separator);

/*
 * 	DateTime_Update(&today, 2022, 07, 11, 10, 25, 00);
	DateTime_setDateString(&today, NULL); // today.DateString = "20220711"
	DateTime_setDateString(&today, "/"); // today.DateString_wSeparator = "2022/07/11"
 */

#endif /* INC_DATETIME_H_ */
