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

/*
 * @brief This method update the value of psa structure when it reachs Compensation0 state
 * @author William Favaro
 * @date 21/09/2022
 */
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
void PSA_STATE_UpdateValve()
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
