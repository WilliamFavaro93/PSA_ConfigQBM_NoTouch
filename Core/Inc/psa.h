/**
  ******************************************************************************
  * @file   psa.h
  * @author William Favaro
  * @date	14/04/2022
  * @brief  psa structure definition
  *
  * 		This file defines the structure psa
  *
  ******************************************************************************
  * @note
  *
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef PSA_H_
#define PSA_H_

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
//#include "alarm.h"
#include "canspi.h"

#include "psa_mode.h"
#include "psa_time.h"
#include "psa_out.h"
#include "psa_state.h"
#include "psa_request.h"
#include "psa_command.h"
#include "psa_alarm.h"

/* Time structure ------------------------------------------------------------*/
//typedef struct
//{
//	uint16_t Adsorption;
//	uint16_t TotalCompensation;
//	uint16_t Compensation_0;
//	uint16_t Compensation_1;
//	uint16_t Compensation_2;
//	uint16_t PreStandby_1;
//	uint16_t PreStandby_2;
//
//	uint16_t SendAliveMessageToValve_Timer;
//	uint16_t SendAliveMessageToValve_Refresh;
//
//	uint16_t SendStateMessageToValve_Timer;
//	uint16_t SendStateMessageToValve_Refresh;
//} uint16_Time;

/* Mode structure ------------------------------------------------------------*/
//typedef struct
//{
//	uint8_t Enable;		/**< define if psa start to work:
//	 	 	 	 	 	 0: psa is not in standby-mode
//	 	 	 	 	 	 1:	psa is in standy-mode			*/
//	uint8_t Ready; 		/**< define if psa is in ready-mode:
//	 	 	 	 	 	 0: psa is not in ready-mode
//	 	 	 	 	 	 1: psa is in ready-mode			*/
//	uint8_t Run;		/**< define if psa is run-mode:
//	 	 	 	 	 	 0: psa is not run-mode
//	 	 	 	 	 	 1:	psa is run-mode					*/
//} uint8_Mode;

/* Out structure -------------------------------------------------------------*/
//typedef struct
//{
//	uint8_t Enable;		/**< define if the out is enabled:
//	 	 	 	 	 	 0: the out is not enabled
//	 	 	 	 	 	 1: the out is enabled				*/
//	uint8_t Ready;		/**< define if the out is ready:
//	 	 	 	 	 	 0: the out is not ready
//	 	 	 	 	 	 1: the out is ready				*/
//	uint8_t Run;	/**< define if the out is working:
//	 	 	 	 	 	 0: the out is not working
//	 	 	 	 	 	 1: the out is working				*/
//} uint8_Out;

/* State structure -------------------------------------------------------------*/
//typedef struct
//{
//	 int8_t Value;
//	uint8_t Timer;
//	uint8_t Update;
//	uint8_t Module;	/**< the number of modules */
//	uint8_t Valve[8];
//} int8_State;

/* Digital Input structure ---------------------------------------------------*/
typedef struct
{
	uint8_t Value;
} uint8_DigitalInput;

/* Analog Input structure ----------------------------------------------------*/
typedef struct{
	uint16_t Value;				/**< value of the analog input */
	uint16_t Average;
	uint16_t Acquisition;		/**< define if last acquisition value is already saved in queue */

	uint16_t UpperThreshold;	/**< upper threshold of the analog input */
	uint16_t LowerThreshold;	/**< lower threshold of the analog input */

	uint16_t UpperLimit;		/**< upper limit of the analog input */
	uint16_t LowerLimit;		/**< lower limit of the analog input */
}uint16_AnalogInput;


/*		Blocking Alarm 	-> It resets only if the machine resets
 * 		Alarm 			-> It resets while the machine is working and when a condition happens
 */
