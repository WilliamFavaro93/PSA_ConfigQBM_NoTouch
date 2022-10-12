/**
  ******************************************************************************
  * @file	acquisition.c
  * @author	William.Favaro
  * @date	2022/10/12
  * @brief	Acquisition function
  *
  ******************************************************************************
  * @note
  *
  *
  *
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include <acquisition.h>
/* Defines -------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
/* Private Function definition -----------------------------------------------*/
/* Public Function -----------------------------------------------------------*/
void Acquisition_AnalogInputIntoQueueWithAlarm(uint16_AnalogInput *AnalogInput, MyQueue *Queue, Alarm *Alarm)
{
	  /* If received new acquisition value, ... */
	  if((AnalogInput->Acquisition)
			  && (AnalogInput->Value >= AnalogInput->LowerLimit)
			  && (AnalogInput->Value <= AnalogInput->UpperLimit))
	  {
		  Alarm_CheckCondition(Alarm, 0);
		  MyQueue_InsertElement(Queue, AnalogInput->Value);
		  AnalogInput->Acquisition = 0;
	  }
	  else
	  {
		  Alarm_CheckCondition(Alarm, 1);
	  }
}

void Acquisition_AnalogInputIntoQueue(uint16_AnalogInput *AnalogInput, MyQueue *Queue)
{
	  /* If received new acquisition value, ... */
	  if((AnalogInput->Acquisition)
			  && (AnalogInput->Value >= AnalogInput->LowerLimit)
			  && (AnalogInput->Value <= AnalogInput->UpperLimit))
	  {
		  MyQueue_InsertElement(Queue, AnalogInput->Value);
		  AnalogInput->Acquisition = 0;
	  }
}
/* Private Function ----------------------------------------------------------*/
/* End of the file -----------------------------------------------------------*/
