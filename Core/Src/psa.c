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

/*
 * @brief This method add the value of out1 or out2, if active, to the CAN message
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_OutValve()
{
	if(PSA.Out1.Working)
	{
		PSA.Valve[0] += 1;
	}
	else if(PSA.Out2.Working)
	{
		PSA.Valve[1] += 1;
	}
}

/*
 * @brief This method update the value of psa structure when it reachs Adsorption1 state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_Adsorption1(uint8_t Module)
{
	if(PSA.Module > Module)
		PSA.Valve[Module] = 0xC6;
}

/*
 * @brief This method update the value of psa structure when it reachs Compensation0 state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_Compensation0(uint8_t Module)
{
	if(PSA.Module > Module)
		PSA.Valve[Module] = 0x00;
}

/*
 * @brief This method update the value of psa structure when it reachs Compensation1 state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_Compensation1_1(uint8_t Module)
{
	if(PSA.Module > Module)
		PSA.Valve[Module] = 0x20;
}

/*
 * @brief This method update the value of psa structure when it reachs Compensation1 state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_Compensation1_2(uint8_t Module)
{
	if(PSA.Module > Module)
		PSA.Valve[Module] = 0x04;
}

/*
 * @brief This method update the value of psa structure when it reachs Compensation2 state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_Compensation2(uint8_t Module)
{
	if(PSA.Module > Module)
		PSA.Valve[Module] = 0x24;
}

/*
 * @brief This method update the value of psa structure when it reachs Adsorption2 state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_Adsorption2(uint8_t Module)
{
	if(PSA.Module > Module)
		PSA.Valve[Module] = 0xB8;
}

/*
 * @brief This method update the value of psa structure when it reachs PreStandby1 state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_PreStandby1(uint8_t Module)
{
	if(PSA.Module > Module)
		PSA.Valve[Module] = 0x08;
}

/*
 * @brief This method update the value of psa structure when it reachs PreStandby2 state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_PreStandby2(uint8_t Module)
{
	if(PSA.Module > Module)
		PSA.Valve[Module] = 0x48;
}

/*
 * @brief This method update the value of psa structure when it reachs Standby state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_Standby(uint8_t Module)
{
	if(PSA.Module > Module)
		PSA.Valve[Module] = 0x00;
}

/*
 * @brief This method select the method to update psa structure
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_State_UpdateValveMessage()
{
	/* Reset -----------------------------------------------------------------*/
	PSA.Valve[0] = 0x00;
	PSA.Valve[1] = 0x00;

	/* Standby ---------------------------------------------------------------*/
	if(PSA.State == -2)
	{
		PSA_PreStandby1(0);
		PSA_PreStandby1(1);
		PSA.Time.StateTimer = PSA.Time.PreStandby_1;
	}
	if(PSA.State == -1)
	{
		PSA_PreStandby2(0);
		PSA_PreStandby2(1);
		PSA.Time.StateTimer = PSA.Time.PreStandby_2;
	}
	if(PSA.State == 0)
	{
		PSA_Standby(0);
		PSA_Standby(1);
		PSA.Time.StateTimer = 1;
	}

	/* Run -------------------------------------------------------------------*/
	if(PSA.State == 1)
	{
		PSA_Adsorption1(0);
		PSA_Adsorption1(1);
		PSA.Time.StateTimer = (PSA.Time.Adsorption - (PSA.Time.Compensation_0
				+ PSA.Time.Compensation_1 + PSA.Time.Compensation_2))/2;
	}
	if(PSA.State == 2)
	{
		PSA_Adsorption1(0);
		PSA_Compensation0(1);
		PSA.Time.StateTimer = PSA.Time.Compensation_0;
	}
	if(PSA.State == 3)
	{
		PSA_Adsorption1(0);
		PSA_Compensation1_1(1);
		PSA.Time.StateTimer = PSA.Time.Compensation_1;
	}
	if(PSA.State == 4)
	{
		PSA_Adsorption1(0);
		PSA_Compensation2(1);
		PSA.Time.StateTimer = PSA.Time.Compensation_2;
	}
	if(PSA.State == 5)
	{
		PSA_Adsorption1(0);
		PSA_Adsorption2(1);
		PSA.Time.StateTimer = (PSA.Time.Adsorption + 1 - (PSA.Time.Compensation_0
				+ PSA.Time.Compensation_1 + PSA.Time.Compensation_2))/2;
	}
	if(PSA.State == 6)
	{
		PSA_Compensation0(0);
		PSA_Adsorption2(1);
		PSA.Time.StateTimer = PSA.Time.Compensation_0;
	}
	if(PSA.State == 7)
	{
		PSA_Compensation1_1(0);
		PSA_Adsorption2(1);
		PSA.Time.StateTimer = PSA.Time.Compensation_1;
	}
	if(PSA.State == 8)
	{
		PSA_Compensation2(0);
		PSA_Adsorption2(1);
		PSA.Time.StateTimer = PSA.Time.Compensation_2;
	}
	if(PSA.State == 9)
	{
		PSA_Adsorption2(0);
		PSA_Adsorption2(1);
		PSA.Time.StateTimer = (PSA.Time.Adsorption - (PSA.Time.Compensation_0
				+ PSA.Time.Compensation_1 + PSA.Time.Compensation_2))/2;
	}
	if(PSA.State == 10)
	{
		PSA_Adsorption2(0);
		PSA_Compensation0(1);
		PSA.Time.StateTimer = PSA.Time.Compensation_0;
	}
	if(PSA.State == 11)
	{
		PSA_Adsorption2(0);
		PSA_Compensation1_2(1);
		PSA.Time.StateTimer = PSA.Time.Compensation_1;
	}
	if(PSA.State == 12)
	{
		PSA_Adsorption2(0);
		PSA_Compensation2(1);
		PSA.Time.StateTimer = PSA.Time.Compensation_2;
	}
	if(PSA.State == 13)
	{
		PSA_Adsorption2(0);
		PSA_Adsorption1(1);
		PSA.Time.StateTimer = (PSA.Time.Adsorption + 1 - (PSA.Time.Compensation_0
				+ PSA.Time.Compensation_1 + PSA.Time.Compensation_2))/2;
	}
	if(PSA.State == 14)
	{
		PSA_Compensation0(0);
		PSA_Adsorption1(1);
		PSA.Time.StateTimer = PSA.Time.Compensation_0;
	}
	if(PSA.State == 15)
	{
		PSA_Compensation1_2(0);
		PSA_Adsorption1(1);
		PSA.Time.StateTimer = PSA.Time.Compensation_1;
	}
	if(PSA.State == 16)
	{
		PSA_Compensation2(0);
		PSA_Adsorption1(1);
		PSA.Time.StateTimer = PSA.Time.Compensation_2;
	}

	PSA_OutValve();
	PSA.StateUpdated = 1;
}

