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
void MyQueue_Init(MyQueue *Queue)
{
	for(int i=0; i < MYQUEUE_N_MAX_ELEMENT; i++){
		Queue->Element[i] = 0;
	}
	Queue->NextElementPositionPointer = 0;
	Queue->AverageValue = 0;
	Queue->Size = 0;
}

void MyQueue_InsertElement(MyQueue *Queue, int16_t ElementToInsert)
{
	/* Setup: This piece of code is useless without Update AverageValue works together */
	int16_t ElementToEliminate = 0;
	if(Queue->Size==MYQUEUE_N_MAX_ELEMENT)
		ElementToEliminate = Queue->Element[Queue->NextElementPositionPointer];
	/* Insert the element */
	Queue->Element[Queue->NextElementPositionPointer]=ElementToInsert;
	/* Update Queue */
	Queue->NextElementPositionPointer++;
	if(Queue->NextElementPositionPointer==MYQUEUE_N_MAX_ELEMENT)
		Queue->NextElementPositionPointer=0;
	if(Queue->Size!=MYQUEUE_N_MAX_ELEMENT)
		Queue->Size++;
	/* Update AverageValue */
	Queue->Sum = Queue->Sum + ElementToInsert - ElementToEliminate;
	Queue->AverageValue = Queue->Sum / Queue->Size;
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
	if(Queue.Size)
	{
		if(Queue.NextElementPositionPointer)
			return Queue.Element[Queue.NextElementPositionPointer-1];
		else
			return Queue.Element[Queue.Size];
	}
	return 0;
}
/* Private Function ----------------------------------------------------------*/
/* End of the file -----------------------------------------------------------*/
