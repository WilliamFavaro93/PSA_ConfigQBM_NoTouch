/**
  ******************************************************************************
  * @file   psa.h
  * @author William Favaro
  * @date	14/04/2022
  * @brief  psa structure function
  *
  * 		This file defines the structure psa functions
  *
  ******************************************************************************
  * @note
  *
  *
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <psa.h>

/* Defines -------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
PSAStruct PSA;

/* Private Function definition -----------------------------------------------*/
/* Public Function: PSA.Time -------------------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/
void PSA_TIME_SetAdsorption(uint16_t TimeToSet)
{
	PSA_TIME__SetAdsorption(&PSA.Time, TimeToSet);
}

void PSA_TIME_SetCompensation_0(uint16_t TimeToSet)
{
	PSA_TIME__SetCompensation_0(&PSA.Time, TimeToSet);
}

void PSA_TIME_SetCompensation_1(uint16_t TimeToSet)
{
	PSA_TIME__SetCompensation_1(&PSA.Time, TimeToSet);
}

void PSA_TIME_SetCompensation_2(uint16_t TimeToSet)
{
	PSA_TIME__SetCompensation_2(&PSA.Time, TimeToSet);
}

void PSA_TIME_SetPreStandby_1(uint16_t TimeToSet)
{
	PSA_TIME__SetPreStandby_1(&PSA.Time, TimeToSet);
}

void PSA_TIME_SetPreStandby_2(uint16_t TimeToSet)
{
	PSA_TIME__SetPreStandby_2(&PSA.Time, TimeToSet);
}

void PSA_TIME_Set_Standby()
{
	PSA_TIME__Set_Standby(&PSA.Time);
}

/* Public Function definition: Get -------------------------------------------*/
uint16_t PSA_TIME_GetAdsorption()
{
	return PSA_TIME__GetAdsorption(PSA.Time);
}

uint16_t PSA_TIME_Get_Adsorption()
{
	return PSA_TIME__Get_Adsorption(PSA.Time);
}

uint16_t PSA_TIME_GetCompensation_0()
{
	return PSA_TIME__GetCompensation_0(PSA.Time);
}

uint16_t PSA_TIME_GetCompensation_1()
{
	return PSA_TIME__GetCompensation_1(PSA.Time);
}

uint16_t PSA_TIME_GetCompensation_2()
{
	return PSA_TIME__GetCompensation_2(PSA.Time);
}

uint16_t PSA_TIME_GetPreStandby_1()
{
	return PSA_TIME__GetPreStandby_1(PSA.Time);
}

uint16_t PSA_TIME_GetPreStandby_2()
{
	return PSA_TIME__GetPreStandby_2(PSA.Time);
}

uint16_t PSA_TIME_Get_Standby()
{
	return PSA_TIME__Get_Standby(PSA.Time);
}

/* Public Function definition: PSA.Mode --------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/
void PSA_MODE_SetEnable()
{
	PSA_MODE__SetEnable(&PSA.Mode);
}

void PSA_MODE_SetDisable()
{
	PSA_MODE__SetDisable(&PSA.Mode);
}

void PSA_MODE_SetReady()
{
	PSA_MODE__SetReady(&PSA.Mode);
}

void PSA_MODE_SetNotReady()
{
	PSA_MODE__SetNotReady(&PSA.Mode);
}

void PSA_MODE_SetRun()
{
	PSA_MODE__SetRun(&PSA.Mode);
}

void PSA_MODE_SetStandby()
{
	PSA_MODE__SetStandby(&PSA.Mode);
}

/* Public Function definition: Get -------------------------------------------*/
uint8_t PSA_MODE_GetEnable()
{
	return PSA_MODE__GetEnable(PSA.Mode);
}

uint8_t PSA_MODE_GetReady()
{
	return PSA_MODE__GetReady(PSA.Mode);
}

uint8_t PSA_MODE_GetRun()
{
	return PSA_MODE__GetRun(PSA.Mode);
}

/* Public Function: PSA.Out1 -------------------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/
void PSA_OUT1_Enable()
{
	PSA_OUT__SetEnable(&PSA.Out1);
}

void PSA_OUT1_Disable()
{
	PSA_OUT__ResetEnable(&PSA.Out1);
}

void PSA_OUT1_Ready()
{
	PSA_OUT__SetReady(&PSA.Out1);
}

void PSA_OUT1_NotReady()
{
	PSA_OUT__ResetReady(&PSA.Out1);
}

void PSA_OUT1_Run()
{
	PSA_OUT__SetRun(&PSA.Out1);
}

void PSA_OUT1_Standby()
{
	PSA_OUT__ResetRun(&PSA.Out1);
}

/* Public Function definition: Get -------------------------------------------*/
uint8_t PSA_OUT1_GetEnable()
{
	return PSA_OUT__GetEnable(PSA.Out1);
}

uint8_t PSA_OUT1_GetReady()
{
	return PSA_OUT__GetReady(PSA.Out1);
}

uint8_t PSA_OUT1_GetRun()
{
	return PSA_OUT__GetRun(PSA.Out1);
}

/* Public Function: PSA.Out2 -------------------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/
void PSA_OUT2_Enable()
{
	PSA_OUT__SetEnable(&PSA.Out2);
}

void PSA_OUT2_Disable()
{
	PSA_OUT__ResetEnable(&PSA.Out2);
}

void PSA_OUT2_Ready()
{
	PSA_OUT__SetReady(&PSA.Out2);
}

void PSA_OUT2_NotReady()
{
	PSA_OUT__ResetReady(&PSA.Out2);
}

void PSA_OUT2_Run()
{
	PSA_OUT__SetRun(&PSA.Out2);
}

void PSA_OUT2_Standby()
{
	PSA_OUT__ResetRun(&PSA.Out2);
}

/* Public Function definition: Get -------------------------------------------*/
uint8_t PSA_OUT2_GetEnable()
{
	return PSA_OUT__GetEnable(PSA.Out2);
}

uint8_t PSA_OUT2_GetReady()
{
	return PSA_OUT__GetReady(PSA.Out2);
}

uint8_t PSA_OUT2_GetRun()
{
	return PSA_OUT__GetRun(PSA.Out2);
}

/* Public Function: PSA.OutPriority ------------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/
void PSA_SetOutPriority(uint8_t NumberOfOutToSetPriority)
{
	PSA.OutPriority = NumberOfOutToSetPriority;
}
/* Public Function definition: Get -------------------------------------------*/
uint8_t PSA_GetOutPriority()
{
	return PSA.OutPriority;
}