void PSA_Mode_Run()
{
	PSA.Mode.Run = 0x01;
	PSA.Mode.Standby = 0x00;
}

void PSA_Mode_Standby()
{
	PSA.Mode.Run = 0x00;
	PSA.Mode.Standby = 0x01;
}

uint8_t PSA_Alarm_NumberOfAlarmsTriggered()
{
	uint8_t alarm_count = 0;

	if(PSA.Alarm.AL01_CANbusError.Trigger)
		alarm_count++;
	if(PSA.Alarm.AL02_LowAirPressure.Trigger)
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
	  PSA.Out2.Working = 0;

	  PSA.Command.EnableOut1_DisableOut2 = 0;
}

void PSA_Command_EnableOut2_DisableOut1()
{
	  PSA.Out2.Enable = 1;

	  PSA.Out1.Enable = 0;
	  PSA.Out1.Ready = 0;
	  PSA.Out1.Working = 0;

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

void PSA_Request_State()
{

}

void PSA_Request_Alarm()
{

}

void PSA_Request_OxygenPercentual()
{

}

void PSA_Request_InputAirDewpoint()
{

}

void PSA_Request_OutputAirPressure_1()
{

}

void PSA_Request_ProcessTankAirPressure()
{

}

void PSA_Request_OutputAirPressure_2()
{

}

void PSA_Request_AirFlowmeter()
{

}

void PSA_Request_AverageAirFlowmeter()
{

}

void PSA_Request_Out2ValvePosition()
{

}

void PSA_Request_DischangeValvePosition()
{

}

void PSA_Request_Out1ValvePosition()
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