/* Alarm and Fault structure -------------------------------------------------*/
//typedef struct
//{
//	uint8_t NumberOfTriggeredAlarms;			/**< number of alarms triggered */
//	uint8_t NumberOfTriggeredBlockingAlarms;	/**< number of blocking alarms triggered */
//
//	Alarm AL01_CANbusError;				/**< define if AL01 is triggered:
//	 	 	 	 	 	 	 	 	 	 0: AL01 is not triggered
//	 	 	 	 	 	 	 	 	 	 1: AL01 is triggered				*/
//	Alarm AL02_LowInputAirPressure;		/**< define if AL02 is triggered:
//	 	 	 	 	 	 	 	 	 	 0: AL02 is not triggered
//	 	 	 	 	 	 	 	 	 	 1: AL02 is triggered				*/
//	Alarm AL05_LowProcessTankPressure;	/**< define if AL05 is triggered:
//	 	 	 	 	 	 	 	 	 	 0: AL05 is not triggered
//	 	 	 	 	 	 	 	 	 	 1: AL05 is triggered				*/
//	Alarm AL11_External;				/**< define if AL11 is triggered:
//	 	 	 	 	 	 	 	 	 	 0: AL11 is not triggered
//	 	 	 	 	 	 	 	 	 	 1: AL11 is triggered				*/
//	Alarm AL16_HighOut2Pressure;		/**< define if AL16 is triggered:
//	 	 	 	 	 	 	 	 	 	 0: AL16 is not triggered
//	 	 	 	 	 	 	 	 	 	 1: AL16 is triggered				*/
//	Alarm AL17_HighDewpoint;			/**< define if AL17 is triggered:
//	 	 	 	 	 	 	 	 	 	 0: AL17 is not triggered
//	 	 	 	 	 	 	 	 	 	 1: AL17 is triggered				*/
//	Alarm AL18_HighDewpoint;			/**< define if AL18 is triggered:
//	 	 	 	 	 	 	 	 	 	 0: AL18 is not triggered
//	 	 	 	 	 	 	 	 	 	 1: AL18 is triggered				*/
//	Alarm AL19_HighOut1Pressure;		/**< not anymore used				*/
//	Alarm AL20_PCComunicationFault;		/**< define if AL20 is triggered:
//	 	 	 	 	 	 	 	 	 	 0: AL20 is not triggered
//	 	 	 	 	 	 	 	 	 	 1: AL20 is triggered				*/
//	Alarm AL31_B1ProbeFault;			/**< define if AL31 is triggered:
//	 	 	 	 	 	 	 	 	 	 0: AL31 is not triggered
//	 	 	 	 	 	 	 	 	 	 1: AL31 is triggered				*/
//	Alarm AL32_B2ProbeFault;			/**< define if AL32 is triggered:
//	 	 	 	 	 	 	 	 	 	 0: AL32 is not triggered
//	 	 	 	 	 	 	 	 	 	 1: AL32 is triggered				*/
//	Alarm AL33_B3ProbeFault;			/**< define if AL33 is triggered:
//	 	 	 	 	 	 	 	 	 	 0: AL33 is not triggered
//	 	 	 	 	 	 	 	 	 	 1: AL33 is triggered				*/
//	Alarm AL34_B4ProbeFault;			/**< define if AL34 is triggered:
//	 	 	 	 	 	 	 	 	 	 0: AL34 is not triggered
//	 	 	 	 	 	 	 	 	 	 1: AL34 is triggered				*/
//	Alarm AL35_IFWProbeFault;
//	Alarm AL36_DEWProbeFault;
//	Alarm AL37_KE25ProbeFault;
//	Alarm AL40_PsaDischanging;			/**< define if AL40 is triggered:
//	 	 	 	 	 	 	 	 	 	 0: AL40 is not triggered
//	 	 	 	 	 	 	 	 	 	 1: AL40 is triggered				*/
//	Alarm MSDC_MissingSDCard;				/**< define if MissingSDCard is triggered:
//	 	 	 	 	 	 	 	 	 	 0: MissingSDCard is not triggered
//	 	 	 	 	 	 	 	 	 	 1: MissingSDCard is triggered		*/
//} SetOfAlarms;