/* Public Function: PSA.State ------------------------------------------------*/
/* Private Function definition -----------------------------------------------*/
void PSA_STATE_ValveOut();
void PSA_STATE_Adsorption1(uint8_t Module);
void PSA_STATE_Compensation0(uint8_t Module);
void PSA_STATE_Compensation1_1(uint8_t Module);
void PSA_STATE_Compensation1_2(uint8_t Module);
void PSA_STATE_Compensation2(uint8_t Module);
void PSA_STATE_Adsorption2(uint8_t Module);
void PSA_STATE_PreStandby1(uint8_t Module);
void PSA_STATE_PreStandby2(uint8_t Module);
void PSA_STATE_Standby(uint8_t Module);
/* Public Function definition: Set -------------------------------------------*/
void PSA_STATE_SetValue(int8_t ValueToSet);
void PSA_STATE_SetTimer(uint8_t ValueToSet);
void PSA_STATE_SetUpdate(uint8_t ValueToSet);
void PSA_STATE_SetModule(uint8_t ValueToSet);
void PSA_STATE_MemSetValve(uint8_t* ArrayToSet, uint8_t ArrayToSet_length);
/* Public Function definition: Get -------------------------------------------*/
int8_t PSA_STATE_GetValue();
uint8_t PSA_STATE_GetTimer();
uint8_t PSA_STATE_GetUpdate();
uint8_t PSA_STATE_GetModule();
uint8_t PSA_STATE_MemGetValve();
/* Private Function ----------------------------------------------------------*/
/*
 * @brief This method add the value of out1 or out2, if active, to the CAN message
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_STATE_ValveOut()
{
	if(PSA.Out1.Run)
	{
		PSA.State.Valve[0] += 1;
	}
	else if(PSA.Out2.Run)
	{
		PSA.State.Valve[1] += 1;
	}
}

/*
 * @brief This method update the value of psa structure when it reachs Adsorption1 state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_STATE_Adsorption1(uint8_t Module)
{
	if(PSA.State.Module > Module)
		PSA.State.Valve[Module] = 0xC6;
}

///*
// * @brief This method update the value of psa structure when it reachs Compensation0 state
// * @author William Favaro
// * @date 21/09/2022
// */
void PSA_STATE_Compensation0(uint8_t Module)
{
	if(PSA.State.Module > Module)
		PSA.State.Valve[Module] = 0x00;
}

/*
 * @brief This method update the value of psa structure when it reachs Compensation1 state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_STATE_Compensation1_1(uint8_t Module)
{
	if(PSA.State.Module > Module)
		PSA.State.Valve[Module] = 0x20;
}

/*
 * @brief This method update the value of psa structure when it reachs Compensation1 state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_STATE_Compensation1_2(uint8_t Module)
{
	if(PSA.State.Module > Module)
		PSA.State.Valve[Module] = 0x04;
}

/*
 * @brief This method update the value of psa structure when it reachs Compensation2 state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_STATE_Compensation2(uint8_t Module)
{
	if(PSA.State.Module > Module)
		PSA.State.Valve[Module] = 0x24;
}

/*
 * @brief This method update the value of psa structure when it reachs Adsorption2 state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_STATE_Adsorption2(uint8_t Module)
{
	if(PSA.State.Module > Module)
		PSA.State.Valve[Module] = 0xB8;
}

/*
 * @brief This method update the value of psa structure when it reachs PreStandby1 state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_STATE_PreStandby1(uint8_t Module)
{
	if(PSA.State.Module > Module)
		PSA.State.Valve[Module] = 0x08;
}

/*
 * @brief This method update the value of psa structure when it reachs PreStandby2 state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_STATE_PreStandby2(uint8_t Module)
{
	if(PSA.State.Module > Module)
		PSA.State.Valve[Module] = 0x48;
}

/*
 * @brief This method update the value of psa structure when it reachs Standby state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_STATE_Standby(uint8_t Module)
{
	if(PSA.State.Module > Module)
		PSA.State.Valve[Module] = 0x00;
}

/*
 * @brief This method select the method to update psa structure
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_State_UpdateState()
{
	/* Reset -----------------------------------------------------------------*/
	PSA.State.Valve[0] = 0x00;
	PSA.State.Valve[1] = 0x00;

	/* Standby ---------------------------------------------------------------*/
	if(PSA.State.Value == -2)
	{
		PSA_STATE_PreStandby1(0);
		PSA_STATE_PreStandby1(1);
		PSA.State.Timer = PSA.Time.PreStandby_1;
	}
	if(PSA.State.Value == -1)
	{
		PSA_STATE_PreStandby2(0);
		PSA_STATE_PreStandby2(1);
		PSA.State.Timer = PSA.Time.PreStandby_2;
	}
	if(PSA.State.Value == 0)
	{
		PSA_STATE_Standby(0);
		PSA_STATE_Standby(1);
		PSA.State.Timer = 1;
	}

	/* Run -------------------------------------------------------------------*/
	if(PSA.State.Value == 1)
	{
		PSA_STATE_Adsorption1(0);
		PSA_STATE_Adsorption1(1);
		PSA.State.Timer = (PSA.Time.Adsorption - PSA.Time._TotalCompensation) / 2;
	}
	if(PSA.State.Value == 2)
	{
		PSA_STATE_Adsorption1(0);
		PSA_STATE_Compensation0(1);
		PSA.State.Timer = PSA.Time.Compensation_0;
	}
	if(PSA.State.Value == 3)
	{
		PSA_STATE_Adsorption1(0);
		PSA_STATE_Compensation1_1(1);
		PSA.State.Timer = PSA.Time.Compensation_1;
	}
	if(PSA.State.Value == 4)
	{
		PSA_STATE_Adsorption1(0);
		PSA_STATE_Compensation2(1);
		PSA.State.Timer = PSA.Time.Compensation_2;
	}
	if(PSA.State.Value == 5)
	{
		PSA_STATE_Adsorption1(0);
		PSA_STATE_Adsorption2(1);
		PSA.State.Timer = (PSA.Time.Adsorption + 1 - PSA.Time._TotalCompensation) / 2;
	}
	if(PSA.State.Value == 6)
	{
		PSA_STATE_Compensation0(0);
		PSA_STATE_Adsorption2(1);
		PSA.State.Timer = PSA.Time.Compensation_0;
	}
	if(PSA.State.Value == 7)
	{
		PSA_STATE_Compensation1_1(0);
		PSA_STATE_Adsorption2(1);
		PSA.State.Timer = PSA.Time.Compensation_1;
	}
	if(PSA.State.Value == 8)
	{
		PSA_STATE_Compensation2(0);
		PSA_STATE_Adsorption2(1);
		PSA.State.Timer = PSA.Time.Compensation_2;
	}
	if(PSA.State.Value == 9)
	{
		PSA_STATE_Adsorption2(0);
		PSA_STATE_Adsorption2(1);
		PSA.State.Timer = (PSA.Time.Adsorption + 1 - PSA.Time._TotalCompensation) / 2;
	}
	if(PSA.State.Value == 10)
	{
		PSA_STATE_Adsorption2(0);
		PSA_STATE_Compensation0(1);
		PSA.State.Timer = PSA.Time.Compensation_0;
	}
	if(PSA.State.Value == 11)
	{
		PSA_STATE_Adsorption2(0);
		PSA_STATE_Compensation1_2(1);
		PSA.State.Timer = PSA.Time.Compensation_1;
	}
	if(PSA.State.Value == 12)
	{
		PSA_STATE_Adsorption2(0);
		PSA_STATE_Compensation2(1);
		PSA.State.Timer = PSA.Time.Compensation_2;
	}
	if(PSA.State.Value == 13)
	{
		PSA_STATE_Adsorption2(0);
		PSA_STATE_Adsorption1(1);
		PSA.State.Timer = (PSA.Time.Adsorption - PSA.Time._TotalCompensation) / 2;
	}
	if(PSA.State.Value == 14)
	{
		PSA_STATE_Compensation0(0);
		PSA_STATE_Adsorption1(1);
		PSA.State.Timer = PSA.Time.Compensation_0;
	}
	if(PSA.State.Value == 15)
	{
		PSA_STATE_Compensation1_2(0);
		PSA_STATE_Adsorption1(1);
		PSA.State.Timer = PSA.Time.Compensation_1;
	}
	if(PSA.State.Value == 16)
	{
		PSA_STATE_Compensation2(0);
		PSA_STATE_Adsorption1(1);
		PSA.State.Timer = PSA.Time.Compensation_2;
	}

	PSA_STATE_ValveOut();
	PSA.State.Update = 1;
}

