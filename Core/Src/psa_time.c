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
#include "psa_time.h"

/* Defines -------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
/* Private Function definition -----------------------------------------------*/
void PSA_TIME__Update_Adsorption(uint16_Time* Time);
void PSA_TIME__UpdateTotalCompensation(uint16_Time* Time);
/* Public Function -----------------------------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/
void PSA_TIME__SetAdsorption(uint16_Time* Time, uint16_t TimeToSet)
{
	Time->Adsorption = TimeToSet;
	PSA_TIME__Update_Adsorption(Time);
}

void PSA_TIME__SetCompensation_0(uint16_Time* Time, uint16_t TimeToSet)
{
	Time->Compensation_0 = TimeToSet;
	PSA_TIME__Update_Adsorption(Time);
	PSA_TIME__UpdateTotalCompensation(Time);
}

void PSA_TIME__SetCompensation_1(uint16_Time* Time, uint16_t TimeToSet)
{
	Time->Compensation_1 = TimeToSet;
	PSA_TIME__Update_Adsorption(Time);
	PSA_TIME__UpdateTotalCompensation(Time);
}

void PSA_TIME__SetCompensation_2(uint16_Time* Time, uint16_t TimeToSet)
{
	Time->Compensation_2 = TimeToSet;
	PSA_TIME__Update_Adsorption(Time);
	PSA_TIME__UpdateTotalCompensation(Time);
}

void PSA_TIME__SetPreStandby_1(uint16_Time* Time, uint16_t TimeToSet)
{
	Time->PreStandby_1 = TimeToSet;
}

void PSA_TIME__SetPreStandby_2(uint16_Time* Time, uint16_t TimeToSet)
{
	Time->PreStandby_2 = TimeToSet;
}

void PSA_TIME__Set_Standby(uint16_Time* Time)
{
	Time->_Standby = 1;
}

/* Public Function definition: Get -------------------------------------------*/
uint16_t PSA_TIME__GetAdsorption(uint16_Time Time)
{
	return Time.Adsorption;
}

uint16_t PSA_TIME__Get_Adsorption(uint16_Time Time)
{
	return Time._Adsorption;
}

uint16_t PSA_TIME__GetCompensation_0(uint16_Time Time)
{
	return Time.Compensation_0;
}

uint16_t PSA_TIME__GetCompensation_1(uint16_Time Time)
{
	return Time.Compensation_1;
}

uint16_t PSA_TIME__GetCompensation_2(uint16_Time Time)
{
	return Time.Compensation_2;
}

uint16_t PSA_TIME__GetPreStandby_1(uint16_Time Time)
{
	return Time.PreStandby_1;
}

uint16_t PSA_TIME__GetPreStandby_2(uint16_Time Time)
{
	return Time.PreStandby_2;
}

uint16_t PSA_TIME__Get_Standby(uint16_Time Time)
{
	return Time._Standby;
}
/* Private Function ----------------------------------------------------------*/
void PSA_TIME__Update_Adsorption(uint16_Time* Time)
{
	Time->_Adsorption = (Time->Adsorption - Time->_TotalCompensation)/2;
}

void PSA_TIME__UpdateTotalCompensation(uint16_Time* Time)
{
	Time->_TotalCompensation = Time->Compensation_0 + Time->Compensation_1 + Time->Compensation_2;
}
/* End of the file -----------------------------------------------------------*/
