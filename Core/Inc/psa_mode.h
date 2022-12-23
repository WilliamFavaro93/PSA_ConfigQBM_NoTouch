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
#ifndef INC_PSA_MODE_H_
#define INC_PSA_MODE_H_

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
void MODE_SetEnable(uint8_Mode* Mode);
void MODE_SetDisable(uint8_Mode* Mode);
void MODE_SetReady(uint8_Mode* Mode);
void MODE_SetNotReady(uint8_Mode* Mode);
void MODE_SetRun(uint8_Mode* Mode);
void MODE_SetStandby(uint8_Mode* Mode);

/* Public Function definition: Get -------------------------------------------*/
uint8_t MODE_GetEnable(uint8_Mode Mode);
uint8_t MODE_GetReady(uint8_Mode Mode);
uint8_t MODE_GetRun(uint8_Mode Mode);

/* Private Function ----------------------------------------------------------*/

#endif /* INC_PSA_MODE_H_ */