/* Public Function: PSA.Command ----------------------------------------------*/
/* Private Function definition -----------------------------------------------*/
/* Public Function definition: Get -------------------------------------------*/
uint8_t PSA_COMMAND_GetEnableOutGoingNitrogen()
{
	return PSA_COMMAND__GetEnableOutGoingNitrogen(PSA.Command);
}

uint8_t PSA_COMMAND_GetDisableOutGoingNitrogen()
{
	return PSA_COMMAND__GetDisableOutGoingNitrogen(PSA.Command);
}

uint8_t PSA_COMMAND_GetEnableOut1_DisableOut2()
{
	return PSA_COMMAND__GetEnableOut1_DisableOut2(PSA.Command);
}
uint8_t PSA_COMMAND_GetEnableOut2_DisableOut1()
{
	return PSA_COMMAND__GetEnableOut2_DisableOut1(PSA.Command);
}
uint8_t PSA_COMMAND_GetEnableOut1_EnableOut2()
{
	return PSA_COMMAND__GetEnableOut1_EnableOut2(PSA.Command);
}
uint8_t PSA_COMMAND_GetSetPriorityOut1()
{
	return PSA_COMMAND__GetSetPriorityOut1(PSA.Command);
}
uint8_t PSA_COMMAND_GetSetPriorityOut2()
{
	return PSA_COMMAND__GetSetPriorityOut2(PSA.Command);
}
uint8_t PSA_COMMAND_GetPulldownOn()
{
	return PSA_COMMAND__GetPulldownOn(PSA.Command);
}
uint8_t PSA_COMMAND_GetPulldownOff()
{
	return PSA_COMMAND__GetPulldownOff(PSA.Command);
}
/* Public Function definition: Set -------------------------------------------*/
void PSA_COMMAND_SetEnableOutGoingNitrogen()
{
	PSA_COMMAND__SetEnableOutGoingNitrogen(&PSA.Command);
}
void PSA_COMMAND_SetDisableOutGoingNitrogen()
{
	PSA_COMMAND__SetDisableOutGoingNitrogen(&PSA.Command);
}
void PSA_COMMAND_SetEnableOut1_DisableOut2()
{
	PSA_COMMAND__SetEnableOut1_DisableOut2(&PSA.Command);
}
void PSA_COMMAND_SetEnableOut2_DisableOut1()
{
	PSA_COMMAND__SetEnableOut2_DisableOut1(&PSA.Command);
}
void PSA_COMMAND_SetEnableOut1_EnableOut2()
{
	PSA_COMMAND__SetEnableOut1_EnableOut2(&PSA.Command);
}
void PSA_COMMAND_SetSetPriorityOut1()
{
	PSA_COMMAND__SetSetPriorityOut1(&PSA.Command);
}
void PSA_COMMAND_SetSetPriorityOut2()
{
	PSA_COMMAND__SetSetPriorityOut2(&PSA.Command);
}
void PSA_COMMAND_SetPulldownOn()
{
	PSA_COMMAND__SetPulldownOn(&PSA.Command);
}
void PSA_COMMAND_SetPulldownOff()
{
	PSA_COMMAND__SetPulldownOff(&PSA.Command);
}
/* Public Function definition: Reset -----------------------------------------*/
void PSA_COMMAND_ResetEnableOutGoingNitrogen()
{
	PSA_COMMAND__ResetEnableOutGoingNitrogen(&PSA.Command);
}

void PSA_COMMAND_ResetDisableOutGoingNitrogen()
{
	PSA_COMMAND__ResetDisableOutGoingNitrogen(&PSA.Command);
}

void PSA_COMMAND_ResetEnableOut1_DisableOut2()
{
	PSA_COMMAND__ResetEnableOut1_DisableOut2(&PSA.Command);
}

void PSA_COMMAND_ResetEnableOut2_DisableOut1()
{
	PSA_COMMAND__ResetEnableOut2_DisableOut1(&PSA.Command);
}

void PSA_COMMAND_ResetEnableOut1_EnableOut2()
{
	PSA_COMMAND__ResetEnableOut1_EnableOut2(&PSA.Command);
}

void PSA_COMMAND_ResetSetPriorityOut1()
{
	PSA_COMMAND__ResetSetPriorityOut1(&PSA.Command);
}

void PSA_COMMAND_ResetSetPriorityOut2()
{
	PSA_COMMAND__ResetSetPriorityOut2(&PSA.Command);
}

void PSA_COMMAND_ResetPulldownOn()
{
	PSA_COMMAND__ResetPulldownOn(&PSA.Command);
}

void PSA_COMMAND_ResetPulldownOff()
{
	PSA_COMMAND__ResetPulldownOff(&PSA.Command);
}

/* TODO ----------------------------------------------------------------------*/
/* Public Function: PSA.Request ----------------------------------------------*/
/* Private Function definition -----------------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/
/* Public Function definition: Get -------------------------------------------*/

/* TODO ----------------------------------------------------------------------*/
/* Public Function: PSA.Alarm ------------------------------------------------*/
/* Public Function definition: Init ------------------------------------------*/
void PSA_ALARM_AL01_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF)
{
	ALARM_Init(&PSA.Alarm.AL01_CANbusError, RefreshTimer_ON, RefreshTimer_OFF);
}

void PSA_ALARM_AL02_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF)
{
	ALARM_Init(&PSA.Alarm.AL02_LowInputAirPressure, RefreshTimer_ON, RefreshTimer_OFF);
}