/* Relay structure -----------------------------------------------------------*/
typedef struct
{
	uint8_t K1;			/**< define if Relay K1 is ON:
	 	 	 	 	 	 0: Relay K1 is OFF
	 	 	 	 	 	 1: Relay K1 is ON			*/
	uint8_t K6;			/**< define if Relay K6 is ON:
	 	 	 	 	 	 0: Relay K6 is OFF
	 	 	 	 	 	 1: Relay K6 is ON			*/
	uint8_t K5;			/**< define if Relay K5 is ON:
	 	 	 	 	 	 0: Relay K5 is OFF
	 	 	 	 	 	 1: Relay K5 is ON			*/
	uint8_t K4;			/**< define if Relay K4 is ON:
	 	 	 	 	 	 0: Relay K4 is OFF
	 	 	 	 	 	 1: Relay K4 is ON			*/
} SetOfRelays;


/* Command structure ---------------------------------------------------------*/
//typedef struct
//{
//	uint8_t EnableOutGoingNitrogen;		/**< define if the command EnableOutGoingNitrogen must be managed:
//	 	 	 	 	 	 	 	 	 	 0: EnableOutGoingNitrogen must not be managed
//	 	 	 	 	 	 	 	 	 	 1: EnableOutGoingNitrogen must be managed		*/
//	uint8_t DisableOutGoingNitrogen;	/**< define if the command DisableOutGoingNitrogen must be managed:
//	 	 	 	 	 	 	 	 	 	 0: DisableOutGoingNitrogen must not be managed
//	 	 	 	 	 	 	 	 	 	 1: DisableOutGoingNitrogen must be managed		*/
//	uint8_t EnableOut1_DisableOut2;		/**< define if the command EnableOut1_DisableOut2 must be managed:
//	 	 	 	 	 	 	 	 	 	 0: EnableOut1_DisableOut2 must not be managed
//	 	 	 	 	 	 	 	 	 	 1: EnableOut1_DisableOut2 must be managed		*/
//	uint8_t EnableOut2_DisableOut1;		/**< define if the command EnableOut2_DisableOut1 must be managed:
//	 	 	 	 	 	 	 	 	 	 0: EnableOut2_DisableOut1 must not be managed
//	 	 	 	 	 	 	 	 	 	 1: EnableOut2_DisableOut1 must be managed		*/
//	uint8_t EnableOut1_EnableOut2;		/**< define if the command EnableOut1_EnableOut2 must be managed:
//	 	 	 	 	 	 	 	 	 	 0: EnableOut1_EnableOut2 must not be managed
//	 	 	 	 	 	 	 	 	 	 1: EnableOut1_EnableOut2 must be managed		*/
//	uint8_t SetPriorityOut1;			/**< define if the command SetPriorityOut1 must be managed:
//	 	 	 	 	 	 	 	 	 	 0: SetPriorityOut1 must not be managed
//	 	 	 	 	 	 	 	 	 	 1: SetPriorityOut1 must be managed		*/
//	uint8_t SetPriorityOut2;			/**< define if the command SetPriorityOut2 must be managed:
//	 	 	 	 	 	 	 	 	 	 0: SetPriorityOut2 must not be managed
//	 	 	 	 	 	 	 	 	 	 1: SetPriorityOut2 must be managed		*/
//	uint8_t PulldownOn;					/**< define if the command PulldownOn must be managed:
//	 	 	 	 	 	 	 	 	 	 0: PulldownOn must not be managed
//	 	 	 	 	 	 	 	 	 	 1: PulldownOn must be managed		*/
//	uint8_t PulldownOff;				/**< define if the command PulldownOff must be managed:
//	 	 	 	 	 	 	 	 	 	 0: PulldownOff must not be managed
//	 	 	 	 	 	 	 	 	 	 1: PulldownOff must be managed		*/
//} SetOfCommands;

