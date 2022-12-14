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
/* Variables -----------------------------------------------------------------*/
/* Private Function definition -----------------------------------------------*/
/* Public Function -----------------------------------------------------------*/

/*
 * @brief This method initialize the alarm structure value
 * @author William Favaro
 * @date 15/09/2022
 * @note This method also enable the alarm
 */
void ALARM_Init(Alarm * Alarm, uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF)
{
	Alarm->Enable = 1;
	Alarm->Trigger = 0;
	Alarm->RefreshTimer_ON = RefreshTimer_ON;
	Alarm->RefreshTimer_OFF = RefreshTimer_OFF;
	Alarm->Timer = Alarm->RefreshTimer_OFF;
}

/*
 * @brief This method check the condition of the alarm and can be able to reflesh the alarm
 * @author William Favaro
 * @date 15/09/2022
 * @note This method also enable the alarm
 */
void ALARM_Check(Alarm * Alarm, uint8_t Condition)
{
	/* Check if Alarm is Enable */
	if(!(Alarm->Enable))
		return;

	/* Check if Timer is 0 */
	if(!(Alarm->Timer))
	{
		if(Alarm->Trigger)
		{
			Alarm->Trigger = 0;
			Alarm->Timer = Alarm->RefreshTimer_ON;
		}
		else
		{
			Alarm->Trigger = 1;
			Alarm->Timer = Alarm->RefreshTimer_OFF;
		}

		Alarm->WriteToSD = 1;
	}

	/* Check the Timer condition */
	if((Condition) && (Alarm->Trigger))
	{
		Alarm->Timer = Alarm->RefreshTimer_ON;
	}

	if((!Condition) && (!Alarm->Trigger))
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
void ALARM_Disable(Alarm * Alarm)
{
	Alarm->Enable = 0;
	Alarm->Trigger = 0;
	Alarm->Timer = 0;
}

/*
 * @brief This method enable the alarm
 * @author William Favaro
 * @date 15/09/2022
 * @note This method also enable the alarm
 */
void ALARM_Enable(Alarm * Alarm)
{
	Alarm->Enable = 1;
	Alarm->Trigger = 0;
	Alarm->Timer = Alarm->RefreshTimer_ON;
}
/* Private Function ----------------------------------------------------------*/
/* End of the file -----------------------------------------------------------*/


