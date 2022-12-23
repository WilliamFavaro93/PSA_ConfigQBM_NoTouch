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
#ifndef INC_PSA_STATE_H_
#define INC_PSA_STATE_H_

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"

/* Defines -------------------------------------------------------------------*/
/* Typedef Struct definition -------------------------------------------------*/
/* State structure -------------------------------------------------------------*/
typedef struct
{
	 int8_t Value;
	uint8_t Timer;
	uint8_t Update;
	uint8_t Module;	/**< the number of modules */
	uint8_t Valve[8];
} int8_State;

/* Public Function definition ------------------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/

/* Public Function definition: Get -------------------------------------------*/

#endif /* INC_PSA_STATE_H_ */
