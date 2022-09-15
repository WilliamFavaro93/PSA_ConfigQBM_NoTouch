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
	uint8_t isEnabled;
	uint8_t isTriggered;
	uint16_t Timer;
	uint16_t RefreshTimer_ON;
	uint16_t RefreshTimer_OFF;
} Alarm;

/* Public Function definition ------------------------------------------------*/
void Alarm_Init(Alarm * Alarm, uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF);
void Alarm_CheckCondition(Alarm * Alarm, uint8_t condition);
void Alarm_Disable(Alarm * Alarm);
void Alarm_Enable(Alarm * Alarm);
void Alarm_test_all();

#endif /* INC_ALARM_H_ */
