/**
  ******************************************************************************
  * @file   myqueue.h
  * @author William Favaro
  * @date	13/04/2022
  * @brief  queue definition functions
  * 		This module is created to simplify the usage of SD with STM32F4
  *
  ******************************************************************************
  * @note
  *
  *			fatman -> FAT File System Manager
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MYQUEUE_H_
#define MYQUEUE_H_

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

/* Defines -------------------------------------------------------------------*/
#define MYQUEUE_DEBUG 1 /* 0: Ignore the code between #ifDEBUG and #endif */
#define MYQUEUE_N_MAX_SAMPLE 255

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
