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


/* Includes ------------------------------------------------------------------*/
#include <psa_request.h>
/* Defines -------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
/* Private Function definition -----------------------------------------------*/
/* Public Function definition ------------------------------------------------*/
/* Public Function definition: Get -------------------------------------------*/
uint8_t PSA_REQUEST__GetNumberOfRequest(SetOfRequests Alarm)
{
	return Alarm.NumberOfRequest;
}

uint8_t PSA_REQUEST__GetState(SetOfRequests Alarm)
{
	return Alarm.State;
}

uint8_t PSA_REQUEST__GetAlarm(SetOfRequests Alarm)
{
	return Alarm.Alarm;
}

uint8_t PSA_REQUEST__GetOxygenPercentual(SetOfRequests Alarm)
{
	return Alarm.OxygenPercentual;
}

uint8_t PSA_REQUEST__GetInputAirDewpoint(SetOfRequests Alarm)
{
	return Alarm.InputAirDewpoint;
}

uint8_t PSA_REQUEST__GetInputAirPressure(SetOfRequests Alarm)
{
	return Alarm.InputAirPressure;
}

uint8_t PSA_REQUEST__GetOutputAirPressure_1(SetOfRequests Alarm)
{
	return Alarm.OutputAirPressure_1;
}

uint8_t PSA_REQUEST__GetProcessTankAirPressure(SetOfRequests Alarm)
{
	return Alarm.ProcessTankAirPressure;
}

uint8_t PSA_REQUEST__GetOutputAirPressure_2(SetOfRequests Alarm)
{
	return Alarm.OutputAirPressure_2;
}

uint8_t PSA_REQUEST__GetAirFlowmeter(SetOfRequests Alarm)
{
	return Alarm.AirFlowmeter;
}

uint8_t PSA_REQUEST__GetAverageAirFlowmeter(SetOfRequests Alarm)
{
	return Alarm.AverageAirFlowmeter;
}

uint8_t PSA_REQUEST__GetOut2ValvePosition(SetOfRequests Alarm)
{
	return Alarm.Out2ValvePosition;
}

uint8_t PSA_REQUEST__GetDischangeValvePosition(SetOfRequests Alarm)
{
	return Alarm.DischangeValvePosition;
}

uint8_t PSA_REQUEST__GetOut1ValvePosition(SetOfRequests Alarm)
{
	return Alarm.Out1ValvePosition;
}

uint8_t PSA_REQUEST__GetDeliveryValvePosition(SetOfRequests Alarm)
{
	return Alarm.DeliveryValvePosition;
}

uint8_t PSA_REQUEST__GetOut1WorkingHour(SetOfRequests Alarm)
{
	return Alarm.Out1WorkingHour;
}

uint8_t PSA_REQUEST__GetOut2WorkingHour(SetOfRequests Alarm)
{
	return Alarm.Out2WorkingHour;
}

uint8_t PSA_REQUEST__GetTotalWorkingHour(SetOfRequests Alarm)
{
	return Alarm.TotalWorkingHour;
}

uint8_t PSA_REQUEST__GetActualWorkingHour(SetOfRequests Alarm)
{
	return Alarm.ActualWorkingHour;
}

uint8_t PSA_REQUEST_UpdateNumberOfRequest(SetOfRequests* Alarm)
{
	return Alarm->State + Alarm->Alarm + Alarm->OxygenPercentual + Alarm->InputAirDewpoint
			+ Alarm->InputAirPressure + Alarm->OutputAirPressure_1 + Alarm->ProcessTankAirPressure
			+ Alarm->OutputAirPressure_2 + Alarm->AirFlowmeter + Alarm->AverageAirFlowmeter
			+ Alarm->Out2ValvePosition + Alarm->DischangeValvePosition + Alarm->Out1ValvePosition
			+ Alarm->DeliveryValvePosition + Alarm->Out1WorkingHour + Alarm->Out2WorkingHour
			+ Alarm->TotalWorkingHour + Alarm->ActualWorkingHour;
}

