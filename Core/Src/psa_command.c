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
#include <psa_command.h>
/* Defines -------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
/* Private Function definition -----------------------------------------------*/
/* Public Function -----------------------------------------------------------*/
/* Public Function definition: Get -------------------------------------------*/
uint8_t PSA_COMMAND__GetEnableOutGoingNitrogen(SetOfCommands Command)
{
	return Command.EnableOutGoingNitrogen;
}

uint8_t PSA_COMMAND__GetDisableOutGoingNitrogen(SetOfCommands Command)
{
	return Command.DisableOutGoingNitrogen;
}

uint8_t PSA_COMMAND__GetEnableOut1_DisableOut2(SetOfCommands Command)
{
	return Command.EnableOut1_DisableOut2;
}

uint8_t PSA_COMMAND__GetEnableOut2_DisableOut1(SetOfCommands Command)
{
	return Command.EnableOut2_DisableOut1;
}

uint8_t PSA_COMMAND__GetEnableOut1_EnableOut2(SetOfCommands Command)
{
	return Command.EnableOut1_EnableOut2;
}

uint8_t PSA_COMMAND__GetSetPriorityOut1(SetOfCommands Command)
{
	return Command.SetPriorityOut1;
}

uint8_t PSA_COMMAND__GetSetPriorityOut2(SetOfCommands Command)
{
	return Command.SetPriorityOut2;
}

uint8_t PSA_COMMAND__GetPulldownOn(SetOfCommands Command)
{
	return Command.PulldownOn;
}

uint8_t PSA_COMMAND__GetPulldownOff(SetOfCommands Command)
{
	return Command.PulldownOff;
}

/* Public Function definition: Set -------------------------------------------*/
void PSA_COMMAND__SetEnableOutGoingNitrogen(SetOfCommands* Command)
{
	Command->EnableOutGoingNitrogen = 1;
}

void PSA_COMMAND__SetDisableOutGoingNitrogen(SetOfCommands* Command)
{
	Command->DisableOutGoingNitrogen = 1;
}

void PSA_COMMAND__SetEnableOut1_DisableOut2(SetOfCommands* Command)
{
	Command->EnableOut1_DisableOut2 = 1;
}

void PSA_COMMAND__SetEnableOut2_DisableOut1(SetOfCommands* Command)
{
	Command->EnableOut2_DisableOut1 = 1;
}

void PSA_COMMAND__SetEnableOut1_EnableOut2(SetOfCommands* Command)
{
	Command->EnableOut1_EnableOut2 = 1;
}

void PSA_COMMAND__SetSetPriorityOut1(SetOfCommands* Command)
{
	Command->SetPriorityOut1 = 1;
}

void PSA_COMMAND__SetSetPriorityOut2(SetOfCommands* Command)
{
	Command->SetPriorityOut2 = 1;
}

void PSA_COMMAND__SetPulldownOn(SetOfCommands* Command)
{
	Command->PulldownOn = 1;
}

void PSA_COMMAND__SetPulldownOff(SetOfCommands* Command)
{
	Command->PulldownOff = 1;
}
/* Public Function definition: Reset -----------------------------------------*/
void PSA_COMMAND__ResetEnableOutGoingNitrogen(SetOfCommands* Command)
{
	Command->EnableOutGoingNitrogen = 0;
}

void PSA_COMMAND__ResetDisableOutGoingNitrogen(SetOfCommands* Command)
{
	Command->DisableOutGoingNitrogen = 0;
}

void PSA_COMMAND__ResetEnableOut1_DisableOut2(SetOfCommands* Command)
{
	Command->EnableOut1_DisableOut2 = 0;
}

void PSA_COMMAND__ResetEnableOut2_DisableOut1(SetOfCommands* Command)
{
	Command->EnableOut2_DisableOut1 = 0;
}

void PSA_COMMAND__ResetEnableOut1_EnableOut2(SetOfCommands* Command)
{
	Command->EnableOut1_EnableOut2 = 0;
}

void PSA_COMMAND__ResetSetPriorityOut1(SetOfCommands* Command)
{
	Command->SetPriorityOut1 = 0;
}

void PSA_COMMAND__ResetSetPriorityOut2(SetOfCommands* Command)
{
	Command->SetPriorityOut2 = 0;
}

void PSA_COMMAND__ResetPulldownOn(SetOfCommands* Command)
{
	Command->PulldownOn = 0;
}

void PSA_COMMAND__ResetPulldownOff(SetOfCommands* Command)
{
	Command->PulldownOff = 0;
}
/* Private Function ----------------------------------------------------------*/
/* End of the file -----------------------------------------------------------*/
