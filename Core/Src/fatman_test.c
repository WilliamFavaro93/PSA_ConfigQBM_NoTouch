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

#ifdef DEBUG
/* Includes ------------------------------------------------------------------*/
#include "fatman.h"
/* Defines -------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
extern ManageSD fatman;
/* Private Function definition -----------------------------------------------*/
void fm_test_NormalUse1();
void fm_test_NormalUse2();
void fm_test_WHITheFilePathChanges();
void fm_test_WHIitsWritedSeveralConsecutiveTimes();
void fm_test_CheckIf4096IsTheLimit();
void fm_test_WHItheBufferIsTooBig();
void fm_test_read();
void fm_test_rename();
/* Public Function -----------------------------------------------------------*/
/*
 * This method is used to test if the module works as wanted
 * @author William Favaro
 * @date 05/08/2022
 */
void fatman_test_all()
{
	f_mount(&SDFatFS, (TCHAR const*)SDPath, 0);
	fm_test_NormalUse1();
	fm_test_NormalUse2();
	fm_test_WHITheFilePathChanges();
	fm_test_WHIitsWritedSeveralConsecutiveTimes();
	fm_test_WHItheBufferIsTooBig();
	fm_test_read();
	fm_test_rename();
	f_mount(NULL, (TCHAR const*)SDPath, 0);
}
/* Private Function ----------------------------------------------------------*/
/*
 * The purpose of this test is to see if it works normally
 * @author William Favaro
 * @date 05/08/2022
 */
void fm_test_NormalUse1()
{
	/* Fatman */
	memcpy(&fatman.Directory[1].DirectoryName, "TEST0", sizeof("FIGA"));
	memcpy(&fatman.Directory[1].FilePath, "TEST0/TEST0.TXT", sizeof("TEST0/TEST0.TXT"));
	fatman_init(1);
	memcpy(&fatman.Buffer, "Odio tutti\n", sizeof("Odio tutti\n"));
	fatman.Buffer_size = strlen("Odio tutti\n");
	fatman_write(1);
}

/*
 * The purpose of this test is to see if it can adapt to the situation
 * @author William Favaro
 * @date 05/08/2022
 */
