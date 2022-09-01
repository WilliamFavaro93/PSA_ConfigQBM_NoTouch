/**
  ******************************************************************************
  * @file   fatman.h
  * @author William Favaro
  * @date	13/07/2022
  * @brief  ManageSD and ManageDirectory structure definition
  * 		This module is created to simplify the usage of SD with STM32F4
  *
  ******************************************************************************
  * @note
  *
  *			fatman -> FAT File System Manager
  *
  *
  ******************************************************************************
  */

#ifndef INC_FATMAN_H_
#define INC_FATMAN_H_

#include "fatfs.h"
#include "string.h"
#include "stdint.h"

#define DIRECTORY_NAME_LENGTH 	10
#define FILEPATH_LENGTH 		(2*(DIRECTORY_NAME_LENGTH) + 14)
#define N_DIRECTORY 			8
#define BUFFER_SIZE 			4128

typedef struct
{
	uint8_t State;
	char DirectoryName[DIRECTORY_NAME_LENGTH];			/* Nome della cartella */
	char FilePath[FILEPATH_LENGTH];				/* Nome del percorso del file usato */
	FIL SaveFIL;					/*  */
	uint8_t FileIsCreated;			/*  */
	uint8_t AlreadyWrittenOnce;		/*  */
} ManageDirectory;

typedef struct
{
	uint16_t State;					/* Contiene lo stato passaggio per passaggio */
	uint8_t OpenFile_ID; 			/* Identifica la struttura usata */
	FIL OpenFIL; 					/* Salva a struttura aperta. */
	ManageDirectory Directory[N_DIRECTORY];	/* */
	char Buffer[BUFFER_SIZE];				/* */
	uint8_t Buffer_size;			/* */
} ManageSD;

void fm_init(uint8_t Directory_ID);
void fm_write(uint8_t Directory_ID);
void fm_read();
void fm_test_all();


#endif /* INC_FATMAN_H_ */