/* Public Function definition: Set -------------------------------------------*/
void PSA_REQUEST__SetState(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->State = 1;
}

void PSA_REQUEST__SetAlarm(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->Alarm = 1;
}

void PSA_REQUEST__SetOxygenPercentual(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->OxygenPercentual = 1;
}

void PSA_REQUEST__SetInputAirDewpoint(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->InputAirDewpoint = 1;
}

void PSA_REQUEST__SetInputAirPressure(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->InputAirPressure = 1;
}

void PSA_REQUEST__SetOutputAirPressure_1(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->OutputAirPressure_1 = 1;
}

void PSA_REQUEST__SetProcessTankAirPressure(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->ProcessTankAirPressure = 1;
}

void PSA_REQUEST__SetOutputAirPressure_2(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->OutputAirPressure_2 = 1;
}

void PSA_REQUEST__SetAirFlowmeter(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->AirFlowmeter = 1;
}

void PSA_REQUEST__SetAverageAirFlowmeter(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->AverageAirFlowmeter = 1;
}

void PSA_REQUEST__SetOut2ValvePosition(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->Out2ValvePosition = 1;
}

void PSA_REQUEST__SetDischangeValvePosition(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->DischangeValvePosition = 1;
}

void PSA_REQUEST__SetOut1ValvePosition(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->Out1ValvePosition = 1;
}

void PSA_REQUEST__SetDeliveryValvePosition(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->DeliveryValvePosition = 1;
}

void PSA_REQUEST__SetOut1WorkingHour(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->Out1WorkingHour = 1;
}

void PSA_REQUEST__SetOut2WorkingHour(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->Out2WorkingHour = 1;
}

void PSA_REQUEST__SetTotalWorkingHour(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->TotalWorkingHour = 1;
}

void PSA_REQUEST__SetActualWorkingHour(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->ActualWorkingHour = 1;
}

/* Public Function definition: Reset -----------------------------------------*/
void PSA_REQUEST__ResetState(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->State = 0;
}

void PSA_REQUEST__ResetAlarm(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->Alarm = 0;
}

void PSA_REQUEST__ResetInputAirDewpoint(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->InputAirDewpoint = 0;
}

void PSA_REQUEST__ResetInputAirPressure(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->InputAirPressure = 0;
}

void PSA_REQUEST__ResetOutputAirPressure_1(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->OutputAirPressure_1 = 0;
}

void PSA_REQUEST__ResetProcessTankAirPressure(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->InputAirPressure = 0;
}

void PSA_REQUEST__ResetOutputAirPressure_2(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->OutputAirPressure_2 = 0;
}

void PSA_REQUEST__ResetAirFlowmeter(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->AirFlowmeter = 0;
}

void PSA_REQUEST__ResetAverageAirFlowmeter(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->AverageAirFlowmeter = 0;
}

void PSA_REQUEST__ResetOut2ValvePosition(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->Out2ValvePosition = 0;
}

void PSA_REQUEST__ResetDischangeValvePosition(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->DischangeValvePosition = 0;
}

void PSA_REQUEST__ResetOut1ValvePosition(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->Out1ValvePosition = 0;
}

void PSA_REQUEST__ResetDeliveryValvePosition(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->DeliveryValvePosition = 0;
}

void PSA_REQUEST__ResetOut1WorkingHour(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->Out1WorkingHour = 0;
}

void PSA_REQUEST__ResetOut2WorkingHour(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->Out2WorkingHour = 0;
}

void PSA_REQUEST__ResetTotalWorkingHour(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->TotalWorkingHour = 0;
}
void PSA_REQUEST__ResetActualWorkingHour(SetOfRequests* Alarm)
{
	Alarm->NumberOfRequest = PSA_REQUEST_UpdateNumberOfRequest(Alarm);
	Alarm->ActualWorkingHour = 0;
}
/* Private Function ----------------------------------------------------------*/
/* End of the file -----------------------------------------------------------*/
