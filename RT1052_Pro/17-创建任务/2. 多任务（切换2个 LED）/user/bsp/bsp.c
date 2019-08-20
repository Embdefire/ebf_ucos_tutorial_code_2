/*
  ******************************************************************************
  * @file    bsp.c
  * @author  fire
  * @version V1.0
  * @date    2019-xx-xx
  * @brief   板级驱动
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火  i.MXRT1052开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************************
*/


/*
*********************************************************************************************************
*                                             包含的文件
*********************************************************************************************************
*/

//板级驱动
#include "fsl_debug_console.h"
#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "./led/bsp_led.h" 
#include "bsp.h" 

/*
*********************************************************************************************************
* 函数名 : BSP_Init
* 描述   : 所有的硬件设备都应该放在这个函数里边初始化
* 形参   : 无
* 返回值 : 无
*********************************************************************************************************
*/
void  BSP_Init (void)
{
  /* 初始化内存保护单元 */
  BOARD_ConfigMPU();
  /* 初始化开发板引脚 */
  BOARD_InitPins();
  /* 初始化开发板时钟 */
  //BOARD_BootClockRUN();
  /* 初始化调试串口 */
  BOARD_InitDebugConsole();
 
  /* 打印系统时钟 */
  PRINTF("\r\n");
  PRINTF("*****欢迎使用 野火i.MX RT1052 开发板*****\r\n");
  PRINTF("CPU:             %d Hz\r\n", CLOCK_GetFreq(kCLOCK_CpuClk));
  PRINTF("AHB:             %d Hz\r\n", CLOCK_GetFreq(kCLOCK_AhbClk));
  PRINTF("SEMC:            %d Hz\r\n", CLOCK_GetFreq(kCLOCK_SemcClk));
  PRINTF("SYSPLL:          %d Hz\r\n", CLOCK_GetFreq(kCLOCK_SysPllClk));
  PRINTF("SYSPLLPFD0:      %d Hz\r\n", CLOCK_GetFreq(kCLOCK_SysPllPfd0Clk));
  PRINTF("SYSPLLPFD1:      %d Hz\r\n", CLOCK_GetFreq(kCLOCK_SysPllPfd1Clk));
  PRINTF("SYSPLLPFD2:      %d Hz\r\n", CLOCK_GetFreq(kCLOCK_SysPllPfd2Clk));
  PRINTF("SYSPLLPFD3:      %d Hz\r\n", CLOCK_GetFreq(kCLOCK_SysPllPfd3Clk)); 
  PRINTF("这是一个[野火]-全系列开发板-uCOS-III  多任务  实验！\n\n");	
	/* 硬件BSP初始化统统放在这里，比如LED，串口，LCD等 */
  LED_GPIO_Config(); 		//初始化LED

}
