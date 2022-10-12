/**
  ******************************************************************************
  * @file   myqueue.c
  * @author William Favaro
  * @date	13/04/2022
  * @brief  Queue definition functions.
  *
  ******************************************************************************
  * @note
  *
  *
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <myqueue.h>

/* Defines -------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
/* Private Function definition -----------------------------------------------*/
/* Public Function -----------------------------------------------------------*/
void MyQueue_Init(MyQueue *Queue, uint8_t MaxSize)
{
	for(int i=0; i < MYQUEUE_N_MAX_ELEMENT; i++){
		Queue->Element[i] = 0;
	}
	Queue->NextElementPositionPointer = 0;
	Queue->AverageValue = 0;
	Queue->Size = 0;
	Queue->Sum = 0;

	Queue->Enable = 1;

	if(MaxSize > MYQUEUE_N_MAX_ELEMENT)
		Queue->MaxSize = MYQUEUE_N_MAX_ELEMENT;
	else
		Queue->MaxSize = MaxSize;
}

void MyQueue_InsertElement(MyQueue *Queue, int16_t ElementToInsert)
{
	if(!(Queue->Enable))
		return;
	/* Setup: This piece of code is useless without Update AverageValue works together */
	Queue->Sum -= Queue->Element[Queue->NextElementPositionPointer];
	/* Insert the element */
	Queue->Element[Queue->NextElementPositionPointer] = ElementToInsert;
	Queue->Sum += ElementToInsert;
	Queue->NextElementPositionPointer++;
	Queue->NextElementPositionPointer %= Queue->MaxSize;

	if(Queue->Size != Queue->MaxSize)
		Queue->Size++;
	/* Update AverageValue */
	Queue->AverageValue = (Queue->Sum / Queue->Size);
}

uint16_t MyQueue_GetAverageValue(MyQueue Queue)
{
	return Queue.AverageValue;
}

/*
 *
 */
uint16_t MyQueue_GetLastValue(MyQueue Queue)
{
	if(Queue.NextElementPositionPointer)
		return Queue.Element[Queue.NextElementPositionPointer - 1];
	else
		return Queue.Element[Queue.MaxSize - 1];
}
/* Private Function ----------------------------------------------------------*/
/* End of the file -----------------------------------------------------------*/
