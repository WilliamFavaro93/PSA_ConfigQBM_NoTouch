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
#include <stdint.h>
#include <alarm.h>

/* Defines -------------------------------------------------------------------*/
/* Typedef Struct definition -------------------------------------------------*/
typedef struct
{
	uint8_t TriggeredAlarms;			/**< number of alarms triggered */
	uint8_t TriggeredBlockingAlarms;	/**< number of blocking alarms triggered */

	Alarm AL01_CANbusError;				/**< define if AL01 is triggered:
	 	 	 	 	 	 	 	 	 	 0: AL01 is not triggered
	 	 	 	 	 	 	 	 	 	 1: AL01 is triggered				*/
	Alarm AL02_LowInputAirPressure;		/**< define if AL02 is triggered:
	 	 	 	 	 	 	 	 	 	 0: AL02 is not triggered
	 	 	 	 	 	 	 	 	 	 1: AL02 is triggered				*/
	Alarm AL05_LowProcessTankPressure;	/**< define if AL05 is triggered:
	 	 	 	 	 	 	 	 	 	 0: AL05 is not triggered
	 	 	 	 	 	 	 	 	 	 1: AL05 is triggered				*/
	Alarm AL11_External;				/**< define if AL11 is triggered:
	 	 	 	 	 	 	 	 	 	 0: AL11 is not triggered
	 	 	 	 	 	 	 	 	 	 1: AL11 is triggered				*/
	Alarm AL16_HighOut2Pressure;		/**< define if AL16 is triggered:
	 	 	 	 	 	 	 	 	 	 0: AL16 is not triggered
	 	 	 	 	 	 	 	 	 	 1: AL16 is triggered				*/
	Alarm AL17_HighDewpoint;			/**< define if AL17 is triggered:
	 	 	 	 	 	 	 	 	 	 0: AL17 is not triggered
	 	 	 	 	 	 	 	 	 	 1: AL17 is triggered				*/
	Alarm AL18_HighDewpoint;			/**< define if AL18 is triggered:
	 	 	 	 	 	 	 	 	 	 0: AL18 is not triggered
	 	 	 	 	 	 	 	 	 	 1: AL18 is triggered				*/
	Alarm AL19_HighOut1Pressure;		/**< not anymore used				*/
	Alarm AL20_PCComunicationFault;		/**< define if AL20 is triggered:
	 	 	 	 	 	 	 	 	 	 0: AL20 is not triggered
	 	 	 	 	 	 	 	 	 	 1: AL20 is triggered				*/
	Alarm AL31_B1ProbeFault;			/**< define if AL31 is triggered:
	 	 	 	 	 	 	 	 	 	 0: AL31 is not triggered
	 	 	 	 	 	 	 	 	 	 1: AL31 is triggered				*/
	Alarm AL32_B2ProbeFault;			/**< define if AL32 is triggered:
	 	 	 	 	 	 	 	 	 	 0: AL32 is not triggered
	 	 	 	 	 	 	 	 	 	 1: AL32 is triggered				*/
	Alarm AL33_B3ProbeFault;			/**< define if AL33 is triggered:
	 	 	 	 	 	 	 	 	 	 0: AL33 is not triggered
	 	 	 	 	 	 	 	 	 	 1: AL33 is triggered				*/
	Alarm AL34_B4ProbeFault;			/**< define if AL34 is triggered:
	 	 	 	 	 	 	 	 	 	 0: AL34 is not triggered
	 	 	 	 	 	 	 	 	 	 1: AL34 is triggered				*/
	Alarm AL35_IFWProbeFault;
	Alarm AL36_DEWProbeFault;
	Alarm AL37_KE25ProbeFault;
	Alarm AL40_PsaDischanging;			/**< define if AL40 is triggered:
	 	 	 	 	 	 	 	 	 	 0: AL40 is not triggered
	 	 	 	 	 	 	 	 	 	 1: AL40 is triggered				*/
	Alarm MSDC_MissingSDCard;				/**< define if MissingSDCard is triggered:
	 	 	 	 	 	 	 	 	 	 0: MissingSDCard is not triggered
	 	 	 	 	 	 	 	 	 	 1: MissingSDCard is triggered		*/
} SetOfAlarms;

/* Public Function definition ------------------------------------------------*/
/* Public Function definition: Get -------------------------------------------*/

/* Public Function definition: Set -------------------------------------------*/
/* Public Function definition: Reset -----------------------------------------*/

#endif /* INC_PSA_ALARM_H_ */
