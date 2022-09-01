/*
 * State.c
 *
 *  Created on: 12 mag 2022
 *      Author: William.Favaro
 */

#include <state.h>


/* CYCLE: Adsorption_1 -> Compensation_1 -> Compensation_2 -> Adsorption_2 -> Compensation_1 -> Compensation_2 -> */

//uint8_t charState[2]; /* Send the state by UART communication during DEBUG */
extern PSAStruct PSA;


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
	PSA.NextState.Timer = 27; /* 275 ds */

}

void State_Compensation0()
{
	PSA.ValveState[0] = 0x00;
	State_OutValve();
	PSA.NextState.Timer = 1; /* 5 ds */

}

void State_Compensation1()
{
	PSA.ValveState[0] = 0xA0;
	State_OutValve();
	PSA.NextState.Timer = 1; /* 5 ds */

}

void State_Compensation2()
{
	PSA.ValveState[0] = 0x24;
	State_OutValve();
	PSA.NextState.Timer = 1; /* 5 ds */
}
void State_Adsorption2()
{
	PSA.ValveState[0] = 0xB8;
	State_OutValve();
	PSA.NextState.Timer = 27; /* 275 ds */
}

/* -> Standby1 -> Standby2 -> Standby3 -> */
void State_PreStandby1()
{
	PSA.ValveState[0] = 0x08;
	PSA.NextState.Timer = 5; /* 50 ds */

}
void State_PreStandby2()
{
	PSA.ValveState[0] = 0x48;
	PSA.NextState.Timer = 5; /* 50 ds */
}
void State_Standby()
{
	PSA.ValveState[0] = 0x00;
	PSA.NextState.Timer = 0; /* ds */
}

#define STATE_COMPENSATION2
//#define STATE_COMPENSATION0

#ifdef STATE_COMPENSATION2
#ifdef STATE_COMPENSATION0
//if((define STATE_COMPENSATION2) && (define STATE_COMPENSATION0))
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
#endif
#endif

#ifdef STATE_COMPENSATION2
#ifndef STATE_COMPENSATION0
//if((define STATE_COMPENSATION2) && !(define STATE_COMPENSATION0))
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
		State_Compensation1();
		return 3;
	case 3:
		State_Compensation2();
		return 4;
	case 4:
		State_Adsorption2();
		return 5;
	case 5:
		State_Compensation1();
		return 6;
	case 6:
		State_Compensation2();
		return 1;
	}
	return 0;
}
#endif
#endif

#ifndef STATE_COMPENSATION2
//if(!(define STATE_COMPENSATION2))
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
		State_Compensation2();
		return 3;
	case 3:
		State_Adsorption2();
		return 4;
	case 4:
		State_Compensation2();
		return 1;
	}
	return 0;
}
#endif
