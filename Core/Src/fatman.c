/*
 * 		@file fatman.c
 *		@brief This module is created to simplify the usage of SD with STM32F4
 *      @author William.Favaro
 *      @date 13/07/2022
 *
 *      "fatman" stands for FAT File System Manager
 */


#include "fatman.h"

#define FATMAN_AUTEST 1

ManageSD fm;

/*** PRIVATE METHOD REFERENCEs ***/

/*** PUBLIC METHODs ***/
/*
 * This method is used to initialize. It creates the directory if it doesn't exists. It creates the file if it doesn't exists.
 * @author William Favaro
 * @date 05/08/2022
 * @param ID The number that identifies the directory
 */
void fm_init(uint8_t ID)
{
	/* If the file does not exist, create the directory */
	f_mkdir((TCHAR const*)fm.Directory[ID].DirectoryName);

	/* It creates the file */
	f_open(&fm.OpenFIL, (TCHAR const*)fm.Directory[ID].FilePath, FA_CREATE_ALWAYS|FA_WRITE);

	/* Save the file and close */
	memcpy(&fm.Directory[ID].SaveFIL, &fm.OpenFIL, sizeof(FIL));

	/* Update Directory State */
	fm.Directory[ID].FileIsCreated = 1;
	fm.Directory[ID].AlreadyWrittenOnce = 0;
}

/*
 * This method is used to write the text in the buffer on the file
 * @author William Favaro
 * @date 05/08/2022
 * @param ID The number that identifies the directory and the file
 */
void fm_write(uint8_t ID)
{
	/* Write the text saved in fm.rwFileBuffer in the file targeted by fm.Directory[ID].FilePath */
	uint32_t byteswritten;
	memcpy(&fm.OpenFIL, &fm.Directory[ID].SaveFIL, sizeof(FIL));
	fm.OpenFile_ID = ID;
	f_write(&fm.OpenFIL, (void *)&fm.Buffer, fm.Buffer_size, (void *)&byteswritten);
	f_sync(&fm.OpenFIL);

	/* Save the FIL */
	memcpy(&fm.Directory[ID].SaveFIL, &fm.OpenFIL, sizeof(FIL));
	fm.Directory[ID].AlreadyWrittenOnce = 1;

	/* Clear fm.rwFileBuffer */
	fm.Buffer_size = 0;
	memset(&fm.Buffer, 0, 255);

	/* Close fm.OpenFIL */
	f_close(&fm.OpenFIL);
	fm.OpenFile_ID = 0;
}

/* NOTE: Deve andare a leggere dal buffer qual'è il percorso */
void fm_read()
{
	fm.OpenFile_ID = N_DIRECTORY + 1;
	f_open(&fm.OpenFIL, (TCHAR const*)fm.Buffer, FA_READ);
	f_read(&fm.OpenFIL, (void *)&fm.Buffer, BUFFER_SIZE, (void *)&fm.Buffer_size);
	f_close(&fm.OpenFIL);
	fm.OpenFile_ID = 0;
}

/*** PRIVATE METHODs ***/


/*** UNIT TEST ***/
/* WHI == WhatHappensIf */
#if FATMAN_AUTEST

/*
 * The purpose of this test is to see if it works normally
 * @author William Favaro
 * @date 05/08/2022
 */
void fm_test_NormalUsage1()
{
	/* Fatman */
	memcpy(&fm.Directory[1].DirectoryName, "FIGA", sizeof("FIGA"));
	memcpy(&fm.Directory[1].FilePath, "FIGA/FIGA.TXT", sizeof("FIGA/FIGA.TXT"));
	fm_init(1);
	memcpy(&fm.Buffer, "Odio tutti\n", sizeof("Odio tutti\n"));
	fm.Buffer_size = strlen("Odio tutti\n");
	fm_write(1);
}

/*
 * The purpose of this test is to see if it can adapt to the situation
 * @author William Favaro
 * @date 05/08/2022
 */
void fm_test_NormalUsage2()
{
	uint8_t ID = 2;
	uint8_t NameDir[] = "TEST2";
	uint8_t NameFile[] = "20220805";
	uint8_t wtext[] = "Funziona Bene!!\n";
	/* fm.Directory[1].DirectoryName = "FILE" */
	memcpy(&fm.Directory[ID].DirectoryName, &NameDir, sizeof(NameDir));
	/* fm.Directory[1].FilePath = "FILE/20220805_FILE" */
	memset((void *)fm.Directory[ID].FilePath, 0, 30);
	strcat((char *)fm.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fm.Directory[ID].FilePath, "/");
	strcat((char *)fm.Directory[ID].FilePath, (char const*)NameFile);
	strcat((char *)fm.Directory[ID].FilePath, "_");
	strcat((char *)fm.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fm.Directory[ID].FilePath, ".TXT");
	/* Fatman */
	fm_init(ID);
	memcpy(&fm.Buffer, wtext, strlen((char const*)wtext));
	fm.Buffer_size = strlen((char const*)wtext);
	fm_write(ID);
}

