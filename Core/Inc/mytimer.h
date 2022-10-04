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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef INC_MYTIMER_H_
#define INC_MYTIMER_H_

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

/* Defines -------------------------------------------------------------------*/
/* Typedef Struct definition -------------------------------------------------*/
/* Public Function definition ------------------------------------------------*/
void MyTimer_SubtractDeciSecond(uint16_t * Timer);
void MyTimer_Refresh(uint16_t * Timer, uint16_t Refresh);

#endif /* INC_A_HEADER_FILE_EXAMPLE_H_ */
