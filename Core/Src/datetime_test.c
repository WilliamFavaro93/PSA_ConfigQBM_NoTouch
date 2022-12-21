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

#ifdef DEBUG
/* Includes ------------------------------------------------------------------*/
#include <datetime.h>
#include <stdio.h>
/* Defines -------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
extern DateTime datetime;
/* Private Function definition -----------------------------------------------*/
void DateTime_test_AddSecond();
void DateTime_test_NewDay();
void DateTime_test_NewYear();
void DateTime_test_its29february();
/* Public Function -----------------------------------------------------------*/
/*
 * @brief
 * @author William Favaro
 * @date 05/08/2022
 */
void DATETIME_test_all()
{
	DateTime_test_AddSecond();
	DateTime_test_NewDay();
	DateTime_test_NewYear();
	DateTime_test_its29february();
}
/* Private Function ----------------------------------------------------------*/
uint8_t CompareStrings(char * string1, char * string2, uint8_t numberElementsToCompare)
{
	uint8_t i = 0;
	while(!(i == numberElementsToCompare))
	{
		if(string1[i] != string2[i])
			return 1;
		i++;
	}

	return 0;
}
/*
 * @brief
 * @author William Favaro
 * @date 05/08/2022
 */
void DateTime_test_AddSecond()
{
	DATETIME_Init(2022, 8, 5, 11, 37, 0);
	while(CompareStrings((char *)datetime.TimeString, "113700", 6)){}

	DATETIME_AddSecond();
	while(CompareStrings((char *)datetime.TimeString, "113701", 6)){}

	for(uint8_t i = 0; i < 10; i++)
	{
		DATETIME_AddDeciSecond();
	}

	while(CompareStrings((char *)datetime.TimeString, "113702", 6)){}
}

/*
 * @brief
 * @author William Favaro
 * @date 05/08/2022
 */
void DateTime_test_NewDay()
{
	DATETIME_Init(2021, 12, 31, 23, 59, 59);
	DATETIME_AddSecond();
	while(CompareStrings((char *)datetime.TimeString, "000000", 6)){}
}

/*
 * @brief
 * @author William Favaro
 * @date 05/08/2022
 */
void DateTime_test_NewYear()
{

	DATETIME_Init(2021, 12, 31, 23, 59, 59);
	DATETIME_AddSecond();
	while(CompareStrings((char *)datetime.TimeString_withSeparator, "00:00:00", 8)){}
	while(CompareStrings((char *)datetime.DateString_withSeparator, "2022/01/01", 10)){}
}

/*
 * @brief
 * @author William Favaro
 * @date 05/08/2022
 */
void DateTime_test_its29february()
{
	DATETIME_Init(2020, 2, 28, 23, 59, 59);
	DATETIME_AddSecond();
	while(CompareStrings((char *)datetime.DateString, "20200229", 8)){}
}
#endif /* DEBUG */
/* End of the file -----------------------------------------------------------*/
