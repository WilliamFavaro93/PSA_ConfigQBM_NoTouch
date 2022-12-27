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
#ifndef INC_PSA_COMMAND_H_
#define INC_PSA_COMMAND_H_

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
/* Defines -------------------------------------------------------------------*/
/* Typedef Struct definition -------------------------------------------------*/
typedef struct
{
	uint8_t EnableOutGoingNitrogen;		/**< define if the command EnableOutGoingNitrogen must be managed:
	 	 	 	 	 	 	 	 	 	 0: EnableOutGoingNitrogen must not be managed
	 	 	 	 	 	 	 	 	 	 1: EnableOutGoingNitrogen must be managed		*/
	uint8_t DisableOutGoingNitrogen;	/**< define if the command DisableOutGoingNitrogen must be managed:
	 	 	 	 	 	 	 	 	 	 0: DisableOutGoingNitrogen must not be managed
	 	 	 	 	 	 	 	 	 	 1: DisableOutGoingNitrogen must be managed		*/
	uint8_t EnableOut1_DisableOut2;		/**< define if the command EnableOut1_DisableOut2 must be managed:
	 	 	 	 	 	 	 	 	 	 0: EnableOut1_DisableOut2 must not be managed
	 	 	 	 	 	 	 	 	 	 1: EnableOut1_DisableOut2 must be managed		*/
	uint8_t EnableOut2_DisableOut1;		/**< define if the command EnableOut2_DisableOut1 must be managed:
	 	 	 	 	 	 	 	 	 	 0: EnableOut2_DisableOut1 must not be managed
	 	 	 	 	 	 	 	 	 	 1: EnableOut2_DisableOut1 must be managed		*/
	uint8_t EnableOut1_EnableOut2;		/**< define if the command EnableOut1_EnableOut2 must be managed:
	 	 	 	 	 	 	 	 	 	 0: EnableOut1_EnableOut2 must not be managed
	 	 	 	 	 	 	 	 	 	 1: EnableOut1_EnableOut2 must be managed		*/
	uint8_t SetPriorityOut1;			/**< define if the command SetPriorityOut1 must be managed:
	 	 	 	 	 	 	 	 	 	 0: SetPriorityOut1 must not be managed
	 	 	 	 	 	 	 	 	 	 1: SetPriorityOut1 must be managed		*/
	uint8_t SetPriorityOut2;			/**< define if the command SetPriorityOut2 must be managed:
	 	 	 	 	 	 	 	 	 	 0: SetPriorityOut2 must not be managed
	 	 	 	 	 	 	 	 	 	 1: SetPriorityOut2 must be managed		*/
	uint8_t PulldownOn;					/**< define if the command PulldownOn must be managed:
	 	 	 	 	 	 	 	 	 	 0: PulldownOn must not be managed
	 	 	 	 	 	 	 	 	 	 1: PulldownOn must be managed		*/
	uint8_t PulldownOff;				/**< define if the command PulldownOff must be managed:
	 	 	 	 	 	 	 	 	 	 0: PulldownOff must not be managed
	 	 	 	 	 	 	 	 	 	 1: PulldownOff must be managed		*/
} SetOfCommands;
/* Public Function definition ------------------------------------------------*/
/* Public Function definition: Get -------------------------------------------*/
uint8_t PSA_COMMAND__GetEnableOutGoingNitrogen(SetOfCommands Command);
uint8_t PSA_COMMAND__GetEnableOutGoingNitrogen(SetOfCommands Command);
uint8_t PSA_COMMAND__GetDisableOutGoingNitrogen(SetOfCommands Command);
uint8_t PSA_COMMAND__GetEnableOut1_DisableOut2(SetOfCommands Command);
uint8_t PSA_COMMAND__GetEnableOut2_DisableOut1(SetOfCommands Command);
uint8_t PSA_COMMAND__GetEnableOut1_EnableOut2(SetOfCommands Command);
uint8_t PSA_COMMAND__GetSetPriorityOut1(SetOfCommands Command);
uint8_t PSA_COMMAND__GetSetPriorityOut2(SetOfCommands Command);
uint8_t PSA_COMMAND__GetPulldownOn(SetOfCommands Command);
uint8_t PSA_COMMAND__GetPulldownOff(SetOfCommands Command);
/* Public Function definition: Set -------------------------------------------*/
void PSA_COMMAND__SetEnableOutGoingNitrogen(SetOfCommands* Command);
void PSA_COMMAND__SetEnableOutGoingNitrogen(SetOfCommands* Command);
void PSA_COMMAND__SetDisableOutGoingNitrogen(SetOfCommands* Command);
void PSA_COMMAND__SetEnableOut1_DisableOut2(SetOfCommands* Command);
void PSA_COMMAND__SetEnableOut2_DisableOut1(SetOfCommands* Command);
void PSA_COMMAND__SetEnableOut1_EnableOut2(SetOfCommands* Command);
void PSA_COMMAND__SetSetPriorityOut1(SetOfCommands* Command);
void PSA_COMMAND__SetSetPriorityOut2(SetOfCommands* Command);
void PSA_COMMAND__SetPulldownOn(SetOfCommands* Command);
void PSA_COMMAND__SetPulldownOff(SetOfCommands* Command);
/* Public Function definition: Reset -----------------------------------------*/
void PSA_COMMAND__ResetEnableOutGoingNitrogen(SetOfCommands* Command);
void PSA_COMMAND__ResetEnableOutGoingNitrogen(SetOfCommands* Command);
void PSA_COMMAND__ResetDisableOutGoingNitrogen(SetOfCommands* Command);
void PSA_COMMAND__ResetEnableOut1_DisableOut2(SetOfCommands* Command);
void PSA_COMMAND__ResetEnableOut2_DisableOut1(SetOfCommands* Command);
void PSA_COMMAND__ResetEnableOut1_EnableOut2(SetOfCommands* Command);
void PSA_COMMAND__ResetSetPriorityOut1(SetOfCommands* Command);
void PSA_COMMAND__ResetSetPriorityOut2(SetOfCommands* Command);
void PSA_COMMAND__ResetPulldownOn(SetOfCommands* Command);
void PSA_COMMAND__ResetPulldownOff(SetOfCommands* Command);

#endif /* INC_PSA_COMMAND_H_ */
