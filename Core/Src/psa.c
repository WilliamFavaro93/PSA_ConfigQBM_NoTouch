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

#include <psa.h>

PSAStruct PSA;

void PSA_DebugInit()
{
#if (DEBUG)
	PSA.Time.Adsorption_1 = 27;
	PSA.Time.Adsorption_2 = 27;
	PSA.Time.Compensation_0 = 1;
	PSA.Time.Compensation_1 = 1;
	PSA.Time.Compensation_2 = 1;
	PSA.Time.PreStandby_1 = 5;
	PSA.Time.PreStandby_2 = 5;
#endif /* DEBUG */
}

void PSA_OutValve()
{
	PSA.ValveState[1] = 0;
	if(/*PSA.OUT_1 == 2*/ PSA.Out1.Working)
	{
		PSA.ValveState[0]++;
	}
	else if(/*PSA.OUT_2 == 2*/ PSA.Out2.Working)
	{
		PSA.ValveState[1]++;
	}
}

void PSA_Adsorption1()
{

	PSA.ValveState[0] = 0xC6;
	PSA_OutValve();
	PSA.Time.StateTimer = PSA.Time.Adsorption_1; /* 275 ds */

}

void PSA_Compensation0()
{
	PSA.ValveState[0] = 0x00;
	PSA_OutValve();
	PSA.Time.StateTimer = PSA.Time.Compensation_0; /* 5 ds */

}

void PSA_Compensation1()
{
	PSA.ValveState[0] = 0xA0;
	PSA_OutValve();
	PSA.Time.StateTimer = PSA.Time.Compensation_1; /* 5 ds */

}

void PSA_Compensation2()
{
	PSA.ValveState[0] = 0x24;
	PSA_OutValve();
	PSA.Time.StateTimer = PSA.Time.Compensation_2; /* 5 ds */
}
void PSA_Adsorption2()
{
	PSA.ValveState[0] = 0xB8;
	PSA_OutValve();
	PSA.Time.StateTimer = PSA.Time.Adsorption_2; /* 275 ds */
}

/* -> Standby1 -> Standby2 -> Standby3 -> */
void PSA_PreStandby1()
{
	PSA.ValveState[0] = 0x08;
	PSA.Time.StateTimer = PSA.Time.PreStandby_1; /* 50 ds */

}
void PSA_PreStandby2()
{
	PSA.ValveState[0] = 0x48;
	PSA.Time.StateTimer = PSA.Time.PreStandby_2; /* 50 ds */
}
void PSA_Standby()
{
	PSA.ValveState[0] = 0x00;
	PSA.Time.StateTimer = 1; /* ds */
}





void PSA_UpdateState()
{

	/* STANDBY */
	if(PSA.State == -2)
		PSA_PreStandby1();
	if(PSA.State == -1)
		PSA_PreStandby2();
	if(PSA.State == 0)
		PSA_Standby();

	/* ADSORPTION_CYCLE */
	if(PSA.State == 1)
		PSA_Adsorption1();
	if(PSA.State == 2)
		PSA_Compensation0();
	if(PSA.State == 3)
		PSA_Compensation1();
	if(PSA.State == 4)
		PSA_Compensation2();
	if(PSA.State == 5)
		PSA_Adsorption2();
	if(PSA.State == 6)
		PSA_Compensation0();
	if(PSA.State == 7)
		PSA_Compensation1();
	if(PSA.State == 8)
		PSA_Compensation2();
	PSA.StateUpdated = 1;
}



void PSA_Relay_RunningAndOutNotUsed()
{
	PSA.Relay.K1 = PSA_RELAY_ON;
	PSA.Relay.K6 = PSA_RELAY_ON;
	PSA.Relay.K5 = PSA_RELAY_ON;
	PSA.Relay.K4 = PSA_RELAY_ON;
}

void PSA_Relay_RunningAndOutUsed()
{
	PSA.Relay.K1 = PSA_RELAY_ON;
	PSA.Relay.K6 = PSA_RELAY_ON;
	PSA.Relay.K5 = PSA_RELAY_ON;
	PSA.Relay.K4 = PSA_RELAY_OFF;
}

void PSA_Relay_GoingStandby()
{
	PSA.Relay.K1 = PSA_RELAY_ON;
	PSA.Relay.K6 = PSA_RELAY_ON;
	PSA.Relay.K5 = PSA_RELAY_OFF;
	PSA.Relay.K4 = PSA_RELAY_OFF;
}

void PSA_Relay_Standby()
{
	PSA.Relay.K1 = PSA_RELAY_ON;
	PSA.Relay.K6 = PSA_RELAY_OFF;
	PSA.Relay.K5 = PSA_RELAY_OFF;
	PSA.Relay.K4 = PSA_RELAY_OFF;
}
