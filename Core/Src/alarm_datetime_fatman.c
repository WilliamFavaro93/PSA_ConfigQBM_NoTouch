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
#include <alarm_datetime_fatman.h>
/* Defines -------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
extern DateTime today;
extern ManageSD fatman;
/* Private Function definition -----------------------------------------------*/
/* Public Function -----------------------------------------------------------*/
void DirectoryInit(uint8_t ID, char * nameDir, uint8_t nameDir_length)
{
	memcpy(&fatman.Directory[ID].DirectoryName, (char *)nameDir, nameDir_length);
	fatman_rename(ID, (char *)today.DateString, 8);

	memcpy(fatman.Directory[0].FilePath, (char *)fatman.Directory[ID].FilePath, sizeof(fatman.Directory[0].FilePath));
	fatman_read();

	fatman_init(ID);
	if(fatman.Buffer_size)
		fatman_write(ID);
}

void CheckAlarmConditionToWriteSD(Alarm * Alarm, char * AlarmMessage, uint8_t sizeofAlarmMessage)
{
	if(Alarm->toWriteToSD)
	{
	  memcpy(&fatman.Buffer[0], (char*)today.DateString_withSeparator, 10);
	  memcpy(&fatman.Buffer[11], (char*)today.TimeString_withSeparator, 8);
	  memcpy(&fatman.Buffer[20], (char*)AlarmMessage, sizeofAlarmMessage);
	  if(Alarm->isTriggered)
		  memcpy(&fatman.Buffer[20 + sizeofAlarmMessage], "<<<", sizeof("<<<"));
	  else
		  memcpy(&fatman.Buffer[20 + sizeofAlarmMessage], ">>>", sizeof(">>>"));
	  memcpy(&fatman.Buffer[99], "\n", 1);
	  fatman.Buffer_size = 100;
	  fatman_write(1);
	  Alarm->toWriteToSD = 0;
	}
}
/* Private Function ----------------------------------------------------------*/
/* End of the file -----------------------------------------------------------*/