void fm_test_NormalUse2()
{
	uint8_t ID = 2;
	uint8_t NameDir[] = "TEST2";
	uint8_t NameFile[] = "20220805";
	uint8_t wtext[] = "Funziona Bene!!\n";
	/* fm.Directory[1].DirectoryName = "FILE" */
	memcpy(&fatman.Directory[ID].DirectoryName, &NameDir, sizeof(NameDir));
	/* fm.Directory[1].FilePath = "FILE/20220805_FILE" */
	memset((void *)fatman.Directory[ID].FilePath, 0, 30);
	strcat((char *)fatman.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fatman.Directory[ID].FilePath, "/");
	strcat((char *)fatman.Directory[ID].FilePath, (char const*)NameFile);
	strcat((char *)fatman.Directory[ID].FilePath, "_");
	strcat((char *)fatman.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fatman.Directory[ID].FilePath, ".TXT");
	/* Fatman */
	fatman_init(ID);
	memcpy(&fatman.Buffer, wtext, strlen((char const*)wtext));
	fatman.Buffer_size = strlen((char const*)wtext);
	fatman_write(ID);
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
	memcpy(&fatman.Directory[ID].DirectoryName, &NameDir, sizeof(NameDir));
	/* fm.Directory[1].FilePath = "FILE/20220805_FILE" */
	memset((void *)fatman.Directory[ID].FilePath, 0, 30);
	strcat((char *)fatman.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fatman.Directory[ID].FilePath, "/");
	strcat((char *)fatman.Directory[ID].FilePath, (char const*)NameFile);
	strcat((char *)fatman.Directory[ID].FilePath, "_");
	strcat((char *)fatman.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fatman.Directory[ID].FilePath, ".TXT");
	/* Fatman */
	fatman_init(ID);
	memcpy(&fatman.Buffer, wtext, strlen((char const*)wtext));
	fatman.Buffer_size = strlen((char const*)wtext);
	fatman_write(ID);
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
	memcpy(&fatman.Directory[ID].DirectoryName, &NameDir, sizeof(NameDir));
	/* fm.Directory[1].FilePath = "FILE/20220805_FILE" */
	memset((void *)fatman.Directory[ID].FilePath, 0, 30);
	strcat((char *)fatman.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fatman.Directory[ID].FilePath, "/");
	strcat((char *)fatman.Directory[ID].FilePath, (char const*)NameFile);
	strcat((char *)fatman.Directory[ID].FilePath, "_");
	strcat((char *)fatman.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fatman.Directory[ID].FilePath, ".TXT");

	/* Fatman */
	fatman_init(ID);
	for(uint8_t i = 0; i < nTimes; i++)
	{
		memcpy(&fatman.Buffer, wtext, strlen((char const*)wtext));
		fatman.Buffer_size = strlen((char const*)wtext);
		fatman_write(ID);
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
	memcpy(&fatman.Directory[ID].DirectoryName, &NameDir, sizeof(NameDir));
	/* fm.Directory[1].FilePath = "FILE/20220829_FILE" */
	memset((void *)fatman.Directory[ID].FilePath, 0, 30);
	strcat((char *)fatman.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fatman.Directory[ID].FilePath, "/");
	strcat((char *)fatman.Directory[ID].FilePath, (char const*)NameFile);
	strcat((char *)fatman.Directory[ID].FilePath, "_");
	strcat((char *)fatman.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fatman.Directory[ID].FilePath, ".TXT");

	/* create the file to test */
	uint16_t bw = 0;
	fatman_init(ID);
	memcpy(&fatman.Buffer, wtext, strlen((char const*)wtext));
	fatman.Buffer_size = strlen((char const*)wtext);
	for(uint8_t i = 0; i < 129; i++)
	{
		memcpy(&fatman.Buffer, wtext, strlen((char const*)wtext));
		fatman.Buffer_size = strlen((char const*)wtext);
		fatman_write(ID);
		bw += strlen((char const*)wtext);
	}
	fatman.State = bw;

	/* It creates the file */
	uint16_t br = 0;
	f_open(&fatman.OpenFIL, (TCHAR const*)fatman.Directory[ID].FilePath, FA_READ);
	f_read(&fatman.OpenFIL, (void *)&fatman.Buffer, 4127, (void *)&br);
	f_close(&fatman.OpenFIL);
	fatman.State = br;



	f_open(&fatman.OpenFIL, "TEST3/20220805_TEST3_1.TXT", FA_CREATE_ALWAYS|FA_WRITE);
	f_write(&fatman.OpenFIL, (void *)&fatman.Buffer, 4127, (void *)&br);
	f_close(&fatman.OpenFIL);
	fatman.State = br;
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
	memcpy(&fatman.Directory[ID].DirectoryName, &NameDir, sizeof(NameDir));
	/* fm.Directory[1].FilePath = "FILE/20220829_FILE" */
	memset((void *)fatman.Directory[ID].FilePath, 0, 30);
	strcat((char *)fatman.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fatman.Directory[ID].FilePath, "/");
	strcat((char *)fatman.Directory[ID].FilePath, (char const*)NameFile);
	strcat((char *)fatman.Directory[ID].FilePath, "_");
	strcat((char *)fatman.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fatman.Directory[ID].FilePath, "_01");
	strcat((char *)fatman.Directory[ID].FilePath, ".TXT");

	/* create the file to test */
	uint16_t bw = 0;
	fatman_init(ID);

	for(uint16_t i = 0; i < 300; i++)
	{
		/* Fill the buffer*/
		memcpy(&fatman.Buffer, wtext, strlen((char const*)wtext));
		fatman.Buffer_size = strlen((char const*)wtext);

		/* Change name of the file if it's becoming to big  */
		if((fatman.Directory[ID].SaveFIL.fptr + fatman.Buffer_size) > FATMAN_BUFFER_SIZE)
		{
			fatman.Directory[ID].FilePath[22] += 1;
			fatman_init(ID);
		}

		/*  */
		fatman_write(ID);

		/* Just for help in debugging */
		bw += strlen((char const*)wtext);
	}

	fatman.State = bw;
}

void fm_test_read()
{
	uint8_t ID = 1;
	uint8_t NameDir[] = "TEST1";
	uint8_t NameFile[] = "20220901";

	/* fm.Directory[1].DirectoryName = "FILE" */
	memcpy(&fatman.Directory[ID].DirectoryName, &NameDir, sizeof(NameDir));
	/* fm.Directory[1].FilePath = "FILE/20220829_FILE" */
	memset((void *)fatman.Directory[ID].FilePath, 0, 30);
	strcat((char *)fatman.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fatman.Directory[ID].FilePath, "/");
	strcat((char *)fatman.Directory[ID].FilePath, (char const*)NameFile);
	strcat((char *)fatman.Directory[ID].FilePath, "_");
	strcat((char *)fatman.Directory[ID].FilePath, (char const*)NameDir);
	strcat((char *)fatman.Directory[ID].FilePath, ".TXT");

	fatman_init(ID);

	memcpy(fatman.Directory[0].FilePath, "TEST6/20220830_TEST6_01.TXT", sizeof("TEST6/20220830_TEST6_01.TXT"));
	fatman_read();

	fatman_write(ID);
}

void fm_test_rename()
{
	uint8_t ID = 7;
	uint8_t NameDir[] = "TEST7";
	uint8_t NameFile[] = "20220922";
	uint8_t wtext[] = "Il Rinomina funziona Bene!!\n";
	/* fm.Directory[1].DirectoryName = "FILE" */
	memcpy(&fatman.Directory[ID].DirectoryName, &NameDir, sizeof(NameDir));
	/* fm.Directory[1].FilePath = "FILE/20220805_FILE" */
	fatman_rename(ID, (char*)NameFile, 8);
	/* Fatman */
	fatman_init(ID);
	memcpy(&fatman.Buffer, wtext, strlen((char const*)wtext));
	fatman.Buffer_size = strlen((char const*)wtext);
	fatman_write(ID);
}
#endif /* DEBUG */
/* End of the file -----------------------------------------------------------*/
