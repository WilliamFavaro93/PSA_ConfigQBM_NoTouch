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
#ifndef INC_ALARM_DATETIME_FATMAN_H_
#define INC_ALARM_DATETIME_FATMAN_H_

/* Includes ------------------------------------------------------------------*/
#include <datetime.h>
#include <fatman.h>
#include <alarm.h>
/* Defines -------------------------------------------------------------------*/
/* Typedef Struct definition -------------------------------------------------*/
/* Public Function definition ------------------------------------------------*/
void DirectoryInit(uint8_t ID, char * nameDir, uint8_t nameDir_length);
void CheckAlarmConditionToWriteSD(Alarm * Alarm, char * AlarmMessage, uint8_t sizeofAlarmMessage);

#endif /* INC_ALARM_DATETIME_FATMAN_H_ */
