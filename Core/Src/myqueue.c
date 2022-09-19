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

/* Includes ------------------------------------------------------------------*/
#include <myqueue.h>

/* Defines -------------------------------------------------------------------*/
#if DEBUG
	#define MYQUEUE_AUTEST 1
#else /* DEBUG */
	#define MYQUEUE_AUTEST 0
#endif /* DEBUG */
/* Variables -----------------------------------------------------------------*/
#if MYQUEUE_AUTEST
	MyQueue test;
#endif /* MYQUEUE_AUTEST */

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

MyQueue_RemoveLastInsertElement(MyQueue *Queue)
{
	/* TODO */
}
/* Private Function ----------------------------------------------------------*/
/* Public Automated Testing Function -----------------------------------------*/
#if MYQUEUE_AUTEST
/*
 * This method is just for testing with debug this code
 */
void MyQueue_test_InsertBigNumberOfSameValueElements()
{
	uint16_t AverageElement = 30;

	MyQueue_Init(&test);
	for(uint8_t i=0; i<120; i++){
		MyQueue_InsertElement(&test, AverageElement);
	}

	while(!(MyQueue_GetAverageValue(test) == AverageElement)){}
	while(!(MyQueue_GetLastValue(test) == AverageElement)){}
}

/*
 * This method is just for testing with debug this code
 */
void MyQueue_test_InsertIncresingValueElements()
{
	uint16_t StartingElement = 1600;

	for(uint8_t i=0; i < MYQUEUE_N_MAX_ELEMENT; i++){
		MyQueue_InsertElement(&test, StartingElement + i);
	}

	while(!(MyQueue_GetAverageValue(test) > (1600))){}
	while(!(MyQueue_GetAverageValue(test) < (1600 + MYQUEUE_N_MAX_ELEMENT))){}
}
#endif /* MYQUEUE_AUTEST */

void MyQueue_test_all()
{
#if MYQUEUE_AUTEST
	MyQueue_test_InsertBigNumberOfSameValueElements();
	MyQueue_test_InsertIncresingValueElements();
#endif /* MYQUEUE_AUTEST */
}
/* End of the file -----------------------------------------------------------*/
