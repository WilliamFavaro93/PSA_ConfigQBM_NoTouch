/*
 * PSA.h
 *
 *  Created on: 14 apr 2022
 *      Author: William.Favaro
 */

#ifndef PSA_H_
#define PSA_H_

#include "stdint.h"
//#include "fatfs.h"

/*** MODE ***/
typedef struct
{
	uint8_t Ready; /* It's Ready changes between 0 and 0xFF when someone press the graphical power button */
	uint8_t Run;
	uint8_t Standby;
} uint8_Mode;

/*** OUT ***/
typedef struct
{
	uint8_t Enable;
	uint8_t Ready;
	uint8_t Working;
} uint8_Out;

/*** DIGITAL INPUT ***/
typedef struct
{
	uint8_t Value;
} uint8_DigitalInput;

/*** ANALOG INPUT ***/
typedef struct{
	uint16_t Value;
	uint16_t UpperThreshold;
	uint16_t LowerThreshold;
}uint16_AnalogInput;

/*** TIME ***/
typedef struct{
	uint16_t Time;
}uint16_Time;

typedef struct{
	uint16_t Timer;
	uint16_t Refresh;
}uint16_Timer;

/*** ALARM ***/
/*		Blocking Alarm 	-> It resets only if the machine resets
 * 		Alarm 			-> It resets while the machine is working and when a condition happens
 */
typedef struct
{
	uint64_t State;

	uint8_t AL01_CANbusError;
	uint8_t AL02_LowAirPressure;
	uint8_t AL05_LowProcessTankPressure;
	uint8_t AL11_External;
	uint8_t AL16_HighOut2Pressure;
	uint8_t AL17_HighDewpoint;
	uint8_t AL18_HighDewpoint;
	uint8_t AL19_HighOut1Pressure;
	uint8_t AL20_PCComunicationFault;
	uint8_t AL31_B1ProbeFault;
	uint8_t AL32_B2ProbeFault;
	uint8_t AL33_B3ProbeFault;
	uint8_t AL34_B4ProbeFault;
	uint8_t AL40_PsaDischanging;
	uint8_t MissingSDCard;
} SetOfAlarms;

/*** RELAY ***/
typedef struct
{
	uint8_t K1;
	uint8_t K6;
	uint8_t K5;
	uint8_t K4;
} SetOfRelays;

/*** COMMAND ***/
typedef struct
{
	uint32_t State;
	uint8_t ArrayID[4];

//	uint8_t OutGoingNitrogen;
	uint8_t EnableOutGoingNitrogen;
	uint8_t DisableOutGoingNitrogen;
//	uint8_t EnableOut;
	uint8_t EnableOut1_DisableOut2;
	uint8_t EnableOut2_DisableOut1;
	uint8_t EnableOut1_EnableOut2;
//	uint8_t SetPriority;
	uint8_t SetPriorityOut1;
	uint8_t SetPriorityOut2;
//	uint8_t PulldownOn;
	uint8_t PulldownOn;
	uint8_t PulldownOff;
} SetOfCommands;

/*** Request ***/
typedef struct
{
	uint32_t State;
	uint16_t ID[20];
} SetOfRequests;

/*** CAN2 ***/
typedef struct
{
	uint32_t Ide;
	uint8_t State;
	uint32_t Error;

	uint16_Timer TransmitAliveMessage;
	uint8_t TransmitValveMessage;
	uint8_t ReceiveAliveMessage;

//	uint8_t AliveMessage[8];
//	uint8_t AliveMessage_timer;
//
//	uint8_t StateMessage[8];
//	uint8_t StateMessage_timer;
} ManageCAN2;

/*** CAN1 ***/
typedef struct
{
	uint32_t Ide;
	uint8_t State;

} ManageCANSPI;

//typedef struct
//{
//	uint8_t State;
//	uint8_t ID;
//	uint8_t DirectoryName[10];
//	uint8_t FileName[30];
//	uint8_t FileIsCreated;
//} ManageDirectory;
//
//typedef struct
//{
//	uint8_t State;
//	uint8_t OpenedFile_ID;
//	uint8_t FileLastID;
//	ManageDirectory EventDir;
//	uint8_t rwFileBuffer[512];
//} ManageSD;

typedef struct{
	/* Mode */
	uint8_Mode Mode;			/**/
	/* State */
	int State; 				/* This global variable is used by the tasks: StateTask & */
	uint16_Timer NextState; /* PSA.NextState is used by the tasks: StateTask & */
	uint16_Timer ReceiveValveMessage;
	/* OUT */
	uint8_Out Out1;
	uint8_Out Out2;
	uint8_t OUT_1;			/* OUT_1, OUT_2 */
	uint8_t OUT_2;			/* OUT_1, OUT_2 -> 0: Not used; 1: Can be used 2: Actually in use */
	uint8_t OUTPriority;
	/* ... */
	uint8_t CloseDrain;

	uint8_t ValveState[8];
	uint32_t MaskOutputPreview; // <- PSA.Valve.Module

	/* Command */
//	SetOfRequests Request;
	SetOfCommands Command;
	/* Analog Input */
	uint16_AnalogInput B1_IncomingAirPressure;			/* B1: 0 - 16 bar */
	uint16_AnalogInput B2_OutputPressure_1;				/* B2: 0 - 16 bar */
	uint16_AnalogInput B3_ProcessTankPressure;			/* B3: 0 - 16 bar */
	uint16_AnalogInput B4_OutputPressure_2;				/* B4: 0 - 16 bar */

	uint16_AnalogInput DP_IncomingAirDewpoint;
	uint16_AnalogInput FM_NitrogenFlowmeter;
	uint16_AnalogInput KE1_OxygenSensor_1;			/* KE: UpperTh = LowerTh*/
	uint16_AnalogInput KE2_OxygenSensor_2;			/* KE: */
	/* Digital Input */
	uint8_DigitalInput IN5_RemoteStartOUT_2;
	uint8_DigitalInput IN6_RemoteStartOUT_1;
	uint8_DigitalInput IN8_FaultAL11_EXT;
	/* Relay */
	SetOfRelays Relay;
	/* Alarm */
	SetOfAlarms Alarm;
	/* Time (in ds) */
	uint16_Time Adsorption; 		/* 0 - 3600 decimi */
//	uint16_Time InitialAdsorption; 	/* 0 - 3600 decimi */
	uint16_Time Compensation; 		/* 0 -  100 decimi */
	uint16_Time Standby_1;			/* 0 -  900 decimi */
	uint16_Time Standby_2;			/* 0 -  900 decimi */
	uint16_Time StartUp;			/* 0 - 1000 decimi */

	/* Task Management */
	ManageCANSPI CANSPI;
	ManageCAN2 CAN_2;
//	ManageSD SD;


} PSAStruct;

void PSA_Relay_RunningAndOutNotUsed();
void PSA_Relay_RunningAndOutUsed();
void PSA_Relay_GoingStandby();
void PSA_Relay_Standby();

#endif /* PSA_H_ */