void PSA_ALARM_AL05_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF)
{
	ALARM_Init(&PSA.Alarm.AL05_LowProcessTankPressure, RefreshTimer_ON, RefreshTimer_OFF);
}

void PSA_ALARM_AL11_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF)
{
	ALARM_Init(&PSA.Alarm.AL11_External, RefreshTimer_ON, RefreshTimer_OFF);
}

void PSA_ALARM_AL16_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF)
{
	ALARM_Init(&PSA.Alarm.AL16_HighOut2Pressure, RefreshTimer_ON, RefreshTimer_OFF);
}

void PSA_ALARM_AL17_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF)
{
	ALARM_Init(&PSA.Alarm.AL17_HighDewpoint, RefreshTimer_ON, RefreshTimer_OFF);
}

void PSA_ALARM_AL18_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF)
{
	ALARM_Init(&PSA.Alarm.AL18_HighDewpoint, RefreshTimer_ON, RefreshTimer_OFF);
}

void PSA_ALARM_AL19_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF)
{
	ALARM_Init(&PSA.Alarm.AL19_HighOut1Pressure, RefreshTimer_ON, RefreshTimer_OFF);
}

void PSA_ALARM_AL20_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF)
{
	ALARM_Init(&PSA.Alarm.AL20_PCComunicationFault, RefreshTimer_ON, RefreshTimer_OFF);
}

void PSA_ALARM_AL31_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF)
{
	ALARM_Init(&PSA.Alarm.AL31_B1ProbeFault, RefreshTimer_ON, RefreshTimer_OFF);
}

void PSA_ALARM_AL32_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF)
{
	ALARM_Init(&PSA.Alarm.AL32_B2ProbeFault, RefreshTimer_ON, RefreshTimer_OFF);
}

void PSA_ALARM_AL33_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF)
{
	ALARM_Init(&PSA.Alarm.AL33_B3ProbeFault, RefreshTimer_ON, RefreshTimer_OFF);
}

void PSA_ALARM_AL34_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF)
{
	ALARM_Init(&PSA.Alarm.AL34_B4ProbeFault, RefreshTimer_ON, RefreshTimer_OFF);
}

void PSA_ALARM_AL35_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF)
{
	ALARM_Init(&PSA.Alarm.AL35_IFWProbeFault, RefreshTimer_ON, RefreshTimer_OFF);
}

void PSA_ALARM_AL36_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF)
{
	ALARM_Init(&PSA.Alarm.AL36_DEWProbeFault, RefreshTimer_ON, RefreshTimer_OFF);
}

void PSA_ALARM_AL37_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF)
{
	ALARM_Init(&PSA.Alarm.AL37_KE25ProbeFault, RefreshTimer_ON, RefreshTimer_OFF);
}

void PSA_ALARM_AL40_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF)
{
	ALARM_Init(&PSA.Alarm.AL40_PsaDischanging, RefreshTimer_ON, RefreshTimer_OFF);
}

void PSA_ALARM_MSDC_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF)
{
	ALARM_Init(&PSA.Alarm.MSDC_MissingSDCard, RefreshTimer_ON, RefreshTimer_OFF);
}
/* Public Function definition: Enable ----------------------------------------*/
void PSA_ALARM_AL01_Enable()
{
	ALARM_Enable(&PSA.Alarm.AL01_CANbusError);
}

void PSA_ALARM_AL02_Enable()
{
	ALARM_Enable(&PSA.Alarm.AL02_LowInputAirPressure);
}

void PSA_ALARM_AL05_Enable()
{
	ALARM_Enable(&PSA.Alarm.AL05_LowProcessTankPressure);
}

void PSA_ALARM_AL11_Enable()
{
	ALARM_Enable(&PSA.Alarm.AL11_External);
}

void PSA_ALARM_AL16_Enable()
{
	ALARM_Enable(&PSA.Alarm.AL16_HighOut2Pressure);
}

void PSA_ALARM_AL17_Enable()
{
	ALARM_Enable(&PSA.Alarm.AL17_HighDewpoint);
}

void PSA_ALARM_AL18_Enable()
{
	ALARM_Enable(&PSA.Alarm.AL18_HighDewpoint);
}

void PSA_ALARM_AL19_Enable()
{
	ALARM_Enable(&PSA.Alarm.AL19_HighOut1Pressure);
}

void PSA_ALARM_AL20_Enable()
{
	ALARM_Enable(&PSA.Alarm.AL20_PCComunicationFault);
}

void PSA_ALARM_AL31_Enable()
{
	ALARM_Enable(&PSA.Alarm.AL31_B1ProbeFault);
}

void PSA_ALARM_AL32_Enable()
{
	ALARM_Enable(&PSA.Alarm.AL32_B2ProbeFault);
}

void PSA_ALARM_AL33_Enable()
{
	ALARM_Enable(&PSA.Alarm.AL33_B3ProbeFault);
}

void PSA_ALARM_AL34_Enable()
{
	ALARM_Enable(&PSA.Alarm.AL34_B4ProbeFault);
}

void PSA_ALARM_AL35_Enable()
{
	ALARM_Enable(&PSA.Alarm.AL35_IFWProbeFault);
}

void PSA_ALARM_AL36_Enable()
{
	ALARM_Enable(&PSA.Alarm.AL36_DEWProbeFault);
}

void PSA_ALARM_AL37_Enable()
{
	ALARM_Enable(&PSA.Alarm.AL37_KE25ProbeFault);
}

void PSA_ALARM_AL40_Enable()
{
	ALARM_Enable(&PSA.Alarm.AL40_PsaDischanging);
}

void PSA_ALARM_MSDC_Enable()
{
	ALARM_Enable(&PSA.Alarm.MSDC_MissingSDCard);
}
/* Public Function definition: Disable ---------------------------------------*/
void PSA_ALARM_AL01_Disable()
{
	ALARM_Disable(&PSA.Alarm.AL01_CANbusError);
}

void PSA_ALARM_AL02_Disable()
{
	ALARM_Disable(&PSA.Alarm.AL02_LowInputAirPressure);
}

void PSA_ALARM_AL05_Disable()
{
	ALARM_Disable(&PSA.Alarm.AL05_LowProcessTankPressure);
}

void PSA_ALARM_AL11_Disable()
{
	ALARM_Disable(&PSA.Alarm.AL11_External);
}

void PSA_ALARM_AL16_Disable()
{
	ALARM_Disable(&PSA.Alarm.AL16_HighOut2Pressure);
}

void PSA_ALARM_AL17_Disable()
{
	ALARM_Disable(&PSA.Alarm.AL17_HighDewpoint);
}

void PSA_ALARM_AL18_Disable()
{
	ALARM_Disable(&PSA.Alarm.AL18_HighDewpoint);
}

void PSA_ALARM_AL19_Disable()
{
	ALARM_Disable(&PSA.Alarm.AL19_HighOut1Pressure);
}

