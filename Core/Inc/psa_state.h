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
#include "string.h"

/* Defines -------------------------------------------------------------------*/
/* Typedef Struct definition -------------------------------------------------*/
/* State structure -------------------------------------------------------------*/
typedef struct
{
	 int8_t Value;			/**<the number that identifies the actual state */
	uint8_t Timer;			/**<the timer value is the number of deciseconds to wait because the state changes */
	uint8_t Update;			/**<It's 1 if the state is changed in the last execution of StateTask */
	uint8_t Module;			/**< the number of used modules */
	uint8_t Valve[8];		/**< the message to send by CAN1 */
} int8_State;

/* Public Function definition ------------------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/
void PSA_STATE__SetValue(int8_State* State, int8_t ValueToSet);
void PSA_STATE__SetTimer(int8_State* State, uint8_t ValueToSet);
void PSA_STATE__SetUpdate(int8_State* State, uint8_t ValueToSet);
void PSA_STATE__SetModule(int8_State* State, uint8_t ValueToSet);
void PSA_STATE__MemSetValve(int8_State* State, uint8_t* ArrayToCopy, uint8_t ArrayToCopy_length);
/* Public Function definition: Get -------------------------------------------*/
int8_t PSA_STATE__GetValue(int8_State* State);
uint8_t PSA_STATE__GetTimer(int8_State* State);
uint8_t PSA_STATE__GetUpdate(int8_State* State);
uint8_t PSA_STATE__GetModule(int8_State* State);
void PSA_STATE__MemGetValve(int8_State* State, uint8_t* CopyArray, uint8_t CopyArray_length);
/* Public Function definition: State -----------------------------------------*/


#endif /* INC_PSA_STATE_H_ */
