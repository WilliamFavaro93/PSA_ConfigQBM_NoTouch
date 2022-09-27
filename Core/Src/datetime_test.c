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


/* Includes ------------------------------------------------------------------*/
#include <datetime.h>
#include <stdio.h>
/* Defines -------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
extern DateTime today;
extern DateTime today_LastUpdate;
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
void DateTime_test_all()
{
	DateTime_test_AddSecond();
	DateTime_test_NewDay();
	DateTime_test_NewYear();
	DateTime_test_its29february();
}
/* Private Function ----------------------------------------------------------*/
/*
 * @brief
 * @author William Favaro
 * @date 05/08/2022
 */
void DateTime_test_AddSecond()
{
	DateTime_Init(2022, 8, 5, 11, 37, 0);
	DateTime_UpdateString();
	while(strcmp(&today.TimeString, "113700")){}

	DateTime_AddSecond();
	DateTime_UpdateString();
	while(strcmp(&today.TimeString, "113701")){}
}

/*
 * @brief
 * @author William Favaro
 * @date 05/08/2022
 */
void DateTime_test_NewDay()
{
	DateTime_Init(2021, 12, 31, 23, 59, 59);
	while(DateTime_ItsaNewDay()){}
	DateTime_AddSecond();
	while(!DateTime_ItsaNewDay()){}
	DateTime_UpdateString();
	while(strcmp(&today.TimeString, "000000")){}
	while(strcmp(&today.DateString, "20220101")){}
}

/*
 * @brief
 * @author William Favaro
 * @date 05/08/2022
 */
void DateTime_test_NewYear()
{

	DateTime_Init(2021, 12, 31, 23, 59, 59);
	DateTime_AddSecond();
	DateTime_UpdateString();
	while(strcmp(&today.TimeString, "000000")){}
	while(strcmp(&today.DateString, "20220101")){}
}

/*
 * @brief
 * @author William Favaro
 * @date 05/08/2022
 */
void DateTime_test_its29february()
{
	DateTime_Init(2020, 2, 28, 23, 59, 59);
	DateTime_AddSecond();
	DateTime_UpdateString();
	while(strcmp(&today.DateString, "20200229")){}
}

/* End of the file -----------------------------------------------------------*/
