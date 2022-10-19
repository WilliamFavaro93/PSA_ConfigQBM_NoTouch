/**
  ******************************************************************************
  * @file   fatman.c
  * @author William Favaro
  * @date	13/07/2022
  * @brief  fatman functions.
  * 		This module is created to simplify the usage of SD with STM32F4.
  *
  ******************************************************************************
  * @note
  *
  *			fatman -> FAT File System Manager
  *
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "fatman.h"
/* Defines -------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
ManageSD fatman;
/* Private Function definition -----------------------------------------------*/
/* Public Function -----------------------------------------------------------*/
/*
 * @brief This method is used to initialize.
 * It creates the directory if it doesn't exists.
 * It creates the file if it doesn't exists.
 * @author William Favaro
 * @date 05/08/2022
 * @param ID The number that identifies the directory
 */
void fatman_init(uint8_t ID)
{
	/* If the file does not exist, create the directory */
	f_mkdir((TCHAR const*)fatman.Directory[ID].DirectoryName);

	/* It creates the file */
	f_open(&fatman.OpenFIL,
			(TCHAR const*)fatman.Directory[ID].FilePath,
			FA_CREATE_ALWAYS|FA_WRITE);

	/* Save the file and close */
	memcpy(&fatman.Directory[ID].SaveFIL,
			&fatman.OpenFIL, sizeof(FIL));
	f_close(&fatman.OpenFIL);

	/* Update Directory State */
	fatman.Directory[ID].FileIsCreated = 1;
	fatman.Directory[ID].AlreadyWrittenOnce = 0;
}

/*
 * @brief This method is used to write the text in the buffer on the file
 * @author William Favaro
 * @date 05/08/2022
 * @param ID The number that identifies the directory and the file
 */
void fatman_write(uint8_t ID)
{
	/* Write the text saved in fm.rwFileBuffer in the file targeted by fm.Directory[ID].FilePath */
	uint32_t byteswritten;

	memcpy(&fatman.OpenFIL, &fatman.Directory[ID].SaveFIL,
			sizeof(FIL));
	fatman.OpenFile_ID = ID;

	f_write(&fatman.OpenFIL, (void *)&fatman.Buffer[0],
			fatman.Buffer_size, (void *)&byteswritten);
	f_sync(&fatman.OpenFIL);

	/* Save the FIL */
	memcpy(&fatman.Directory[ID].SaveFIL, &fatman.OpenFIL,
			sizeof(FIL));
	fatman.Directory[ID].AlreadyWrittenOnce = 1;

	/* Clear fm.rwFileBuffer */
	fatman.Buffer_size = 0;
	memset(&fatman.Buffer, 0, FATMAN_BUFFER_SIZE);

	/* Close fm.OpenFIL */
	f_close(&fatman.OpenFIL);
	fatman.OpenFile_ID = 0;
}

/*
 * @brief This method is used to read the text inside a file
 * @author William Favaro
 * @date 05/08/2022
 */
void fatman_read()
{
//	uint8_t status;
	uint32_t bytesread = 0;
	uint8_t fm_state = 0;

	/* It opens the file, if it exists, in read-only mode */
	fm_state = f_open(&fatman.OpenFIL,
			(TCHAR const*)fatman.Directory[0].FilePath, FA_READ);

	if(!fm_state)
	{
		fatman.OpenFile_ID = FATMAN_N_DIRECTORY + 1;

		/* Update Directory State */
		fatman.Directory[0].FileIsCreated = 1;
		fatman.Directory[0].AlreadyWrittenOnce = 0;

		f_read(&fatman.OpenFIL, &fatman.Buffer,
				FATMAN_BUFFER_SIZE, (void *)&bytesread);
		fatman.Buffer_size = bytesread;

		fatman.Directory[0].AlreadyWrittenOnce = 1;
	}

	/* Close fm.OpenFIL */
	f_close(&fatman.OpenFIL);
	fatman.OpenFile_ID = 0;
}

/*
 * @brief This method is used to rename the filepath
 * @author William Favaro
 * @date 05/08/2022
 */
void fatman_rename(uint8_t ID, char * NameFile, uint8_t NameFile_length)
{
	uint8_t i = 0;
	uint8_t DirectoryName_length = 0;
	/* fm.Directory[1].FilePath = "FILE/20220805_FILE" */
	memset((void *)fatman.Directory[ID].FilePath, 0, 30);

	DirectoryName_length = strlen((char *)fatman.Directory[ID].DirectoryName);

	memcpy(&fatman.Directory[ID].FilePath[i],
			(char *)fatman.Directory[ID].DirectoryName,
			DirectoryName_length);
	i += DirectoryName_length;

	memcpy(&fatman.Directory[ID].FilePath[i], "/", 1);
	i++;

	memcpy(&fatman.Directory[ID].FilePath[i],
			(char const*)NameFile, NameFile_length);
	i += NameFile_length;

	memcpy(&fatman.Directory[ID].FilePath[i], "_", 1);
	i++;

	memcpy(&fatman.Directory[ID].FilePath[i],
			(char const*)fatman.Directory[ID].DirectoryName,
			DirectoryName_length);
	i += DirectoryName_length;

	memcpy(&fatman.Directory[ID].FilePath[i], ".TXT", 4);
}
/* Private Function ----------------------------------------------------------*/
/* End of the file -----------------------------------------------------------*/