void PSA_ALARM_AL20_Disable()
{
	ALARM_Disable(&PSA.Alarm.AL20_PCComunicationFault);
}

void PSA_ALARM_AL31_Disable()
{
	ALARM_Disable(&PSA.Alarm.AL31_B1ProbeFault);
}

void PSA_ALARM_AL32_Disable()
{
	ALARM_Disable(&PSA.Alarm.AL32_B2ProbeFault);
}

void PSA_ALARM_AL33_Disable()
{
	ALARM_Disable(&PSA.Alarm.AL33_B3ProbeFault);
}

void PSA_ALARM_AL34_Disable()
{
	ALARM_Disable(&PSA.Alarm.AL34_B4ProbeFault);
}

void PSA_ALARM_AL35_Disable()
{
	ALARM_Disable(&PSA.Alarm.AL35_IFWProbeFault);
}

void PSA_ALARM_AL36_Disable()
{
	ALARM_Disable(&PSA.Alarm.AL36_DEWProbeFault);
}

void PSA_ALARM_AL37_Disable()
{
	ALARM_Disable(&PSA.Alarm.AL37_KE25ProbeFault);
}

void PSA_ALARM_AL40_Disable()
{
	ALARM_Disable(&PSA.Alarm.AL40_PsaDischanging);
}

void PSA_ALARM_MSDC_Disable()
{
	ALARM_Disable(&PSA.Alarm.MSDC_MissingSDCard);
}

/* Public Function definition: GetEnable -------------------------------------*/
uint8_t PSA_ALARM_AL01_GetEnable()
{
	return PSA.Alarm.AL01_CANbusError.Enable;
}

uint8_t PSA_ALARM_AL02_GetEnable()
{
	return PSA.Alarm.AL02_LowInputAirPressure.Enable;
}

uint8_t PSA_ALARM_AL05_GetEnable()
{
	return PSA.Alarm.AL05_LowProcessTankPressure.Enable;
}

uint8_t PSA_ALARM_AL11_GetEnable()
{
	return PSA.Alarm.AL11_External.Enable;
}

uint8_t PSA_ALARM_AL16_GetEnable()
{
	return PSA.Alarm.AL16_HighOut2Pressure.Enable;
}

uint8_t PSA_ALARM_AL17_GetEnable()
{
	return PSA.Alarm.AL17_HighDewpoint.Enable;
}

uint8_t PSA_ALARM_AL18_GetEnable()
{
	return PSA.Alarm.AL18_HighDewpoint.Enable;
}

uint8_t PSA_ALARM_AL19_GetEnable()
{
	return PSA.Alarm.AL19_HighOut1Pressure.Enable;
}

uint8_t PSA_ALARM_AL20_GetEnable()
{
	return PSA.Alarm.AL20_PCComunicationFault.Enable;
}

uint8_t PSA_ALARM_AL31_GetEnable()
{
	return PSA.Alarm.AL31_B1ProbeFault.Enable;
}

uint8_t PSA_ALARM_AL32_GetEnable()
{
	return PSA.Alarm.AL32_B2ProbeFault.Enable;
}

uint8_t PSA_ALARM_AL33_GetEnable()
{
	return PSA.Alarm.AL33_B3ProbeFault.Enable;
}

uint8_t PSA_ALARM_AL34_GetEnable()
{
	return PSA.Alarm.AL34_B4ProbeFault.Enable;
}

uint8_t PSA_ALARM_AL35_GetEnable()
{
	return PSA.Alarm.AL35_IFWProbeFault.Enable;
}

uint8_t PSA_ALARM_AL36_GetEnable()
{
	return PSA.Alarm.AL36_DEWProbeFault.Enable;
}

uint8_t PSA_ALARM_AL37_GetEnable()
{
	return PSA.Alarm.AL37_KE25ProbeFault.Enable;
}

uint8_t PSA_ALARM_AL40_GetEnable()
{
	return PSA.Alarm.AL40_PsaDischanging.Enable;
}

uint8_t PSA_ALARM_MSDC_GetEnable()
{
	return PSA.Alarm.MSDC_MissingSDCard.Enable;
}

/* Public Function definition: GetTrigger ------------------------------------*/
uint8_t PSA_ALARM_AL01_GetTrigger()
{
	return PSA.Alarm.AL01_CANbusError.Trigger;
}

uint8_t PSA_ALARM_AL02_GetTrigger()
{
	return PSA.Alarm.AL02_LowInputAirPressure.Trigger;
}

uint8_t PSA_ALARM_AL05_GetTrigger()
{
	return PSA.Alarm.AL05_LowProcessTankPressure.Trigger;
}

uint8_t PSA_ALARM_AL11_GetTrigger()
{
	return PSA.Alarm.AL11_External.Trigger;
}

uint8_t PSA_ALARM_AL16_GetTrigger()
{
	return PSA.Alarm.AL16_HighOut2Pressure.Trigger;
}

uint8_t PSA_ALARM_AL17_GetTrigger()
{
	return PSA.Alarm.AL17_HighDewpoint.Trigger;
}

uint8_t PSA_ALARM_AL18_GetTrigger()
{
	return PSA.Alarm.AL18_HighDewpoint.Trigger;
}

uint8_t PSA_ALARM_AL19_GetTrigger()
{
	return PSA.Alarm.AL19_HighOut1Pressure.Trigger;
}

uint8_t PSA_ALARM_AL20_GetTrigger()
{
	return PSA.Alarm.AL20_PCComunicationFault.Trigger;
}

uint8_t PSA_ALARM_AL31_GetTrigger()
{
	return PSA.Alarm.AL31_B1ProbeFault.Trigger;
}

uint8_t PSA_ALARM_AL32_GetTrigger()
{
	return PSA.Alarm.AL32_B2ProbeFault.Trigger;
}

uint8_t PSA_ALARM_AL33_GetTrigger()
{
	return PSA.Alarm.AL33_B3ProbeFault.Trigger;
}

uint8_t PSA_ALARM_AL34_GetTrigger()
{
	return PSA.Alarm.AL34_B4ProbeFault.Trigger;
}

uint8_t PSA_ALARM_AL35_GetTrigger()
{
	return PSA.Alarm.AL35_IFWProbeFault.Trigger;
}

uint8_t PSA_ALARM_AL36_GetTrigger()
{
	return PSA.Alarm.AL36_DEWProbeFault.Trigger;
}

uint8_t PSA_ALARM_AL37_GetTrigger()
{
	return PSA.Alarm.AL37_KE25ProbeFault.Trigger;
}

uint8_t PSA_ALARM_AL40_GetTrigger()
{
	return PSA.Alarm.AL40_PsaDischanging.Trigger;
}

uint8_t PSA_ALARM_MSDC_GetTrigger()
{
	return PSA.Alarm.MSDC_MissingSDCard.Trigger;
}

