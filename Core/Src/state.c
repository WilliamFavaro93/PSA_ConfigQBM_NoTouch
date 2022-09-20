/**
  ******************************************************************************
  * @file   state.h
  * @author William Favaro
  * @date	12/05/2022
  * @brief  datetime functions
  *
  *
  ******************************************************************************
  * @note
  *
  *
  *
  ******************************************************************************
  */

#include <state.h>


/* CYCLE: Adsorption_1 -> Compensation_1 -> Compensation_2 -> Adsorption_2 -> Compensation_1 -> Compensation_2 -> */

extern PSAStruct PSA;


void State_DebugInit()
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

void State_OutValve()
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

void State_Adsorption1()
{

	PSA.ValveState[0] = 0xC6;
	State_OutValve();
	PSA.Time.NextStateTimer = PSA.Time.Adsorption_1; /* 275 ds */

}

void State_Compensation0()
{
	PSA.ValveState[0] = 0x00;
	State_OutValve();
	PSA.Time.NextStateTimer = PSA.Time.Compensation_0; /* 5 ds */

}

void State_Compensation1()
{
	PSA.ValveState[0] = 0xA0;
	State_OutValve();
	PSA.Time.NextStateTimer = PSA.Time.Compensation_1; /* 5 ds */

}

void State_Compensation2()
{
	PSA.ValveState[0] = 0x24;
	State_OutValve();
	PSA.Time.NextStateTimer = PSA.Time.Compensation_2; /* 5 ds */
}
void State_Adsorption2()
{
	PSA.ValveState[0] = 0xB8;
	State_OutValve();
	PSA.Time.NextStateTimer = PSA.Time.Adsorption_2; /* 275 ds */
}

/* -> Standby1 -> Standby2 -> Standby3 -> */
void State_PreStandby1()
{
	PSA.ValveState[0] = 0x08;
	PSA.Time.NextStateTimer = PSA.Time.PreStandby_1; /* 50 ds */

}
void State_PreStandby2()
{
	PSA.ValveState[0] = 0x48;
	PSA.Time.NextStateTimer = PSA.Time.PreStandby_2; /* 50 ds */
}
void State_Standby()
{
	PSA.ValveState[0] = 0x00;
	PSA.Time.NextStateTimer = 0; /* ds */
}





int State_NextState(int n)
{
	switch(n)
	{
	/* STANDBY */
	case -2:
		State_PreStandby1();
		return -1;
	case -1:
		State_PreStandby2();
		return 0;
	case 0:
		State_Standby();
		return 0;

	/* ADSORPTION_CYCLE */
	case 1:
		State_Adsorption1();
		return 2;
	case 2:
		State_Compensation0();
		return 3;
	case 3:
		State_Compensation1();
		return 4;
	case 4:
		State_Compensation2();
		return 5;
	case 5:
		State_Adsorption2();
		return 6;
	case 6:
		State_Compensation0();
		return 7;
	case 7:
		State_Compensation1();
		return 8;
	case 8:
		State_Compensation2();
		return 1;
	}
	return 0;
}
