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
#ifndef INC_PSA_TIME_H_
#define INC_PSA_TIME_H_

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"

/* Defines -------------------------------------------------------------------*/
/* Typedef Struct definition -------------------------------------------------*/
typedef struct
{
	uint16_t Adsorption;
	uint16_t _Adsorption;
	uint16_t Compensation_0;
	uint16_t Compensation_1;
	uint16_t Compensation_2;
	uint16_t _TotalCompensation;
	uint16_t PreStandby_1;
	uint16_t PreStandby_2;
	uint16_t _Standby;

	uint16_t SendAliveMessageToValve_Timer;
	uint16_t SendAliveMessageToValve_Refresh;

	uint16_t SendStateMessageToValve_Timer;
	uint16_t SendStateMessageToValve_Refresh;
} uint16_Time;

/* Public Function -----------------------------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/
void PSA_TIME__SetAdsorption(uint16_Time* Time, uint16_t TimeToSet);
void PSA_TIME__SetCompensation_0(uint16_Time* Time, uint16_t TimeToSet);
void PSA_TIME__SetCompensation_1(uint16_Time* Time, uint16_t TimeToSet);
void PSA_TIME__SetCompensation_2(uint16_Time* Time, uint16_t TimeToSet);
void PSA_TIME__SetPreStandby_1(uint16_Time* Time, uint16_t TimeToSet);
void PSA_TIME__SetPreStandby_2(uint16_Time* Time, uint16_t TimeToSet);
void PSA_TIME__Set_Standby(uint16_Time* Time);

/* Public Function definition: Get -------------------------------------------*/
uint16_t PSA_TIME__GetAdsorption(uint16_Time Time);
uint16_t PSA_TIME__Get_Adsorption(uint16_Time Time);
uint16_t PSA_TIME__GetCompensation_0(uint16_Time Time);
uint16_t PSA_TIME__GetCompensation_1(uint16_Time Time);
uint16_t PSA_TIME__GetCompensation_2(uint16_Time Time);
uint16_t PSA_TIME__GetPreStandby_1(uint16_Time Time);
uint16_t PSA_TIME__GetPreStandby_2(uint16_Time Time);
uint16_t PSA_TIME__Get_Standby(uint16_Time Time);

#endif /* INC_PSA_TIME_H_ */
