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
#ifndef INC_E2_PSA__H_
#define INC_E2_PSA__H_

/* Includes ------------------------------------------------------------------*/
/* Defines -------------------------------------------------------------------*/
/* Defines: Page 01 ----------------------------------------------------------*/
#define E2_1__EEPROM_INITIALIZE											0x0000
#define E2_1__DEVICE_TYPE												0x0002
/* Defines: Page 02 ----------------------------------------------------------*/
#define E2_2__SET_O2_1               0
#define E2_2_SET_O2_2               1
#define E2_2_ISTERESI               2
#define E2_2_SET_O2_1_ISOS0FT       3
#define E2_2_SET_O2_2_ISOS0FT       4
#define E2_2_ADS                    5
#define E2_2_TMR_PSA_AVVIO          6
#define E2_2_COMP                   7
#define E2_2_RITARDOAL11            8
#define E2_2_STBY_1                 9
#define E2_2_STBY_2                10
#define E2_2_EN_MODULE             11
#define E2_2_ADS_AVVIO             12
#define E2_2_OUT_ENABLING          13
#define E2_2_MAX_DISCHARGE         14
#define E2_2_PRESS_B3_OPEN         15 //B3 - usato per apertura/chiusura valvole mandata (scarico,pulldown,mantenimento)
#define E2_2_PRESS_B3_CLOSE        16
#define E2_2_PRESS_B2_START        17 //B2 - set pressione apertura valvola mandata linea 1 - se 0 = OFF al raggiungimento della soglia max (stby) segnala allarme linea
#define E2_2_PRESS_B2_STBY         18 //se 0 = OFF la macchina lavora con i pressostati
#define E2_2_PRESS_B4_START        19 //B4 - set pressione apertura valvola mandata linea 2 - se 0 = OFF al raggiungimento della soglia max (stby) segnala allarme linea
#define E2_2_PRESS_B4_STBY         20 //se 0 = OFF la macchina lavora con i pressostati
#define E2_2_PRESS_B1_START_AL2    21 //B1 - usato per allarme AL2
#define E2_2_PRESS_B1_STOP_AL2     22
#define E2_2_TMR_B2_ERROR          23 //timer ritardo errore sonda B2 - se 0 non c'� ritardo
#define E2_2_TMR_B4_ERROR          24 //timer ritardo errore sonda B4 - se 0 non c'� ritardo
#define E2_2_NUM_BLOCCO_VALVOLE    25
#define E2_2_TMR_WARMUP            26 //timer riscaldamento sensore
#define E2_2_DP_SET                27 //set dewpoint di lavoro
#define E2_2_DP_ALARM              28 //set dewpoint di allarme - arresta la macchina
#define E2_2_DP_DELAY              29 //set ritardo dewpoint (20200818 dewpoint)
#define E2_2_NUM_MODULE            30
#define E2_2_MACHINE               31 //tipo macchina
/* Typedef Struct definition -------------------------------------------------*/
/* Public Function definition ------------------------------------------------*/

#endif /* INC_E2_PSA__H_ */
