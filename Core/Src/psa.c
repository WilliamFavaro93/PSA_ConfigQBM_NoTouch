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
	PSA.ValveState[1] = 0;
	if(PSA.Out1.Working)
	{
		PSA.ValveState[0]++;
	}
	else if(PSA.Out2.Working)
	{
		PSA.ValveState[1]++;
	}
}

/*
 * @brief This method update the value of psa structure when it reachs Adsorption1 state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_Adsorption1(uint8_t module)
{
	PSA.ValveState[module] = 0xC6;
}

/*
 * @brief This method update the value of psa structure when it reachs Compensation0 state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_Compensation0(uint8_t module)
{
	PSA.ValveState[module] = 0x00;
}

/*
 * @brief This method update the value of psa structure when it reachs Compensation1 state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_Compensation1_1(uint8_t module)
{
	PSA.ValveState[module] = 0x20;
}

/*
 * @brief This method update the value of psa structure when it reachs Compensation1 state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_Compensation1_2(uint8_t module)
{
	PSA.ValveState[module] = 0x04;
}

/*
 * @brief This method update the value of psa structure when it reachs Compensation2 state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_Compensation2(uint8_t module)
{
	PSA.ValveState[module] = 0x24;
	PSA.Time.StateTimer = PSA.Time.Compensation_2; /* 5 ds */
}

/*
 * @brief This method update the value of psa structure when it reachs Adsorption2 state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_Adsorption2(uint8_t module)
{
	PSA.ValveState[module] = 0xB8;
}

/*
 * @brief This method update the value of psa structure when it reachs PreStandby1 state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_PreStandby1(uint8_t module)
{
	PSA.ValveState[module] = 0x08;
}

/*
 * @brief This method update the value of psa structure when it reachs PreStandby2 state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_PreStandby2(uint8_t module)
{
	PSA.ValveState[module] = 0x48;
}

/*
 * @brief This method update the value of psa structure when it reachs Standby state
 * @author William Favaro
 * @date 21/09/2022
 */
void PSA_Standby(uint8_t module)
{
	PSA.ValveState[module] = 0x00;
}




/*
 * @brief This method select the method to update psa structure
 * @author William Favaro
 * @date 21/09/2022
 */
//void PSA_UpdateState()
//{
//	/* Standby ---------------------------------------------------------------*/
//	if(PSA.State == -2)
//		PSA_PreStandby1();
//	if(PSA.State == -1)
//		PSA_PreStandby2();
//	if(PSA.State == 0)
//		PSA_Standby();
//
//	/* Run -------------------------------------------------------------------*/
//	if(PSA.State == 1)
//		PSA_Adsorption1();
//	if(PSA.State == 2)
//		PSA_Compensation0();
//	if(PSA.State == 3)
//		PSA_Compensation1();
//	if(PSA.State == 4)
//		PSA_Compensation2();
//	if(PSA.State == 5)
//		PSA_Adsorption2();
//	if(PSA.State == 6)
//		PSA_Compensation0();
//	if(PSA.State == 7)
//		PSA_Compensation1();
//	if(PSA.State == 8)
//		PSA_Compensation2();
//
//	if(PSA.State > 0)
//		PSA_OutValve();
//
//	PSA.StateUpdated = 1;
//}

void PSA_UpdateState()
{
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
		PSA.Time.StateTimer = PSA.Time.PreStandby_1;
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
		PSA.Time.StateTimer = (PSA.Time.Adsorption - (PSA.Time.Compensation_0
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
		PSA.Time.StateTimer = (PSA.Time.Adsorption - (PSA.Time.Compensation_0
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