/* Request structure ---------------------------------------------------------*/
//typedef struct
//{
//	uint8_t State;
//	uint8_t Alarm;
//	uint8_t OxygenPercentual;
//	uint8_t InputAirDewpoint;
//	uint8_t InputAirPressure;
//	uint8_t OutputAirPressure_1;
//	uint8_t ProcessTankAirPressure;
//	uint8_t OutputAirPressure_2;
//	uint8_t AirFlowmeter;
//	uint8_t AverageAirFlowmeter;
//	uint8_t Out2ValvePosition;
//	uint8_t DischangeValvePosition;
//	uint8_t Out1ValvePosition;
//	uint8_t DeliveryValvePosition;
//	uint8_t Out1WorkingHour;
//	uint8_t Out2WorkingHour;
//	uint8_t TotalWorkingHour;
//	uint8_t ActualWorkingHour;
//} SetOfRequests;

/* Controller Area Network 2 structure ---------------------------------------*/
typedef struct
{
	uint32_t Ide;
	uint8_t State;
	uint32_t Error;

	uint8_t AliveMessageReceived;
} ManageCAN2;

/* Controller Area Network 1 structure ---------------------------------------*/
typedef struct
{
	uint32_t Ide;
	uint8_t State;

	uCAN_MSG ReceiveMessage;
	uCAN_MSG RequestMessage;
} ManageCANSPI;

/* Pressure Swing Adsorption structure ---------------------------------------*/
typedef struct{
	/* Time ------------------------------------------------------------------*/
	uint16_Time Time;		/**< the time structure managed by TimeTask */
	/* Mode ------------------------------------------------------------------*/
	uint8_Mode Mode;		/**< the mode structure managed by ModeTask */
	/* State -----------------------------------------------------------------*/
	int8_State State;		/**< the state structure managed by StateTask */
	/* Out -------------------------------------------------------------------*/
	uint8_Out Out1;
	uint8_Out Out2;
	uint8_t OutPriority;
	/* Valve -----------------------------------------------------------------*/
//	uint8_t Module;	/**< the number of modules */
//	uint8_t Valve[8];

	/* Command */
	SetOfRequests Request;
	SetOfCommands Command;
	/* Analog Input */
	uint16_AnalogInput B1_InputAirPressure;			/* B1: 0 - 16 bar */
	uint16_AnalogInput B2_OutputAirPressure_1;		/* B2: 0 - 16 bar */
	uint16_AnalogInput B3_ProcessTankAirPressure;	/* B3: 0 - 16 bar */
	uint16_AnalogInput B4_OutputAirPressure_2;		/* B4: 0 - 16 bar */

	uint16_AnalogInput DEW_InputAirDewpoint;
	uint16_AnalogInput IFM_AirFlowmeter;
	uint16_AnalogInput KE25_OxygenSensor_1;			/* KE: UpperTh = LowerTh*/
	uint16_AnalogInput KE25_OxygenSensor_2;			/* KE: */
	/* Digital Input */
	uint8_DigitalInput IN5_RemoteStartOUT_2;
	uint8_DigitalInput IN6_RemoteStartOUT_1;
	uint8_DigitalInput IN8_FaultAL11_EXT;
	/* Relay */
	SetOfRelays Relay;
	/* Alarm */
	SetOfAlarms Alarm;
	/* Task Management */
	ManageCANSPI CANSPI;
	ManageCAN2 CAN_2;
} PSAStruct;

