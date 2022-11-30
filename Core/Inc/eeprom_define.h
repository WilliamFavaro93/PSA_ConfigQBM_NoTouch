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
#define E2_1__EEPROM_INITIALIZE											00
#define E2_1__DEVICE_TYPE												01
/* Defines: Page 02 ----------------------------------------------------------*/
//#define E2_2__SET_O2_1               0
//#define E2_2_SET_O2_2               1
//#define E2_2_ISTERESI               2
//#define E2_2_SET_O2_1_ISOS0FT       3
//#define E2_2_SET_O2_2_ISOS0FT       4
#define E2_2__ADSORPTION_TIME      										37
#define E2_2__STARTUP_TIME         										38
#define E2_2__COMPENSATION_TIME     									39
#define E2_2__AL11_DELAY           										40
#define E2_2__PRESTANDBY_1_TIME    										41
#define E2_2__PRESTANDBY_2_TIME    										42
//#define E2_2_EN_MODULE             11
#define E2_2__FIRST_ADSORPTION_TIME 									44
#define E2_2__OUT_ENABLING          									45
//#define E2_2_MAX_DISCHARGE         14
#define E2_2__B3_LOWERTHRESHOLD     									47
#define E2_2__B3_UPPERTHRESHOLD     									48
#define E2_2__B2_LOWERTHRESHOLD     									49
#define E2_2__B2_UPPERTHRESHOLD     									50
#define E2_2__B4_LOWERTHRESHOLD     									51
#define E2_2__B4_UPPERTHRESHOLD     									52
#define E2_2__B1_LOWERTHRESHOLD     									53
#define E2_2__B1_UPPERTHRESHOLD     									54
#define E2_2__AL19_DELAY            									55
#define E2_2__AL16_DELAY            									56
#define E2_2__NUMBER_VALVEBLOCK     									57
//#define E2_2_TMR_WARMUP            26 //timer riscaldamento sensore
//#define E2_2_DP_SET                27 //set dewpoint di lavoro
//#define E2_2_DP_ALARM              28 //set dewpoint di allarme - arresta la macchina
//#define E2_2__DP_DELAY              29 //set ritardo dewpoint (20200818 dewpoint)
#define E2_2__NUMBER_MODULES        									62
#define E2_2__MACHINE_TYPE          									63
/* Defines: Page 03 ----------------------------------------------------------*/
#define E2_3__CAN_1_IDENTIFIER           								64
#define E2_3__CAN_2_IDENTIFIER          								65
//#define E2_3_ID_CAN_PORT_SEL    2  //seleziona quale porta CAN ?Master e quale Slave
//#define E2_3__CAN_1_BAUDRATE     3  //imposta BTR0 per baudrate CAN 1
//#define E2_3__CAN_2_BAUDRATE     4  //imposta BTR0 per baudrate CAN 2
//#define E2_3_ID_RS485_1         5  //identificatore scheda nella rete RS485
//#define E2_3_ID_RS485_2         6  //identificatore scheda nella rete RS485
//#define E2_3_ID_RS485_PORT_SEL  7  //seleziona quale porta COM ?Master e quale Slave
//#define E2_3_UART1_BAUDRATE     8  //configurazione BAUDRATE seriale 1
//#define E2_3_UART2_BAUDRATE     9  //configurazione BAUDRATE seriale 2
/* Defines: Page 04 ----------------------------------------------------------*/
//#define E2_4_INPUT_1_ZEROADC   0
//#define E2_4_INPUT_1_SPANADC   1
//#define E2_4_INPUT_2_ZEROADC   2
//#define E2_4_INPUT_2_SPANADC   3
//#define E2_4_INPUT_3_ZEROADC   4
//#define E2_4_INPUT_3_SPANADC   5
//#define E2_4_INPUT_4_ZEROADC   6
//#define E2_4_INPUT_4_SPANADC   7
//#define E2_4_INPUT_5_ZEROADC   8
//#define E2_4_INPUT_5_SPANADC   9
//#define E2_4_INPUT_6_ZEROADC  10
//#define E2_4_INPUT_6_SPANADC  11
//#define E2_4_INPUT_7_ZEROADC  12
//#define E2_4_INPUT_7_SPANADC  13
//#define E2_4_INPUT_8_ZEROADC  14
//#define E2_4_INPUT_8_SPANADC  15
//#define E2_4_INPUT_9_ZEROADC  16
//#define E2_4_INPUT_9_SPANADC  17
//#define E2_4_INPUT_10_ZEROADC 18
//#define E2_4_INPUT_10_SPANADC 19
//#define E2_4_AVGINDEXMAX      20
//#define E2_4_HALFDAY          21 // - solo da programma: ogni 12 ore salva su E2prom ore lavoro
//#define E2_4_LOC_REM_STATUS   22 // - solo da programma: impostazione stato CMD_LOCAL_ON, CMD_LOCAL_OFF, CMD_REMOTE
//#define E2_4_COMMAND          23 //comando remoto o locale
//#define E2_4_COLLAUDO         24
//#define E2_4_PDOWN_COUNTER    25 //contatore ore Pulldown     (OUT 1)
//#define E2_4_MAINT_COUNTER    26 //contatore ore Mantenimento (OUT 2)
//#define E2_4_SAMPLE_QUEUE     27 //numero campioni per media O2
//#define E2_4_O2_TYPE          28 //tipo sensore O2
//#define E2_4_LOGO_TYPE        29 //tipo LOGO divisione Isolcell 1111-Storage, 2222-industry, 3333-Fire Prevention
//#define E2_4_COMP_2           30
/* Defines: Page 05 ----------------------------------------------------------*/
#define E2_5_PULLDOWN_BUTTON_STATUS										128
#define E2_5_PUREZZA_OUT1												129
#define E2_5_PUREZZA_OUT2												130
#define E2_5_PRIORITA_OUT												131
#define E2_5_PULLDOWN_FIRST_START									   	132
#define E2_5_COLOR_THEME_1												133
#define E2_5_COLOR_THEME_2												134
#define E2_5_COLOR_THEME_3												135
#define E2_5_DEWPOINT													136
#define E2_5_FLUX_N2													137
/* Typedef Struct definition -------------------------------------------------*/
/* Public Function definition ------------------------------------------------*/
void EEPROM_DEFINE_Init();

#endif /* INC_E2_PSA__H_ */
