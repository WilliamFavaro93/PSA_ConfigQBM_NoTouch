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
/* Public Function -----------------------------------------------------------*/
void MyQueue_test_all()
{
	MyQueue_test_InsertBigNumberOfSameValueElements();
}
/* Private Function ----------------------------------------------------------*/
/*
 * This method is just for testing with debug this code
 */
void MyQueue_test_InsertBigNumberOfSameValueElements()
{
	uint16_t AverageElement = 30;
	uint8_t MaxSize = 20;
	uint16_t LastElement = 50;

	MyQueue_Init(&test, MaxSize);

	for(uint8_t i = 0; i < test.MaxSize; i++){
		MyQueue_InsertElement(&test, AverageElement);
	}

	MyQueue_InsertElement(&test, LastElement);

	while(!(MyQueue_GetLastValue(test) == LastElement)){}

	uint32_t Sum = (test.MaxSize - 1) * AverageElement + LastElement;

	while(!(test.Sum == Sum)){}
}
#endif /* DEBUG */
/* End of the file -----------------------------------------------------------*/