/* Public Function -----------------------------------------------------------*/
/* Public Function: PSA.Time -------------------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/
void PSA_TIME_SetAdsorption(uint16_t TimeToSet);
void PSA_TIME_SetCompensation_0(uint16_t TimeToSet);
void PSA_TIME_SetCompensation_1(uint16_t TimeToSet);
void PSA_TIME_SetCompensation_2(uint16_t TimeToSet);
void PSA_TIME_SetPreStandby_1(uint16_t TimeToSet);
void PSA_TIME_SetPreStandby_2(uint16_t TimeToSet);
void PSA_TIME_Set_Standby();

/* Public Function definition: Get -------------------------------------------*/
uint16_t PSA_TIME_GetAdsorption();
uint16_t PSA_TIME_Get_Adsorption();
uint16_t PSA_TIME_GetCompensation_0();
uint16_t PSA_TIME_GetCompensation_1();
uint16_t PSA_TIME_GetCompensation_2();
uint16_t PSA_TIME_GetPreStandby_1();
uint16_t PSA_TIME_GetPreStandby_2();
uint16_t PSA_TIME_Get_Standby();

/* Public Function: PSA.Mode -------------------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/
void PSA_MODE_SetEnable();
void PSA_MODE_SetDisable();
void PSA_MODE_SetReady();
void PSA_MODE_SetNotReady();
void PSA_MODE_SetRun();
void PSA_MODE_SetStandby();

/* Public Function definition: Get -------------------------------------------*/
uint8_t PSA_MODE_GetEnable();
uint8_t PSA_MODE_GetReady();
uint8_t PSA_MODE_GetRun();

/* Public Function: PSA.Out1 -------------------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/
void PSA_OUT1_Enable();
void PSA_OUT1_Disable();
void PSA_OUT1_Ready();
void PSA_OUT1_NotReady();
void PSA_OUT1_Run();
void PSA_OUT1_Standby();
/* Public Function definition: Get -------------------------------------------*/
uint8_t PSA_OUT1_GetEnable();
uint8_t PSA_OUT1_GetReady();
uint8_t PSA_OUT1_GetRun();

/* Public Function: PSA.Out2 -------------------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/
void PSA_OUT2_Enable();
void PSA_OUT2_Disable();
void PSA_OUT2_Ready();
void PSA_OUT2_NotReady();
void PSA_OUT2_Run();
void PSA_OUT2_Standby();
/* Public Function definition: Get -------------------------------------------*/
uint8_t PSA_OUT2_GetEnable();
uint8_t PSA_OUT2_GetReady();
uint8_t PSA_OUT2_GetRun();

/* Public Function: PSA.State ------------------------------------------------*/
/* Private Function definition -----------------------------------------------*/
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
/* Public Function: PSA.State ------------------------------------------------*/
void PSA_State_UpdateState();
/* Public Function: PSA.Command ----------------------------------------------*/
/* Private Function definition -----------------------------------------------*/
/* Public Function definition: Get -------------------------------------------*/
uint8_t PSA_COMMAND_GetEnableOutGoingNitrogen();
uint8_t PSA_COMMAND_GetDisableOutGoingNitrogen();
uint8_t PSA_COMMAND_GetEnableOut1_DisableOut2();
uint8_t PSA_COMMAND_GetEnableOut2_DisableOut1();
uint8_t PSA_COMMAND_GetEnableOut1_EnableOut2();
uint8_t PSA_COMMAND_GetSetPriorityOut1();
uint8_t PSA_COMMAND_GetSetPriorityOut2();
uint8_t PSA_COMMAND_GetPulldownOn();
uint8_t PSA_COMMAND_GetPulldownOff();
/* Public Function definition: Set -------------------------------------------*/
void PSA_COMMAND_SetEnableOutGoingNitrogen();
void PSA_COMMAND_SetDisableOutGoingNitrogen();
void PSA_COMMAND_SetEnableOut1_DisableOut2();
void PSA_COMMAND_SetEnableOut2_DisableOut1();
void PSA_COMMAND_SetEnableOut1_EnableOut2();
void PSA_COMMAND_SetSetPriorityOut1();
void PSA_COMMAND_SetSetPriorityOut2();
void PSA_COMMAND_SetPulldownOn();
void PSA_COMMAND_SetPulldownOff();
/* Public Function definition: Reset -----------------------------------------*/
void PSA_COMMAND_ResetEnableOutGoingNitrogen();
void PSA_COMMAND_ResetDisableOutGoingNitrogen();
void PSA_COMMAND_ResetEnableOut1_DisableOut2();
void PSA_COMMAND_ResetEnableOut2_DisableOut1();
void PSA_COMMAND_ResetEnableOut1_EnableOut2();
void PSA_COMMAND_ResetSetPriorityOut1();
void PSA_COMMAND_ResetSetPriorityOut2();
void PSA_COMMAND_ResetPulldownOn();
void PSA_COMMAND_ResetPulldownOff();

