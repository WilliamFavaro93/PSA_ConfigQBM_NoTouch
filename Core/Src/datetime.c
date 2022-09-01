/**
  ******************************************************************************
  * @file   datetime.c
  * @author William Favaro
  * @date	13/07/2022
  * @brief  datetime functions
  *
  * 		This module is created to simplify the memorization of the time
  *
  ******************************************************************************
  * @note
  *
  *
  *
  ******************************************************************************
  */

#include <datetime.h>

#define DATETIME_AUTEST 1

/* global-static variable */
DateTime today;
DateTime today_LastUpdate;

/*** PRIVATE METHODs ***/
void DateTime_setDateString(char* separator);
void DateTime_setTimeString(char* separator);


/*** PUBLIC METHODs ***/
/*
 * @brief This method is used to initialize or update the char[] of the DateTime
 * @author William Favaro
 * @date 05/08/2022
 * @param year The number that identifies the year
 * @param month The number that identifies the month
 * @param day The number that identifies the day
 * @param hours The number that identifies the hours
 * @param minutes The number that identifies the minutes
 * @param seconds The number that identifies the seconds
 */
void DateTime_Init(uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, uint8_t seconds)
{
	today.year = year;
	today.month = month;
	today.day = day;

	today.hours = hours;
	today.minutes = minutes;
	today.seconds = seconds;

	/* Update the datetime today_LastUpdate*/
	memcpy(&today_LastUpdate, &today, sizeof(DateTime));
}

/*
 * @brief This method is used to update the char[] of the DateTime
 * @author William Favaro
 * @date 05/08/2022
 * @note you should use it after the update of DateTime_Init() or DateTime_AddSecond()
 */
void DateTime_UpdateString()
{
	DateTime_setDateString(NULL);
	DateTime_setDateString("/");
	DateTime_setTimeString(NULL);
	DateTime_setTimeString(":");
}

/*
 * @brief This method is used to update the structure as if a second had passed
 * @author William Favaro
 * @date 05/08/2022
 */
void DateTime_AddSecond()
{
	today.seconds++;
	today.seconds %= 60;
		if(today.seconds == 0)
		{
			today.minutes++;
			today.minutes %= 60;
			if(today.minutes == 0)
			{
				today.hours++;
				today.hours %= 24;
				if(today.hours == 0)
				{
					today.day++;
					if((today.month == 1)||(today.month == 3)||(today.month == 5)||(today.month == 7)||(today.month == 8)||(today.month == 10)||(today.month == 12))
					{
						today.day %= (31+1);
					}
					else if((today.month == 4)||(today.month == 6)||(today.month == 9)||(today.month == 11))
					{
						today.day %= (30+1);
					}
					else
						today.day %= (28+1);

					if(today.day == 0)
					{
						today.day++; /* The day start with 1 instead of 0 */
						today.month++;
						today.month %= (12+1);
						if(today.month == 0)
						{
							today.month++; /* The month start with 1 instead of 0 */
							today.year++;
						}
					}
				}
			}
		}
}

/*
 * @brief This method return if it's a new day from last time that was used this method or DateTime_Init
 * @author William Favaro
 * @date 05/08/2022
 */
uint8_t DateTime_ItsaNewDay()
{
	int8_t result = 0;
	/* Compare if it is a new day */
	if((today.day > today_LastUpdate.day)||(today.month > today_LastUpdate.month)||(today.year > today_LastUpdate.year))
	{
		result = 1;
	}
	/* Update the datetime today_LastUpdate*/
	memcpy(&today_LastUpdate, &today, sizeof(DateTime));
	/* return the result */
	return result;
}

/*** PRIVATE METHODs ***/
/*
 * @brief This method update today.DateString or today.DateString_wSeparator
 * @author William Favaro
 * @date 05/08/2022
 * @note pass NULL as a parameter to modify today.DateString
 */
