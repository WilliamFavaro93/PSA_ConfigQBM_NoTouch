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

/* Defines -------------------------------------------------------------------*/

/* Variables -----------------------------------------------------------------*/
static DateTime datetime;

/* Private Function definition -----------------------------------------------*/
void DATETIME_ConvertUnsignedNumberIntoString(uint16_t number, char * pointerToCharArray, uint8_t CharArray_length);
void DATETIME_SetDateString();
void DATETIME_SetDateString_withSeparator();
void DATETIME_SetTimeString();
void DATETIME_SetTimeString_withSeparator();
void DATETIME_AddSecond();

/* Public Function -----------------------------------------------------------*/
uint16_t DATETIME_GetYear()
{
	return datetime.Year;
}

uint8_t DATETIME_GetMonth()
{
	return datetime.Month;
}

uint8_t DATETIME_GetDay()
{
	return datetime.Day;
}

uint8_t DATETIME_GetHours()
{
	return datetime.Hours;
}

uint8_t DATETIME_GetMinutes()
{
	return datetime.Minutes;
}

uint8_t DATETIME_GetSeconds()
{
	return datetime.Seconds;
}

uint8_t DATETIME_GetDeciseconds()
{
	return datetime.Deciseconds;
}

uint8_t DATETIME_GetDailyLight()
{
	return datetime.DailyLight;
}

uint8_t DATETIME_GetEnable()
{
	return datetime.Enable;
}

void DATETIME_MemcpyGetDateString(char * PointerToStringToCopy, uint16_t StringToCopy_Length)
{
	uint8_t CopiedString_Length = 8;

	if(StringToCopy_Length < CopiedString_Length)
		memcpy(PointerToStringToCopy, &datetime.DateString, StringToCopy_Length);
	else
		memcpy(PointerToStringToCopy, &datetime.DateString, CopiedString_Length);
}

void DATETIME_MemcpyGetDateString_withSeparator(char * PointerToStringToCopy, uint16_t StringToCopy_Length)
{
	uint8_t CopiedString_Length = 10;

	if(StringToCopy_Length < CopiedString_Length)
		memcpy(PointerToStringToCopy, &datetime.DateString_withSeparator, StringToCopy_Length);
	else
		memcpy(PointerToStringToCopy, &datetime.DateString_withSeparator, CopiedString_Length);
}

void DATETIME_MemcpyGetTimeString(char * PointerToStringToCopy, uint16_t StringToCopy_Length)
{
	uint8_t CopiedString_Length = 6;

	if(StringToCopy_Length < CopiedString_Length)
		memcpy(PointerToStringToCopy, &datetime.TimeString, StringToCopy_Length);
	else
		memcpy(PointerToStringToCopy, &datetime.TimeString, CopiedString_Length);
}

