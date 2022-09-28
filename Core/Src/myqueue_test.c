/**
  ******************************************************************************
  * @file
  * @author
  * @date
  * @brief
  *
  ******************************************************************************
  * @note
  *
  *
  *
  ******************************************************************************
  */

#ifdef DEBUG
/* Includes ------------------------------------------------------------------*/
#include <myqueue.h>
/* Defines -------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
MyQueue test;
/* Private Function definition -----------------------------------------------*/
void MyQueue_test_InsertBigNumberOfSameValueElements();
void MyQueue_test_InsertIncresingValueElements();
/* Public Function -----------------------------------------------------------*/
void MyQueue_test_all()
{
	MyQueue_test_InsertBigNumberOfSameValueElements();
	MyQueue_test_InsertIncresingValueElements();
}
/* Private Function ----------------------------------------------------------*/
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
#endif /* DEBUG */
/* End of the file -----------------------------------------------------------*/
