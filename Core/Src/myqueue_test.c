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
static MyQueue myqtest;
/* Private Function definition -----------------------------------------------*/
void MyQueue_test_InsertValueWithoutInit();
void MyQueue_test_InsertBigNumberOfSameValueElements();
void MyQueue_test_InsertDifferentValueAfterReachMaxSize();
/* Public Function -----------------------------------------------------------*/
void MyQueue_test_all()
{
	MyQueue_test_InsertValueWithoutInit();
	MyQueue_test_InsertBigNumberOfSameValueElements();
	MyQueue_test_InsertDifferentValueAfterReachMaxSize();
}
/* Private Function ----------------------------------------------------------*/
void MyQueue_test_InsertValueWithoutInit()
{
	uint16_t AverageElement = 30;

	for(uint8_t i = 0; i < myqtest.MaxSize; i++){
		MyQueue_InsertElement(&myqtest, AverageElement);
	}

	/* Mi aspetto che se non inizializzo la queue e provo a inserire dei valori,
	 * la queue non deve inserire nulla
	 * Mi aspetto che i valori di somma e lunghezza */
	while(!(myqtest.Size == 0)){}
	while(!(myqtest.Sum == 0)){}
}
/*
 * This method is just for testing with debug this code
 */
void MyQueue_test_InsertBigNumberOfSameValueElements()
{
	uint16_t AverageElement = 30;
	uint8_t MaxSize = 20;

	if(MaxSize > MYQUEUE_N_MAX_ELEMENT)
		MaxSize = MYQUEUE_N_MAX_ELEMENT;

	MyQueue_Init(&myqtest, MaxSize);

	for(uint8_t i = 0; i < myqtest.MaxSize; i++){
		MyQueue_InsertElement(&myqtest, AverageElement);
	}

	while(!(myqtest.Size == MaxSize)){}
	while(!(myqtest.Sum == (MaxSize * AverageElement))){}
	while(!(MyQueue_GetLastValue(myqtest) == MyQueue_GetAverageValue(myqtest))){}
}

void MyQueue_test_InsertDifferentValueAfterReachMaxSize()
{
	uint16_t LastElement = MyQueue_GetLastValue(myqtest) + myqtest.MaxSize;
	uint16_t AverageElement = MyQueue_GetLastValue(myqtest);
	uint8_t MaxSize = myqtest.MaxSize;

	MyQueue_InsertElement(&myqtest, LastElement);

	while(!(myqtest.Size == MaxSize)){}
	while(!(myqtest.Sum == (MaxSize * AverageElement + MaxSize))){}
}

#endif /* DEBUG */
/* End of the file -----------------------------------------------------------*/
