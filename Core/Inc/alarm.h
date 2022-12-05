/**
  ******************************************************************************
  * @file	alarm.h
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef INC_ALARM_H_
#define INC_ALARM_H_

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
/* Defines -------------------------------------------------------------------*/
/* Typedef struct definition -------------------------------------------------*/
/**
  * @brief  Alarm structure definition
  */
typedef struct
{
	uint8_t Enable;				/**< define if the alarm is enable */
	uint8_t Trigger;			/**< define if the alarm is triggered */
	uint8_t WriteToSD;			/**< define if there is the command to write the alarm into SD */

	uint16_t Timer;				/**< the value of the timer of the alarm */
	uint16_t RefreshTimer_ON;	/**< the refresh value of the timer when the trigger is ON */
	uint16_t RefreshTimer_OFF;	/**< the refresh value of the timer when the trigger is OFF */
} Alarm;

/* Public Function definition ------------------------------------------------*/
void Alarm_Init(Alarm * Alarm, uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF);
void Alarm_CheckCondition(Alarm * Alarm, uint8_t condition);
void Alarm_Disable(Alarm * Alarm);
void Alarm_Enable(Alarm * Alarm);
/* Public Automated Testing Function -----------------------------------------*/
#ifdef DEBUG
void Alarm_test_all();
#endif /* DEBUG */

#endif /* INC_ALARM_H_ */
