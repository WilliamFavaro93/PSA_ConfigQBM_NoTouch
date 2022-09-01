/*
 * Queue.h
 *
 *  Created on: 13 apr 2022
 *      Author: William.Favaro
 */

#ifndef MYQUEUE_H_
#define MYQUEUE_H_

#include <stdint.h>
#include "Settings.h"

#define MYQUEUE_DEBUG 1 /* 0: Ignore the code between #ifDEBUG and #endif */
#define MYQUEUE_N_MAX_SAMPLE 255
/* QUEUE_ELEMENT_TYPE & QUEUE_SIZE_TYPE -> Less changing, less bugs */
//#define MYQUEUE_ELEMENT_TYPE uint16_t
//#define MYQUEUE_SIZE_TYPE uint8_t

typedef struct{
	uint16_t Queue[MYQUEUE_N_MAX_SAMPLE];
	uint16_t AverageValue;
	uint8_t NextElementPositionPointer;
	uint8_t Size;
	uint32_t Sum;
}QueueStruct;

void MyQueue_Init(QueueStruct *Prototype);
void MyQueue_InsertElement(QueueStruct *Prototype, int16_t ElementToInsert);
uint16_t MyQueue_GetAverageValue(QueueStruct *Prototype);
uint16_t MyQueue_GetLastValue(QueueStruct *Prototype);

#endif /* MYQUEUE_H_ */
