/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
void USBReceive(uint8_t *buf);
/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LCD_RS_Pin GPIO_PIN_14
#define LCD_RS_GPIO_Port GPIOC
#define LCD_RW_Pin GPIO_PIN_15
#define LCD_RW_GPIO_Port GPIOC
#define LCD_E_Pin GPIO_PIN_0
#define LCD_E_GPIO_Port GPIOA
#define DB0_Pin GPIO_PIN_1
#define DB0_GPIO_Port GPIOA
#define DB1_Pin GPIO_PIN_2
#define DB1_GPIO_Port GPIOA
#define SW_BW_Pin GPIO_PIN_3
#define SW_BW_GPIO_Port GPIOA
#define LED_BW_Pin GPIO_PIN_4
#define LED_BW_GPIO_Port GPIOA
#define SW_PW_Pin GPIO_PIN_5
#define SW_PW_GPIO_Port GPIOA
#define LED_PW_Pin GPIO_PIN_6
#define LED_PW_GPIO_Port GPIOA
#define SW_SUM_Pin GPIO_PIN_7
#define SW_SUM_GPIO_Port GPIOA
#define LED_SUM_Pin GPIO_PIN_0
#define LED_SUM_GPIO_Port GPIOB
#define SW_TOTAL_Pin GPIO_PIN_1
#define SW_TOTAL_GPIO_Port GPIOB
#define SW_TAR_Pin GPIO_PIN_8
#define SW_TAR_GPIO_Port GPIOA
#define DB3_Pin GPIO_PIN_15
#define DB3_GPIO_Port GPIOA
#define LCD_LIGHT_Pin GPIO_PIN_3
#define LCD_LIGHT_GPIO_Port GPIOB
#define DATA_L1_Pin GPIO_PIN_4
#define DATA_L1_GPIO_Port GPIOB
#define CLK_L1_Pin GPIO_PIN_5
#define CLK_L1_GPIO_Port GPIOB
#define DATA_L2_Pin GPIO_PIN_6
#define DATA_L2_GPIO_Port GPIOB
#define CLK_L2_Pin GPIO_PIN_7
#define CLK_L2_GPIO_Port GPIOB
#define DB2_Pin GPIO_PIN_3
#define DB2_GPIO_Port GPIOH
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
