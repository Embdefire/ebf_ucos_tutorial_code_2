/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2016-xx-xx
  * @brief   GPIO输出--使用固件库点亮LED灯
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火  STM32 F767 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f7xx.h"
#include "main.h"
#include "./led/bsp_led.h"

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{
    /* 系统时钟初始化成216 MHz */
    SystemClock_Config();
	/* LED 端口初始化 */
	LED_GPIO_Config();

	/* 控制LED灯 */
	while (1)
	{
		LED1( ON );			 // 亮 
		HAL_Delay(500);      //延时500ms
		LED1( OFF );		  // 灭

		LED2( ON );			// 亮 
		HAL_Delay(500);
		LED2( OFF );		  // 灭

		LED3( ON );			 // 亮 
		HAL_Delay(500);
		LED3( OFF );		  // 灭	
        
		LED4( ON );			 // 亮 
		HAL_Delay(500);
		LED4( OFF );		  // 灭	
        
		/*轮流显示 红绿蓝黄紫青白 颜色*/
		LED_RED;
		HAL_Delay(500);
		
		LED_GREEN;
		HAL_Delay(500);
		
		LED_BLUE;
		HAL_Delay(500);
		
		LED_YELLOW;
		HAL_Delay(500);
		
		LED_PURPLE;
		HAL_Delay(500);
				
		LED_CYAN;
		HAL_Delay(500);
		
		LED_WHITE;
		HAL_Delay(500);
		
		LED_RGBOFF;
		HAL_Delay(500);
	}
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 216000000
  *            HCLK(Hz)                       = 216000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 25
  *            PLL_N                          = 432
  *            PLL_P                          = 2
  *            PLL_Q                          = 9
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 7
  * @param  None
  * @retval None
  */
void SystemClock_Config(void)
{
    RCC_ClkInitTypeDef RCC_ClkInitStruct;
    RCC_OscInitTypeDef RCC_OscInitStruct;
    HAL_StatusTypeDef ret = HAL_OK;

    /* Enable HSE Oscillator and activate PLL with HSE as source */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 25;
    RCC_OscInitStruct.PLL.PLLN = 432;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = 9;

    ret = HAL_RCC_OscConfig(&RCC_OscInitStruct);
    if(ret != HAL_OK)
    {
        while(1) { ; }
    }

    /* Activate the OverDrive to reach the 216 MHz Frequency */  
    ret = HAL_PWREx_EnableOverDrive();
    if(ret != HAL_OK)
    {
        while(1) { ; }
    }

    /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers */
    RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2; 

    ret = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7);
    if(ret != HAL_OK)
    {
        while(1) { ; }
    }  
}

/*********************************************END OF FILE**********************/