void DateTime_setDateString(char* separator)
{
	char yy[4];
	char mm[2]="00";
	char dd[2]="00";

	sprintf(yy, "%d", today.year);
	if(today.month > 9)
		sprintf(mm, "%d", today.month);
	else
		sprintf(&mm[1], "%d", today.month);
	if(today.day > 9)
		sprintf(dd, "%d", today.day);
	else
		sprintf(&dd[1], "%d", today.day);

	if(separator == NULL)
	{
		today.DateString[0] = yy[0];
		today.DateString[1] = yy[1];
		today.DateString[2] = yy[2];
		today.DateString[3] = yy[3];

		today.DateString[4] = mm[0];
		today.DateString[5] = mm[1];

		today.DateString[6] = dd[0];
		today.DateString[7] = dd[1];
	}
	else
	{
		today.DateString_withSeparator[0] = yy[0];
		today.DateString_withSeparator[1] = yy[1];
		today.DateString_withSeparator[2] = yy[2];
		today.DateString_withSeparator[3] = yy[3];

		today.DateString_withSeparator[4] = separator[0];

		today.DateString_withSeparator[5] = mm[0];
		today.DateString_withSeparator[6] = mm[1];

		today.DateString_withSeparator[7] = separator[0];

		today.DateString_withSeparator[8] = dd[0];
		today.DateString_withSeparator[9] = dd[1];
	}
}

/*
 * @brief This method update today.TimeString or today.TimeString_wSeparator
 * @author William Favaro
 * @date 05/08/2022
 * @note pass NULL as a parameter to modify today.TimeString
 */
void DateTime_setTimeString(char* separator)
{
	char hh[2]="00";
	char mm[2]="00";
	char ss[2]="00";

	if(today.hours > 9)
		sprintf(hh, "%d", today.hours);
	else
		sprintf(&hh[1], "%d", today.hours);
	if(today.minutes > 9)
		sprintf(mm, "%d", today.minutes);
	else
		sprintf(&mm[1], "%d", today.minutes);
	if(today.seconds > 9)
		sprintf(ss, "%d", today.seconds);
	else
		sprintf(&ss[1], "%d", today.seconds);
//	sprintf(dd, "%d", today->day);

	if(separator == NULL)
	{
		today.TimeString[0] = hh[0];
		today.TimeString[1] = hh[1];

		today.TimeString[2] = mm[0];
		today.TimeString[3] = mm[1];

		today.TimeString[4] = ss[0];
		today.TimeString[5] = ss[1];
	}
	else
	{
		today.TimeString_withSeparator[0] = hh[0];
		today.TimeString_withSeparator[1] = hh[1];

		today.TimeString_withSeparator[2] = separator[0];

		today.TimeString_withSeparator[3] = mm[0];
		today.TimeString_withSeparator[4] = mm[1];

		today.TimeString_withSeparator[5] = separator[0];

		today.TimeString_withSeparator[6] = ss[0];
		today.TimeString_withSeparator[7] = ss[1];
	}
}

/*** UNIT TEST ***/
#define DATETIME_AUTEST 1
#if DATETIME_AUTEST

uint8_t DateTime_test_AddSecond()
{
	uint8_t error = 0x01;
	DateTime_Init(2022, 8, 5, 11, 37, 0);
	DateTime_UpdateString();
	if(strcmp(&today.TimeString, "113700") != 0)
		return error;

	DateTime_AddSecond();
	DateTime_UpdateString();
	if(strcmp(&today.TimeString, "113701") != 0)
		return error;

	return 0;
}

uint8_t DateTime_test_NewDay()
{
	uint8_t error = 0x01;
	DateTime_Init(2021, 12, 31, 23, 59, 59);
	DateTime_ItsaNewDay();
	DateTime_AddSecond();
	DateTime_UpdateString();
	if(strcmp(&today.TimeString, "000000") != 0)
		return error;
	if(strcmp(&today.TimeString, "20220101") != 0)
		return error;

	return 0;
}

uint8_t DateTime_test_NewYear()
{
	uint8_t error = 0x01;
	DateTime_Init(2021, 12, 31, 23, 59, 59);
	DateTime_AddSecond();
	DateTime_UpdateString();
	if(strcmp(&today.TimeString, "000000") != 0)
		return error;
	if(strcmp(&today.DateString, "20220101") != 0)
		return error;

	return 0;
}

uint8_t DateTime_test_UpdateString()
{

}

#endif /* DATETIME_AUTEST */

/*
 * @brief This method is used to test if the module works as wanted. If the return is 0, the test result is passed.
 * @author William Favaro
 * @date 05/08/2022
 */
uint8_t DateTime_test_all()
{
#if DATETIME_AUTEST
	uint8_t error;

	error = DateTime_test_AddSecond() * 0x01;
	error = DateTime_test_NewDay() * 0x02;
	error = DateTime_test_NewYear() * 0x04;

	if(error)
		return error;
#endif /* DATETIME_UTEST */
	return 0;
}

/*********************************** EOF **************************************/
