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

/* Includes ------------------------------------------------------------------*/
#include <datetime.h>
#include <stdio.h>
/* Defines -------------------------------------------------------------------*/

/* Variables -----------------------------------------------------------------*/
DateTime today;

/* Private Function definition -----------------------------------------------*/

void DateTime_setDateString();
void DateTime_setDateString_withSeparator();
void DateTime_setTimeString();
void DateTime_setTimeString_withSeparator();
void DateTime_AddSecond();


/* Public Function -----------------------------------------------------------*/
void ConvertNumberIntoString(uint16_t number, char * pointerToCharArray, uint8_t CharArray_length)
{
	for(uint8_t i = 0; i <= CharArray_length; i++)
	{
		pointerToCharArray[i] = '0';
	}

	uint8_t i = 0;
	/* while(n): n=0 when number is copied or i = CharArrayLength */
	while(!((number == 0) || (i == CharArray_length)))
	{
		uint8_t remainder = number % 10;
		pointerToCharArray[CharArray_length - i - 1] = remainder + '0';

		number /= 10;
		i++;
	}
}

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
	today.Enable = 1;

	today.year = year;
	today.month = month;
	today.day = day;

	today.hours = hours;
	today.minutes = minutes;
	today.seconds = seconds;

	if((today.month > 3) && (today.day > 27) && (today.hours > 2))
	{
		if((today.month < 10) && (today.day < 30) && (today.hours < 3))
			today.DailyLight = 0;
		else
			today.DailyLight = 1;
	}

	DateTime_setDateString();
	DateTime_setDateString_withSeparator("/");
	DateTime_setTimeString();
	DateTime_setTimeString_withSeparator(":");
}

/*
 * @brief This method is used to update the structure as if a decisecond had passed
 * @author William Favaro
 * @date 05/08/2022
 */
void DateTime_AddDeciSecond()
{
	if(!today.Enable)
		return;

	today.deciseconds++;
	today.deciseconds %= 10;
	if(today.deciseconds == 0)
		DateTime_AddSecond();
}

/* Private Function ----------------------------------------------------------*/
/*
 * @brief This method is used to update the structure as if a second had passed
 * @author William Favaro
 * @date 05/08/2022
 */
void DateTime_AddSecond()
{
	if(!today.Enable)
		return;

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
				else if((today.year % 4))
				{
					today.day %= (28+1);
				}
				else
					today.day %= (29+1);

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
				DateTime_setDateString();
				DateTime_setDateString_withSeparator("/");
			}
		}
	}
	/* 27 marzo, 2:00, no daylight -> -1h, daylight */
	if((today.month == 3)&&(today.day == 27)&&(today.hours == 3)&&(!today.DailyLight))
	{
		today.DailyLight = 1;
		today.hours = 2;
	}

	/* 30 ottobre, 3:00, daylight -> +1h, no daylight */
	if((today.month == 3)&&(today.day == 27)&&(today.hours == 2)&&(today.DailyLight))
	{
		today.DailyLight = 0;
		today.hours = 3;
	}

	DateTime_setTimeString();
	DateTime_setTimeString_withSeparator(":");
}

/*
 * @brief This method update today.DateString or today.DateString_wSeparator
 * @author William Favaro
 * @date 05/08/2022
 * @note pass NULL as a parameter to modify today.DateString
 */
void DateTime_setDateString()
{
	if(!today.Enable)
		return;

	ConvertNumberIntoString(today.year, &today.DateString[0], 4);
	ConvertNumberIntoString(today.month, &today.DateString[4], 2);
	ConvertNumberIntoString(today.day, &today.DateString[6], 2);
}

/*
 * @brief This method update today.DateString or today.DateString_wSeparator
 * @author William Favaro
 * @date 05/08/2022
 * @note pass NULL as a parameter to modify today.DateString
 */
void DateTime_setDateString_withSeparator(char* separator)
{
	if(!today.Enable)
		return;

	ConvertNumberIntoString(today.year, &today.DateString_withSeparator[0], 4);
	today.DateString_withSeparator[4] = separator[0];
	ConvertNumberIntoString(today.month, &today.DateString_withSeparator[5], 2);
	today.DateString_withSeparator[7] = separator[0];
	ConvertNumberIntoString(today.day, &today.DateString_withSeparator[8], 2);
}

/*
 * @brief This method update today.TimeString or today.TimeString_wSeparator
 * @author William Favaro
 * @date 05/08/2022
 * @note pass NULL as a parameter to modify today.TimeString
 */
void DateTime_setTimeString()
{
	if(!today.Enable)
		return;

	ConvertNumberIntoString(today.hours, &today.TimeString[0], 2);
	ConvertNumberIntoString(today.minutes, &today.TimeString[2], 2);
	ConvertNumberIntoString(today.seconds, &today.TimeString[4], 2);
}

/*
 * @brief This method update today.TimeString or today.TimeString_wSeparator
 * @author William Favaro
 * @date 05/08/2022
 * @note pass NULL as a parameter to modify today.TimeString
 */
void DateTime_setTimeString_withSeparator(char* separator)
{
	if(!today.Enable)
		return;

	ConvertNumberIntoString(today.hours, &today.TimeString_withSeparator[0], 2);
	today.TimeString_withSeparator[2] = separator[0];
	ConvertNumberIntoString(today.minutes, &today.TimeString_withSeparator[3], 2);
	today.TimeString_withSeparator[5] = separator[0];
	ConvertNumberIntoString(today.seconds, &today.TimeString_withSeparator[6], 2);
}

/* Private Function ----------------------------------------------------------*/
/* End of the file -----------------------------------------------------------*/
