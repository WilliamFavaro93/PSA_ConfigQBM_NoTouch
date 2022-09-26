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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef INC_FATMAN_H_
#define INC_FATMAN_H_

/* Includes ------------------------------------------------------------------*/
#include "fatfs.h"
#include "string.h"
#include "stdint.h"

/* Exported macro ------------------------------------------------------------*/
#define DIRECTORYNAME_LENGTH 	10
#define FILEPATH_LENGTH 		(2*(DIRECTORYNAME_LENGTH) + 14)
#define N_DIRECTORY 			8
#define BUFFER_SIZE 			4096

#define BYTE_READ_EACH_STEP		32

/* Exported variables --------------------------------------------------------*/
/**
  * @brief  ManageDirectory structure definition
  */
typedef struct
{
	FRESULT State;
	char DirectoryName[DIRECTORYNAME_LENGTH];	/**< Directory's Name					*/
	char FilePath[FILEPATH_LENGTH];				/**< Path of the file					*/
	FIL SaveFIL;									/**< FIL structure of the file 			*/
	uint8_t FileIsCreated;							/**< 0: File is not already created
	 	 	 	 	 	 	 	 	 				1: File is created (DEBUG) 		*/
	uint8_t AlreadyWrittenOnce;						/**< 0: File is not already written once
	 	 	 	 	 	 	 	 	 	 	 	 	 1:	File is written once (DEBUG) 	*/
} ManageDirectory;

/**
  * @brief  ManageSD structure definition
  */
typedef struct
{
	uint8_t SDisPresent;
	uint8_t State;								/**< State of the driver 			*/
	uint8_t OpenFile_ID; 						/**< ID of the open file			*/
	FIL OpenFIL; 								/**< FIL structure of the open file */
	ManageDirectory Directory[N_DIRECTORY];		/**< array of ManageDirectory		*/
	char Buffer[BUFFER_SIZE];					/**< buffer							*/
	uint16_t Buffer_size;						/**< size of the buffer 			*/
} ManageSD;

/* Exported functions --------------------------------------------------------*/
void fatman_init(uint8_t Directory_ID);
void fatman_write(uint8_t Directory_ID);
void fatman_read(uint8_t Directory_ID);
void fatman_rename(uint8_t Directory_ID, char * NameFile, uint8_t NameFile_length);
void fatman_test_all();


#endif /* INC_FATMAN_H_ */