/* Public Function definition: GetWriteToSD ----------------------------------*/
uint8_t PSA_ALARM_AL01_GetWriteToSD()
{
	return PSA.Alarm.AL01_CANbusError.WriteToSD;
}
uint8_t PSA_ALARM_AL02_GetWriteToSD()
{
	return PSA.Alarm.AL02_LowInputAirPressure.WriteToSD;
}

uint8_t PSA_ALARM_AL05_GetWriteToSD()
{
	return PSA.Alarm.AL05_LowProcessTankPressure.WriteToSD;
}

uint8_t PSA_ALARM_AL11_GetWriteToSD()
{
	return PSA.Alarm.AL11_External.WriteToSD;
}

uint8_t PSA_ALARM_AL16_GetWriteToSD()
{
	return PSA.Alarm.AL16_HighOut2Pressure.WriteToSD;
}

uint8_t PSA_ALARM_AL17_GetWriteToSD()
{
	return PSA.Alarm.AL17_HighDewpoint.WriteToSD;
}

uint8_t PSA_ALARM_AL18_GetWriteToSD()
{
	return PSA.Alarm.AL18_HighDewpoint.WriteToSD;
}

uint8_t PSA_ALARM_AL19_GetWriteToSD()
{
	return PSA.Alarm.AL19_HighOut1Pressure.WriteToSD;
}

uint8_t PSA_ALARM_AL20_GetWriteToSD()
{
	return PSA.Alarm.AL20_PCComunicationFault.WriteToSD;
}

uint8_t PSA_ALARM_AL31_GetWriteToSD()
{
	return PSA.Alarm.AL31_B1ProbeFault.WriteToSD;
}

uint8_t PSA_ALARM_AL32_GetWriteToSD()
{
	return PSA.Alarm.AL32_B2ProbeFault.WriteToSD;
}

uint8_t PSA_ALARM_AL33_GetWriteToSD()
{
	return PSA.Alarm.AL33_B3ProbeFault.WriteToSD;
}

uint8_t PSA_ALARM_AL34_GetWriteToSD()
{
	return PSA.Alarm.AL34_B4ProbeFault.WriteToSD;
}

uint8_t PSA_ALARM_AL35_GetWriteToSD()
{
	return PSA.Alarm.AL35_IFWProbeFault.WriteToSD;
}

uint8_t PSA_ALARM_AL36_GetWriteToSD()
{
	return PSA.Alarm.AL36_DEWProbeFault.WriteToSD;
}

uint8_t PSA_ALARM_AL37_GetWriteToSD()
{
	return PSA.Alarm.AL37_KE25ProbeFault.WriteToSD;
}

uint8_t PSA_ALARM_AL40_GetWriteToSD()
{
	return PSA.Alarm.AL40_PsaDischanging.WriteToSD;
}

uint8_t PSA_ALARM_MSDC_GetWriteToSD()
{
	return PSA.Alarm.MSDC_MissingSDCard.WriteToSD;
}

/* Public Function definition: Get -------------------------------------------*/
uint8_t PSA_ALARM_GetNumberOfTriggeredAlarms()
{
	return PSA.Alarm.NumberOfTriggeredAlarms;
}

uint8_t PSA_ALARM_GetNumberOfTriggeredBlockingAlarms()
{
	return PSA.Alarm.NumberOfTriggeredBlockingAlarms;
}

/* Public Function definition: ResetWriteToSD --------------------------------*/
void PSA_ALARM_AL01_ResetWriteToSD()
{
	PSA.Alarm.AL01_CANbusError.WriteToSD = 0;
}

void PSA_ALARM_AL02_ResetWriteToSD()
{
	PSA.Alarm.AL02_LowInputAirPressure.WriteToSD = 0;
}

void PSA_ALARM_AL05_ResetWriteToSD()
{
	PSA.Alarm.AL05_LowProcessTankPressure.WriteToSD = 0;
}

void PSA_ALARM_AL11_ResetWriteToSD()
{
	PSA.Alarm.AL11_External.WriteToSD = 0;
}

void PSA_ALARM_AL16_ResetWriteToSD()
{
	PSA.Alarm.AL16_HighOut2Pressure.WriteToSD = 0;
}

void PSA_ALARM_AL17_ResetWriteToSD()
{
	PSA.Alarm.AL17_HighDewpoint.WriteToSD = 0;
}

void PSA_ALARM_AL18_ResetWriteToSD()
{
	PSA.Alarm.AL18_HighDewpoint.WriteToSD = 0;
}

void PSA_ALARM_AL19_ResetWriteToSD()
{
	PSA.Alarm.AL19_HighOut1Pressure.WriteToSD = 0;
}

void PSA_ALARM_AL20_ResetWriteToSD()
{
	PSA.Alarm.AL20_PCComunicationFault.WriteToSD = 0;
}

void PSA_ALARM_AL31_ResetWriteToSD()
{
	PSA.Alarm.AL31_B1ProbeFault.WriteToSD = 0;
}

void PSA_ALARM_AL32_ResetWriteToSD()
{
	PSA.Alarm.AL32_B2ProbeFault.WriteToSD = 0;
}

void PSA_ALARM_AL33_ResetWriteToSD()
{
	PSA.Alarm.AL33_B3ProbeFault.WriteToSD = 0;
}

void PSA_ALARM_AL34_ResetWriteToSD()
{
	PSA.Alarm.AL34_B4ProbeFault.WriteToSD = 0;
}

void PSA_ALARM_AL35_ResetWriteToSD()
{
	PSA.Alarm.AL35_IFWProbeFault.WriteToSD = 0;
}

void PSA_ALARM_AL36_ResetWriteToSD()
{
	PSA.Alarm.AL36_DEWProbeFault.WriteToSD = 0;
}

void PSA_ALARM_AL37_ResetWriteToSD()
{
	PSA.Alarm.AL37_KE25ProbeFault.WriteToSD = 0;
}

void PSA_ALARM_AL40_ResetWriteToSD()
{
	PSA.Alarm.AL40_PsaDischanging.WriteToSD = 0;
}

void PSA_ALARM_MSDC_ResetWriteToSD()
{
	PSA.Alarm.MSDC_MissingSDCard.WriteToSD = 0;
}

/* Public Function definition: Check -----------------------------------------*/
void PSA_ALARM_AL01_Check(uint8_t Condition)
{
	ALARM_Check(&PSA.Alarm.AL01_CANbusError, Condition);
}

void PSA_ALARM_AL02_Check(uint8_t Condition)
{
	ALARM_Check(&PSA.Alarm.AL02_LowInputAirPressure, Condition);
}

void PSA_ALARM_AL05_Check(uint8_t Condition)
{
	ALARM_Check(&PSA.Alarm.AL05_LowProcessTankPressure, Condition);
}

void PSA_ALARM_AL11_Check(uint8_t Condition)
{
	ALARM_Check(&PSA.Alarm.AL11_External, Condition);
}