/*
 * The purpose of this test is testing what happen when I create a new file in the same directory
 * @author William Favaro
 * @date 05/08/2022
 */
void fm_test_WHITheFilePathChanges()
{
	uint8_t ID = 2;
	uint8_t NameDir[] = "TEST2";
	uint8_t NameFile[] = "20220804";
	uint8_t wtext[] = "Funziona Bene se all'interno della cartella c'è anche il file 20220805_TEST1\n";
	/* fm.Directory[1].DirectoryName = "FILE" */
	memcpy(&fm.Directory[ID].DirectoryName, &NameDir, sizeof(NameDir));
	/* fm.Directory[1].FilePath = "FILE/20220805_FILE" */
	memset((void *)fm.Directory[ID].FilePath, 0, 30);
	strcat((char *)fm.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fm.Directory[ID].FilePath, "/");
	strcat((char *)fm.Directory[ID].FilePath, (char const*)NameFile);
	strcat((char *)fm.Directory[ID].FilePath, "_");
	strcat((char *)fm.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fm.Directory[ID].FilePath, ".TXT");
	/* Fatman */
	fm_init(ID);
	memcpy(&fm.Buffer, wtext, strlen((char const*)wtext));
	fm.Buffer_size = strlen((char const*)wtext);
	fm_write(ID);
}

/*
 * The purpose of this test is testing what happen when I write more times in the same file
 * @author William Favaro
 * @date 05/08/2022
 */
void fm_test_WHIitsWritedSeveralConsecutiveTimes()
{
	uint8_t ID = 3;
	uint8_t NameDir[] = "TEST3";
	uint8_t NameFile[] = "20220805";
	uint8_t wtext[] = "Diobello\n";
	uint8_t nTimes = 10;

	/* fm.Directory[1].DirectoryName = "FILE" */
	memcpy(&fm.Directory[ID].DirectoryName, &NameDir, sizeof(NameDir));
	/* fm.Directory[1].FilePath = "FILE/20220805_FILE" */
	memset((void *)fm.Directory[ID].FilePath, 0, 30);
	strcat((char *)fm.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fm.Directory[ID].FilePath, "/");
	strcat((char *)fm.Directory[ID].FilePath, (char const*)NameFile);
	strcat((char *)fm.Directory[ID].FilePath, "_");
	strcat((char *)fm.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fm.Directory[ID].FilePath, ".TXT");

	/* Fatman */
	fm_init(ID);
	for(uint8_t i = 0; i < nTimes; i++)
	{
		memcpy(&fm.Buffer, wtext, strlen((char const*)wtext));
		fm.Buffer_size = strlen((char const*)wtext);
		fm_write(ID);
	}
}

/*
 * The purpose of this test is to simulate what could happen if I read a file too big for the buffer to before writing
 * @author William Favaro
 * @date 05/08/2022
 *
 * The only limit is the BUFFER_SIZE
 */
void fm_test_CheckIf4096IsTheLimit()
{
	uint8_t ID = 4;
	uint8_t NameDir[] = "TEST4";
	uint8_t NameFile[] = "20220829";
	uint8_t wtext[] = "tanti auguri e buon compleanno!\n";
//	uint8_t wtext_size = 32;

	/* fm.Directory[1].DirectoryName = "FILE" */
	memcpy(&fm.Directory[ID].DirectoryName, &NameDir, sizeof(NameDir));
	/* fm.Directory[1].FilePath = "FILE/20220829_FILE" */
	memset((void *)fm.Directory[ID].FilePath, 0, 30);
	strcat((char *)fm.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fm.Directory[ID].FilePath, "/");
	strcat((char *)fm.Directory[ID].FilePath, (char const*)NameFile);
	strcat((char *)fm.Directory[ID].FilePath, "_");
	strcat((char *)fm.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fm.Directory[ID].FilePath, ".TXT");

	/* create the file to test */
	uint16_t bw = 0;
	fm_init(ID);
	memcpy(&fm.Buffer, wtext, strlen((char const*)wtext));
	fm.Buffer_size = strlen((char const*)wtext);
	for(uint8_t i = 0; i < 129; i++)
	{
		memcpy(&fm.Buffer, wtext, strlen((char const*)wtext));
		fm.Buffer_size = strlen((char const*)wtext);
		fm_write(ID);
		bw += strlen((char const*)wtext);
	}
	fm.State = bw;

	/* It creates the file */
	uint16_t br = 0;
	f_open(&fm.OpenFIL, (TCHAR const*)fm.Directory[ID].FilePath, FA_READ);
	f_read(&fm.OpenFIL, (void *)&fm.Buffer, 4127, (void *)&br);
	f_close(&fm.OpenFIL);
	fm.State = br;



	f_open(&fm.OpenFIL, "TEST3/20220805_TEST3_1.TXT", FA_CREATE_ALWAYS|FA_WRITE);
	f_write(&fm.OpenFIL, (void *)&fm.Buffer, 4127, (void *)&br);
	f_close(&fm.OpenFIL);
	fm.State = br;
}

