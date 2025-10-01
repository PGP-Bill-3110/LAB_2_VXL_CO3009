/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void clear7SEG() {
    HAL_GPIO_WritePin(LED_a_GPIO_Port, LED_a_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_b_GPIO_Port, LED_b_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_c_GPIO_Port, LED_c_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_d_GPIO_Port, LED_d_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_e_GPIO_Port, LED_e_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_f_GPIO_Port, LED_f_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_g_GPIO_Port, LED_g_Pin, GPIO_PIN_SET);
}

void display7SEG(int num){
	  // common anode => set = off; reset= on
	  clear7SEG();
	  switch(num){
	  case 0:
		  HAL_GPIO_WritePin(LED_g_GPIO_Port, LED_g_Pin, SET);

		  HAL_GPIO_WritePin(LED_a_GPIO_Port, LED_a_Pin, RESET);
		  HAL_GPIO_WritePin(LED_b_GPIO_Port, LED_b_Pin, RESET);
		  HAL_GPIO_WritePin(LED_c_GPIO_Port, LED_c_Pin, RESET);
		  HAL_GPIO_WritePin(LED_d_GPIO_Port, LED_d_Pin, RESET);
		  HAL_GPIO_WritePin(LED_e_GPIO_Port, LED_e_Pin, RESET);
		  HAL_GPIO_WritePin(LED_f_GPIO_Port, LED_f_Pin, RESET);
		  break;

	  case 1:
		  HAL_GPIO_WritePin(LED_a_GPIO_Port, LED_a_Pin, SET);
		  HAL_GPIO_WritePin(LED_f_GPIO_Port, LED_f_Pin, SET);
		  HAL_GPIO_WritePin(LED_e_GPIO_Port, LED_e_Pin, SET);
		  HAL_GPIO_WritePin(LED_d_GPIO_Port, LED_d_Pin, SET);

		  HAL_GPIO_WritePin(LED_b_GPIO_Port, LED_b_Pin, RESET);
		  HAL_GPIO_WritePin(LED_c_GPIO_Port, LED_c_Pin, RESET);
		  break;
     case 2: // a b d e g sang
         HAL_GPIO_WritePin(LED_a_GPIO_Port, LED_a_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_b_GPIO_Port, LED_b_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_c_GPIO_Port, LED_c_Pin, GPIO_PIN_SET);
         HAL_GPIO_WritePin(LED_d_GPIO_Port, LED_d_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_e_GPIO_Port, LED_e_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_f_GPIO_Port, LED_f_Pin, GPIO_PIN_SET);
         HAL_GPIO_WritePin(LED_g_GPIO_Port, LED_g_Pin, GPIO_PIN_RESET);
         break;
     case 3: // a b c d g sang
         HAL_GPIO_WritePin(LED_a_GPIO_Port, LED_a_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_b_GPIO_Port, LED_b_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_c_GPIO_Port, LED_c_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_d_GPIO_Port, LED_d_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_e_GPIO_Port, LED_e_Pin, GPIO_PIN_SET);
         HAL_GPIO_WritePin(LED_f_GPIO_Port, LED_f_Pin, GPIO_PIN_SET);
         HAL_GPIO_WritePin(LED_g_GPIO_Port, LED_g_Pin, GPIO_PIN_RESET);
         break;

     case 4: // b c f g sang
         HAL_GPIO_WritePin(LED_a_GPIO_Port, LED_a_Pin, GPIO_PIN_SET);
         HAL_GPIO_WritePin(LED_b_GPIO_Port, LED_b_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_c_GPIO_Port, LED_c_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_d_GPIO_Port, LED_d_Pin, GPIO_PIN_SET);
         HAL_GPIO_WritePin(LED_e_GPIO_Port, LED_e_Pin, GPIO_PIN_SET);
         HAL_GPIO_WritePin(LED_f_GPIO_Port, LED_f_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_g_GPIO_Port, LED_g_Pin, GPIO_PIN_RESET);
         break;

     case 5: // a c d f g sang
         HAL_GPIO_WritePin(LED_a_GPIO_Port, LED_a_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_b_GPIO_Port, LED_b_Pin, GPIO_PIN_SET);
         HAL_GPIO_WritePin(LED_c_GPIO_Port, LED_c_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_d_GPIO_Port, LED_d_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_e_GPIO_Port, LED_e_Pin, GPIO_PIN_SET);
         HAL_GPIO_WritePin(LED_f_GPIO_Port, LED_f_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_g_GPIO_Port, LED_g_Pin, GPIO_PIN_RESET);
         break;

     case 6: // a c d e f g sang
         HAL_GPIO_WritePin(LED_a_GPIO_Port, LED_a_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_b_GPIO_Port, LED_b_Pin, GPIO_PIN_SET);
         HAL_GPIO_WritePin(LED_c_GPIO_Port, LED_c_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_d_GPIO_Port, LED_d_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_e_GPIO_Port, LED_e_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_f_GPIO_Port, LED_f_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_g_GPIO_Port, LED_g_Pin, GPIO_PIN_RESET);
         break;

     case 7: // a b c sang
         HAL_GPIO_WritePin(LED_a_GPIO_Port, LED_a_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_b_GPIO_Port, LED_b_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_c_GPIO_Port, LED_c_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_d_GPIO_Port, LED_d_Pin, GPIO_PIN_SET);
         HAL_GPIO_WritePin(LED_e_GPIO_Port, LED_e_Pin, GPIO_PIN_SET);
         HAL_GPIO_WritePin(LED_f_GPIO_Port, LED_f_Pin, GPIO_PIN_SET);
         HAL_GPIO_WritePin(LED_g_GPIO_Port, LED_g_Pin, GPIO_PIN_SET);
         break;

     case 8: // all
         HAL_GPIO_WritePin(LED_a_GPIO_Port, LED_a_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_b_GPIO_Port, LED_b_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_c_GPIO_Port, LED_c_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_d_GPIO_Port, LED_d_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_e_GPIO_Port, LED_e_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_f_GPIO_Port, LED_f_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_g_GPIO_Port, LED_g_Pin, GPIO_PIN_RESET);
         break;

     case 9: // a b c d f g sang
         HAL_GPIO_WritePin(LED_a_GPIO_Port, LED_a_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_b_GPIO_Port, LED_b_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_c_GPIO_Port, LED_c_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_d_GPIO_Port, LED_d_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_e_GPIO_Port, LED_e_Pin, GPIO_PIN_SET);
         HAL_GPIO_WritePin(LED_f_GPIO_Port, LED_f_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(LED_g_GPIO_Port, LED_g_Pin, GPIO_PIN_RESET);
         break;
	  }
 }

void initState() {
	display7SEG(8);
	HAL_Delay(2000);
	clear7SEG();
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_All, GPIO_PIN_SET);
	HAL_Delay(1000);
}