void PSA_ALARM_AL16_Check(uint8_t Condition)
{
	ALARM_Check(&PSA.Alarm.AL16_HighOut2Pressure, Condition);
}

void PSA_ALARM_AL17_Check(uint8_t Condition)
{
	ALARM_Check(&PSA.Alarm.AL17_HighDewpoint, Condition);
}

void PSA_ALARM_AL18_Check(uint8_t Condition)
{
	ALARM_Check(&PSA.Alarm.AL18_HighDewpoint, Condition);
}

void PSA_ALARM_AL19_Check(uint8_t Condition)
{
	ALARM_Check(&PSA.Alarm.AL19_HighOut1Pressure, Condition);
}

void PSA_ALARM_AL20_Check(uint8_t Condition)
{
	ALARM_Check(&PSA.Alarm.AL20_PCComunicationFault, Condition);
}

void PSA_ALARM_AL31_Check(uint8_t Condition)
{
	ALARM_Check(&PSA.Alarm.AL31_B1ProbeFault, Condition);
}

void PSA_ALARM_AL32_Check(uint8_t Condition)
{
	ALARM_Check(&PSA.Alarm.AL32_B2ProbeFault, Condition);
}

void PSA_ALARM_AL33_Check(uint8_t Condition)
{
	ALARM_Check(&PSA.Alarm.AL33_B3ProbeFault, Condition);
}

void PSA_ALARM_AL34_Check(uint8_t Condition)
{
	ALARM_Check(&PSA.Alarm.AL34_B4ProbeFault, Condition);
}

void PSA_ALARM_AL35_Check(uint8_t Condition)
{
	ALARM_Check(&PSA.Alarm.AL35_IFWProbeFault, Condition);
}

void PSA_ALARM_AL36_Check(uint8_t Condition)
{
	ALARM_Check(&PSA.Alarm.AL36_DEWProbeFault, Condition);
}

void PSA_ALARM_AL37_Check(uint8_t Condition)
{
	ALARM_Check(&PSA.Alarm.AL37_KE25ProbeFault, Condition);
}

void PSA_ALARM_AL40_Check(uint8_t Condition)
{
	ALARM_Check(&PSA.Alarm.AL40_PsaDischanging, Condition);
}

void PSA_ALARM_MSDC_Check(uint8_t Condition)
{
	ALARM_Check(&PSA.Alarm.MSDC_MissingSDCard, Condition);
}

/* TODO ----------------------------------------------------------------------*/
/* Public Function: PSA.DigitalInput -----------------------------------------*/
/* Private Function definition -----------------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/
/* Public Function definition: Get -------------------------------------------*/

/* TODO ----------------------------------------------------------------------*/
/* Public Function: PSA.AnalogInput ------------------------------------------*/
/* Private Function definition -----------------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/
/* Public Function definition: Get -------------------------------------------*/

/* TODO ----------------------------------------------------------------------*/
/* Public Function: PSA.Relay ------------------------------------------------*/
/* Private Function definition -----------------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/
/* Public Function definition: Get -------------------------------------------*/











void PSA_AnalogInput_Acquisition(uint16_AnalogInput *AnalogInput, uint16_t AnalogInputValue)
{
	AnalogInput->Value = AnalogInputValue;
	AnalogInput->Acquisition = 1;
}

uint8_t PSA_Alarm_NumberOfAlarmsTriggered()
{
	uint8_t alarm_count = 0;

	if(PSA.Alarm.AL01_CANbusError.Trigger)
		alarm_count++;
	if(PSA.Alarm.AL02_LowInputAirPressure.Trigger)
		alarm_count++;
	if(PSA.Alarm.AL05_LowProcessTankPressure.Trigger)
		alarm_count++;
	if(PSA.Alarm.AL11_External.Trigger)
		alarm_count++;
	if(PSA.Alarm.AL16_HighOut2Pressure.Trigger)
		alarm_count++;
	if(PSA.Alarm.AL17_HighDewpoint.Trigger)
		alarm_count++;
	if(PSA.Alarm.AL18_HighDewpoint.Trigger)
		alarm_count++;
	if(PSA.Alarm.AL19_HighOut1Pressure.Trigger)
		alarm_count++;
	if(PSA.Alarm.AL20_PCComunicationFault.Trigger)
		alarm_count++;
	if(PSA.Alarm.AL31_B1ProbeFault.Trigger)
		alarm_count++;
	if(PSA.Alarm.AL32_B2ProbeFault.Trigger)
		alarm_count++;
	if(PSA.Alarm.AL33_B3ProbeFault.Trigger)
		alarm_count++;
	if(PSA.Alarm.AL34_B4ProbeFault.Trigger)
		alarm_count++;
	if(PSA.Alarm.AL35_IFWProbeFault.Trigger)
		alarm_count++;
	if(PSA.Alarm.AL36_DEWProbeFault.Trigger)
		alarm_count++;
	if(PSA.Alarm.AL37_KE25ProbeFault.Trigger)
		alarm_count++;
	if(PSA.Alarm.AL40_PsaDischanging.Trigger)
		alarm_count++;

	return alarm_count;
}

uint8_t PSA_Alarm_NumberOfBlockingAlarmsTriggered()
{
	uint8_t alarm_count = 0;

	if(PSA.Alarm.AL11_External.Trigger)
		alarm_count++;
	if(PSA.Alarm.AL17_HighDewpoint.Trigger)
		alarm_count++;

	return alarm_count;
}

void PSA_Command_EnableOut1_DisableOut2()
{
	  PSA.Out1.Enable = 1;

	  PSA.Out2.Enable = 0;
	  PSA.Out2.Ready = 0;
	  PSA.Out2.Run = 0;

	  PSA.Command.EnableOut1_DisableOut2 = 0;
}

void PSA_Command_EnableOut2_DisableOut1()
{
	  PSA.Out2.Enable = 1;

	  PSA.Out1.Enable = 0;
	  PSA.Out1.Ready = 0;
	  PSA.Out1.Run = 0;

	  PSA.Command.EnableOut2_DisableOut1 = 0;
}

void PSA_Command_EnableOut1_EnableOut2()
{
	  PSA.Out2.Enable = 1;
	  PSA.Out1.Enable = 1;

	  PSA.Command.EnableOut1_EnableOut2 = 0;
}

void PSA_Command_SetPriorityOut1()
{
	  PSA.OutPriority = 1;

	  PSA.Command.SetPriorityOut1 = 0;
}

void PSA_Command_SetPriorityOut2()
{
	  PSA.OutPriority = 2;

	  PSA.Command.SetPriorityOut2 = 0;
}

