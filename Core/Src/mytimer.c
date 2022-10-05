/**
  ******************************************************************************
  * @file		mytimer.c
  * @author		William Favaro
  * @date		2022/10/04
  * @brief		Timer definition function
  *
  ******************************************************************************
  * @note
  *
  *
  *
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include <mytimer.h>
/* Defines -------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
/* Private Function definition -----------------------------------------------*/
/* Public Function -----------------------------------------------------------*/
/*
 * @brief This method subtract a decisecond for a timer
 * @author William Favaro
 * @date 21/09/2022
 */
void MyTimer_SubtractDeciSecond(uint16_t *Timer)
{
	if(*Timer)
		*Timer -= 1;
}

/*
 * @brief This method refresh the value of the timer
 * @author William Favaro
 * @date 21/09/2022
 */
void MyTimer_Refresh(uint16_t *Timer, uint16_t Refresh)
{
	*Timer = Refresh;
}
/* Private Function ----------------------------------------------------------*/
/* End of the file -----------------------------------------------------------*/