/* TODO ----------------------------------------------------------------------*/
/* Public Function: PSA.Request ----------------------------------------------*/
/* Private Function definition -----------------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/
/* Public Function definition: Get -------------------------------------------*/

/* TODO ----------------------------------------------------------------------*/
/* Public Function: PSA.Alarm ------------------------------------------------*/
/* Public Function definition: Init ------------------------------------------*/
void PSA_ALARM_AL01_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF);
void PSA_ALARM_AL02_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF);
void PSA_ALARM_AL05_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF);
void PSA_ALARM_AL11_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF);
void PSA_ALARM_AL16_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF);
void PSA_ALARM_AL17_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF);
void PSA_ALARM_AL18_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF);
void PSA_ALARM_AL19_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF);
void PSA_ALARM_AL20_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF);
void PSA_ALARM_AL31_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF);
void PSA_ALARM_AL32_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF);
void PSA_ALARM_AL33_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF);
void PSA_ALARM_AL34_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF);
void PSA_ALARM_AL35_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF);
void PSA_ALARM_AL36_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF);
void PSA_ALARM_AL37_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF);
void PSA_ALARM_AL40_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF);
void PSA_ALARM_MSDC_Init(uint16_t RefreshTimer_ON, uint16_t RefreshTimer_OFF);
/* Public Function definition: Enable ----------------------------------------*/
void PSA_ALARM_AL01_Enable();
void PSA_ALARM_AL02_Enable();
void PSA_ALARM_AL05_Enable();
void PSA_ALARM_AL11_Enable();
void PSA_ALARM_AL16_Enable();
void PSA_ALARM_AL17_Enable();
void PSA_ALARM_AL18_Enable();
void PSA_ALARM_AL19_Enable();
void PSA_ALARM_AL20_Enable();
void PSA_ALARM_AL31_Enable();
void PSA_ALARM_AL32_Enable();
void PSA_ALARM_AL33_Enable();
void PSA_ALARM_AL34_Enable();
void PSA_ALARM_AL35_Enable();
void PSA_ALARM_AL36_Enable();
void PSA_ALARM_AL37_Enable();
void PSA_ALARM_AL40_Enable();
void PSA_ALARM_MSDC_Enable();
/* Public Function definition: Disable ---------------------------------------*/
void PSA_ALARM_AL01_Disable();
void PSA_ALARM_AL02_Disable();
void PSA_ALARM_AL05_Disable();
void PSA_ALARM_AL11_Disable();
void PSA_ALARM_AL16_Disable();
void PSA_ALARM_AL17_Disable();
void PSA_ALARM_AL18_Disable();
void PSA_ALARM_AL19_Disable();
void PSA_ALARM_AL20_Disable();
void PSA_ALARM_AL31_Disable();
void PSA_ALARM_AL32_Disable();
void PSA_ALARM_AL33_Disable();
void PSA_ALARM_AL34_Disable();
void PSA_ALARM_AL35_Disable();
void PSA_ALARM_AL36_Disable();
void PSA_ALARM_AL37_Disable();
void PSA_ALARM_AL40_Disable();
void PSA_ALARM_MSDC_Disable();
/* Public Function definition: GetEnable -------------------------------------*/
uint8_t PSA_ALARM_AL01_GetEnable();
uint8_t PSA_ALARM_AL02_GetEnable();
uint8_t PSA_ALARM_AL05_GetEnable();
uint8_t PSA_ALARM_AL11_GetEnable();
uint8_t PSA_ALARM_AL16_GetEnable();
uint8_t PSA_ALARM_AL17_GetEnable();
uint8_t PSA_ALARM_AL18_GetEnable();
uint8_t PSA_ALARM_AL19_GetEnable();
uint8_t PSA_ALARM_AL20_GetEnable();
uint8_t PSA_ALARM_AL31_GetEnable();
uint8_t PSA_ALARM_AL32_GetEnable();
uint8_t PSA_ALARM_AL33_GetEnable();
uint8_t PSA_ALARM_AL34_GetEnable();
uint8_t PSA_ALARM_AL35_GetEnable();
uint8_t PSA_ALARM_AL36_GetEnable();
uint8_t PSA_ALARM_AL37_GetEnable();
uint8_t PSA_ALARM_AL40_GetEnable();
uint8_t PSA_ALARM_MSDC_GetEnable();
/* Public Function definition: GetTrigger ------------------------------------*/
uint8_t PSA_ALARM_AL01_GetTrigger();
uint8_t PSA_ALARM_AL02_GetTrigger();
uint8_t PSA_ALARM_AL05_GetTrigger();
uint8_t PSA_ALARM_AL11_GetTrigger();
uint8_t PSA_ALARM_AL16_GetTrigger();
uint8_t PSA_ALARM_AL17_GetTrigger();
uint8_t PSA_ALARM_AL18_GetTrigger();
uint8_t PSA_ALARM_AL19_GetTrigger();
uint8_t PSA_ALARM_AL20_GetTrigger();
uint8_t PSA_ALARM_AL31_GetTrigger();
uint8_t PSA_ALARM_AL32_GetTrigger();
uint8_t PSA_ALARM_AL33_GetTrigger();
uint8_t PSA_ALARM_AL34_GetTrigger();
uint8_t PSA_ALARM_AL35_GetTrigger();
uint8_t PSA_ALARM_AL36_GetTrigger();
uint8_t PSA_ALARM_AL37_GetTrigger();
uint8_t PSA_ALARM_AL40_GetTrigger();
uint8_t PSA_ALARM_MSDC_GetTrigger();
/* Public Function definition: GetWriteToSD ----------------------------------*/
uint8_t PSA_ALARM_AL01_GetWriteToSD();
uint8_t PSA_ALARM_AL02_GetWriteToSD();
uint8_t PSA_ALARM_AL05_GetWriteToSD();
uint8_t PSA_ALARM_AL11_GetWriteToSD();
uint8_t PSA_ALARM_AL16_GetWriteToSD();
uint8_t PSA_ALARM_AL17_GetWriteToSD();
uint8_t PSA_ALARM_AL18_GetWriteToSD();
uint8_t PSA_ALARM_AL19_GetWriteToSD();
uint8_t PSA_ALARM_AL20_GetWriteToSD();
uint8_t PSA_ALARM_AL31_GetWriteToSD();
uint8_t PSA_ALARM_AL32_GetWriteToSD();
uint8_t PSA_ALARM_AL33_GetWriteToSD();
uint8_t PSA_ALARM_AL34_GetWriteToSD();
uint8_t PSA_ALARM_AL35_GetWriteToSD();
uint8_t PSA_ALARM_AL36_GetWriteToSD();
uint8_t PSA_ALARM_AL37_GetWriteToSD();
uint8_t PSA_ALARM_AL40_GetWriteToSD();
uint8_t PSA_ALARM_MSDC_GetWriteToSD();
/* Public Function definition: Get -------------------------------------------*/
uint8_t PSA_ALARM_GetNumberOfTriggeredAlarms();
uint8_t PSA_ALARM_GetNumberOfTriggeredBlockingAlarms();
/* Public Function definition: ResetWriteToSD --------------------------------*/
void PSA_ALARM_AL01_ResetWriteToSD();
void PSA_ALARM_AL02_ResetWriteToSD();
void PSA_ALARM_AL05_ResetWriteToSD();
void PSA_ALARM_AL11_ResetWriteToSD();
void PSA_ALARM_AL16_ResetWriteToSD();
void PSA_ALARM_AL17_ResetWriteToSD();
void PSA_ALARM_AL18_ResetWriteToSD();
void PSA_ALARM_AL19_ResetWriteToSD();
void PSA_ALARM_AL20_ResetWriteToSD();
void PSA_ALARM_AL31_ResetWriteToSD();
void PSA_ALARM_AL32_ResetWriteToSD();
void PSA_ALARM_AL33_ResetWriteToSD();
void PSA_ALARM_AL34_ResetWriteToSD();
void PSA_ALARM_AL35_ResetWriteToSD();
void PSA_ALARM_AL36_ResetWriteToSD();
void PSA_ALARM_AL37_ResetWriteToSD();
void PSA_ALARM_AL40_ResetWriteToSD();
void PSA_ALARM_MSDC_ResetWriteToSD();
/* Public Function definition: Check -----------------------------------------*/
void PSA_ALARM_AL01_Check(uint8_t Condition);
void PSA_ALARM_AL02_Check(uint8_t Condition);
void PSA_ALARM_AL05_Check(uint8_t Condition);
void PSA_ALARM_AL11_Check(uint8_t Condition);
void PSA_ALARM_AL16_Check(uint8_t Condition);
void PSA_ALARM_AL17_Check(uint8_t Condition);
void PSA_ALARM_AL18_Check(uint8_t Condition);
void PSA_ALARM_AL19_Check(uint8_t Condition);
void PSA_ALARM_AL20_Check(uint8_t Condition);
void PSA_ALARM_AL31_Check(uint8_t Condition);
void PSA_ALARM_AL32_Check(uint8_t Condition);
void PSA_ALARM_AL33_Check(uint8_t Condition);
void PSA_ALARM_AL34_Check(uint8_t Condition);
void PSA_ALARM_AL35_Check(uint8_t Condition);
void PSA_ALARM_AL36_Check(uint8_t Condition);
void PSA_ALARM_AL37_Check(uint8_t Condition);
void PSA_ALARM_AL40_Check(uint8_t Condition);
void PSA_ALARM_MSDC_Check(uint8_t Condition);

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

