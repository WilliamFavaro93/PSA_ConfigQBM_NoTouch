/*
 * MyQueue.c
 *
 *  Created on: 14 apr 2022
 *      Author: William.Favaro
 */

#include <myqueue.h>

/* TODO Change Prototype with QueueStruct */

void MyQueue_Init(QueueStruct *Prototype)
{
	for(int i=0; i<MYQUEUE_N_MAX_SAMPLE; i++){
		Prototype->Queue[i]=1;
	}
	Prototype->NextElementPositionPointer=0;
	Prototype->AverageValue=0;
	Prototype->Size=0;
}

void MyQueue_InsertElement(QueueStruct *Prototype, int16_t ElementToInsert)
{
	/* Setup: This piece of code is useless without Update AverageValue works together */
	int16_t ElementToEliminate = 0;
	if(Prototype->Size==MYQUEUE_N_MAX_SAMPLE)
		ElementToEliminate = Prototype->Queue[Prototype->NextElementPositionPointer];
	/* Insert the element */
	Prototype->Queue[Prototype->NextElementPositionPointer]=ElementToInsert;
	/* Update Queue */
	Prototype->NextElementPositionPointer++;
	if(Prototype->NextElementPositionPointer==MYQUEUE_N_MAX_SAMPLE)
		Prototype->NextElementPositionPointer=0;
	if(Prototype->Size!=MYQUEUE_N_MAX_SAMPLE)
		Prototype->Size++;
	/* Update AverageValue */
	Prototype->Sum = Prototype->Sum + ElementToInsert - ElementToEliminate;
	Prototype->AverageValue = Prototype->Sum / Prototype->Size;
}

uint16_t MyQueue_GetAverageValue(QueueStruct *Prototype)
{
	return Prototype->AverageValue;
}

/*
 *
 */
uint16_t MyQueue_GetLastValue(QueueStruct *Prototype)
{
	if(Prototype->Size)
		return Prototype->Queue[Prototype->NextElementPositionPointer-1];
	return 0;
}

#ifdef DEBUG
/*
 * This method is just for testing with debug this code
 */
void MyQueue_InsertElementTesting_1(QueueStruct *Prototype)
{
	for(uint8_t i=0; i<125; i++){
		MyQueue_InsertElement(Prototype, i+2);
	}
}

/*
 * This method is just for testing with debug this code
 */
void MyQueue_InsertElementTesting_2(QueueStruct *Prototype)
{
	for(uint8_t i=0; i<125; i++){
		MyQueue_InsertElement(Prototype, 3000);
	}
}
#endif /* DEBUG */
