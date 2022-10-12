/**
  ******************************************************************************
  * @file	acquisition.h
  * @author	William.Favaro
  * @date	2022/10/12
  * @brief	define acquisition function
  *
  ******************************************************************************
  * @note
  *
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef INC_ACQUISITION_H_
#define INC_ACQUISITION_H_

/* Includes ------------------------------------------------------------------*/
#include <psa.h>
#include <alarm.h>
#include <myqueue.h>

/* Defines -------------------------------------------------------------------*/
/* Typedef Struct definition -------------------------------------------------*/
/* Public Function definition ------------------------------------------------*/
void Acquisition_AnalogInputIntoQueueWithAlarm(uint16_AnalogInput *AnalogInput, MyQueue *Queue, Alarm *Alarm);
void Acquisition_AnalogInputIntoQueue(uint16_AnalogInput *AnalogInput, MyQueue *Queue);
#endif /* INC_ACQUISITION_H_ */
