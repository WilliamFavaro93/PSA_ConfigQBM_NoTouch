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
/* Private Function definition -----------------------------------------------*/
/* Public Function -----------------------------------------------------------*/
void DirectoryInit(uint8_t ID, char * nameDir, uint8_t nameDir_length)
{
	/* Salva il nome che dovrà avere la cartella alla sua creazione */
	FATMAN_DirectoryID_MemcpySetDirectoryName(ID, nameDir, FATMAN_DIRECTORYNAME_LENGTH);

	/* Assegna al file da creare il nome del tipo YYYYMMDD_nameDir */
	uint8_t DateString_length = 9;
	char CopyDateString[DateString_length];
	DATETIME_MemcpyGetDateString((char *)CopyDateString, DateString_length);
	FATMAN_RenameFilePath(ID, (char *)CopyDateString, (DateString_length - 1));

	/* Inizializza Directory[0] con lo stesso FilePath per leggere */
	FATMAN_DirectoryID_MemcpySetDirectoryName(0, nameDir, FATMAN_DIRECTORYNAME_LENGTH);
	FATMAN_RenameFilePath(0, (char *)CopyDateString, (DateString_length - 1));
	FATMAN_Read();

	/* Se esiste un file con filepath omonimo, lo ricrea, e ci scrive tutto il contenuto letto */
	FATMAN_Init(ID);
	FATMAN_Write(ID);
}

void CheckAlarmConditionToWriteSD(Alarm * Alarm, char * AlarmMessage, uint8_t sizeofAlarmMessage)
{
	if(Alarm->WriteToSD)
	{
		/* Scrive la data nel buffer */
		uint8_t DateString_withSeparator_length = 11;
		char CopyDateString_withSeparator[DateString_withSeparator_length];
		DATETIME_MemcpyGetDateString_withSeparator((char *)CopyDateString_withSeparator, DateString_withSeparator_length - 1);
		FATMAN_AddStringOnBuffer((char*)CopyDateString_withSeparator, (DateString_withSeparator_length - 1));
		FATMAN_AddStringOnBuffer(" ", 1);

		/* Scrive l'orario nel buffer */
		uint8_t TimeString_withSeparator_length = 9;
		char CopyTimeString_withSeparator[DateString_withSeparator_length];
		DATETIME_MemcpyGetTimeString_withSeparator((char *)CopyTimeString_withSeparator, TimeString_withSeparator_length - 1);
		FATMAN_AddStringOnBuffer((char*)CopyTimeString_withSeparator, (TimeString_withSeparator_length - 1));
		FATMAN_AddStringOnBuffer(" ", 1);

		/* Scrive il messaggio d'allarme nel buffer */
		FATMAN_AddStringOnBuffer((char*)AlarmMessage, sizeofAlarmMessage);
		/* Scrive "<<<" o ">>>" */
		if(Alarm->Trigger)
			FATMAN_AddStringOnBuffer("<<<", sizeof("<<<"));
		else
			FATMAN_AddStringOnBuffer(">>>", sizeof(">>>"));
		FATMAN_AddStringOnBuffer("\n", 1);

		/* Scrive tutto il messaggio nel buffer nel file di testo */
		FATMAN_Write(1);
		Alarm->WriteToSD = 0;
	}
}
/* Private Function ----------------------------------------------------------*/
/* End of the file -----------------------------------------------------------*/
