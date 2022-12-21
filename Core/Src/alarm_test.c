/**
  ******************************************************************************
  * @file	alarm_test.c
  * @author Willam.Favaro
  * @date	2022/09/27
  * @brief	test alarm library
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
#include "alarm.h"
/* Defines -------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
Alarm alatest;

/* Private Function definition -----------------------------------------------*/
void Alarm_test_Triggered();
void Alarm_test_FromTriggeredToNoTriggered();
void Alarm_test_DisabledAlarm_AlarmMustNotTrigger();
void Alarm_test_ConditionKeepsChanging();

/* Public Function -----------------------------------------------------------*/
void ALARM_test_all()
{
	Alarm_test_Triggered();
	Alarm_test_FromTriggeredToNoTriggered();
	Alarm_test_DisabledAlarm_AlarmMustNotTrigger();
	Alarm_test_ConditionKeepsChanging();
}
/* Private Function ----------------------------------------------------------*/
/*
 * @brief This method test normal usage of CheckCondition
 * @author William Favaro
 * @date 15/09/2022
 */
void Alarm_test_Triggered()
{
	ALARM_Init(&alatest, 5, 5);

	uint8_t condition = 1;

	for(uint8_t i = 0; i<5; i++)
	{
		ALARM_CheckCondition(&alatest, condition);
		alatest.Timer--;
		while(!(alatest.Trigger == 0))
		{

		}
	}

	ALARM_CheckCondition(&alatest, condition);
	while(!(alatest.Trigger == 1))
	{

	}
}

/*
 * @brief This method test CheckCondition forcing it to trigger
 * @author William Favaro
 * @date 15/09/2022
 */
void Alarm_test_FromTriggeredToNoTriggered()
{
	uint8_t condition = 0;

	for(uint8_t i = 0; i < 5; i++)
	{
		ALARM_CheckCondition(&alatest, condition);
		alatest.Timer--;
		while(!(alatest.Trigger == 1))
		{
			/* test failed */
		}
	}

	ALARM_CheckCondition(&alatest, condition);
	while(!(alatest.Trigger == 0))
	{

	}
}

/*
 * @brief This method tests DisableAlarm method
 * @author William Favaro
 * @date 15/09/2022
 */
void Alarm_test_DisabledAlarm_AlarmMustNotTrigger()
{
	uint8_t condition = 0;

	ALARM_Disable(&alatest);

	for(uint8_t i = 0; i<5; i++)
	{
		ALARM_CheckCondition(&alatest, condition);
		alatest.Timer--;
		while(!(alatest.Trigger == 0))
		{
			/* test failed */
		}
	}

	ALARM_CheckCondition(&alatest, condition);
	while(!(alatest.Trigger == 0))
	{
		/* test failed */
	}

	ALARM_Enable(&alatest);

	ALARM_CheckCondition(&alatest, condition);
	while(!(alatest.Trigger == 0))
	{
		/* test failed */
	}
}

/*
 * @brief This method tests if the alarm change when the condition keeps changing
 * @author William Favaro
 * @date 15/09/2022
 */
void Alarm_test_ConditionKeepsChanging()
{
	uint8_t condition = 0;

	for(uint8_t i = 0; i<15; i++)
	{
		condition = !(condition);

		ALARM_CheckCondition(&alatest, condition);
		alatest.Timer--;
		while(!(alatest.Trigger == 0))
		{
			/* test failed */
		}
	}
}
#endif /* DEBUG */
/* End of the file -----------------------------------------------------------*/
