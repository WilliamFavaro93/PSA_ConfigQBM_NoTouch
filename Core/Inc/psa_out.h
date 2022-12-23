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
#ifndef INC_PSA_OUT_H_
#define INC_PSA_OUT_H_

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"

/* Defines -------------------------------------------------------------------*/
/* Typedef Struct definition -------------------------------------------------*/
/* Out structure -------------------------------------------------------------*/
typedef struct
{
	uint8_t Enable;		/**< define if the out is enabled:
	 	 	 	 	 	 0: the out is not enabled
	 	 	 	 	 	 1: the out is enabled				*/
	uint8_t Ready;		/**< define if the out is ready:
	 	 	 	 	 	 0: the out is not ready
	 	 	 	 	 	 1: the out is ready				*/
	uint8_t Run;	/**< define if the out is working:
	 	 	 	 	 	 0: the out is not working
	 	 	 	 	 	 1: the out is working				*/
} uint8_Out;

/* Public Function definition ------------------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/
void PSA_OUT__SetEnable(uint8_Out* Out);
void PSA_OUT__ResetEnable(uint8_Out* Out);
void PSA_OUT__SetReady(uint8_Out* Out);
void PSA_OUT__ResetReady(uint8_Out* Out);
void PSA_OUT__SetRun(uint8_Out* Out);
void PSA_OUT__ResetRun(uint8_Out* Out);

/* Public Function definition: Get -------------------------------------------*/
uint8_t PSA_OUT__GetEnable(uint8_Out Out);
uint8_t PSA_OUT__GetReady(uint8_Out Out);
uint8_t PSA_OUT__GetRun(uint8_Out Out);

#endif /* INC_PSA_OUT_H_ */