void fm_test_read()
{
	uint8_t ID = 5;
	uint8_t NameDir[] = "TEST5";
	uint8_t NameFile[] = "20220829";

	/* fm.Directory[1].DirectoryName = "FILE" */
	memcpy(&fm.Directory[ID].DirectoryName, &NameDir, sizeof(NameDir));
	/* fm.Directory[1].FilePath = "FILE/20220829_FILE" */
	memset((void *)fm.Directory[ID].FilePath, 0, 30);
	strcat((char *)fm.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fm.Directory[ID].FilePath, "/");
	strcat((char *)fm.Directory[ID].FilePath, (char const*)NameFile);
	strcat((char *)fm.Directory[ID].FilePath, "_");
	strcat((char *)fm.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fm.Directory[ID].FilePath, ".TXT");

	fm.Buffer_size = strlen("FIGA/FIGA.TXT ");
	memcpy(fm.Buffer, "FIGA/FIGA.TXT ", fm.Buffer_size);
	fm_read();

	fm_init(ID);
	fm_write(ID);
}

/*
 * The purpose of this test is to simulate what could happen if I read a file too big for the buffer to before writing
 * @author William Favaro
 * @date 05/08/2022
 */
void fm_test_WHItheBufferIsTooBig()
{
	uint8_t ID = 6;
	uint8_t NameDir[] = "TEST6";
	uint8_t NameFile[] = "20220830";
	uint8_t wtext[] = "tanti auguri e buon compleanno!\n";

	/* fm.Directory[1].DirectoryName = "FILE" */
	memcpy(&fm.Directory[ID].DirectoryName, &NameDir, sizeof(NameDir));
	/* fm.Directory[1].FilePath = "FILE/20220829_FILE" */
	memset((void *)fm.Directory[ID].FilePath, 0, 30);
	strcat((char *)fm.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fm.Directory[ID].FilePath, "/");
	strcat((char *)fm.Directory[ID].FilePath, (char const*)NameFile);
	strcat((char *)fm.Directory[ID].FilePath, "_");
	strcat((char *)fm.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fm.Directory[ID].FilePath, "_01");
	strcat((char *)fm.Directory[ID].FilePath, ".TXT");

	/* create the file to test */
	uint16_t bw = 0;
	fm_init(ID);

	for(uint16_t i = 0; i < 300; i++)
	{
		/* Fill the buffer*/
		memcpy(&fm.Buffer, wtext, strlen((char const*)wtext));
		fm.Buffer_size = strlen((char const*)wtext);

		/* Change name of the file if it's becoming to big  */
		if((fm.Directory[ID].SaveFIL.fptr + fm.Buffer_size) > BUFFER_SIZE)
		{
			fm.Directory[ID].FilePath[22] += 1;
			fm_init(ID);
		}

		/*  */
		fm_write(ID);

		/* Just for help in debugging */
		bw += strlen((char const*)wtext);
	}

	fm.State = bw;
}

#endif /* UNIT_TEST */

/*
 * This method is used to test if the module works as wanted
 * @author William Favaro
 * @date 05/08/2022
 */
void fm_test_all()
{
#if FATMAN_AUTEST
	f_mount(&SDFatFS, (TCHAR const*)SDPath, 0);

	fm_test_NormalUsage1();
	fm_test_NormalUsage2();

	fm_test_WHITheFilePathChanges();
	fm_test_WHIitsWritedSeveralConsecutiveTimes();
	fm_test_read();
	fm_test_WHItheBufferIsTooBig();

	f_mount(NULL, (TCHAR const*)SDPath, 0);
#endif /* FATMAN_UTEST */
}

/* END FILE */
