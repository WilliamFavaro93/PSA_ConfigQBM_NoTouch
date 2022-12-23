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
#include "psa_mode.h"

/* Defines -------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
/* Private Function definition -----------------------------------------------*/
/* Public Function -----------------------------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/
void MODE_SetEnable(uint8_Mode* Mode)
{
	Mode->Enable = 1;
}

void MODE_SetDisable(uint8_Mode* Mode)
{
	Mode->Enable = 0;
}

void MODE_SetReady(uint8_Mode* Mode)
{
	Mode->Ready = 1;
}

void MODE_SetNotReady(uint8_Mode* Mode)
{
	Mode->Ready = 0;
}

void MODE_SetRun(uint8_Mode* Mode)
{
	if((Mode->Enable) && (Mode->Ready))
	{
		Mode->Run = 1;
	}
}

void MODE_SetStandby(uint8_Mode* Mode)
{
	Mode->Run = 0;
}

/* Public Function definition: Get -------------------------------------------*/
uint8_t MODE_GetEnable(uint8_Mode Mode)
{
	return Mode.Enable;
}

uint8_t MODE_GetReady(uint8_Mode Mode)
{
	return Mode.Ready;
}

uint8_t MODE_GetRun(uint8_Mode Mode)
{
	return Mode.Run;
}

/* Private Function ----------------------------------------------------------*/
/* End of the file -----------------------------------------------------------*/
