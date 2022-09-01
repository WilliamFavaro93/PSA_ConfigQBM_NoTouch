/*
 * DateTime.c
 *
 *  Created on: 30 giu 2022
 *      Author: William.Favaro
 */

#include <datetime.h>
#include "string.h"

void DateTime_Update(DateTime* DateTime, uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, uint8_t seconds)
{
	DateTime->year = year;
	DateTime->month = month;
	DateTime->day = day;

	DateTime->hours = hours;
	DateTime->minutes = minutes;
	DateTime->seconds = seconds;
}

void DateTime_AddSecond(DateTime* DateTime)
{
	DateTime->seconds++;
	DateTime->seconds %= 60;
		if(DateTime->seconds == 0)
		{
			DateTime->minutes++;
			DateTime->minutes %= 60;
			if(DateTime->minutes == 0)
			{
				DateTime->hours++;
				DateTime->hours %= 24;
				if(DateTime->hours == 0)
				{
					DateTime->day++;
					if((DateTime->month == 1)||(DateTime->month == 3)||(DateTime->month == 5)||(DateTime->month == 7)||(DateTime->month == 8)||(DateTime->month == 10)||(DateTime->month == 12))
					{
						DateTime->day %= 31;
					}
					else if((DateTime->month == 4)||(DateTime->month == 6)||(DateTime->month == 9)||(DateTime->month == 11))
					{
						DateTime->day %= 30;
					}
					else
						DateTime->day %= 28;

					if(DateTime->day == 0)
					{
						DateTime->month++;
						DateTime->month %= 12;
						if(DateTime->month)
						{
							DateTime->year++;
						}
					}
				}
			}
		}
}

void DateTime_setDateString(DateTime* DateTime, char* separator)
{
	char yy[4];
	char mm[2]="00";
	char dd[2]="00";

	sprintf(yy, "%d", DateTime->year);
	if(DateTime->month > 9)
		sprintf(mm, "%d", DateTime->month);
	else
		sprintf(&mm[1], "%d", DateTime->month);
	if(DateTime->day > 9)
		sprintf(dd, "%d", DateTime->day);
	else
		sprintf(&dd[1], "%d", DateTime->day);
//	sprintf(dd, "%d", DateTime->day);

	if(separator == NULL)
	{
		DateTime->DateString[0] = yy[0];
		DateTime->DateString[1] = yy[1];
		DateTime->DateString[2] = yy[2];
		DateTime->DateString[3] = yy[3];

		DateTime->DateString[4] = mm[0];
		DateTime->DateString[5] = mm[1];

		DateTime->DateString[6] = dd[0];
		DateTime->DateString[7] = dd[1];
	}
	else
	{
		DateTime->DateString_wSeparator[0] = yy[0];
		DateTime->DateString_wSeparator[1] = yy[1];
		DateTime->DateString_wSeparator[2] = yy[2];
		DateTime->DateString_wSeparator[3] = yy[3];

		DateTime->DateString_wSeparator[4] = separator[0];

		DateTime->DateString_wSeparator[5] = mm[0];
		DateTime->DateString_wSeparator[6] = mm[1];

		DateTime->DateString_wSeparator[7] = separator[0];

		DateTime->DateString_wSeparator[8] = dd[0];
		DateTime->DateString_wSeparator[9] = dd[1];
	}
}

void DateTime_setTimeString(DateTime* DateTime, char* separator)
{
	char hh[2]="00";
	char mm[2]="00";
	char ss[2]="00";

	if(DateTime->hours > 9)
		sprintf(hh, "%d", DateTime->hours);
	else
		sprintf(&hh[1], "%d", DateTime->hours);
	if(DateTime->minutes > 9)
		sprintf(mm, "%d", DateTime->minutes);
	else
		sprintf(&mm[1], "%d", DateTime->minutes);
	if(DateTime->seconds > 9)
		sprintf(ss, "%d", DateTime->seconds);
	else
		sprintf(&ss[1], "%d", DateTime->seconds);
//	sprintf(dd, "%d", DateTime->day);

	if(separator == NULL)
	{
		DateTime->TimeString[0] = hh[0];
		DateTime->TimeString[1] = hh[1];

		DateTime->TimeString[2] = mm[0];
		DateTime->TimeString[3] = mm[1];

		DateTime->TimeString[4] = ss[0];
		DateTime->TimeString[5] = ss[1];
	}
	else
	{
		DateTime->TimeString_wSeparator[0] = hh[0];
		DateTime->TimeString_wSeparator[1] = hh[1];

		DateTime->TimeString_wSeparator[2] = separator[0];

		DateTime->TimeString_wSeparator[3] = mm[0];
		DateTime->TimeString_wSeparator[4] = mm[1];

		DateTime->TimeString_wSeparator[5] = separator[0];

		DateTime->TimeString_wSeparator[6] = ss[0];
		DateTime->TimeString_wSeparator[7] = ss[1];
	}
}
