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
//extern DateTime datetime;
extern ManageSD fatman;
/* Private Function definition -----------------------------------------------*/
/* Public Function -----------------------------------------------------------*/
void DirectoryInit(uint8_t ID, char * nameDir, uint8_t nameDir_length)
{
	memcpy(&fatman.Directory[ID].DirectoryName, (char *)nameDir, nameDir_length);

	uint8_t DateString_length = 9;
	char CopyDateString[DateString_length];
	DATETIME_MemcpyDateString((char *)CopyDateString, DateString_length);
	fatman_rename(ID, (char *)CopyDateString, (DateString_length - 1));

	memcpy(fatman.Directory[0].FilePath, (char *)fatman.Directory[ID].FilePath, sizeof(fatman.Directory[0].FilePath));
	fatman_read();

	fatman_init(ID);
	if(fatman.Buffer_size)
		fatman_write(ID);
}

void CheckAlarmConditionToWriteSD(Alarm * Alarm, char * AlarmMessage, uint8_t sizeofAlarmMessage)
{
	if(Alarm->WriteToSD)
	{
		/**/
		uint8_t DateString_withSeparator_length = 11;
		char CopyDateString_withSeparator[DateString_withSeparator_length];
		DATETIME_MemcpyDateString_withSeparator((char *)CopyDateString_withSeparator, DateString_withSeparator_length - 1);
		memcpy(&fatman.Buffer[0], (char*)CopyDateString_withSeparator, (DateString_withSeparator_length - 1));

		uint8_t TimeString_withSeparator_length = 9;
		char CopyTimeString_withSeparator[DateString_withSeparator_length];
		DATETIME_MemcpyTimeString_withSeparator((char *)CopyTimeString_withSeparator, TimeString_withSeparator_length - 1);
		memcpy(&fatman.Buffer[11], (char*)CopyTimeString_withSeparator, TimeString_withSeparator_length - 1);

		memcpy(&fatman.Buffer[20], (char*)AlarmMessage, sizeofAlarmMessage);

		if(Alarm->Trigger)
			memcpy(&fatman.Buffer[20 + sizeofAlarmMessage], "<<<", sizeof("<<<"));
		else
			memcpy(&fatman.Buffer[20 + sizeofAlarmMessage], ">>>", sizeof(">>>"));
		memcpy(&fatman.Buffer[99], "\n", 1);
		fatman.Buffer_size = 100;
		fatman_write(1);
		Alarm->WriteToSD = 0;
	}
}
/* Private Function ----------------------------------------------------------*/
/* End of the file -----------------------------------------------------------*/
