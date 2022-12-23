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
#include "psa_out.h"

/* Defines -------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
/* Private Function definition -----------------------------------------------*/
/* Public Function -----------------------------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/
void PSA_OUT__Enable(uint8_Out* Out)
{
	Out->Enable = 1;
}

void PSA_OUT__Disable(uint8_Out* Out)
{
	Out->Run = 0;
	Out->Ready = 0;
	Out->Enable = 0;
}

void PSA_OUT__Ready(uint8_Out* Out)
{
	if(Out->Enable)
	{
		Out->Ready = 1;
	}
}

void PSA_OUT__NotReady(uint8_Out* Out)
{
	Out->Ready = 0;
	Out->Run = 0;
}

void PSA_OUT__Run(uint8_Out* Out)
{
	if((Out->Enable) && (Out->Ready))
	{
		Out->Run = 1;
	}
}

void PSA_OUT__Standby(uint8_Out* Out)
{
	Out->Run = 0;
}

/* Public Function definition: Get -------------------------------------------*/
uint8_t PSA_OUT__GetEnable(uint8_Out Out)
{
	return Out.Enable;
}

uint8_t PSA_OUT__GetReady(uint8_Out Out)
{
	return Out.Ready;
}

uint8_t PSA_OUT__GetRun(uint8_Out Out)
{
	return Out.Run;
}
/* Private Function ----------------------------------------------------------*/
/* End of the file -----------------------------------------------------------*/
