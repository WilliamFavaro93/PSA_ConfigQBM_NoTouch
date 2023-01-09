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
#ifndef INC_PSA_ALARM_H_
#define INC_PSA_ALARM_H_

/* Includes ------------------------------------------------------------------*/
//#include <stdint.h>
#include <alarm.h>

/* Defines -------------------------------------------------------------------*/
/* Typedef Struct definition -------------------------------------------------*/
typedef struct
{
	uint8_t NumberOfTriggeredAlarms;			/**< number of alarms triggered */
	uint8_t NumberOfTriggeredBlockingAlarms;	/**< number of blocking alarms triggered */

	Alarm AL01_CANbusError;
	Alarm AL02_LowInputAirPressure;
	Alarm AL05_LowProcessTankPressure;
	Alarm AL11_External;
	Alarm AL16_HighOut2Pressure;
	Alarm AL17_HighDewpoint;
	Alarm AL18_HighDewpoint;
	Alarm AL19_HighOut1Pressure;		/**< not anymore used				*/
	Alarm AL20_PCComunicationFault;
	Alarm AL31_B1ProbeFault;
	Alarm AL32_B2ProbeFault;
	Alarm AL33_B3ProbeFault;
	Alarm AL34_B4ProbeFault;
	Alarm AL35_IFWProbeFault;
	Alarm AL36_DEWProbeFault;
	Alarm AL37_KE25ProbeFault;
	Alarm AL40_PsaDischanging;
	Alarm MSDC_MissingSDCard;
} SetOfAlarms;

/* Public Function definition ------------------------------------------------*/
/* Public Function definition: Get -------------------------------------------*/
/* Public Function definition: Set -------------------------------------------*/
/* Public Function definition: Reset -----------------------------------------*/

#endif /* INC_PSA_ALARM_H_ */