const unsigned int MAX_LED = 4;
int led_buffer[4] = {1, 2, 3, 4};
void update7SEG ( int index ){
	switch (index) {
		case 0:
			display7SEG(led_buffer[0]);
			HAL_GPIO_WritePin(En0_GPIO_Port, En0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(En1_GPIO_Port, En1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(En2_GPIO_Port, En2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(En3_GPIO_Port, En3_Pin, GPIO_PIN_SET);
			break;
		case 1:
			display7SEG(led_buffer[1]);
			HAL_GPIO_WritePin(En0_GPIO_Port, En0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(En1_GPIO_Port, En1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(En2_GPIO_Port, En2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(En3_GPIO_Port, En3_Pin, GPIO_PIN_SET);
			break;
		case 2:
			display7SEG(led_buffer[2]);
			HAL_GPIO_WritePin(En0_GPIO_Port, En0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(En1_GPIO_Port, En1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(En2_GPIO_Port, En2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(En3_GPIO_Port, En3_Pin, GPIO_PIN_SET);
			break;
		case 3:
			display7SEG(led_buffer[3]);
			HAL_GPIO_WritePin(En0_GPIO_Port, En0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(En1_GPIO_Port, En1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(En2_GPIO_Port, En2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(En3_GPIO_Port, En3_Pin, GPIO_PIN_RESET);
			break;
		default:
			HAL_GPIO_WritePin(En0_GPIO_Port, En0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(En1_GPIO_Port, En1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(En2_GPIO_Port, En2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(En3_GPIO_Port, En3_Pin, GPIO_PIN_RESET);
			break;
	}
}

void setNumberOnClock(int num) {
  if (num >= 1 && num <= 12) HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0 << num, GPIO_PIN_RESET);
  else return;
}

void clearNumberOnClock(int num) {
  if (num >= 1 && num <= 12) HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0 << num, GPIO_PIN_SET);
  else return;
}
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
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	  HAL_Delay(1000);
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
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
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
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
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, DOT_Pin|LED_RED_Pin|En0_Pin|En1_Pin
                          |En2_Pin|En3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_a_Pin|LED_b_Pin|LED_c_Pin|LED_d_Pin
                          |LED_e_Pin|LED_f_Pin|LED_g_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : DOT_Pin LED_RED_Pin En0_Pin En1_Pin
                           En2_Pin En3_Pin */
  GPIO_InitStruct.Pin = DOT_Pin|LED_RED_Pin|En0_Pin|En1_Pin
                          |En2_Pin|En3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_a_Pin LED_b_Pin LED_c_Pin LED_d_Pin
                           LED_e_Pin LED_f_Pin LED_g_Pin */
  GPIO_InitStruct.Pin = LED_a_Pin|LED_b_Pin|LED_c_Pin|LED_d_Pin
                          |LED_e_Pin|LED_f_Pin|LED_g_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

const unsigned int SCALE = 200; // Switch time * Number of LED / timer (in ms)
int counter = SCALE;
unsigned int index_led = 0;
int tick = 0;
// Ham nay giong nhu while loop nhung 10ms chay 1 lan (dgl Timer)
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{
	// Testing
	tick++;
    if (tick > 100 ) {
        HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
        tick =0;
    }

	// Production
	if (counter == SCALE) {
		update7SEG(index_led++);
	} else if(counter == (SCALE*3/4)) {
		update7SEG(index_led++);
	} else if (counter == (SCALE*2/4)) {
		update7SEG(index_led++);
	} else if (counter == (SCALE*1/4)) {
		update7SEG(index_led++);
	}

	if (!(index_led < MAX_LED)) index_led = 0;

	counter = (counter > 0) ? counter-1 : SCALE;
}

/* USER CODE END 4 */

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
