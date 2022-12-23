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
#ifndef INC_PSA_MODE__H_
#define INC_PSA_MODE__H_

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"

/* Defines -------------------------------------------------------------------*/
/* Typedef Struct definition -------------------------------------------------*/
/* Mode structure ------------------------------------------------------------*/
typedef struct
{
	uint8_t Enable;		/**< define if psa start to work:
	 	 	 	 	 	 0: psa is not in standby-mode
	 	 	 	 	 	 1:	psa is in standy-mode			*/
	uint8_t Ready; 		/**< define if psa is in ready-mode:
	 	 	 	 	 	 0: psa is not in ready-mode
	 	 	 	 	 	 1: psa is in ready-mode			*/
	uint8_t Run;		/**< define if psa is run-mode:
	 	 	 	 	 	 0: psa is not run-mode
	 	 	 	 	 	 1:	psa is run-mode					*/
} uint8_Mode;

/* Public Function -----------------------------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/
void PSA_MODE__SetEnable(uint8_Mode* Mode);
void PSA_MODE__SetDisable(uint8_Mode* Mode);
void PSA_MODE__SetReady(uint8_Mode* Mode);
void PSA_MODE__SetNotReady(uint8_Mode* Mode);
void PSA_MODE__SetRun(uint8_Mode* Mode);
void PSA_MODE__SetStandby(uint8_Mode* Mode);

/* Public Function definition: Get -------------------------------------------*/
uint8_t PSA_MODE__GetEnable(uint8_Mode Mode);
uint8_t PSA_MODE__GetReady(uint8_Mode Mode);
uint8_t PSA_MODE__GetRun(uint8_Mode Mode);

/* Private Function ----------------------------------------------------------*/

#endif /* INC_PSA_MODE_H_ */