void PSA_CANSPI_RequestMessage_ResetData()
{
	PSA.CANSPI.RequestMessage.frame.data0 = 0;
	PSA.CANSPI.RequestMessage.frame.data1 = 0;
	PSA.CANSPI.RequestMessage.frame.data2 = 0;
	PSA.CANSPI.RequestMessage.frame.data3 = 0;
	PSA.CANSPI.RequestMessage.frame.data4 = 0;
	PSA.CANSPI.RequestMessage.frame.data5 = 0;
	PSA.CANSPI.RequestMessage.frame.data6 = 0;
	PSA.CANSPI.RequestMessage.frame.data7 = 0;
}

void PSA_Request_State()
{

}

void PSA_Request_Alarm()
{

}

void PSA_Request_OxygenPercentual()
{
	PSA_CANSPI_RequestMessage_ResetData();

	PSA.CANSPI.RequestMessage.frame.data0 = 0x4B;
	PSA.CANSPI.RequestMessage.frame.data2 = 0x0A;

	PSA.CANSPI.RequestMessage.frame.data4 =
			(PSA.KE25_OxygenSensor_1.Value >> 8);
	PSA.CANSPI.RequestMessage.frame.data5 =
			(PSA.KE25_OxygenSensor_1.Value >> 0);
}

void PSA_Request_InputAirDewpoint()
{
	PSA_CANSPI_RequestMessage_ResetData();

	PSA.CANSPI.RequestMessage.frame.data0 = 0x4B;
	PSA.CANSPI.RequestMessage.frame.data2 = 0x02;

	PSA.CANSPI.RequestMessage.frame.data4 =
			(PSA.DEW_InputAirDewpoint.Value >> 8);
	PSA.CANSPI.RequestMessage.frame.data5 =
			(PSA.DEW_InputAirDewpoint.Value >> 0);
}

void PSA_Request_InputAirPressure()
{
	PSA_CANSPI_RequestMessage_ResetData();

	PSA.CANSPI.RequestMessage.frame.data0 = 0x4B;
	PSA.CANSPI.RequestMessage.frame.data2 = 0x03;

	PSA.CANSPI.RequestMessage.frame.data4 =
			(PSA.B1_InputAirPressure.Value >> 8);
	PSA.CANSPI.RequestMessage.frame.data5 =
			(PSA.B1_InputAirPressure.Value >> 0);
}

void PSA_Request_OutputAirPressure_1()
{
	PSA_CANSPI_RequestMessage_ResetData();

	PSA.CANSPI.RequestMessage.frame.data0 = 0x4B;
	PSA.CANSPI.RequestMessage.frame.data2 = 0x04;

	PSA.CANSPI.RequestMessage.frame.data4 =
			(PSA.B2_OutputAirPressure_1.Value >> 8);
	PSA.CANSPI.RequestMessage.frame.data5 =
			(PSA.B2_OutputAirPressure_1.Value >> 0);
}

void PSA_Request_ProcessTankAirPressure()
{
	PSA_CANSPI_RequestMessage_ResetData();

	PSA.CANSPI.RequestMessage.frame.data0 = 0x4B;
	PSA.CANSPI.RequestMessage.frame.data2 = 0x05;

	PSA.CANSPI.RequestMessage.frame.data4 =
			(PSA.B3_ProcessTankAirPressure.Value >> 8);
	PSA.CANSPI.RequestMessage.frame.data5 =
			(PSA.B3_ProcessTankAirPressure.Value >> 0);
}

void PSA_Request_OutputAirPressure_2()
{
	PSA_CANSPI_RequestMessage_ResetData();

	PSA.CANSPI.RequestMessage.frame.data0 = 0x4B;
	PSA.CANSPI.RequestMessage.frame.data2 = 0x06;

	PSA.CANSPI.RequestMessage.frame.data4 =
			(PSA.B4_OutputAirPressure_2.Value >> 8);
	PSA.CANSPI.RequestMessage.frame.data5 =
			(PSA.B4_OutputAirPressure_2.Value >> 0);
}

void PSA_Request_AirFlowmeter()
{
	PSA_CANSPI_RequestMessage_ResetData();

	PSA.CANSPI.RequestMessage.frame.data0 = 0x4B;
	PSA.CANSPI.RequestMessage.frame.data2 = 0x01;

	PSA.CANSPI.RequestMessage.frame.data4 =
			(PSA.B3_ProcessTankAirPressure.Value >> 8);
	PSA.CANSPI.RequestMessage.frame.data5 =
			(PSA.B3_ProcessTankAirPressure.Value >> 0);
}

void PSA_Request_AverageAirFlowmeter()
{
	PSA_CANSPI_RequestMessage_ResetData();

	PSA.CANSPI.RequestMessage.frame.data0 = 0x4B;
	PSA.CANSPI.RequestMessage.frame.data2 = 0x1D;

	PSA.CANSPI.RequestMessage.frame.data4 =
			(PSA.IFM_AirFlowmeter.Value >> 8);
	PSA.CANSPI.RequestMessage.frame.data5 =
			(PSA.IFM_AirFlowmeter.Value >> 0);
}

void PSA_Request_Out2ValvePosition()
{
	PSA_CANSPI_RequestMessage_ResetData();

	PSA.CANSPI.RequestMessage.frame.data0 = 0x4B;
	PSA.CANSPI.RequestMessage.frame.data2 = 0x1D;

	PSA.CANSPI.RequestMessage.frame.data4 = PSA.Out2.Run;
}

void PSA_Request_DischangeValvePosition()
{

}

void PSA_Request_Out1ValvePosition()
{
	PSA_CANSPI_RequestMessage_ResetData();

	PSA.CANSPI.RequestMessage.frame.data0 = 0x4B;
	PSA.CANSPI.RequestMessage.frame.data2 = 0x1D;

	PSA.CANSPI.RequestMessage.frame.data4 = PSA.Out1.Run;
}

void PSA_Request_DeliveryValvePosition()
{

}

void PSA_Request_Out1WorkingHour()
{

}

void PSA_Request_Out2WorkingHour()
{

}

void PSA_Request_TotalWorkingHour()
{

}

void PSA_Request_ActualWorkingHour()
{

}

void PSA_Relay_RunningAndOutNotUsed()
{
	PSA.Relay.K1 = 1;
	PSA.Relay.K6 = 1;
	PSA.Relay.K5 = 1;
	PSA.Relay.K4 = 1;
}

void PSA_Relay_RunningAndOutUsed()
{
	PSA.Relay.K1 = 1;
	PSA.Relay.K6 = 1;
	PSA.Relay.K5 = 1;
	PSA.Relay.K4 = 0;
}

void PSA_Relay_GoingStandby()
{
	PSA.Relay.K1 = 1;
	PSA.Relay.K6 = 1;
	PSA.Relay.K5 = 0;
	PSA.Relay.K4 = 0;
}

void PSA_Relay_Standby()
{
	PSA.Relay.K1 = 1;
	PSA.Relay.K6 = 0;
	PSA.Relay.K5 = 0;
	PSA.Relay.K4 = 0;
}