uint8_t PSA_Alarm_NumberOfAlarmsTriggered();
uint8_t PSA_Alarm_NumberOfBlockingAlarmsTriggered();

void PSA_Command_EnableOut1_DisableOut2();
void PSA_Command_EnableOut2_DisableOut1();
void PSA_Command_EnableOut1_EnableOut2();
void PSA_Command_SetPriorityOut1();
void PSA_Command_SetPriorityOut2();

void PSA_Request_State();
void PSA_Request_Alarm();
void PSA_Request_OxygenPercentual();
void PSA_Request_InputAirDewpoint();
void PSA_Request_InputAirPressure();
void PSA_Request_OutputAirPressure_1();
void PSA_Request_ProcessTankAirPressure();
void PSA_Request_OutputAirPressure_2();
void PSA_Request_AirFlowmeter();
void PSA_Request_AverageAirFlowmeter();
void PSA_Request_Out2ValvePosition();
void PSA_Request_DischangeValvePosition();
void PSA_Request_Out1ValvePosition();
void PSA_Request_DeliveryValvePosition();
void PSA_Request_Out1WorkingHour();
void PSA_Request_Out2WorkingHour();
void PSA_Request_TotalWorkingHour();
void PSA_Request_ActualWorkingHour();

void PSA_Relay_RunningAndOutNotUsed();
void PSA_Relay_RunningAndOutUsed();
void PSA_Relay_GoingStandby();
void PSA_Relay_Standby();


#endif /* PSA_H_ */
