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


/* Includes ------------------------------------------------------------------*/
#include "psa_state.h"

/* Defines -------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
/* Private Function definition -----------------------------------------------*/
/* Public Function -----------------------------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/
void PSA_STATE__SetValue(int8_State* State, int8_t ValueToSet)
{
	State->Value = ValueToSet;
}

void PSA_STATE__SetTimer(int8_State* State, uint8_t ValueToSet)
{
	State->Timer = ValueToSet;
}

void PSA_STATE__SetUpdate(int8_State* State, uint8_t ValueToSet)
{
	State->Update = ValueToSet;
}

void PSA_STATE__SetModule(int8_State* State, uint8_t ValueToSet)
{
	State->Module = ValueToSet;
}

void PSA_STATE__MemSetValve(int8_State* State, uint8_t* ArrayToSet, uint8_t ArrayToSet_length)
{
	memcpy(State->Valve, ArrayToSet, ArrayToSet_length);
}

/* Public Function definition: Get -------------------------------------------*/
int8_t PSA_STATE__GetValue(int8_State* State)
{
	return State->Value;
}

uint8_t PSA_STATE__GetTimer(int8_State* State)
{
	return State->Timer;
}

uint8_t PSA_STATE__GetUpdate(int8_State* State)
{
	return State->Update;
}

uint8_t PSA_STATE__GetModule(int8_State* State)
{
	return State->Module;
}

uint8_t PSA_STATE__MemGetValve(int8_State* State)
{
	return State->Value;
}
/* Private Function ----------------------------------------------------------*/

/* End of the file -----------------------------------------------------------*/
