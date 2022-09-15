/**
  ******************************************************************************
  * @file   myqueue.c
  * @author William Favaro
  * @date	13/04/2022
  * @brief  queue definition functions
  * 		This module is created to simplify the usage of SD with STM32F4
  *
  ******************************************************************************
  * @note
  *
  *
  *
  ******************************************************************************
  */

#include <myqueue.h>

void MyQueue_Init(QueueStruct *Queue)
{
	for(int i=0; i<MYQUEUE_N_MAX_ELEMENT; i++){
		Queue->Element[i]=1;
	}
	Queue->NextElementPositionPointer=0;
	Queue->AverageValue=0;
	Queue->Size=0;
}

void MyQueue_InsertElement(QueueStruct *Queue, int16_t ElementToInsert)
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

uint16_t MyQueue_GetAverageValue(QueueStruct *Queue)
{
	return Queue->AverageValue;
}

/*
 *
 */
uint16_t MyQueue_GetLastValue(QueueStruct *Queue)
{
	if(Queue->Size)
		return Queue->Element[Queue->NextElementPositionPointer-1];
	return 0;
}

#ifdef DEBUG
/*
 * This method is just for testing with debug this code
 */
void MyQueue_InsertElementTesting_1(QueueStruct *Queue)
{
	for(uint8_t i=0; i<125; i++){
		MyQueue_InsertElement(Queue, i+2);
	}
}

/*
 * This method is just for testing with debug this code
 */
void MyQueue_InsertElementTesting_2(QueueStruct *Queue)
{
	for(uint8_t i=0; i<125; i++){
		MyQueue_InsertElement(Queue, 3000);
	}
}
#endif /* DEBUG */
