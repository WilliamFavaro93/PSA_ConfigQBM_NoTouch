/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "fatfs.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include "canspi.h"
#include "datetime.h"
#include "fatman.h"
#include "mcp2515.h"
#include "myqueue.h"
#include "mytimer.h"
#include "psa.h"
#include "timecounter.h"
#include "alarm.h"
#include "stdio.h"
#include "alarm_datetime_fatman.h"
#include "cjson.h"
#include "eeprom.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

CAN_HandleTypeDef hcan1;
CAN_HandleTypeDef hcan2;

CRC_HandleTypeDef hcrc;

DMA2D_HandleTypeDef hdma2d;

DSI_HandleTypeDef hdsi;

I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c2;

LTDC_HandleTypeDef hltdc;

QSPI_HandleTypeDef hqspi;

SD_HandleTypeDef hsd;
DMA_HandleTypeDef hdma_sdio_rx;
DMA_HandleTypeDef hdma_sdio_tx;

SPI_HandleTypeDef hspi2;

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim7;

UART_HandleTypeDef huart6;

SDRAM_HandleTypeDef hsdram1;

/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal2,
};
/* Definitions for StateTask */
osThreadId_t StateTaskHandle;
const osThreadAttr_t StateTask_attributes = {
  .name = "StateTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal3,
};
/* Definitions for OutTask */
osThreadId_t OutTaskHandle;
const osThreadAttr_t OutTask_attributes = {
  .name = "OutTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal4,
};
/* Definitions for ModeTask */
osThreadId_t ModeTaskHandle;
const osThreadAttr_t ModeTask_attributes = {
  .name = "ModeTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal5,
};
/* Definitions for TimeTask */
osThreadId_t TimeTaskHandle;
const osThreadAttr_t TimeTask_attributes = {
  .name = "TimeTask",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal7,
};
/* Definitions for CAN2TxTask */
osThreadId_t CAN2TxTaskHandle;
const osThreadAttr_t CAN2TxTask_attributes = {
  .name = "CAN2TxTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal2,
};
/* Definitions for SDTask */
osThreadId_t SDTaskHandle;
const osThreadAttr_t SDTask_attributes = {
  .name = "SDTask",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for CAN1RxTxTask */
osThreadId_t CAN1RxTxTaskHandle;
const osThreadAttr_t CAN1RxTxTask_attributes = {
  .name = "CAN1RxTxTask",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal1,
};
/* Definitions for AlarmTask */
osThreadId_t AlarmTaskHandle;
const osThreadAttr_t AlarmTask_attributes = {
  .name = "AlarmTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal6,
};
/* Definitions for RequestTask */
osThreadId_t RequestTaskHandle;
const osThreadAttr_t RequestTask_attributes = {
  .name = "RequestTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for CAN1_ReceiveTas */
osThreadId_t CAN1_ReceiveTasHandle;
const osThreadAttr_t CAN1_ReceiveTas_attributes = {
  .name = "CAN1_ReceiveTas",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal2,
};
/* Definitions for CAN1_TransmitTa */
osThreadId_t CAN1_TransmitTaHandle;
const osThreadAttr_t CAN1_TransmitTa_attributes = {
  .name = "CAN1_TransmitTa",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal2,
};
/* Definitions for AcquisitionTask */
osThreadId_t AcquisitionTaskHandle;
const osThreadAttr_t AcquisitionTask_attributes = {
  .name = "AcquisitionTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal2,
};
/* Definitions for BinarySemCAN */
osSemaphoreId_t BinarySemCANHandle;
const osSemaphoreAttr_t BinarySemCAN_attributes = {
  .name = "BinarySemCAN"
};
/* USER CODE BEGIN PV */
/* To delete -----------------------------------------------------------------*/
uint8_t B1_AcquisitionSimulator;

/* Queue ---------------------------------------------------------------------*/
MyQueue B1_InputAirPressureQueue;
MyQueue B2_OutputAirPressure_1Queue;
MyQueue B3_ProcessTankAirPressureQueue;
MyQueue B4_OutputAirPressure_2Queue;
MyQueue IFM_AirFlowmeterQueue;
MyQueue KE25_PercentualOxygenInTheAirQueue_1;
MyQueue KE25_PercentualOxygenInTheAirQueue_2;
MyQueue DEW_InputAirDewpointQueue;

/* TimeCounter ---------------------------------------------------------------*/
TimeCounter PulldownWorking;
TimeCounter MaintenanceWorking;
TimeCounter TotalWorking;

/* Pressure Swing Adsorption Structure ---------------------------------------*/
extern PSAStruct PSA;

/* DateTime Structure --------------------------------------------------------*/
extern DateTime today;

uCAN_MSG rxMessage;
/* ManageSD Structure fatman -------------------------------------------------*/
extern ManageSD fatman;

/* Time Constant -------------------------------------------------------------*/
const TickType_t seconds      = pdMS_TO_TICKS(1000);
const TickType_t deciseconds  = pdMS_TO_TICKS(100);
const TickType_t centiseconds = pdMS_TO_TICKS(10);
const TickType_t milliseconds = pdMS_TO_TICKS(1);
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_CRC_Init(void);
static void MX_DMA2D_Init(void);
static void MX_DSIHOST_DSI_Init(void);
static void MX_FMC_Init(void);
static void MX_LTDC_Init(void);
static void MX_QUADSPI_Init(void);
static void MX_I2C1_Init(void);
static void MX_CAN1_Init(void);
static void MX_CAN2_Init(void);
static void MX_SPI2_Init(void);
static void MX_TIM2_Init(void);
static void MX_I2C2_Init(void);
static void MX_USART6_UART_Init(void);
static void MX_SDIO_SD_Init(void);
static void MX_DMA_Init(void);
static void MX_TIM7_Init(void);
static void MX_ADC1_Init(void);
void StartDefaultTask(void *argument);
void StartStateTask(void *argument);
void StartOutTask(void *argument);
void StartModeTask(void *argument);
void StartTimeTask(void *argument);
void StartCAN2TxTask(void *argument);
void StartSDTask(void *argument);
void StartCAN1RxTxTask(void *argument);
void StartAlarmTask(void *argument);
void StartRequestTask(void *argument);
void StartCAN1_ReceiveTask(void *argument);
void StartCAN1_TransmitTask(void *argument);
void StartAcquisitionTask(void *argument);

/* USER CODE BEGIN PFP */
int __io_putchar(int character);
void AssignDefaultValue();
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan);
//void CheckAlarmConditionToWriteSD(Alarm * Alarm, char * AlarmMessage, uint8_t sizeofAlarmMessage);
//void DirectoryInit(uint8_t ID, char * nameDir, uint8_t nameDir_length);
void TEST_TestAllAndStopIt();
void json_init();
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_CRC_Init();
  MX_DMA2D_Init();
  MX_DSIHOST_DSI_Init();
  MX_FMC_Init();
  MX_LTDC_Init();
  MX_QUADSPI_Init();
  MX_I2C1_Init();
  MX_CAN1_Init();
  MX_CAN2_Init();
  MX_SPI2_Init();
  MX_TIM2_Init();
  MX_I2C2_Init();
  MX_USART6_UART_Init();
  MX_SDIO_SD_Init();
  MX_FATFS_Init();
  MX_DMA_Init();
  MX_TIM7_Init();
  MX_ADC1_Init();
  /* USER CODE BEGIN 2 */
#if 0
  TEST_TestAllAndStopIt();
  HAL_GPIO_TogglePin(GPIOK, GPIO_PIN_3);
  while(1){}
#endif /* TEST */

  HAL_I2C_Init(&hi2c1);
  //write
//  uint16_t blink = 4000;
//  uint16_t read = 0;
////  HAL_I2C_Mem_Write(&hi2c1, (84<<1), 0x03, I2C_MEMADD_SIZE_16BIT, &blink, 2, 1000);
//  EEPROM_Write(0x02, &blink);
//  HAL_Delay(5 * milliseconds);
//
//  //read
////  HAL_I2C_Mem_Read(&hi2c1, (84<<1), 0x03, I2C_MEMADD_SIZE_16BIT, &read,  1, 1000);
//  EEPROM_Read(0x02, &read);
//  HAL_Delay(5 * milliseconds);
//  if(read == 4000)
//  {
//	  HAL_GPIO_TogglePin(GPIOK, GPIO_PIN_3);
//  }
//  while(1){}

  AssignDefaultValue();
  json_init();

  HAL_CAN_Start(&hcan2);
  HAL_CAN_ActivateNotification(&hcan2, CAN_IT_RX_FIFO1_MSG_PENDING);
  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* creation of BinarySemCAN */
  BinarySemCANHandle = osSemaphoreNew(1, 1, &BinarySemCAN_attributes);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of StateTask */
  StateTaskHandle = osThreadNew(StartStateTask, NULL, &StateTask_attributes);

  /* creation of OutTask */
  OutTaskHandle = osThreadNew(StartOutTask, NULL, &OutTask_attributes);

  /* creation of ModeTask */
  ModeTaskHandle = osThreadNew(StartModeTask, NULL, &ModeTask_attributes);

  /* creation of TimeTask */
  TimeTaskHandle = osThreadNew(StartTimeTask, NULL, &TimeTask_attributes);

  /* creation of CAN2TxTask */
  CAN2TxTaskHandle = osThreadNew(StartCAN2TxTask, NULL, &CAN2TxTask_attributes);

  /* creation of SDTask */
  SDTaskHandle = osThreadNew(StartSDTask, NULL, &SDTask_attributes);

  /* creation of CAN1RxTxTask */
  CAN1RxTxTaskHandle = osThreadNew(StartCAN1RxTxTask, NULL, &CAN1RxTxTask_attributes);

  /* creation of AlarmTask */
  AlarmTaskHandle = osThreadNew(StartAlarmTask, NULL, &AlarmTask_attributes);

  /* creation of RequestTask */
  RequestTaskHandle = osThreadNew(StartRequestTask, NULL, &RequestTask_attributes);

  /* creation of CAN1_ReceiveTas */
  CAN1_ReceiveTasHandle = osThreadNew(StartCAN1_ReceiveTask, NULL, &CAN1_ReceiveTas_attributes);

  /* creation of CAN1_TransmitTa */
  CAN1_TransmitTaHandle = osThreadNew(StartCAN1_TransmitTask, NULL, &CAN1_TransmitTa_attributes);

  /* creation of AcquisitionTask */
  AcquisitionTaskHandle = osThreadNew(StartAcquisitionTask, NULL, &AcquisitionTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 180;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 8;
  RCC_OscInitStruct.PLL.PLLR = 6;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = ENABLE;
  hadc1.Init.ContinuousConvMode = ENABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 3;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_5;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_56CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_9;
  sConfig.Rank = 2;
  sConfig.SamplingTime = ADC_SAMPLETIME_84CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_11;
  sConfig.Rank = 3;
  sConfig.SamplingTime = ADC_SAMPLETIME_112CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief CAN1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN1_Init(void)
{

  /* USER CODE BEGIN CAN1_Init 0 */

  /* USER CODE END CAN1_Init 0 */

  /* USER CODE BEGIN CAN1_Init 1 */

  /* USER CODE END CAN1_Init 1 */
  hcan1.Instance = CAN1;
  hcan1.Init.Prescaler = 250;
  hcan1.Init.Mode = CAN_MODE_NORMAL;
  hcan1.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan1.Init.TimeSeg1 = CAN_BS1_7TQ;
  hcan1.Init.TimeSeg2 = CAN_BS2_1TQ;
  hcan1.Init.TimeTriggeredMode = DISABLE;
  hcan1.Init.AutoBusOff = DISABLE;
  hcan1.Init.AutoWakeUp = DISABLE;
  hcan1.Init.AutoRetransmission = DISABLE;
  hcan1.Init.ReceiveFifoLocked = DISABLE;
  hcan1.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN1_Init 2 */
  CAN_FilterTypeDef CAN1_Filter = {0};

  CAN1_Filter.FilterActivation = CAN_FILTER_ENABLE;		/* To enable/disable the filter */
  CAN1_Filter.FilterBank = 9;							/* You can assign any filterbanks from 0 to X-1 are assigned to CAN-MASTER (CAN1) and from X to 27 are assigned to CAN-SLAVE (CAN2), X = SlaveStartFilterBank */
  CAN1_Filter.FilterFIFOAssignment = CAN_RX_FIFO0;
  CAN1_Filter.FilterIdHigh = 0x0000 << 5;				/* */
  CAN1_Filter.FilterIdLow = 0x0000;
  CAN1_Filter.FilterMode = CAN_FILTERMODE_IDMASK;		/* If all the 1 matched with the sended ID. The message will be not filter out */
  CAN1_Filter.FilterScale = CAN_FILTERSCALE_32BIT;
  CAN1_Filter.SlaveStartFilterBank = 14; 				/* FilterBank from 0 to X-1 are assigned to CAN-MASTER (CAN1) and from X to 27 are assigned to CAN-SLAVE (CAN2), X = SlaveStartFilterBank*/

  HAL_CAN_ConfigFilter(&hcan1, &CAN1_Filter);
  /* USER CODE END CAN1_Init 2 */

}

/**
  * @brief CAN2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN2_Init(void)
{

  /* USER CODE BEGIN CAN2_Init 0 */

  /* USER CODE END CAN2_Init 0 */

  /* USER CODE BEGIN CAN2_Init 1 */

  /* USER CODE END CAN2_Init 1 */
  hcan2.Instance = CAN2;
  hcan2.Init.Prescaler = 40;
  hcan2.Init.Mode = CAN_MODE_NORMAL;
  hcan2.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan2.Init.TimeSeg1 = CAN_BS1_7TQ;
  hcan2.Init.TimeSeg2 = CAN_BS2_1TQ;
  hcan2.Init.TimeTriggeredMode = DISABLE;
  hcan2.Init.AutoBusOff = DISABLE;
  hcan2.Init.AutoWakeUp = DISABLE;
  hcan2.Init.AutoRetransmission = DISABLE;
  hcan2.Init.ReceiveFifoLocked = DISABLE;
  hcan2.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN2_Init 2 */
  CAN_FilterTypeDef CAN2_Filter = {0};
  CAN2_Filter.FilterActivation = CAN_FILTER_ENABLE;
  CAN2_Filter.FilterBank = 18;
  CAN2_Filter.FilterFIFOAssignment = CAN_RX_FIFO1;
  CAN2_Filter.FilterIdHigh = (0x701 << 5);
  CAN2_Filter.FilterIdLow = 0x0000;
  CAN2_Filter.FilterMode = CAN_FILTERMODE_IDMASK;
  CAN2_Filter.FilterScale = CAN_FILTERSCALE_32BIT;
  CAN2_Filter.SlaveStartFilterBank = 14;

  HAL_CAN_ConfigFilter(&hcan2, &CAN2_Filter);
  /* USER CODE END CAN2_Init 2 */

}

/**
  * @brief CRC Initialization Function
  * @param None
  * @retval None
  */
static void MX_CRC_Init(void)
{

  /* USER CODE BEGIN CRC_Init 0 */

  /* USER CODE END CRC_Init 0 */

  /* USER CODE BEGIN CRC_Init 1 */

  /* USER CODE END CRC_Init 1 */
  hcrc.Instance = CRC;
  if (HAL_CRC_Init(&hcrc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CRC_Init 2 */

  /* USER CODE END CRC_Init 2 */

}

/**
  * @brief DMA2D Initialization Function
  * @param None
  * @retval None
  */
static void MX_DMA2D_Init(void)
{

  /* USER CODE BEGIN DMA2D_Init 0 */

  /* USER CODE END DMA2D_Init 0 */

  /* USER CODE BEGIN DMA2D_Init 1 */

  /* USER CODE END DMA2D_Init 1 */
  hdma2d.Instance = DMA2D;
  hdma2d.Init.Mode = DMA2D_M2M;
  hdma2d.Init.ColorMode = DMA2D_OUTPUT_ARGB8888;
  hdma2d.Init.OutputOffset = 0;
  hdma2d.LayerCfg[1].InputOffset = 0;
  hdma2d.LayerCfg[1].InputColorMode = DMA2D_INPUT_ARGB8888;
  hdma2d.LayerCfg[1].AlphaMode = DMA2D_NO_MODIF_ALPHA;
  hdma2d.LayerCfg[1].InputAlpha = 0;
  if (HAL_DMA2D_Init(&hdma2d) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DMA2D_ConfigLayer(&hdma2d, 1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN DMA2D_Init 2 */

  /* USER CODE END DMA2D_Init 2 */

}

/**
  * @brief DSIHOST Initialization Function
  * @param None
  * @retval None
  */
static void MX_DSIHOST_DSI_Init(void)
{

  /* USER CODE BEGIN DSIHOST_Init 0 */

  /* USER CODE END DSIHOST_Init 0 */

  DSI_PLLInitTypeDef PLLInit = {0};
  DSI_HOST_TimeoutTypeDef HostTimeouts = {0};
  DSI_PHY_TimerTypeDef PhyTimings = {0};
  DSI_LPCmdTypeDef LPCmd = {0};
  DSI_CmdCfgTypeDef CmdCfg = {0};

  /* USER CODE BEGIN DSIHOST_Init 1 */

  /* USER CODE END DSIHOST_Init 1 */
  hdsi.Instance = DSI;
  hdsi.Init.AutomaticClockLaneControl = DSI_AUTO_CLK_LANE_CTRL_DISABLE;
  hdsi.Init.TXEscapeCkdiv = 4;
  hdsi.Init.NumberOfLanes = DSI_TWO_DATA_LANES;
  PLLInit.PLLNDIV = 125;
  PLLInit.PLLIDF = DSI_PLL_IN_DIV2;
  PLLInit.PLLODF = DSI_PLL_OUT_DIV1;
  if (HAL_DSI_Init(&hdsi, &PLLInit) != HAL_OK)
  {
    Error_Handler();
  }
  HostTimeouts.TimeoutCkdiv = 1;
  HostTimeouts.HighSpeedTransmissionTimeout = 0;
  HostTimeouts.LowPowerReceptionTimeout = 0;
  HostTimeouts.HighSpeedReadTimeout = 0;
  HostTimeouts.LowPowerReadTimeout = 0;
  HostTimeouts.HighSpeedWriteTimeout = 0;
  HostTimeouts.HighSpeedWritePrespMode = DSI_HS_PM_DISABLE;
  HostTimeouts.LowPowerWriteTimeout = 0;
  HostTimeouts.BTATimeout = 0;
  if (HAL_DSI_ConfigHostTimeouts(&hdsi, &HostTimeouts) != HAL_OK)
  {
    Error_Handler();
  }
  PhyTimings.ClockLaneHS2LPTime = 28;
  PhyTimings.ClockLaneLP2HSTime = 33;
  PhyTimings.DataLaneHS2LPTime = 15;
  PhyTimings.DataLaneLP2HSTime = 25;
  PhyTimings.DataLaneMaxReadTime = 0;
  PhyTimings.StopWaitTime = 0;
  if (HAL_DSI_ConfigPhyTimer(&hdsi, &PhyTimings) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DSI_ConfigFlowControl(&hdsi, DSI_FLOW_CONTROL_BTA) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DSI_SetLowPowerRXFilter(&hdsi, 10000) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DSI_ConfigErrorMonitor(&hdsi, HAL_DSI_ERROR_NONE) != HAL_OK)
  {
    Error_Handler();
  }
  LPCmd.LPGenShortWriteNoP = DSI_LP_GSW0P_ENABLE;
  LPCmd.LPGenShortWriteOneP = DSI_LP_GSW1P_ENABLE;
  LPCmd.LPGenShortWriteTwoP = DSI_LP_GSW2P_ENABLE;
  LPCmd.LPGenShortReadNoP = DSI_LP_GSR0P_ENABLE;
  LPCmd.LPGenShortReadOneP = DSI_LP_GSR1P_ENABLE;
  LPCmd.LPGenShortReadTwoP = DSI_LP_GSR2P_ENABLE;
  LPCmd.LPGenLongWrite = DSI_LP_GLW_ENABLE;
  LPCmd.LPDcsShortWriteNoP = DSI_LP_DSW0P_ENABLE;
  LPCmd.LPDcsShortWriteOneP = DSI_LP_DSW1P_ENABLE;
  LPCmd.LPDcsShortReadNoP = DSI_LP_DSR0P_ENABLE;
  LPCmd.LPDcsLongWrite = DSI_LP_DLW_ENABLE;
  LPCmd.LPMaxReadPacket = DSI_LP_MRDP_ENABLE;
  LPCmd.AcknowledgeRequest = DSI_ACKNOWLEDGE_ENABLE;
  if (HAL_DSI_ConfigCommand(&hdsi, &LPCmd) != HAL_OK)
  {
    Error_Handler();
  }
  CmdCfg.VirtualChannelID = 0;
  CmdCfg.ColorCoding = DSI_RGB565;
  CmdCfg.CommandSize = 200;
  CmdCfg.TearingEffectSource = DSI_TE_EXTERNAL;
  CmdCfg.TearingEffectPolarity = DSI_TE_RISING_EDGE;
  CmdCfg.HSPolarity = DSI_HSYNC_ACTIVE_LOW;
  CmdCfg.VSPolarity = DSI_VSYNC_ACTIVE_LOW;
  CmdCfg.DEPolarity = DSI_DATA_ENABLE_ACTIVE_HIGH;
  CmdCfg.VSyncPol = DSI_VSYNC_FALLING;
  CmdCfg.AutomaticRefresh = DSI_AR_DISABLE;
  CmdCfg.TEAcknowledgeRequest = DSI_TE_ACKNOWLEDGE_ENABLE;
  if (HAL_DSI_ConfigAdaptedCommandMode(&hdsi, &CmdCfg) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DSI_SetGenericVCID(&hdsi, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN DSIHOST_Init 2 */

  /* USER CODE END DSIHOST_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 400000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.ClockSpeed = 50000;
  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief LTDC Initialization Function
  * @param None
  * @retval None
  */
static void MX_LTDC_Init(void)
{

  /* USER CODE BEGIN LTDC_Init 0 */

  /* USER CODE END LTDC_Init 0 */

  LTDC_LayerCfgTypeDef pLayerCfg = {0};

  /* USER CODE BEGIN LTDC_Init 1 */

  /* USER CODE END LTDC_Init 1 */
  hltdc.Instance = LTDC;
  hltdc.Init.HSPolarity = LTDC_HSPOLARITY_AL;
  hltdc.Init.VSPolarity = LTDC_VSPOLARITY_AL;
  hltdc.Init.DEPolarity = LTDC_DEPOLARITY_AL;
  hltdc.Init.PCPolarity = LTDC_PCPOLARITY_IPC;
  hltdc.Init.HorizontalSync = 1;
  hltdc.Init.VerticalSync = 1;
  hltdc.Init.AccumulatedHBP = 2;
  hltdc.Init.AccumulatedVBP = 2;
  hltdc.Init.AccumulatedActiveW = 202;
  hltdc.Init.AccumulatedActiveH = 482;
  hltdc.Init.TotalWidth = 203;
  hltdc.Init.TotalHeigh = 483;
  hltdc.Init.Backcolor.Blue = 0;
  hltdc.Init.Backcolor.Green = 0;
  hltdc.Init.Backcolor.Red = 0;
  if (HAL_LTDC_Init(&hltdc) != HAL_OK)
  {
    Error_Handler();
  }
  pLayerCfg.WindowX0 = 0;
  pLayerCfg.WindowX1 = 200;
  pLayerCfg.WindowY0 = 0;
  pLayerCfg.WindowY1 = 480;
  pLayerCfg.PixelFormat = LTDC_PIXEL_FORMAT_RGB565;
  pLayerCfg.Alpha = 255;
  pLayerCfg.Alpha0 = 0;
  pLayerCfg.BlendingFactor1 = LTDC_BLENDING_FACTOR1_CA;
  pLayerCfg.BlendingFactor2 = LTDC_BLENDING_FACTOR2_CA;
  pLayerCfg.FBStartAdress = 0xC0000000;
  pLayerCfg.ImageWidth = 200;
  pLayerCfg.ImageHeight = 480;
  pLayerCfg.Backcolor.Blue = 0;
  pLayerCfg.Backcolor.Green = 0;
  pLayerCfg.Backcolor.Red = 0;
  if (HAL_LTDC_ConfigLayer(&hltdc, &pLayerCfg, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN LTDC_Init 2 */

  /* USER CODE END LTDC_Init 2 */

}

/**
  * @brief QUADSPI Initialization Function
  * @param None
  * @retval None
  */
static void MX_QUADSPI_Init(void)
{

  /* USER CODE BEGIN QUADSPI_Init 0 */

  /* USER CODE END QUADSPI_Init 0 */

  /* USER CODE BEGIN QUADSPI_Init 1 */

  /* USER CODE END QUADSPI_Init 1 */
  /* QUADSPI parameter configuration*/
  hqspi.Instance = QUADSPI;
  hqspi.Init.ClockPrescaler = 1;
  hqspi.Init.FifoThreshold = 1;
  hqspi.Init.SampleShifting = QSPI_SAMPLE_SHIFTING_HALFCYCLE;
  hqspi.Init.FlashSize = 27;
  hqspi.Init.ChipSelectHighTime = QSPI_CS_HIGH_TIME_5_CYCLE;
  hqspi.Init.ClockMode = QSPI_CLOCK_MODE_0;
  hqspi.Init.FlashID = QSPI_FLASH_ID_1;
  hqspi.Init.DualFlash = QSPI_DUALFLASH_DISABLE;
  if (HAL_QSPI_Init(&hqspi) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN QUADSPI_Init 2 */

  /* USER CODE END QUADSPI_Init 2 */

}

/**
  * @brief SDIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_SDIO_SD_Init(void)
{

  /* USER CODE BEGIN SDIO_Init 0 */

  /* USER CODE END SDIO_Init 0 */

  /* USER CODE BEGIN SDIO_Init 1 */

  /* USER CODE END SDIO_Init 1 */
  hsd.Instance = SDIO;
  hsd.Init.ClockEdge = SDIO_CLOCK_EDGE_RISING;
  hsd.Init.ClockBypass = SDIO_CLOCK_BYPASS_DISABLE;
  hsd.Init.ClockPowerSave = SDIO_CLOCK_POWER_SAVE_DISABLE;
  hsd.Init.BusWide = SDIO_BUS_WIDE_1B;
  hsd.Init.HardwareFlowControl = SDIO_HARDWARE_FLOW_CONTROL_DISABLE;
  hsd.Init.ClockDiv = 0;
  /* USER CODE BEGIN SDIO_Init 2 */

  /* USER CODE END SDIO_Init 2 */

}

/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 9000 -1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 10000;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief TIM7 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM7_Init(void)
{

  /* USER CODE BEGIN TIM7_Init 0 */

  /* USER CODE END TIM7_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM7_Init 1 */

  /* USER CODE END TIM7_Init 1 */
  htim7.Instance = TIM7;
  htim7.Init.Prescaler = 179;
  htim7.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim7.Init.Period = 99;
  htim7.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim7) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim7, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM7_Init 2 */

  /* USER CODE END TIM7_Init 2 */

}

/**
  * @brief USART6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART6_UART_Init(void)
{

  /* USER CODE BEGIN USART6_Init 0 */

  /* USER CODE END USART6_Init 0 */

  /* USER CODE BEGIN USART6_Init 1 */

  /* USER CODE END USART6_Init 1 */
  huart6.Instance = USART6;
  huart6.Init.BaudRate = 9600;
  huart6.Init.WordLength = UART_WORDLENGTH_9B;
  huart6.Init.StopBits = UART_STOPBITS_1;
  huart6.Init.Parity = UART_PARITY_EVEN;
  huart6.Init.Mode = UART_MODE_TX_RX;
  huart6.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart6.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart6) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART6_Init 2 */

  /* USER CODE END USART6_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA2_Stream3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream3_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream3_IRQn);
  /* DMA2_Stream6_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream6_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream6_IRQn);

}

/* FMC initialization function */
static void MX_FMC_Init(void)
{

  /* USER CODE BEGIN FMC_Init 0 */

  /* USER CODE END FMC_Init 0 */

  FMC_SDRAM_TimingTypeDef SdramTiming = {0};

  /* USER CODE BEGIN FMC_Init 1 */

  /* USER CODE END FMC_Init 1 */

  /** Perform the SDRAM1 memory initialization sequence
  */
  hsdram1.Instance = FMC_SDRAM_DEVICE;
  /* hsdram1.Init */
  hsdram1.Init.SDBank = FMC_SDRAM_BANK1;
  hsdram1.Init.ColumnBitsNumber = FMC_SDRAM_COLUMN_BITS_NUM_8;
  hsdram1.Init.RowBitsNumber = FMC_SDRAM_ROW_BITS_NUM_12;
  hsdram1.Init.MemoryDataWidth = FMC_SDRAM_MEM_BUS_WIDTH_32;
  hsdram1.Init.InternalBankNumber = FMC_SDRAM_INTERN_BANKS_NUM_4;
  hsdram1.Init.CASLatency = FMC_SDRAM_CAS_LATENCY_3;
  hsdram1.Init.WriteProtection = FMC_SDRAM_WRITE_PROTECTION_DISABLE;
  hsdram1.Init.SDClockPeriod = FMC_SDRAM_CLOCK_DISABLE;
  hsdram1.Init.ReadBurst = FMC_SDRAM_RBURST_ENABLE;
  hsdram1.Init.ReadPipeDelay = FMC_SDRAM_RPIPE_DELAY_2;
  /* SdramTiming */
  SdramTiming.LoadToActiveDelay = 2;
  SdramTiming.ExitSelfRefreshDelay = 7;
  SdramTiming.SelfRefreshTime = 4;
  SdramTiming.RowCycleDelay = 7;
  SdramTiming.WriteRecoveryTime = 3;
  SdramTiming.RPDelay = 2;
  SdramTiming.RCDDelay = 2;

  if (HAL_SDRAM_Init(&hsdram1, &SdramTiming) != HAL_OK)
  {
    Error_Handler( );
  }

  /* USER CODE BEGIN FMC_Init 2 */

  /* USER CODE END FMC_Init 2 */
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOI_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOK_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOJ_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5|GPIO_PIN_4, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOK, GPIO_PIN_3, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(Green_LED_GPIO_Port, Green_LED_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOH, GPIO_PIN_7|SPI_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PD5 PD4 */
  GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : PK3 */
  GPIO_InitStruct.Pin = GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOK, &GPIO_InitStruct);

  /*Configure GPIO pin : Green_LED_Pin */
  GPIO_InitStruct.Pin = Green_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(Green_LED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PG2 */
  GPIO_InitStruct.Pin = GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : PA1 PA2 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PA4 */
  GPIO_InitStruct.Pin = GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PC4 */
  GPIO_InitStruct.Pin = GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PH7 */
  GPIO_InitStruct.Pin = GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

  /*Configure GPIO pins : PA6 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PA5 */
  GPIO_InitStruct.Pin = GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : SPI_CS_Pin */
  GPIO_InitStruct.Pin = SPI_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(SPI_CS_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

void TEST_TestAllAndStopIt()
{
	Alarm_test_all();
	DateTime_test_all();
	fatman_test_all();
	MyQueue_test_all();
}

int __io_putchar(int character)
{
//	HAL_UART_Transmit(&huart6, (uint8_t*)&character, 1, 0xFFFFFFFF);
	ITM_SendChar(character);
	return character;
}

void json_init(){

	f_mount(&SDFatFS, (TCHAR const*)SDPath, 0);

	memcpy(fatman.Directory[0].FilePath, "json_init.JSON", sizeof("json_init.JSON"));
	fatman_read();

	if(fatman.Directory[0].FileIsCreated)
	{
		cJSON *json = cJSON_ParseWithLength((char *)fatman.Buffer, fatman.Buffer_size);

		PSA.Module = cJSON_GetObjectItemCaseSensitive(json, "PSA.Module")->valueint;

		PSA.Time.SendAliveMessageToValve_Refresh = cJSON_GetObjectItemCaseSensitive(json, "PSA.Time.SendAliveMessageToValve_Refresh")->valueint;
		PSA.Time.SendStateMessageToValve_Refresh = cJSON_GetObjectItemCaseSensitive(json, "PSA.Time.SendStateMessageToValve_Refresh")->valueint;

		PSA.CANSPI.Ide = cJSON_GetObjectItemCaseSensitive(json, "PSA.CANSPI.Ide")->valueint;

		PSA.Time.Adsorption = cJSON_GetObjectItemCaseSensitive(json, "PSA.Time.Adsorption")->valueint;
		PSA.Time.Compensation_0 = cJSON_GetObjectItemCaseSensitive(json, "PSA.Time.Compensation_0")->valueint;
		PSA.Time.Compensation_1 = cJSON_GetObjectItemCaseSensitive(json, "PSA.Time.Compensation_1")->valueint;
		PSA.Time.Compensation_2 = cJSON_GetObjectItemCaseSensitive(json, "PSA.Time.Compensation_2")->valueint;
		PSA.Time.PreStandby_1 = cJSON_GetObjectItemCaseSensitive(json, "PSA.Time.PreStandby_1")->valueint;
		PSA.Time.PreStandby_2 = cJSON_GetObjectItemCaseSensitive(json, "PSA.Time.PreStandby_2")->valueint;

		PSA.B1_InputAirPressure.LowerLimit = cJSON_GetObjectItemCaseSensitive(json, "PSA.B1_InputAirPressure.LowerLimit")->valueint;
		PSA.B1_InputAirPressure.LowerThreshold = cJSON_GetObjectItemCaseSensitive(json, "PSA.B1_InputAirPressure.LowerThreshold")->valueint;
		PSA.B1_InputAirPressure.UpperThreshold = cJSON_GetObjectItemCaseSensitive(json, "PSA.B1_InputAirPressure.UpperThreshold")->valueint;
		PSA.B1_InputAirPressure.UpperLimit = cJSON_GetObjectItemCaseSensitive(json, "PSA.B1_InputAirPressure.UpperLimit")->valueint;

		PSA.B2_OutputAirPressure_1.LowerLimit = cJSON_GetObjectItemCaseSensitive(json, "PSA.B2_OutputAirPressure_1.LowerLimit")->valueint;
		PSA.B2_OutputAirPressure_1.LowerThreshold = cJSON_GetObjectItemCaseSensitive(json, "PSA.B2_OutputAirPressure_1.LowerThreshold")->valueint;
		PSA.B2_OutputAirPressure_1.UpperThreshold = cJSON_GetObjectItemCaseSensitive(json, "PSA.B2_OutputAirPressure_1.UpperThreshold")->valueint;
		PSA.B2_OutputAirPressure_1.UpperLimit = cJSON_GetObjectItemCaseSensitive(json, "PSA.B2_OutputAirPressure_1.UpperLimit")->valueint;

		PSA.B3_ProcessTankAirPressure.LowerLimit = cJSON_GetObjectItemCaseSensitive(json, "PSA.B3_ProcessTankAirPressure.LowerLimit")->valueint;
		PSA.B3_ProcessTankAirPressure.LowerThreshold = cJSON_GetObjectItemCaseSensitive(json, "PSA.B3_ProcessTankAirPressure.LowerThreshold")->valueint;
		PSA.B3_ProcessTankAirPressure.UpperThreshold = cJSON_GetObjectItemCaseSensitive(json, "PSA.B3_ProcessTankAirPressure.UpperThreshold")->valueint;
		PSA.B3_ProcessTankAirPressure.UpperLimit = cJSON_GetObjectItemCaseSensitive(json, "PSA.B3_ProcessTankAirPressure")->valueint;

		PSA.B4_OutputAirPressure_2.LowerLimit = cJSON_GetObjectItemCaseSensitive(json, "PSA.B4_OutputAirPressure_2.LowerLimit")->valueint;
		PSA.B4_OutputAirPressure_2.LowerThreshold = cJSON_GetObjectItemCaseSensitive(json, "PSA.B4_OutputAirPressure_2.LowerThreshold")->valueint;
		PSA.B4_OutputAirPressure_2.UpperThreshold = cJSON_GetObjectItemCaseSensitive(json, "PSA.B4_OutputAirPressure_2.UpperThreshold")->valueint;
		PSA.B4_OutputAirPressure_2.UpperLimit = cJSON_GetObjectItemCaseSensitive(json, "PSA.B4_OutputAirPressure_2.UpperLimit")->valueint;

		PSA.IFM_AirFlowmeter.LowerLimit = cJSON_GetObjectItemCaseSensitive(json, "PSA.IFM_AirFlowmeter.LowerLimit")->valueint;
		PSA.IFM_AirFlowmeter.LowerThreshold = cJSON_GetObjectItemCaseSensitive(json, "PSA.IFM_AirFlowmeter.LowerThreshold")->valueint;
		PSA.IFM_AirFlowmeter.UpperThreshold = cJSON_GetObjectItemCaseSensitive(json, "PSA.IFM_AirFlowmeter.UpperThreshold")->valueint;
		PSA.IFM_AirFlowmeter.UpperLimit = cJSON_GetObjectItemCaseSensitive(json, "PSA.IFM_AirFlowmeter.UpperLimit")->valueint;

		PSA.DEW_InputAirDewpoint.LowerLimit = cJSON_GetObjectItemCaseSensitive(json, "PSA.DEW_InputAirDewpoint.LowerLimit")->valueint;
		PSA.DEW_InputAirDewpoint.LowerThreshold = cJSON_GetObjectItemCaseSensitive(json, "PSA.DEW_InputAirDewpoint.LowerThreshold")->valueint;
		PSA.DEW_InputAirDewpoint.UpperThreshold = cJSON_GetObjectItemCaseSensitive(json, "PSA.DEW_InputAirDewpoint.UpperThreshold")->valueint;
		PSA.DEW_InputAirDewpoint.UpperLimit = cJSON_GetObjectItemCaseSensitive(json, "PSA.DEW_InputAirDewpoint.UpperLimit")->valueint;

		PSA.KE25_OxygenSensor_1.LowerLimit = cJSON_GetObjectItemCaseSensitive(json, "PSA.KE25_OxygenSensor_1.LowerLimit")->valueint;
		PSA.KE25_OxygenSensor_1.LowerThreshold = cJSON_GetObjectItemCaseSensitive(json, "PSA.KE25_OxygenSensor_1.LowerThreshold")->valueint;
		PSA.KE25_OxygenSensor_1.UpperThreshold = cJSON_GetObjectItemCaseSensitive(json, "PSA.KE25_OxygenSensor_1.UpperThreshold")->valueint;
		PSA.KE25_OxygenSensor_1.UpperLimit = cJSON_GetObjectItemCaseSensitive(json, "PSA.KE25_OxygenSensor_1.UpperLimit")->valueint;

		PSA.KE25_OxygenSensor_2.LowerLimit = cJSON_GetObjectItemCaseSensitive(json, "PSA.KE25_OxygenSensor_2.LowerLimit")->valueint;
		PSA.KE25_OxygenSensor_2.LowerThreshold = cJSON_GetObjectItemCaseSensitive(json, "PSA.KE25_OxygenSensor_2.LowerThreshold")->valueint;
		PSA.KE25_OxygenSensor_2.UpperThreshold = cJSON_GetObjectItemCaseSensitive(json, "PSA.KE25_OxygenSensor_2.UpperThreshold")->valueint;
		PSA.KE25_OxygenSensor_2.UpperLimit = cJSON_GetObjectItemCaseSensitive(json, "PSA.KE25_OxygenSensor_2.UpperLimit")->valueint;

		PSA.OutPriority = cJSON_GetObjectItemCaseSensitive(json, "PSA.OutPriority")->valueint;
		PSA.Out1.Enable = cJSON_GetObjectItemCaseSensitive(json, "PSA.Out1.Enable")->valueint;
		PSA.Out2.Enable = cJSON_GetObjectItemCaseSensitive(json, "PSA.Out2.Enable")->valueint;

		memset((char *)fatman.Buffer, 0, FATMAN_BUFFER_SIZE);
		fatman.Buffer_size = 0;
	}
}

void AssignDefaultValue()
{
	/* DateTime */
	DateTime_Init(2022, 10, 5, 23, 59, 0);

	PSA.Module = 2;

	PSA.Time.SendAliveMessageToValve_Refresh = 1;
	PSA.Time.SendStateMessageToValve_Refresh = 1;

	PSA.CANSPI.Ide = 0x701;

	/* Inizializza i valori dei timer per il debug */
	PSA.Time.Adsorption = 54;
	PSA.Time.Compensation_0 = 1;
	PSA.Time.Compensation_1 = 1;
	PSA.Time.Compensation_2 = 1;
	PSA.Time.PreStandby_1 = 5;
	PSA.Time.PreStandby_2 = 5;

	PSA.Mode.Ready = 0x00;								/* Altrimenti non parte */

	PSA.B1_InputAirPressure.LowerLimit = 0;
	PSA.B1_InputAirPressure.LowerThreshold = 500; 			//SB1L
//	PSA.B1_InputAirPressure.Value = 710;					/* Altrimenti non parte */
	PSA.B1_InputAirPressure.UpperThreshold = 700; 			//SB1H
	PSA.B1_InputAirPressure.UpperLimit = 10000;

	PSA.B3_ProcessTankAirPressure.LowerLimit = 0;
	PSA.B3_ProcessTankAirPressure.LowerThreshold = 500; 	//SB3L
//	PSA.B3_ProcessTankAirPressure.Value = 600;
	PSA.B3_ProcessTankAirPressure.UpperThreshold = 700; 	//SB3H
	PSA.B3_ProcessTankAirPressure.UpperLimit = 10000;

	PSA.B2_OutputAirPressure_1.LowerLimit = 0;
	PSA.B2_OutputAirPressure_1.LowerThreshold = 500; 		//SB2L
//	PSA.B2_OutputAirPressure_1.Value = 600;
	PSA.B2_OutputAirPressure_1.UpperThreshold = 700; 		//SB2H
	PSA.B2_OutputAirPressure_1.UpperLimit = 10000;

	PSA.B4_OutputAirPressure_2.LowerLimit = 0;
	PSA.B4_OutputAirPressure_2.LowerThreshold = 500; 		//SB4L
//	PSA.B4_OutputAirPressure_2.Value = 600;
	PSA.B4_OutputAirPressure_2.UpperThreshold = 700; 		//SB4H
	PSA.B4_OutputAirPressure_2.UpperLimit = 10000;

	PSA.IFM_AirFlowmeter.LowerLimit = 0;
	PSA.IFM_AirFlowmeter.LowerThreshold = 500;
//	PSA.IFM_AirFlowmeter.Value = 600;
	PSA.IFM_AirFlowmeter.UpperThreshold = 700;
	PSA.IFM_AirFlowmeter.UpperLimit = 10000;

	PSA.DEW_InputAirDewpoint.LowerLimit = 0;
	PSA.DEW_InputAirDewpoint.LowerThreshold = 500;
//	PSA.DEW_InputAirDewpoint.Value = 600;
	PSA.DEW_InputAirDewpoint.UpperThreshold = 700;
	PSA.DEW_InputAirDewpoint.UpperLimit = 10000;

	PSA.KE25_OxygenSensor_1.LowerLimit = 0;
	PSA.KE25_OxygenSensor_1.LowerThreshold = 500;
//	PSA.KE25_OxygenSensor_1.Value = 600;
	PSA.KE25_OxygenSensor_1.UpperThreshold = 700;
	PSA.KE25_OxygenSensor_1.UpperLimit = 10000;

	PSA.KE25_OxygenSensor_2.LowerLimit = 0;
	PSA.KE25_OxygenSensor_2.LowerThreshold = 500;
//	PSA.KE25_OxygenSensor_2.Value = 600;
	PSA.KE25_OxygenSensor_2.UpperThreshold = 700;
	PSA.KE25_OxygenSensor_2.UpperLimit = 10000;


	PSA.OutPriority = 1;								//PR_OUT

//	PSA.KE25_OxygenSensor_1.LowerThreshold = 4; 			//SO2-1
	PSA.Out1.Enable = 1;
//	PSA.KE25_OxygenSensor_2.LowerThreshold = 2; 			//SO2-2
	PSA.Out2.Enable = 1;
}

void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan){
	CAN_RxHeaderTypeDef RxHeader;
	uint8_t RxData[8];
	PSA.CAN_2.State = HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO1, &RxHeader, RxData);
	HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_5);
	if(!PSA.CAN_2.State)
	{
		/* La condizione per verificare la condizione è:
		 * StdId = 0x701
		 * DLC =1
		 * Il primo dato diverso da 0x7F e 0xFF
		 */
		if((RxHeader.StdId == 0x701) && (RxHeader.DLC == 1)
				&& (RxData[0] != 0x7F) && (RxData[0] != 0xFF))
		{
			PSA.CAN_2.AliveMessageReceived = 1;
		}
#ifdef ACQUISITION_DATA_CAN2
		/* Simulazione della ricezione di dati */
		if((RxHeader.StdId == 0x701) && (RxHeader.DLC == 3) && (RxData[0] == 0x01))
		{
			PSA.B1_InputAirPressure.Value = (RxData[1] << 8) + (RxData[2] << 0);
			PSA.B1_InputAirPressure.Acquisition = 1;
		}

		if((RxHeader.StdId == 0x701) && (RxHeader.DLC == 3) && (RxData[0] == 0x02))
		{
			PSA.B2_OutputAirPressure_1.Value = (RxData[1] << 8) + (RxData[2] << 0);
			PSA.B2_OutputAirPressure_1.Acquisition = 1;
		}

		if((RxHeader.StdId == 0x701) && (RxHeader.DLC == 3) && (RxData[0] == 0x03))
		{
			PSA.B3_ProcessTankAirPressure.Value = (RxData[1] << 8) + (RxData[2] << 0);
			PSA.B3_ProcessTankAirPressure.Acquisition = 1;
		}

		if((RxHeader.StdId == 0x701) && (RxHeader.DLC == 3) && (RxData[0] == 0x04))
		{
			PSA.B4_OutputAirPressure_2.Value = (RxData[1] << 8) + (RxData[2] << 0);
			PSA.B4_OutputAirPressure_2.Acquisition = 1;
		}

		if((RxHeader.StdId == 0x701) && (RxHeader.DLC == 3) && (RxData[0] == 0x05))
		{
			PSA.DEW_InputAirDewpoint.Value = (RxData[1] << 8) + (RxData[2] << 0);
			PSA.DEW_InputAirDewpoint.Acquisition = 1;
		}

		if((RxHeader.StdId == 0x701) && (RxHeader.DLC == 3) && (RxData[0] == 0x06))
		{
			PSA.IFM_AirFlowmeter.Value = (RxData[1] << 8) + (RxData[2] << 0);
			PSA.IFM_AirFlowmeter.Acquisition = 1;
		}

		if((RxHeader.StdId == 0x701) && (RxHeader.DLC == 3) && (RxData[0] == 0x07))
		{
			PSA.KE25_OxygenSensor_1.Value = (RxData[1] << 8) + (RxData[2] << 0);
			PSA.KE25_OxygenSensor_2.Value = (RxData[1] << 8) + (RxData[2] << 0);
			PSA.KE25_OxygenSensor_1.Acquisition = 1;
			PSA.KE25_OxygenSensor_2.Acquisition = 1;
		}
#endif
	}
}

//void ADC_SelectChannel(ADC_HandleTypeDef *hadc, )
//{
//	sConfig.Channel = ADC_CHANNEL_11;
//	sConfig.Rank = 1;
//	sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
//	if (HAL_ADC_ConfigChannel(&hadc3, &sConfig) != HAL_OK)
//	{
//		Error_Handler();
//	}
//}

void ADC_SetConfigChannel(ADC_HandleTypeDef *hadc, uint32_t Channel, uint32_t Rank, uint32_t SamplingTime)
{
	ADC_ChannelConfTypeDef sConfig = {0};

	sConfig.Channel = Channel;
	sConfig.Rank = Rank;
	sConfig.SamplingTime = SamplingTime;
	if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
	{
		Error_Handler();
	}
}

uint16_t raw_1;
uint16_t raw_2;
uint16_t raw_3;
/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN 5 */
	uint8_t read = 0;
  /* Infinite loop */
	TickType_t TaskDelayTimer = xTaskGetTickCount();

//	HAL_ADC_Start(&hadc1);
//	HAL_ADC_Start(&hadc2);
//	HAL_ADC_Start(&hadc3);

//	  HAL_ADC_Start(&hadc1);
	  HAL_ADC_PollForConversion(&hadc1, 1 * centiseconds);
//	  HAL_ADC_Start(&hadc1);

  for(;;)
  {
	  ADC_SetConfigChannel(&hadc1, ADC_CHANNEL_5, 1, ADC_SAMPLETIME_56CYCLES);
	  HAL_ADC_Start(&hadc1);
	  raw_1 = HAL_ADC_GetValue(&hadc1);
//	  HAL_ADC_Stop(&hadc1);
	  vTaskDelayUntil(&TaskDelayTimer, 1 * centiseconds);

	  ADC_SetConfigChannel(&hadc1, ADC_CHANNEL_9, 2, ADC_SAMPLETIME_84CYCLES);
	  HAL_ADC_Start(&hadc1);
	  raw_2 = HAL_ADC_GetValue(&hadc1);
//	  HAL_ADC_Stop(&hadc1);
	  vTaskDelayUntil(&TaskDelayTimer, 1 * centiseconds);

	  ADC_SetConfigChannel(&hadc1, ADC_CHANNEL_11, 3, ADC_SAMPLETIME_112CYCLES);
	  HAL_ADC_Start(&hadc1);
	  raw_3 = HAL_ADC_GetValue(&hadc1);
//	  HAL_ADC_Stop(&hadc1);
	  vTaskDelayUntil(&TaskDelayTimer, 1 * centiseconds);

//	  HAL_ADC_PollForConversion(&hadc3, 1 * deciseconds);
//	  raw_3 = HAL_ADC_GetValue(&hadc3);

//	  vTaskDelayUntil(&TaskDelayTimer, 1 * centiseconds);
  }
  /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_StartStateTask */
/**
* @brief Function implementing the StateTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartStateTask */
void StartStateTask(void *argument)
{
  /* USER CODE BEGIN StartStateTask */
	/* Main purpose of StateTask is to manage the value of PSA.State. No other tasks can change its value, but they have to ask StateTask to do it for them. */
	TickType_t StateTaskDelayTimer = xTaskGetTickCount();
  /* Infinite loop */
  for(;;)
  {

	  PSA.Time.TotalCompensation = PSA.Time.Compensation_0 +
			  PSA.Time.Compensation_1 + PSA.Time.Compensation_2;

	  if(PSA.Mode.Enable)
	  {
		  PSA.State_Update = 0;
		  if((PSA.Mode.Run) && (PSA.State < 1))
		  {
			  PSA.State = 1;
			  PSA_State_UpdateValveMessage();
		  }

		  if((!PSA.Mode.Run) && (PSA.State > 0))
		  {
			  PSA.State = -2;
			  PSA_State_UpdateValveMessage();
		  }

		  if(!PSA.State_Timer)
		  {
			  if(PSA.State)
			  {
				  PSA.State++;
			  }

			  if(PSA.State > 16)
			  {
				  PSA.State = 1;
			  }

			  PSA_State_UpdateValveMessage();
		  }
	  }


	  vTaskDelayUntil(&StateTaskDelayTimer, 1 * deciseconds);
  }
  /* USER CODE END StartStateTask */
}

/* USER CODE BEGIN Header_StartOutTask */
/**
* @brief Function implementing the OutTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartOutTask */
void StartOutTask(void *argument)
{
  /* USER CODE BEGIN StartOutTask */
	/* Main purpose of OutTask is to manage the values of the structures PSA.Out1 and PSA.Out2. No other tasks can change their values, but they have to ask OutTask to do it for them. */
	TickType_t OutTaskDelayTimer = xTaskGetTickCount();
	  /* Infinite loop */
	  for(;;)
	  {

		  /* GUI Command ------------------------------------------------*/
#if 0
		  if(!PSA.KE25_OxygenSensor_1.LowerThreshold)
		  {
			  PSA.Out1.Enable = 0;
			  PSA.Out1.Ready = 0;
			  PSA.Out1.Run = 0;
		  }
		  if(!PSA.KE25_OxygenSensor_2.LowerThreshold)
		  {
			  PSA.Out2.Enable = 0;
			  PSA.Out2.Ready = 0;
			  PSA.Out2.Run = 0;
		  }
#endif

		  /* Managing Command ------------------------------------------------*/
		  if(PSA.Command.EnableOut1_DisableOut2)
		  {
			  PSA_Command_EnableOut1_DisableOut2();
		  }
		  if(PSA.Command.EnableOut2_DisableOut1)
		  {
			  PSA_Command_EnableOut2_DisableOut1();
		  }
		  if(PSA.Command.EnableOut1_EnableOut2)
		  {
			  PSA_Command_EnableOut1_EnableOut2();
		  }
		  if(PSA.Command.SetPriorityOut1)
		  {
			  PSA_Command_SetPriorityOut1();
		  }
		  if(PSA.Command.SetPriorityOut2)
		  {
			  PSA_Command_SetPriorityOut2();
		  }

		  /* Starting Condition ----------------------------------------------*/
		  if((PSA.Mode.Run) && ((PSA.Out1.Enable) && (PSA.Out2.Enable)) && ((!PSA.Out1.Ready) && (!PSA.Out2.Ready)) && ((PSA.OutPriority == 1) || (PSA.OutPriority == 2)))
		  {
			  if(PSA.OutPriority == 1)
			  {
				  PSA.Out1.Ready = 1;
			  }

			  if(PSA.OutPriority == 2)
			  {
				  PSA.Out2.Ready = 1;
			  }
		  }
		  if((PSA.Mode.Run) && ((PSA.Out1.Enable) && (!PSA.Out2.Enable)) && ((!PSA.Out1.Ready) && (!PSA.Out2.Ready)))
		  {
			  PSA.Out1.Ready = 1;
		  }
		  if ((PSA.Mode.Run) && ((!PSA.Out1.Enable) && (PSA.Out2.Enable)) && ((!PSA.Out1.Ready) && (!PSA.Out2.Ready)))
		  {
			  PSA.Out2.Ready = 1;
		  }

		  /* Out-Working Condition -------------------------------------------*/
		  if(((PSA.Mode.Run) && (PSA.Out1.Ready) && (!PSA.Out1.Run)) && (PSA.KE25_OxygenSensor_1.Value < PSA.KE25_OxygenSensor_1.LowerThreshold))
		  {
			  PSA.Out1.Run = 1;
		  }
		  if(((PSA.Mode.Run) && (PSA.Out2.Ready) && (!PSA.Out2.Run)) && (PSA.KE25_OxygenSensor_2.Value < PSA.KE25_OxygenSensor_2.LowerThreshold))
		  {
			  PSA.Out2.Run = 1;
		  }

		  /* Out-Swapping Condition ------------------------------------------*/
		  if(((PSA.Mode.Run) && (PSA.Out1.Run)) && (PSA.Alarm.AL19_HighOut1Pressure.Trigger) && ((PSA.Out2.Enable) && (!PSA.Alarm.AL16_HighOut2Pressure.Trigger)))
		  {
			  PSA.Out1.Ready = 0;
			  PSA.Out1.Run = 0;
			  PSA.Out2.Ready = 1;
		  }
		  if(((PSA.Mode.Run) && (PSA.Out2.Run)) && (PSA.Alarm.AL16_HighOut2Pressure.Trigger) && (PSA.Out1.Enable))
		  {
			  PSA.Out1.Ready = 1;
			  PSA.Out2.Ready = 0;
			  PSA.Out2.Run = 0;
		  }

		  /* Standby Mode Condition ------------------------------------------*/
		  if((!PSA.Mode.Run) && (PSA.Out1.Ready))
		  {
			  PSA.Out1.Run = 0;
		  }
		  if((!PSA.Mode.Run) && (PSA.Out2.Ready))
		  {
			  PSA.Out2.Run = 0;
		  }

	    vTaskDelayUntil(&OutTaskDelayTimer, 1 * deciseconds);
	  }
  /* USER CODE END StartOutTask */
}

/* USER CODE BEGIN Header_StartModeTask */
/**
* @brief Function implementing the ModeTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartModeTask */
void StartModeTask(void *argument)
{
  /* USER CODE BEGIN StartModeTask */
	TickType_t ModeTaskDelayTimer = xTaskGetTickCount();
  /* Infinite loop */
  for(;;)
  {
	  /* Enabling condition --------------------------------------------------*/
	  if(((!PSA.Mode.Enable) && (PSA.Mode.Ready) && (!PSA.Mode.Run)) && ((PSA.B1_InputAirPressure.Value > PSA.B1_InputAirPressure.UpperThreshold) && ((PSA.Out1.Enable)||(PSA.Out2.Enable))))
	  {
		  PSA.Mode.Enable = 0x01;
		  PSA.Mode.Run = 0x01;
	  }

	  /* Ready condition -----------------------------------------------------*/
	  if(((PSA.Mode.Enable) && (PSA.Mode.Ready) && (!PSA.State) && (PSA.Out1.Ready)) && (!PSA.Alarm.AL19_HighOut1Pressure.Trigger))
	  {
		  PSA.Mode.Run = 0x01;
	  }

	  if(((PSA.Mode.Enable) && (PSA.Mode.Ready) && (!PSA.State) && (PSA.Out2.Ready)) && (!PSA.Alarm.AL16_HighOut2Pressure.Trigger))
	  {
		  PSA.Mode.Run = 0x01;
	  }

	  /* Not Ready condition -------------------------------------------------*/
	  if(((PSA.Mode.Enable) && (!PSA.Mode.Ready) && (PSA.Mode.Run) && (PSA.Out1.Ready)) && (PSA.Alarm.AL19_HighOut1Pressure.Trigger))
	  {
		  PSA.Mode.Run = 0x00;
	  }

	  if(((PSA.Mode.Enable) && (!PSA.Mode.Ready) && (PSA.Mode.Run) && (PSA.Out2.Ready)) && (PSA.Alarm.AL16_HighOut2Pressure.Trigger))
	  {
		  PSA.Mode.Run = 0x00;
	  }

	  /* Run condition -------------------------------------------------------*/
	  if(((PSA.Mode.Enable) && (PSA.Mode.Ready) && (!PSA.State) && (PSA.Out1.Ready))
			  && (!PSA.Alarm.AL19_HighOut1Pressure.Trigger) && (!PSA.Alarm.BlockingAlarmsTriggered))
	  {
		  PSA.Mode.Run = 0x01;
	  }

	  if(((PSA.Mode.Enable) && (PSA.Mode.Ready) && (!PSA.State) && (PSA.Out2.Ready))
			  && (!PSA.Alarm.AL16_HighOut2Pressure.Trigger) && (!PSA.Alarm.BlockingAlarmsTriggered))
	  {
		  PSA.Mode.Run = 0x01;
	  }

	  /* Standby condition ---------------------------------------------------*/
	  if(((PSA.Mode.Enable) && (PSA.Mode.Ready) && (PSA.Mode.Run) && (PSA.Out1.Run))
			  && ((PSA.Alarm.AL19_HighOut1Pressure.Trigger) && ((!PSA.Out2.Enable) || (PSA.Alarm.AL16_HighOut2Pressure.Trigger))))
	  {
		  PSA.Mode.Run = 0x00;
	  }

	  if(((PSA.Mode.Enable) && (PSA.Mode.Ready) && (PSA.Mode.Run) && (PSA.Out2.Run))
			  && ((PSA.Alarm.AL16_HighOut2Pressure.Trigger) && (!PSA.Out1.Enable)))
	  {
		  PSA.Mode.Run = 0x00;
	  }

	  /* Standby condition: Blocking Alarm -----------------------------------*/
	  if(((PSA.Mode.Enable) && (PSA.Mode.Ready) && (PSA.Mode.Run) && (PSA.Out2.Run))
			  && (PSA.Alarm.BlockingAlarmsTriggered))
	  {
		  PSA.Mode.Run = 0x00;
	  }

	  if(((PSA.Mode.Enable) && (PSA.Mode.Ready) && (PSA.Mode.Run) && (PSA.Out2.Run))
			  && (PSA.Alarm.BlockingAlarmsTriggered))
	  {
		  PSA.Mode.Run = 0x00;
	  }

	  vTaskDelayUntil(&ModeTaskDelayTimer, 1 * deciseconds);
  }
  /* USER CODE END StartModeTask */
}

/* USER CODE BEGIN Header_StartTimeTask */
/**
* @brief Function implementing the TimeTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTimeTask */
void StartTimeTask(void *argument)
{
  /* USER CODE BEGIN StartTimeTask */
	/* Init Refresher */
//	PSA.Time.SendStateMessageToValve_Refresh = 1;
//	PSA.Time.SendAliveMessageToValve_Refresh = 1;
	/* Init Timer */
	MyTimer_Refresh(&PSA.Time.SendStateMessageToValve_Timer, PSA.Time.SendStateMessageToValve_Refresh);
	MyTimer_Refresh(&PSA.Time.SendStateMessageToValve_Timer, PSA.Time.SendAliveMessageToValve_Refresh);
  /* Infinite loop */
	TickType_t TaskDelayTimer = xTaskGetTickCount();
  for(;;)
  {
	  /* DateTime ------------------------------------------------------------*/
	  DateTime_AddDeciSecond();
	  /* Time Counter --------------------------------------------------------*/
	  if(PSA.Out1.Ready)
		  TimeCounter_AddDecisecond(&PulldownWorking);
	  if(PSA.Out2.Ready)
		  TimeCounter_AddDecisecond(&MaintenanceWorking);
	  TimeCounter_AddDecisecond(&TotalWorking);
	  /* Timer ---------------------------------------------------------------*/
	  MyTimer_SubtractDeciSecond(&PSA.State_Timer);
	  MyTimer_SubtractDeciSecond(&PSA.Time.SendStateMessageToValve_Timer);
	  MyTimer_SubtractDeciSecond(&PSA.Time.SendAliveMessageToValve_Timer);
	  /* Alarm Timer ---------------------------------------------------------*/
	  MyTimer_SubtractDeciSecond(&PSA.Alarm.AL01_CANbusError.Timer);
	  MyTimer_SubtractDeciSecond(&PSA.Alarm.AL02_LowInputAirPressure.Timer);
	  MyTimer_SubtractDeciSecond(&PSA.Alarm.AL05_LowProcessTankPressure.Timer);
	  MyTimer_SubtractDeciSecond(&PSA.Alarm.AL11_External.Timer);
	  MyTimer_SubtractDeciSecond(&PSA.Alarm.AL16_HighOut2Pressure.Timer);
	  MyTimer_SubtractDeciSecond(&PSA.Alarm.AL17_HighDewpoint.Timer);
	  MyTimer_SubtractDeciSecond(&PSA.Alarm.AL18_HighDewpoint.Timer);
	  MyTimer_SubtractDeciSecond(&PSA.Alarm.AL19_HighOut1Pressure.Timer);
	  MyTimer_SubtractDeciSecond(&PSA.Alarm.AL20_PCComunicationFault.Timer);
	  MyTimer_SubtractDeciSecond(&PSA.Alarm.AL31_B1ProbeFault.Timer);
	  MyTimer_SubtractDeciSecond(&PSA.Alarm.AL32_B2ProbeFault.Timer);
	  MyTimer_SubtractDeciSecond(&PSA.Alarm.AL33_B3ProbeFault.Timer);
	  MyTimer_SubtractDeciSecond(&PSA.Alarm.AL34_B4ProbeFault.Timer);
	  MyTimer_SubtractDeciSecond(&PSA.Alarm.AL35_IFWProbeFault.Timer);
	  MyTimer_SubtractDeciSecond(&PSA.Alarm.AL36_DEWProbeFault.Timer);
	  MyTimer_SubtractDeciSecond(&PSA.Alarm.AL37_KE25ProbeFault.Timer);
	  MyTimer_SubtractDeciSecond(&PSA.Alarm.MissingSDCard.Timer);
	  /* Message Timer -------------------------------------------------------*/
	  MyTimer_SubtractDeciSecond(&PSA.Time.SendAliveMessageToValve_Timer);
	  MyTimer_SubtractDeciSecond(&PSA.Time.SendStateMessageToValve_Timer);
	  /* Watchdog ------------------------------------------------------------*/
	  /* New day -------------------------------------------------------------*/
	  if((today.hours + today.minutes + today.seconds + today.deciseconds) == 0)
	  {
		  fatman.Directory[1].FileIsCreated = 0;
	  }
	  vTaskDelayUntil(&TaskDelayTimer, 1 * deciseconds);
  }
  /* USER CODE END StartTimeTask */
}

/* USER CODE BEGIN Header_StartCAN2TxTask */
/**
* @brief Function implementing the CAN2TxTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartCAN2TxTask */
void StartCAN2TxTask(void *argument)
{
  /* USER CODE BEGIN StartCAN2TxTask */
	/* TxAliveMxHeader */
	CAN_TxHeaderTypeDef TxAliveMxHeader;
	TxAliveMxHeader.StdId = 0x701;
	TxAliveMxHeader.ExtId = 0x00;
	TxAliveMxHeader.RTR = CAN_RTR_REMOTE;
	TxAliveMxHeader.IDE = CAN_ID_STD;
	TxAliveMxHeader.DLC = 8;
	uint8_t AliveMessage[8] = {0};

	/* TxValveMxHeader */
	CAN_TxHeaderTypeDef TxValveMxHeader;
	TxValveMxHeader.StdId = 0x201;
	TxValveMxHeader.ExtId = 0x00;
	TxValveMxHeader.RTR = CAN_RTR_DATA;
	TxValveMxHeader.IDE = CAN_ID_STD;
	TxValveMxHeader.DLC = 8;

	/* TaskManagement */
	uint32_t TxMailbox;
	TickType_t TaskDelayTimer = xTaskGetTickCount();

	/* Init Message */
	CAN_TxHeaderTypeDef TxInitMxHeader;
	TxInitMxHeader.StdId = 0x00;
	TxInitMxHeader.ExtId = 0x00;
	TxInitMxHeader.RTR = CAN_RTR_DATA;
	TxInitMxHeader.IDE = CAN_ID_STD;
	TxInitMxHeader.DLC = 2;
	uint8_t InitMx[2] = {0};
	InitMx[0] = 0x01;
	PSA.CAN_2.State = HAL_CAN_AddTxMessage(&hcan2, &TxInitMxHeader, InitMx, &TxMailbox);

  /* Infinite loop */
  for(;;)
  {

	  if(PSA.CAN_2.State == HAL_OK)
	  {
		  if(!PSA.Time.SendStateMessageToValve_Timer)
		  {
			  PSA.CAN_2.State = HAL_CAN_AddTxMessage(&hcan2, &TxValveMxHeader, PSA.Valve, &TxMailbox);
			  PSA.Time.SendStateMessageToValve_Timer = PSA.Time.SendStateMessageToValve_Refresh;
		  }

		  if(!PSA.Time.SendAliveMessageToValve_Timer)
		  {
			  PSA.CAN_2.State = HAL_CAN_AddTxMessage(&hcan2, &TxAliveMxHeader, AliveMessage, &TxMailbox);
			  PSA.Time.SendAliveMessageToValve_Timer = PSA.Time.SendAliveMessageToValve_Refresh;
		  }
	  }
	  else if(PSA.CAN_2.State == HAL_ERROR)
	  {
		  MX_CAN1_Init();
		  MX_CAN2_Init();
		  PSA.CAN_2.State = HAL_CAN_AddTxMessage(&hcan2, &TxInitMxHeader, InitMx, &TxMailbox);
	  }
	  vTaskDelayUntil(&TaskDelayTimer, 1 * deciseconds);
  }
  /* USER CODE END StartCAN2TxTask */
}

/* USER CODE BEGIN Header_StartSDTask */
/**
* @brief Function implementing the SDTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartSDTask */
void StartSDTask(void *argument)
{
  /* USER CODE BEGIN StartSDTask */
	TickType_t TaskDelayTimer = xTaskGetTickCount();

	/* Initialize the name of directory */
	f_mount(&SDFatFS, (TCHAR const*)SDPath, 0);
	/* This task do not work until datetime it's initialized */
	while(!today.Enable){}
	/* Initialize all the directory and file */
	DirectoryInit(1, "EVENT", 5);
	vTaskDelayUntil(&TaskDelayTimer, 1 * deciseconds);

  /* Infinite loop */
  for(;;)
  {
#ifdef DEBUG
	  HAL_GPIO_TogglePin(GPIOK, GPIO_PIN_3);
#endif

	  /* new day, new file */
	  if(!fatman.Directory[1].FileIsCreated)
	  {
		  fatman_rename(1, (char *)today.DateString, 8);
		  fatman_init(1);
	  }
	  /* if there is some problem. Try to re-init SD */
	  if(hsd.ErrorCode)
	  {
		  HAL_SD_Init(&hsd);
	  }

	  /* If alarm trigger or stop to trigger, write it on SD */
	  CheckAlarmConditionToWriteSD(&PSA.Alarm.AL01_CANbusError,
			  	  	  	  	  	  "AL01 Errore CAN Bus",
								  sizeof("AL01 Errore CAN Bus"));
	  CheckAlarmConditionToWriteSD(&PSA.Alarm.AL02_LowInputAirPressure,
			  	  	  	  	  	  "AL02 Bassa Pressione Aria in Ingresso",
								  sizeof("AL02 Bassa Pressione Aria in Ingresso"));
	  CheckAlarmConditionToWriteSD(&PSA.Alarm.AL05_LowProcessTankPressure,
			  	  	  	  	  	  "AL05 Bassa Pressione Serbatoio di Processo",
								  sizeof("AL05 Bassa Pressione Serbatoio di Processo"));
	  CheckAlarmConditionToWriteSD(&PSA.Alarm.AL11_External,
			  	  	  	  	  	  "AL11 Allarme Esterno",
								  sizeof("AL11 Allarme Esterno"));
	  CheckAlarmConditionToWriteSD(&PSA.Alarm.AL16_HighOut2Pressure,
			  	  	  	  	  	  "AL16 Alta Pressione OUT 2",
								  sizeof("AL16 Alta Pressione OUT 2"));
	  CheckAlarmConditionToWriteSD(&PSA.Alarm.AL17_HighDewpoint,
			  	  	  	  	  	  "AL17 Valore alto di Dewpoint",
								  sizeof("AL17 Valore alto di Dewpoint"));
	  CheckAlarmConditionToWriteSD(&PSA.Alarm.AL18_HighDewpoint,
			  	  	  	  	  	  "AL18 Valore alto di Dewpoint",
								  sizeof("AL18 Valore alto di Dewpoint"));
	  CheckAlarmConditionToWriteSD(&PSA.Alarm.AL20_PCComunicationFault,
			  	  	  	  	  	  "AL20 Guasto Comunicazione PC",
								  sizeof("AL20 Guasto Comunicazione PC"));
	  CheckAlarmConditionToWriteSD(&PSA.Alarm.AL31_B1ProbeFault,
	  			  	  	  	  	  "AL31 Guasto Sonda B1",
								  sizeof("AL31 Guasto Sonda B1"));
	  CheckAlarmConditionToWriteSD(&PSA.Alarm.AL32_B2ProbeFault,
	  			  	  	  	  	  "AL32 Guasto Sonda B2",
								  sizeof("AL32 Guasto Sonda B2"));
	  CheckAlarmConditionToWriteSD(&PSA.Alarm.AL33_B3ProbeFault,
	  			  	  	  	  	  "AL33 Guasto Sonda B3",
								  sizeof("AL33 Guasto Sonda B3"));
	  CheckAlarmConditionToWriteSD(&PSA.Alarm.AL34_B4ProbeFault,
	  			  	  	  	  	  "AL34 Guasto Sonda B4",
								  sizeof("AL34 Guasto Sonda B4"));
	  CheckAlarmConditionToWriteSD(&PSA.Alarm.AL35_IFWProbeFault,
	  			  	  	  	  	  "AL35 Guasto Sonda IFM",
								  sizeof("AL35 Guasto Sonda IFM"));
	  CheckAlarmConditionToWriteSD(&PSA.Alarm.AL36_DEWProbeFault,
	  			  	  	  	  	  "AL36 Guasto Sonda DEW",
								  sizeof("AL36 Guasto Sonda DEW"));
	  CheckAlarmConditionToWriteSD(&PSA.Alarm.AL37_KE25ProbeFault,
	  			  	  	  	  	  "AL37 Guasto Sonda KE25",
								  sizeof("AL37 Guasto Sonda KE25"));
	  CheckAlarmConditionToWriteSD(&PSA.Alarm.MissingSDCard,
	  			  	  	  	  	  "MicroSD Assente",
								  sizeof("MicroSD Assente"));

	  vTaskDelayUntil(&TaskDelayTimer, 1 * deciseconds);
  }
  /* USER CODE END StartSDTask */
}

/* USER CODE BEGIN Header_StartCAN1RxTxTask */
/**
* @brief Function implementing the CAN1RxTxTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartCAN1RxTxTask */
void StartCAN1RxTxTask(void *argument)
{
  /* USER CODE BEGIN StartCAN1RxTxTask */
		PSA.CANSPI.State = CANSPI_Initialize();

		TickType_t TaskDelayTimer = xTaskGetTickCount();



	  /* Infinite loop */
	  for(;;)
	  {
//		  if(CANSPI_messagesInBuffer() && PSA.CANSPI.State)
//		  {
//			  PSA.CANSPI.State = CANSPI_Receive(&rxMessage);
//			  if((((rxMessage.frame.data4 << 16) | (rxMessage.frame.data5 << 8) | (rxMessage.frame.data6)) == 0x10000) && (rxMessage.frame.id == (0x600 + PSA.CANSPI.Ide)))
//			  {
//				  rxMessage.frame.id -= 0x80;
//
//				  switch((rxMessage.frame.data0 << 16) | (rxMessage.frame.data1 << 8) | (rxMessage.frame.data2))
//				  {
//	//			  /*** COMMAND ***/
//	//			  case 0x230065:
//	//				  break;
//				  case 0x23006E:
//					  if(rxMessage.frame.data7 == 0x02)
//					  {
//						  PSA.Command.EnableOut1_EnableOut2 = 1;
//					  }
//					  else if(rxMessage.frame.data7 == 0x01)
//					  {
//						  PSA.Command.EnableOut2_DisableOut1 = 1;
//					  }
//					  else if(rxMessage.frame.data7 == 0x00)
//					  {
//						  PSA.Command.EnableOut1_DisableOut2 = 1;
//					  }
//					  break;
//				  case 0x23006F:
//					  if(rxMessage.frame.data7 == 0x00)
//						  PSA.Command.SetPriorityOut1 = 1;
//					  else if(rxMessage.frame.data7 == 0x01)
//						  PSA.Command.SetPriorityOut2 = 1;
//					  break;
//	//			  case 0x230074:
//	//
//	//				  break;
//	//
//	//			  /*** REQUEST ***/
//	//			  case 0x400014:
//	//				  rxMessage.frame.data0 = 0x4B;
//	//				  break;
//	//			  case 0x400032:
//	//				  PSA.Request.State |= (1U << 1);
//	//				  break;
////				  case 0x40000A:
////					  rxMessage.frame.data0 = 0x4B;
////					  uint16_t Oxygen_LastValue = MyQueue_GetLastValue(KE25_PercentualOxygenInTheAir);
////					  rxMessage.frame.data4 = Oxygen_LastValue >> 8;
////					  rxMessage.frame.data5 = Oxygen_LastValue;
////					  break;
////				  case 0x400002:
////					  rxMessage.frame.data0 = 0x4B;
////					  uint16_t Dewpoint = PSA.DP_IncomingAirDewpoint.Value;
////					  rxMessage.frame.data4 = Dewpoint >> 8;
////					  rxMessage.frame.data5 = Dewpoint;
////					  break;
////				  case 0x400003:
////					  rxMessage.frame.data0 = 0x4B;
////					  rxMessage.frame.data4 = PSA.B1_InputAirPressure.Value >> 8;
////					  rxMessage.frame.data5 = PSA.B1_InputAirPressure.Value;
////					  break;
////				  case 0x400004:
////					  rxMessage.frame.data0 = 0x4B;
////					  rxMessage.frame.data4 = PSA.B2_OutputAirPressure_1.Value >> 8;
////					  rxMessage.frame.data5 = PSA.B2_OutputAirPressure_1.Value;
////					  break;
////				  case 0x400005:
////					  rxMessage.frame.data0 = 0x4B;
////					  rxMessage.frame.data4 = PSA.B3_ProcessTankAirPressure.Value >> 8;
////					  rxMessage.frame.data5 = PSA.B3_ProcessTankAirPressure.Value;
////					  break;
////				  case 0x400006:
////					  rxMessage.frame.data0 = 0x4B;
////					  rxMessage.frame.data4 = PSA.B4_OutputAirPressure_2.Value >> 8;
////					  rxMessage.frame.data5 = PSA.B4_OutputAirPressure_2.Value;
////					  break;
////				  case 0x400001:
////					  rxMessage.frame.data0 = 0x4B;
////					  uint16_t AirFlux_LastValue = MyQueue_GetLastValue(IFM_AirFlowmeter);
////					  rxMessage.frame.data4 = AirFlux_LastValue >> 8;
////					  rxMessage.frame.data5 = AirFlux_LastValue;
////					  break;
////				  case 0x40001D:
////					  rxMessage.frame.data0 = 0x4B;
////					  uint16_t AirFlux_AverageValue = MyQueue_GetAverageValue(B1_InputAirPressureQueue);
////					  rxMessage.frame.data4 = AirFlux_AverageValue >> 8;
////					  rxMessage.frame.data5 = AirFlux_AverageValue;
////					  break;
//	//			  case 0x40000D:
//	//				  PSA.Request.State |= (1U << 10);
//	//				  break;
//	//			  case 0x40001C:
//	//				  PSA.Request.State |= (1U << 12);
//	//				  break;
//	//			  case 0x40000F:
//	////				  PSA.Request.State |= (1U << 13);
//	//				  break;
//	//			  case 0x40001B:
//	////				  PSA.Request.State |= (1U << 14);
//	//				  break;
//				  case 0x40000B:
//					  rxMessage.frame.data0 = 0x4B;
//					  uint16_t PulldownWorking_TotalHours = TimeCounter_GetTotalHours(&PulldownWorking);
//					  rxMessage.frame.data4 = PulldownWorking_TotalHours >> 8;
//					  rxMessage.frame.data5 = PulldownWorking_TotalHours;
//					  break;
//				  case 0x40000C:
//					  rxMessage.frame.data0 = 0x4B;
//					  uint16_t MaintenanceWorking_TotalHours = TimeCounter_GetTotalHours(&MaintenanceWorking);
//					  rxMessage.frame.data4 = MaintenanceWorking_TotalHours >> 8;
//					  rxMessage.frame.data5 = MaintenanceWorking_TotalHours;
//					  break;
//				  case 0x400028:
//					  rxMessage.frame.data0 = 0x4B;
//					  uint16_t TotalWorking_TotalHours = TimeCounter_GetTotalHours(&TotalWorking);
//					  rxMessage.frame.data4 = TotalWorking_TotalHours >> 8;
//					  rxMessage.frame.data5 = TotalWorking_TotalHours;
//					  break;
//	//			  case 0x400012:
//	////				  PSA.Request.State |= (1U << 18);
//	//				  break;
//	//
//				  default:
//					  break;
//				  }
//				  PSA.CANSPI.State = CANSPI_Transmit(&rxMessage);
//			  }
//		  }
//
//		  if(!PSA.CANSPI.State)
//		  {
//			  MX_SPI2_Init();
//			  PSA.CANSPI.State = CANSPI_Initialize();
//		  }

		  vTaskDelayUntil(&TaskDelayTimer, 1 * deciseconds);
	  }
  /* USER CODE END StartCAN1RxTxTask */
}

/* USER CODE BEGIN Header_StartAlarmTask */
/**
* @brief Function implementing the AlarmTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartAlarmTask */
void StartAlarmTask(void *argument)
{
  /* USER CODE BEGIN StartAlarmTask */
	Alarm_Init(&PSA.Alarm.AL01_CANbusError, 5, 2);
	Alarm_Init(&PSA.Alarm.AL02_LowInputAirPressure, 5, 5);
	Alarm_Init(&PSA.Alarm.AL05_LowProcessTankPressure, 5, 5);
//	Alarm_Init(&PSA.Alarm.AL11_External, 5, 5);
	Alarm_Init(&PSA.Alarm.AL16_HighOut2Pressure, 5, 5);
//	Alarm_Init(&PSA.Alarm.AL17_HighDewpoint, 5, 5);
//	Alarm_Init(&PSA.Alarm.AL18_HighDewpoint, 5, 5);
	Alarm_Init(&PSA.Alarm.AL19_HighOut1Pressure, 5, 5);
	Alarm_Init(&PSA.Alarm.AL31_B1ProbeFault, 5, 5);
	Alarm_Init(&PSA.Alarm.AL32_B2ProbeFault, 5, 5);
	Alarm_Init(&PSA.Alarm.AL33_B3ProbeFault, 5, 5);
	Alarm_Init(&PSA.Alarm.AL34_B4ProbeFault, 5, 5);
	Alarm_Init(&PSA.Alarm.AL35_IFWProbeFault, 5, 5);
	Alarm_Init(&PSA.Alarm.AL36_DEWProbeFault, 5, 5);
	Alarm_Init(&PSA.Alarm.AL37_KE25ProbeFault, 5, 5);
//	Alarm_Init(&PSA.Alarm.AL40_PsaDischanging, 5, 5);
	Alarm_Init(&PSA.Alarm.MissingSDCard, 5, 5);

	TickType_t StateTaskDelayTimer = xTaskGetTickCount();
  /* Infinite loop */
  for(;;)
  {

	  Alarm_CheckCondition(&PSA.Alarm.AL01_CANbusError, !(PSA.CAN_2.AliveMessageReceived));
	  PSA.CAN_2.AliveMessageReceived = 0;

	  if(!PSA.Alarm.AL02_LowInputAirPressure.Trigger)
		  Alarm_CheckCondition(&PSA.Alarm.AL02_LowInputAirPressure,
			  	  	  	  	  (PSA.B1_InputAirPressure.Value < PSA.B1_InputAirPressure.LowerThreshold));
	  else
		  Alarm_CheckCondition(&PSA.Alarm.AL02_LowInputAirPressure,
		 			  	  	  (PSA.B1_InputAirPressure.Value < PSA.B1_InputAirPressure.UpperThreshold));

	  if(!PSA.Alarm.AL05_LowProcessTankPressure.Trigger)
		  Alarm_CheckCondition(&PSA.Alarm.AL05_LowProcessTankPressure,
			  	  	  	  	  (PSA.B3_ProcessTankAirPressure.Value < PSA.B3_ProcessTankAirPressure.LowerThreshold));
	  else
		  Alarm_CheckCondition(&PSA.Alarm.AL05_LowProcessTankPressure,
		  			  	  	  (PSA.B3_ProcessTankAirPressure.Value < PSA.B3_ProcessTankAirPressure.UpperThreshold));

	  if(!PSA.Alarm.AL16_HighOut2Pressure.Trigger)
		  Alarm_CheckCondition(&PSA.Alarm.AL16_HighOut2Pressure,
			  	  	  	  	  (PSA.B4_OutputAirPressure_2.Value > PSA.B4_OutputAirPressure_2.UpperThreshold));
	  else
		  Alarm_CheckCondition(&PSA.Alarm.AL16_HighOut2Pressure,
		  			  	  	  (PSA.B4_OutputAirPressure_2.Value > PSA.B4_OutputAirPressure_2.LowerThreshold));

	  if(!PSA.Alarm.AL19_HighOut1Pressure.Trigger)
		  Alarm_CheckCondition(&PSA.Alarm.AL19_HighOut1Pressure,
			  	  	  	  	  (PSA.B2_OutputAirPressure_1.Value > PSA.B2_OutputAirPressure_1.UpperThreshold));
	  else
		  Alarm_CheckCondition(&PSA.Alarm.AL19_HighOut1Pressure,
		  			  	  	  (PSA.B2_OutputAirPressure_1.Value > PSA.B2_OutputAirPressure_1.LowerThreshold));

	  Alarm_CheckCondition(&PSA.Alarm.MissingSDCard, (hsd.ErrorCode));

	  /* PSA.Alarm Status Update */
	  PSA.Alarm.AlarmsTriggered = PSA_Alarm_NumberOfAlarmsTriggered();
	  PSA.Alarm.BlockingAlarmsTriggered = PSA_Alarm_NumberOfBlockingAlarmsTriggered();

	  vTaskDelayUntil(&StateTaskDelayTimer, 1 * deciseconds);
  }
  /* USER CODE END StartAlarmTask */
}

/* USER CODE BEGIN Header_StartRequestTask */
/**
* @brief Function implementing the RequestTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartRequestTask */
void StartRequestTask(void *argument)
{
  /* USER CODE BEGIN StartRequestTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartRequestTask */
}

/* USER CODE BEGIN Header_StartCAN1_ReceiveTask */
/**
* @brief Function implementing the CAN1_ReceiveTas thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartCAN1_ReceiveTask */
void StartCAN1_ReceiveTask(void *argument)
{
  /* USER CODE BEGIN StartCAN1_ReceiveTask */
	PSA.CANSPI.State = CANSPI_Initialize();
	TickType_t TaskDelayTimer = xTaskGetTickCount();

//	PSA.CANSPI.RequestMessage.frame.dlc = 8;
//	PSA.CANSPI.RequestMessage.frame.id = 0x581;
  /* Infinite loop */
  for(;;)
  {
	  if(CANSPI_messagesInBuffer() && PSA.CANSPI.State)
	  {
		  PSA.CANSPI.State = CANSPI_Receive(&PSA.CANSPI.ReceiveMessage);
		  if(PSA.CANSPI.ReceiveMessage.frame.id == PSA.CANSPI.Ide)
		  {
			  /* Acquisition Message ---*/
			  if(PSA.CANSPI.ReceiveMessage.frame.dlc == 3)
			  {
				  uint8_t AnalogInputIdentifier = PSA.CANSPI.ReceiveMessage.frame.data0;
				  uint16_t AnalogInputValue = (PSA.CANSPI.ReceiveMessage.frame.data1 << 8)
						  + (PSA.CANSPI.ReceiveMessage.frame.data2 << 0);

				  if(AnalogInputIdentifier == 0x01)
					  PSA_AnalogInput_Acquisition(&PSA.B1_InputAirPressure, AnalogInputValue);
				  if(AnalogInputIdentifier == 0x02)
					  PSA_AnalogInput_Acquisition(&PSA.B2_OutputAirPressure_1, AnalogInputValue);
				  if(AnalogInputIdentifier == 0x03)
					  PSA_AnalogInput_Acquisition(&PSA.B3_ProcessTankAirPressure, AnalogInputValue);
				  if(AnalogInputIdentifier == 0x04)
					  PSA_AnalogInput_Acquisition(&PSA.B4_OutputAirPressure_2, AnalogInputValue);
				  if(AnalogInputIdentifier == 0x05)
					  PSA_AnalogInput_Acquisition(&PSA.IFM_AirFlowmeter, AnalogInputValue);
				  if(AnalogInputIdentifier == 0x06)
					  PSA_AnalogInput_Acquisition(&PSA.DEW_InputAirDewpoint, AnalogInputValue);
				  if(AnalogInputIdentifier == 0x07)
				  {
					  PSA_AnalogInput_Acquisition(&PSA.KE25_OxygenSensor_1, AnalogInputValue);
					  PSA_AnalogInput_Acquisition(&PSA.KE25_OxygenSensor_2, AnalogInputValue);
				  }

			  }
			  /* Command and Request ---*/
			  if(PSA.CANSPI.ReceiveMessage.frame.dlc == 8)
			  {
				  uint32_t RequestIdentifier_1 =
							(PSA.CANSPI.ReceiveMessage.frame.data0 << 16)
						  | (PSA.CANSPI.ReceiveMessage.frame.data1 << 8)
						  |	(PSA.CANSPI.ReceiveMessage.frame.data2 << 0);
				  uint32_t RequestIdentifier_2 =
							(PSA.CANSPI.ReceiveMessage.frame.data4 << 16)
						  | (PSA.CANSPI.ReceiveMessage.frame.data5 << 8)
						  |	(PSA.CANSPI.ReceiveMessage.frame.data6 << 0);

				  if((RequestIdentifier_2 == 0x010000))
				  {
					  /* Command ---*/
					  if(RequestIdentifier_1 == 0x230065)
					  {
						  if(PSA.CANSPI.ReceiveMessage.frame.data7 == 0x01)
							  PSA.Command.EnableOutGoingNitrogen = 1;
						  if(PSA.CANSPI.ReceiveMessage.frame.data7 == 0x00)
							  PSA.Command.DisableOutGoingNitrogen = 1;
					  }
					  if(RequestIdentifier_1 == 0x23006E)
					  {
						  if(PSA.CANSPI.ReceiveMessage.frame.data7 == 0x02)
							  PSA.Command.EnableOut1_EnableOut2 = 1;
						  if(PSA.CANSPI.ReceiveMessage.frame.data7 == 0x01)
							  PSA.Command.EnableOut2_DisableOut1 = 1;
						  if(PSA.CANSPI.ReceiveMessage.frame.data7 == 0x00)
							  PSA.Command.EnableOut1_DisableOut2 = 1;
					  }
					  if(RequestIdentifier_1 == 0x23006F)
					  {
						  if(PSA.CANSPI.ReceiveMessage.frame.data7 == 0x00)
							  PSA.Command.SetPriorityOut1 = 1;
						  if(PSA.CANSPI.ReceiveMessage.frame.data7 == 0x01)
							  PSA.Command.SetPriorityOut2 = 1;
					  }
					  if(RequestIdentifier_1 == 0x230074)
					  {
						  if(PSA.CANSPI.ReceiveMessage.frame.data7 == 0x01)
							  PSA.Command.PulldownOn = 1;
						  if(PSA.CANSPI.ReceiveMessage.frame.data7 == 0x00)
							  PSA.Command.PulldownOn = 0;
					  }

					  /* Request ---*/
					  if(RequestIdentifier_1 == 0x400014)
						  PSA.Request.State = 1;
					  if(RequestIdentifier_1 == 0x400032)
						  PSA.Request.Alarm = 1;
					  if(RequestIdentifier_1 == 0x40000A)
						  PSA.Request.OxygenPercentual = 1;
					  if(RequestIdentifier_1 == 0x400002)
						  PSA.Request.InputAirDewpoint = 1;
					  if(RequestIdentifier_1 == 0x400003)
						  PSA.Request.InputAirPressure = 1;
					  if(RequestIdentifier_1 == 0x400004)
						  PSA.Request.OutputAirPressure_1 = 1;
					  if(RequestIdentifier_1 == 0x400005)
						  PSA.Request.ProcessTankAirPressure = 1;
					  if(RequestIdentifier_1 == 0x400006)
						  PSA.Request.OutputAirPressure_2 = 1;
					  if(RequestIdentifier_1 == 0x400001)
						  PSA.Request.AirFlowmeter = 1;
					  if(RequestIdentifier_1 == 0x40001D)
						  PSA.Request.AverageAirFlowmeter = 1;
					  if(RequestIdentifier_1 == 0x40000D)
						  PSA.Request.Out2ValvePosition = 1;
					  if(RequestIdentifier_1 == 0x40001C)
						  PSA.Request.DischangeValvePosition = 1;
					  if(RequestIdentifier_1 == 0x40000F)
						  PSA.Request.Out1ValvePosition = 1;
					  if(RequestIdentifier_1 == 0x40001B)
						  PSA.Request.DeliveryValvePosition = 1;
					  if(RequestIdentifier_1 == 0x40000B)
						  PSA.Request.Out1WorkingHour = 1;
					  if(RequestIdentifier_1 == 0x40000C)
						  PSA.Request.Out2WorkingHour = 1;
					  if(RequestIdentifier_1 == 0x400028)
						  PSA.Request.TotalWorkingHour = 1;
				  }
			  }
		  }
	  }

	  vTaskDelayUntil(&TaskDelayTimer, 1 * centiseconds);
  }
  /* USER CODE END StartCAN1_ReceiveTask */
}

/* USER CODE BEGIN Header_StartCAN1_TransmitTask */
/**
* @brief Function implementing the CAN1_TransmitTa thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartCAN1_TransmitTask */
void StartCAN1_TransmitTask(void *argument)
{
  /* USER CODE BEGIN StartCAN1_TransmitTask */
	PSA.CANSPI.State = CANSPI_Initialize();
	TickType_t TaskDelayTimer = xTaskGetTickCount();

	PSA.CANSPI.RequestMessage.frame.dlc = 8;
	PSA.CANSPI.RequestMessage.frame.id = 0x581;
  /* Infinite loop */
  for(;;)
  {
	  if(PSA.CANSPI.State)
	  {
		  if((PSA.Request.State) && (PSA.CANSPI.State))
		  {
			  PSA_Request_State();
			  PSA.CANSPI.State = CANSPI_Transmit(&PSA.CANSPI.RequestMessage);
			  PSA.Request.State = 0;
		  }
		  if((PSA.Request.Alarm) && (PSA.CANSPI.State))
		  {
			  PSA_Request_Alarm();
			  PSA.CANSPI.State = CANSPI_Transmit(&PSA.CANSPI.RequestMessage);
			  PSA.Request.Alarm = 0;
		  }
		  if((PSA.Request.OxygenPercentual) && (PSA.CANSPI.State))
		  {
			  PSA_Request_OxygenPercentual();
			  PSA.CANSPI.State = CANSPI_Transmit(&PSA.CANSPI.RequestMessage);
			  PSA.Request.OxygenPercentual = 0;
		  }
		  if((PSA.Request.InputAirDewpoint) && (PSA.CANSPI.State))
		  {
			  PSA_Request_InputAirDewpoint();
			  PSA.CANSPI.State = CANSPI_Transmit(&PSA.CANSPI.RequestMessage);
			  PSA.Request.InputAirDewpoint = 0;
		  }
		  if((PSA.Request.InputAirPressure) && (PSA.CANSPI.State))
		  {
			  PSA_Request_InputAirPressure();
			  PSA.CANSPI.State = CANSPI_Transmit(&PSA.CANSPI.RequestMessage);
			  PSA.Request.InputAirPressure = 0;
		  }
		  if((PSA.Request.OutputAirPressure_1) && (PSA.CANSPI.State))
		  {
			  PSA_Request_OutputAirPressure_1();
			  PSA.CANSPI.State = CANSPI_Transmit(&PSA.CANSPI.RequestMessage);
			  PSA.Request.OutputAirPressure_1 = 0;
		  }
		  if((PSA.Request.ProcessTankAirPressure) && (PSA.CANSPI.State))
		  {
			  PSA_Request_ProcessTankAirPressure();
			  PSA.CANSPI.State = CANSPI_Transmit(&PSA.CANSPI.RequestMessage);
			  PSA.Request.ProcessTankAirPressure = 0;
		  }
		  if((PSA.Request.OutputAirPressure_1) && (PSA.CANSPI.State))
		  {
			  PSA_Request_OutputAirPressure_2();
			  PSA.CANSPI.State = CANSPI_Transmit(&PSA.CANSPI.RequestMessage);
			  PSA.Request.OutputAirPressure_1 = 0;
		  }
		  if((PSA.Request.AirFlowmeter) && (PSA.CANSPI.State))
		  {
			  PSA_Request_AirFlowmeter();
			  PSA.CANSPI.State = CANSPI_Transmit(&PSA.CANSPI.RequestMessage);
			  PSA.Request.AirFlowmeter = 0;
		  }
		  if((PSA.Request.Out2ValvePosition) && (PSA.CANSPI.State))
		  {
			  PSA_Request_Out2ValvePosition();
			  PSA.CANSPI.State = CANSPI_Transmit(&PSA.CANSPI.RequestMessage);
			  PSA.Request.Out2ValvePosition = 0;
		  }
		  if((PSA.Request.DischangeValvePosition) && (PSA.CANSPI.State))
		  {
			  PSA_Request_DischangeValvePosition();
			  PSA.CANSPI.State = CANSPI_Transmit(&PSA.CANSPI.RequestMessage);
			  PSA.Request.DischangeValvePosition = 0;
		  }
		  if((PSA.Request.Out1ValvePosition) && (PSA.CANSPI.State))
		  {
			  PSA_Request_Out1ValvePosition();
			  PSA.CANSPI.State = CANSPI_Transmit(&PSA.CANSPI.RequestMessage);
			  PSA.Request.Out1ValvePosition = 0;
		  }
		  if((PSA.Request.DeliveryValvePosition) && (PSA.CANSPI.State))
		  {
			  PSA_Request_DeliveryValvePosition();
			  PSA.CANSPI.State = CANSPI_Transmit(&PSA.CANSPI.RequestMessage);
			  PSA.Request.DeliveryValvePosition = 0;
		  }
		  if((PSA.Request.Out1WorkingHour) && (PSA.CANSPI.State))
		  {
			  PSA_Request_Out1WorkingHour();
			  PSA.CANSPI.State = CANSPI_Transmit(&PSA.CANSPI.RequestMessage);
			  PSA.Request.Out1WorkingHour = 0;
		  }
		  if((PSA.Request.Out2WorkingHour) && (PSA.CANSPI.State))
		  {
			  PSA_Request_Out2WorkingHour();
			  PSA.CANSPI.State = CANSPI_Transmit(&PSA.CANSPI.RequestMessage);
			  PSA.Request.Out2WorkingHour = 0;
		  }
		  if((PSA.Request.TotalWorkingHour) && (PSA.CANSPI.State))
		  {
			  PSA_Request_TotalWorkingHour();
			  PSA.CANSPI.State = CANSPI_Transmit(&PSA.CANSPI.RequestMessage);
			  PSA.Request.TotalWorkingHour = 0;
		  }
		  if((PSA.Request.ActualWorkingHour) && (PSA.CANSPI.State))
		  {
			  PSA_Request_ActualWorkingHour();
			  PSA.CANSPI.State = CANSPI_Transmit(&PSA.CANSPI.RequestMessage);
			  PSA.Request.ActualWorkingHour = 0;
		  }
	  }

	  if(!PSA.CANSPI.State)
	  {
		  MX_SPI2_Init();
		  PSA.CANSPI.State = CANSPI_Initialize();
	  }

	  vTaskDelayUntil(&TaskDelayTimer, 1 * deciseconds);
  }
  /* USER CODE END StartCAN1_TransmitTask */
}

/* USER CODE BEGIN Header_StartAcquisitionTask */
/**
* @brief Function implementing the AcquisitionTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartAcquisitionTask */
void StartAcquisitionTask(void *argument)
{
  /* USER CODE BEGIN StartAcquisitionTask */
	TickType_t TaskDelayTimer = xTaskGetTickCount();
  /* Infinite loop */
  for(;;)
  {
	  Acquisition_AnalogInputIntoQueueWithAlarm(
			  &PSA.B1_InputAirPressure,
			  &B1_InputAirPressureQueue,
			  &PSA.Alarm.AL31_B1ProbeFault);

	  Acquisition_AnalogInputIntoQueueWithAlarm(
			  &PSA.B2_OutputAirPressure_1,
			  &B2_OutputAirPressure_1Queue,
			  &PSA.Alarm.AL32_B2ProbeFault);

	  Acquisition_AnalogInputIntoQueueWithAlarm(
			  &PSA.B3_ProcessTankAirPressure,
			  &B3_ProcessTankAirPressureQueue,
			  &PSA.Alarm.AL33_B3ProbeFault);

	  Acquisition_AnalogInputIntoQueueWithAlarm(
			  &PSA.B4_OutputAirPressure_2,
			  &B4_OutputAirPressure_2Queue,
			  &PSA.Alarm.AL34_B4ProbeFault);

	  Acquisition_AnalogInputIntoQueueWithAlarm(
			  &PSA.IFM_AirFlowmeter,
			  &IFM_AirFlowmeterQueue,
			  &PSA.Alarm.AL35_IFWProbeFault);

	  Acquisition_AnalogInputIntoQueueWithAlarm(
			  &PSA.DEW_InputAirDewpoint,
			  &DEW_InputAirDewpointQueue,
			  &PSA.Alarm.AL36_DEWProbeFault);

	  Acquisition_AnalogInputIntoQueueWithAlarm(
			  &PSA.KE25_OxygenSensor_1,
			  &KE25_PercentualOxygenInTheAirQueue_1,
			  &PSA.Alarm.AL37_KE25ProbeFault);

	  Acquisition_AnalogInputIntoQueueWithAlarm(
			  &PSA.KE25_OxygenSensor_2,
			  &KE25_PercentualOxygenInTheAirQueue_2,
			  &PSA.Alarm.AL37_KE25ProbeFault);

	  vTaskDelayUntil(&TaskDelayTimer, 1 * deciseconds);
  }
  /* USER CODE END StartAcquisitionTask */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

