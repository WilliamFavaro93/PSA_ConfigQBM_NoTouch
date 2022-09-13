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
