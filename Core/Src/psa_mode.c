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
void PSA_MODE__SetEnable(uint8_Mode* Mode)
{
	Mode->Enable = 1;
}

void PSA_MODE__SetDisable(uint8_Mode* Mode)
{
	Mode->Enable = 0;
}

void PSA_MODE__SetReady(uint8_Mode* Mode)
{
	Mode->Ready = 1;
}

void PSA_MODE__SetNotReady(uint8_Mode* Mode)
{
	Mode->Ready = 0;
}

void PSA_MODE__SetRun(uint8_Mode* Mode)
{
	if((Mode->Enable) && (Mode->Ready))
	{
		Mode->Run = 1;
	}
}

void PSA_MODE__SetStandby(uint8_Mode* Mode)
{
	Mode->Run = 0;
}

/* Public Function definition: Get -------------------------------------------*/
uint8_t PSA_MODE__GetEnable(uint8_Mode Mode)
{
	return Mode.Enable;
}

uint8_t PSA_MODE__GetReady(uint8_Mode Mode)
{
	return Mode.Ready;
}

uint8_t PSA_MODE__GetRun(uint8_Mode Mode)
{
	return Mode.Run;
}

/* Private Function ----------------------------------------------------------*/
/* End of the file -----------------------------------------------------------*/
