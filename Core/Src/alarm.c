/**
  ******************************************************************************
  * @file	alarm.c
  * @author Willam.Favaro
  * @date	2022/09/15
  * @brief	alarm structure definition
  *
  ******************************************************************************
  * @note
  *
  *
  *
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "alarm.h"
/* Defines -------------------------------------------------------------------*/
#ifdef DEBUG
	#define ALARM_AUTEST
#endif /* DEBUG */
/* Variables -----------------------------------------------------------------*/
#ifdef ALARM_AUTEST
	Alarm test;
#endif /* ALARM_AUTEST */
/* Private Function definition -----------------------------------------------*/
/* Public Function -----------------------------------------------------------*/

/*
 * @brief This method initialize the alarm structure value
 * @author William Favaro
 * @date 15/09/2022
 * @note This method also enable the alarm
 */
void Alarm_Init(Alarm * Alarm, uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF)
{
	Alarm->isEnabled = 1;
	Alarm->isTriggered = 0;
	Alarm->RefreshTimer_ON = RefreshTimer_ON;
	Alarm->RefreshTimer_OFF = RefreshTimer_OFF;
	Alarm->Timer = Alarm->RefreshTimer_ON;
}

/*
 * @brief This method check the condition of the alarm and can be able to reflesh the alarm
 * @author William Favaro
 * @date 15/09/2022
 * @note This method also enable the alarm
 */
void Alarm_CheckCondition(Alarm * Alarm, uint8_t condition)
{
	/* Check if Alarm is Enable */
	if(!Alarm->isEnabled)
		return;

	/* Check if Timer is 0 */
	if(!Alarm->Timer)
	{
		Alarm->isTriggered = !(Alarm->isTriggered);
		Alarm->toWriteToSD = 1;
	}

	/* Check the Timer condition */
	if((condition) && (Alarm->isTriggered))
	{
		Alarm->Timer = Alarm->RefreshTimer_ON;
	}

	if((!condition) && (!Alarm->isTriggered))
	{
		Alarm->Timer = Alarm->RefreshTimer_OFF;
	}
}

/*
 * @brief This method disable the alarm
 * @author William Favaro
 * @date 15/09/2022
 * @note This method also enable the alarm
 */
void Alarm_Disable(Alarm * Alarm)
{
	Alarm->isEnabled = 0;
	Alarm->isTriggered = 0;
	Alarm->Timer = 0;
}

/*
 * @brief This method enable the alarm
 * @author William Favaro
 * @date 15/09/2022
 * @note This method also enable the alarm
 */
void Alarm_Enable(Alarm * Alarm)
{
	Alarm->isEnabled = 1;
	Alarm->isTriggered = 0;
	Alarm->Timer = Alarm->RefreshTimer_ON;
}
/* Private Function ----------------------------------------------------------*/
/* Public Automated Testing Function -----------------------------------------*/
#ifdef ALARM_AUTEST
void Alarm_test_Triggered()
{
	Alarm_Init(&test, 5, 5);

	uint8_t condition = 1;

	for(uint8_t i = 0; i<5; i++)
	{
		Alarm_CheckCondition(&test, condition);
		test.Timer--;
		while(!(test.isTriggered == 0))
		{

		}
	}

	Alarm_CheckCondition(&test, condition);
	while(!(test.isTriggered == 1))
	{

	}
}

void Alarm_test_FromTriggeredToNoTriggered()
{
	uint8_t condition = 0;

	for(uint8_t i = 0; i<5; i++)
	{
		Alarm_CheckCondition(&test, condition);
		test.Timer--;
		while(!(test.isTriggered == 1))
		{
			/* test failed */
		}
	}

	Alarm_CheckCondition(&test, condition);
	while(!(test.isTriggered == 0))
	{

	}
}

void Alarm_test_DisabledAlarm_AlarmMustNotTrigger()
{
	uint8_t condition = 0;

	Alarm_Disable(&test);

	for(uint8_t i = 0; i<5; i++)
	{
		Alarm_CheckCondition(&test, condition);
		test.Timer--;
		while(!(test.isTriggered == 0))
		{
			/* test failed */
		}
	}

	Alarm_CheckCondition(&test, condition);
	while(!(test.isTriggered == 0))
	{
		/* test failed */
	}

	Alarm_Enable(&test);

	Alarm_CheckCondition(&test, condition);
	while(!(test.isTriggered == 0))
	{
		/* test failed */
	}
}

void Alarm_test_ConditionKeepsChanging()
{
	uint8_t condition = 0;

	for(uint8_t i = 0; i<15; i++)
	{
		condition = !(condition);

		Alarm_CheckCondition(&test, condition);
		test.Timer--;
		while(!(test.isTriggered == 0))
		{
			/* test failed */
		}
	}
}
#endif /* ALARM_AUTEST */

void Alarm_test_all()
{
#ifdef ALARM_AUTEST
	Alarm_test_Triggered();
	Alarm_test_FromTriggeredToNoTriggered();
	Alarm_test_DisabledAlarm_AlarmMustNotTrigger();
	Alarm_test_ConditionKeepsChanging();
#endif /* ALARM_AUTEST */
}
/* End of the file -----------------------------------------------------------*/


