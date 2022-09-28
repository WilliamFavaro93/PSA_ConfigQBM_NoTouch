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
#define MYQUEUE_N_MAX_ELEMENT 30

/* Typedef struct definition -------------------------------------------------*/
typedef struct{
	uint16_t Element[MYQUEUE_N_MAX_ELEMENT];
	uint16_t AverageValue;
	uint8_t NextElementPositionPointer;
	uint8_t Size;
	uint32_t Sum;
}MyQueue;

/* Public Function definition ------------------------------------------------*/
void MyQueue_Init(MyQueue *Queue);
void MyQueue_InsertElement(MyQueue *Queue, int16_t ElementToInsert);
uint16_t MyQueue_GetAverageValue(MyQueue Queue);
uint16_t MyQueue_GetLastValue(MyQueue Queue);
/* Public Automated Testing Function -----------------------------------------*/
#ifdef DEBUG
void MyQueue_test_all();
#endif /* DEBUG */
#endif /* MYQUEUE_H_ */
