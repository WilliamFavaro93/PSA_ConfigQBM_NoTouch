/**
  ******************************************************************************
  * @file
  * @author
  * @date
  * @brief
  *
  ******************************************************************************
  * @note
  *
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef INC_PSA_REQUEST_H_
#define INC_PSA_REQUEST_H_

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
/* Defines -------------------------------------------------------------------*/
/* Typedef Struct definition -------------------------------------------------*/
typedef struct
{
	uint8_t NumberOfRequest;

	uint8_t State;
	uint8_t Alarm;
	uint8_t OxygenPercentual;
	uint8_t InputAirDewpoint;
	uint8_t InputAirPressure;
	uint8_t OutputAirPressure_1;
	uint8_t ProcessTankAirPressure;
	uint8_t OutputAirPressure_2;
	uint8_t AirFlowmeter;
	uint8_t AverageAirFlowmeter;
	uint8_t Out2ValvePosition;
	uint8_t DischangeValvePosition;
	uint8_t Out1ValvePosition;
	uint8_t DeliveryValvePosition;
	uint8_t Out1WorkingHour;
	uint8_t Out2WorkingHour;
	uint8_t TotalWorkingHour;
	uint8_t ActualWorkingHour;
} SetOfRequests;

/* Public Function definition ------------------------------------------------*/
/* Public Function definition: Get -------------------------------------------*/
uint8_t PSA_REQUEST__GetNumberOfRequest(SetOfRequests Alarm);
uint8_t PSA_REQUEST__GetState(SetOfRequests Alarm);
uint8_t PSA_REQUEST__GetAlarm(SetOfRequests Alarm);
uint8_t PSA_REQUEST__GetOxygenPercentual(SetOfRequests Alarm);
uint8_t PSA_REQUEST__GetInputAirDewpoint(SetOfRequests Alarm);
uint8_t PSA_REQUEST__GetInputAirPressure(SetOfRequests Alarm);
uint8_t PSA_REQUEST__GetOutputAirPressure_1(SetOfRequests Alarm);
uint8_t PSA_REQUEST__GetProcessTankAirPressure(SetOfRequests Alarm);
uint8_t PSA_REQUEST__GetOutputAirPressure_2(SetOfRequests Alarm);
uint8_t PSA_REQUEST__GetAirFlowmeter(SetOfRequests Alarm);
uint8_t PSA_REQUEST__GetAverageAirFlowmeter(SetOfRequests Alarm);
uint8_t PSA_REQUEST__GetOut2ValvePosition(SetOfRequests Alarm);
uint8_t PSA_REQUEST__GetDischangeValvePosition(SetOfRequests Alarm);
uint8_t PSA_REQUEST__GetOut1ValvePosition(SetOfRequests Alarm);
uint8_t PSA_REQUEST__GetDeliveryValvePosition(SetOfRequests Alarm);
uint8_t PSA_REQUEST__GetOut1WorkingHour(SetOfRequests Alarm);
uint8_t PSA_REQUEST__GetOut2WorkingHour(SetOfRequests Alarm);
uint8_t PSA_REQUEST__GetTotalWorkingHour(SetOfRequests Alarm);
uint8_t PSA_REQUEST__GetActualWorkingHour(SetOfRequests Alarm);
/* Public Function definition: Set -------------------------------------------*/
void PSA_REQUEST__SetState(SetOfRequests* Alarm);
void PSA_REQUEST__SetAlarm(SetOfRequests* Alarm);
void PSA_REQUEST__SetOxygenPercentual(SetOfRequests* Alarm);
void PSA_REQUEST__SetInputAirDewpoint(SetOfRequests* Alarm);
void PSA_REQUEST__SetInputAirPressure(SetOfRequests* Alarm);
void PSA_REQUEST__SetOutputAirPressure_1(SetOfRequests* Alarm);
void PSA_REQUEST__SetProcessTankAirPressure(SetOfRequests* Alarm);
void PSA_REQUEST__SetOutputAirPressure_2(SetOfRequests* Alarm);
void PSA_REQUEST__SetAirFlowmeter(SetOfRequests* Alarm);
void PSA_REQUEST__SetAverageAirFlowmeter(SetOfRequests* Alarm);
void PSA_REQUEST__SetOut2ValvePosition(SetOfRequests* Alarm);
void PSA_REQUEST__SetDischangeValvePosition(SetOfRequests* Alarm);
void PSA_REQUEST__SetOut1ValvePosition(SetOfRequests* Alarm);
void PSA_REQUEST__SetDeliveryValvePosition(SetOfRequests* Alarm);
void PSA_REQUEST__SetOut1WorkingHour(SetOfRequests* Alarm);
void PSA_REQUEST__SetOut2WorkingHour(SetOfRequests* Alarm);
void PSA_REQUEST__SetTotalWorkingHour(SetOfRequests* Alarm);
void PSA_REQUEST__SetActualWorkingHour(SetOfRequests* Alarm);
/* Public Function definition: Reset -----------------------------------------*/
void PSA_REQUEST__ResetState(SetOfRequests* Alarm);
void PSA_REQUEST__ResetAlarm(SetOfRequests* Alarm);
void PSA_REQUEST__ResetInputAirDewpoint(SetOfRequests* Alarm);
void PSA_REQUEST__ResetInputAirPressure(SetOfRequests* Alarm);
void PSA_REQUEST__ResetOutputAirPressure_1(SetOfRequests* Alarm);
void PSA_REQUEST__ResetProcessTankAirPressure(SetOfRequests* Alarm);
void PSA_REQUEST__ResetOutputAirPressure_2(SetOfRequests* Alarm);
void PSA_REQUEST__ResetAirFlowmeter(SetOfRequests* Alarm);
void PSA_REQUEST__ResetAverageAirFlowmeter(SetOfRequests* Alarm);
void PSA_REQUEST__ResetOut2ValvePosition(SetOfRequests* Alarm);
void PSA_REQUEST__ResetDischangeValvePosition(SetOfRequests* Alarm);
void PSA_REQUEST__ResetOut1ValvePosition(SetOfRequests* Alarm);
void PSA_REQUEST__ResetDeliveryValvePosition(SetOfRequests* Alarm);
void PSA_REQUEST__ResetOut1WorkingHour(SetOfRequests* Alarm);
void PSA_REQUEST__ResetOut2WorkingHour(SetOfRequests* Alarm);
void PSA_REQUEST__ResetTotalWorkingHour(SetOfRequests* Alarm);
void PSA_REQUEST__ResetActualWorkingHour(SetOfRequests* Alarm);

#endif /* INC_PSA_REQUEST_H_ */