void DATETIME_MemcpyGetTimeString_withSeparator(char * PointerToStringToCopy, uint16_t StringToCopy_Length)
{
	uint8_t CopiedString_Length = 8;

	if(StringToCopy_Length < CopiedString_Length)
		memcpy(PointerToStringToCopy, &datetime.TimeString_withSeparator, StringToCopy_Length);
	else
		memcpy(PointerToStringToCopy, &datetime.TimeString_withSeparator, CopiedString_Length);
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
void DATETIME_Init(uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, uint8_t seconds)
{
	datetime.Enable = 1;

	datetime.Year = year;
	datetime.Month = month;
	datetime.Day = day;

	datetime.Hours = hours;
	datetime.Minutes = minutes;
	datetime.Seconds = seconds;

	if((datetime.Month > 3) && (datetime.Day > 27) && (datetime.Hours > 2))
	{
		if((datetime.Month < 10) && (datetime.Day < 30) && (datetime.Hours < 3))
			datetime.DailyLight = 0;
		else
			datetime.DailyLight = 1;
	}

	DATETIME_SetDateString();
	DATETIME_SetDateString_withSeparator("/");
	DATETIME_SetTimeString();
	DATETIME_SetTimeString_withSeparator(":");
}

/*
 * @brief This method is used to update the structure as if a decisecond had passed
 * @author William Favaro
 * @date 05/08/2022
 */
void DATETIME_AddDeciSecond()
{
	if(!datetime.Enable)
		return;

	datetime.Deciseconds++;
	datetime.Deciseconds %= 10;
	if(datetime.Deciseconds == 0)
		DATETIME_AddSecond();
}

/* Private Function ----------------------------------------------------------*/
/*
 * @brief This method is used to update the structure as if a second had passed
 * @author William Favaro
 * @date 05/08/2022
 */
void DATETIME_AddSecond()
{
	if(!datetime.Enable)
		return;

	datetime.Seconds++;
	datetime.Seconds %= 60;
	if(datetime.Seconds == 0)
	{
		datetime.Minutes++;
		datetime.Minutes %= 60;
		if(datetime.Minutes == 0)
		{
			datetime.Hours++;
			datetime.Hours %= 24;
			if(datetime.Hours == 0)
			{
				datetime.Day++;
				if((datetime.Month == 1)||(datetime.Month == 3)||(datetime.Month == 5)||(datetime.Month == 7)||(datetime.Month == 8)||(datetime.Month == 10)||(datetime.Month == 12))
				{
					datetime.Day %= (31+1);
				}
				else if((datetime.Month == 4)||(datetime.Month == 6)||(datetime.Month == 9)||(datetime.Month == 11))
				{
					datetime.Day %= (30+1);
				}
				else if((datetime.Year % 4))
				{
					datetime.Day %= (28+1);
				}
				else
					datetime.Day %= (29+1);

				if(datetime.Day == 0)
				{
					datetime.Day++; /* The day start with 1 instead of 0 */
					datetime.Month++;
					datetime.Month %= (12+1);
					if(datetime.Month == 0)
					{
						datetime.Month++; /* The month start with 1 instead of 0 */
						datetime.Year++;
					}
				}
				DATETIME_SetDateString();
				DATETIME_SetDateString_withSeparator("/");
			}
		}
	}
	/* 27 marzo, 2:00, no daylight -> -1h, daylight */
	if((datetime.Month == 3)&&(datetime.Day == 27)&&(datetime.Hours == 3)&&(!datetime.DailyLight))
	{
		datetime.DailyLight = 1;
		datetime.Hours = 2;
	}

	/* 30 ottobre, 3:00, daylight -> +1h, no daylight */
	if((datetime.Month == 3)&&(datetime.Day == 27)&&(datetime.Hours == 2)&&(datetime.DailyLight))
	{
		datetime.DailyLight = 0;
		datetime.Hours = 3;
	}

	DATETIME_SetTimeString();
	DATETIME_SetTimeString_withSeparator(":");
}

/*
 * @brief This method is used to convert a unsigned number into string
 * @author William Favaro
 * @date 05/08/2022
 */
void DATETIME_ConvertUnsignedNumberIntoString(uint16_t number, char * pointerToCharArray, uint8_t CharArray_length)
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
 * @brief This method update today.DateString or today.DateString_wSeparator
 * @author William Favaro
 * @date 05/08/2022
 * @note pass NULL as a parameter to modify today.DateString
 */
void DATETIME_SetDateString()
{
	if(!datetime.Enable)
		return;

	DATETIME_ConvertUnsignedNumberIntoString(datetime.Year, &datetime.DateString[0], 4);
	DATETIME_ConvertUnsignedNumberIntoString(datetime.Month, &datetime.DateString[4], 2);
	DATETIME_ConvertUnsignedNumberIntoString(datetime.Day, &datetime.DateString[6], 2);
}

/*
 * @brief This method update today.DateString or today.DateString_wSeparator
 * @author William Favaro
 * @date 05/08/2022
 * @note pass NULL as a parameter to modify today.DateString
 */
void DATETIME_SetDateString_withSeparator(char* separator)
{
	if(!datetime.Enable)
		return;

	DATETIME_ConvertUnsignedNumberIntoString(datetime.Year, &datetime.DateString_withSeparator[0], 4);
	datetime.DateString_withSeparator[4] = separator[0];
	DATETIME_ConvertUnsignedNumberIntoString(datetime.Month, &datetime.DateString_withSeparator[5], 2);
	datetime.DateString_withSeparator[7] = separator[0];
	DATETIME_ConvertUnsignedNumberIntoString(datetime.Day, &datetime.DateString_withSeparator[8], 2);
}

/*
 * @brief This method update today.TimeString or today.TimeString_wSeparator
 * @author William Favaro
 * @date 05/08/2022
 * @note pass NULL as a parameter to modify today.TimeString
 */
void DATETIME_SetTimeString()
{
	if(!datetime.Enable)
		return;

	DATETIME_ConvertUnsignedNumberIntoString(datetime.Hours, &datetime.TimeString[0], 2);
	DATETIME_ConvertUnsignedNumberIntoString(datetime.Minutes, &datetime.TimeString[2], 2);
	DATETIME_ConvertUnsignedNumberIntoString(datetime.Seconds, &datetime.TimeString[4], 2);
}

/*
 * @brief This method update today.TimeString or today.TimeString_wSeparator
 * @author William Favaro
 * @date 05/08/2022
 * @note pass NULL as a parameter to modify today.TimeString
 */
void DATETIME_SetTimeString_withSeparator(char* separator)
{
	if(!datetime.Enable)
		return;

	DATETIME_ConvertUnsignedNumberIntoString(datetime.Hours, &datetime.TimeString_withSeparator[0], 2);
	datetime.TimeString_withSeparator[2] = separator[0];
	DATETIME_ConvertUnsignedNumberIntoString(datetime.Minutes, &datetime.TimeString_withSeparator[3], 2);
	datetime.TimeString_withSeparator[5] = separator[0];
	DATETIME_ConvertUnsignedNumberIntoString(datetime.Seconds, &datetime.TimeString_withSeparator[6], 2);
}

/* Private Function ----------------------------------------------------------*/
/* End of the file -----------------------------------------------------------*/
