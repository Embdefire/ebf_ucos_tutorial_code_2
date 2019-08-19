///**
//  ******************************************************************
//  * @file    main.c
//  * @author  fire
//  * @version V1.0
//  * @date    2018-xx-xx
//  * @brief   GPIO输出—使用固件库点亮LED灯
//  ******************************************************************
//  * @attention
//  *
//  * 实验平台:野火  i.MXRT1052开发板 
//  * 论坛    :http://www.firebbs.cn
//  * 淘宝    :http://firestm32.taobao.com
//  *
//  ******************************************************************
//  */
//#include "fsl_debug_console.h"
//
//#include "board.h"
//#include "pin_mux.h"
//#include "clock_config.h"
//
//#include "./led/bsp_led.h"   
//
//
//
///*******************************************************************
// * Prototypes
// *******************************************************************/
///**
// * @brief 延时一段时间
// */
//void delay(uint32_t count);
//
///*******************************************************************
// * Code
// *******************************************************************/
///**
// * @note 本函数在不同的优化模式下延时时间不同，
// *       如flexspi_nor_debug和flexspi_nor_release版本的程序中，
// *       flexspi_nor_release版本的延时要短得多  
// */ 
//void delay(uint32_t count)
//{
//    volatile uint32_t i = 0;
//    for (i = 0; i < count; ++i)
//    {
//        __asm("NOP"); /* 调用nop空指令 */
//    }
//}
//
///**
//  * @brief  主函数
//  * @param  无
//  * @retval 无
//  */
//int main(void)
//{
//    /* 初始化内存保护单元 */
//    BOARD_ConfigMPU();
//    /* 初始化开发板引脚 */
//    BOARD_InitPins();
//    /* 初始化开发板时钟 */
//    BOARD_BootClockRUN();
//    /* 初始化调试串口 */
//    BOARD_InitDebugConsole();
//    /* 打印系统时钟 */
//    PRINTF("\r\n");
//    PRINTF("*****欢迎使用 野火i.MX RT1052 开发板*****\r\n");
//    PRINTF("CPU:             %d Hz\r\n", CLOCK_GetFreq(kCLOCK_CpuClk));
//    PRINTF("AHB:             %d Hz\r\n", CLOCK_GetFreq(kCLOCK_AhbClk));
//    PRINTF("SEMC:            %d Hz\r\n", CLOCK_GetFreq(kCLOCK_SemcClk));
//    PRINTF("SYSPLL:          %d Hz\r\n", CLOCK_GetFreq(kCLOCK_SysPllClk));
//    PRINTF("SYSPLLPFD0:      %d Hz\r\n", CLOCK_GetFreq(kCLOCK_SysPllPfd0Clk));
//    PRINTF("SYSPLLPFD1:      %d Hz\r\n", CLOCK_GetFreq(kCLOCK_SysPllPfd1Clk));
//    PRINTF("SYSPLLPFD2:      %d Hz\r\n", CLOCK_GetFreq(kCLOCK_SysPllPfd2Clk));
//    PRINTF("SYSPLLPFD3:      %d Hz\r\n", CLOCK_GetFreq(kCLOCK_SysPllPfd3Clk));  
//  
//    PRINTF("GPIO输出-使用固件库点亮LED\r\n");
//  
//    /* 初始化LED引脚 */
//    LED_GPIO_Config();  
//    
//    while(1)
//    {         
//      /* LED亮 */
//      CORE_BOARD_LED_ON;
//      /* 延时 */
//      delay(LED_DELAY_COUNT);
//      
//      /* 独立操作红灯 */
//      RGB_RED_LED_ON;
//      delay(LED_DELAY_COUNT);
//      
//      RGB_RED_LED_OFF;
//      delay(LED_DELAY_COUNT);
//      
//      /* 独立操作绿灯 */
//      RGB_GREEN_LED_ON;
//      delay(LED_DELAY_COUNT);
//      
//      RGB_GREEN_LED_OFF;
//      delay(LED_DELAY_COUNT);
//      
//      /* 独立操作蓝灯 */
//      RGB_BLUE_LED_ON;
//      delay(LED_DELAY_COUNT);
//      
//      RGB_BLUE_LED_OFF;
//      delay(LED_DELAY_COUNT);   
//
//      /* 整体操作红色 */
//      RGB_LED_COLOR_RED;
//      delay(LED_DELAY_COUNT);   
//      
//      /* 整体操作绿色 */
//      RGB_LED_COLOR_GREEN;
//      delay(LED_DELAY_COUNT);   
//      
//      /* 整体操作蓝色 */
//      RGB_LED_COLOR_BLUE;
//      delay(LED_DELAY_COUNT);   
//      
//      /* 整体操作黄色 */
//      RGB_LED_COLOR_YELLOW;
//      delay(LED_DELAY_COUNT);   
//      
//      /* 整体操作紫色 */
//      RGB_LED_COLOR_PURPLE;
//      delay(LED_DELAY_COUNT);   
//      
//      /* 整体操作青色 */
//      RGB_LED_COLOR_CYAN;
//      delay(LED_DELAY_COUNT);   
//      
//      /* 整体操作白色 */
//      RGB_LED_COLOR_WHITE;
//      delay(LED_DELAY_COUNT);   
//      
//      /* 整体操作黑色（全关闭） */
//      RGB_LED_COLOR_OFF;
//      delay(LED_DELAY_COUNT);   
//    }     
//
//}
///****************************END OF FILE**********************/
/*
*********************************************************************************************************
*                                            EXAMPLE CODE
*
*               This file is provided as an example on how to use Micrium products.
*
*               Please feel free to use any application code labeled as 'EXAMPLE CODE' in
*               your application products.  Example code may be used as is, in whole or in
*               part, or may be used as a reference only. This file can be modified as
*               required to meet the end-product requirements.
*
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*
*               You can find our product's user manual, API reference, release notes and
*               more information at https://doc.micrium.com.
*               You can contact us at www.micrium.com.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                             uC/OS-III
*                                            EXAMPLE CODE
*
* Filename : main.c
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                            INCLUDE FILES
*********************************************************************************************************
*/

#include  <cpu.h>
#include  <lib_mem.h>
#include  <os.h>
#include  <bsp_os.h>
#include  <bsp_clk.h>
#include  <bsp_led.h>
#include  <bsp_int.h>

#include  "os_app_hooks.h"
#include  "app_cfg.h"


/*
*********************************************************************************************************
*                                            LOCAL DEFINES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                       LOCAL GLOBAL VARIABLES
*********************************************************************************************************
*/

static  OS_TCB   StartupTaskTCB;
static  CPU_STK  StartupTaskStk[APP_CFG_STARTUP_TASK_STK_SIZE];


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static  void  StartupTask (void  *p_arg);


/*
*********************************************************************************************************
*                                                main()
*
* Description : This is the standard entry point for C code.  It is assumed that your code will call
*               main() once you have performed all necessary initialization.
*
* Arguments   : none
*
* Returns     : none
*
* Notes       : none
*********************************************************************************************************
*/

int  main (void)
{
    OS_ERR  os_err;


    BSP_ClkInit();                                              /* Initialize the main clock                            */
    BSP_IntInit();                                              /* Initialize RAM interrupt vector table.               */
    BSP_OS_TickInit();                                          /* Initialize kernel tick timer                         */

    Mem_Init();                                                 /* Initialize Memory Managment Module                   */
    CPU_IntDis();                                               /* Disable all Interrupts                               */
    CPU_Init();                                                 /* Initialize the uC/CPU services                       */

    OSInit(&os_err);                                            /* Initialize uC/OS-III                                 */
    if (os_err != OS_ERR_NONE) {
        while (1);
    }

    App_OS_SetAllHooks();                                       /* Set all applications hooks                           */

    OSTaskCreate(&StartupTaskTCB,                               /* Create the startup task                              */
                 "Startup Task",
                  StartupTask,
                  0u,
                  APP_CFG_STARTUP_TASK_PRIO,
                 &StartupTaskStk[0u],
                  StartupTaskStk[APP_CFG_STARTUP_TASK_STK_SIZE / 10u],
                  APP_CFG_STARTUP_TASK_STK_SIZE,
                  0u,
                  0u,
                  0u,
                 (OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 &os_err);
    if (os_err != OS_ERR_NONE) {
        while (1);
    }

    OSStart(&os_err);                                           /* Start multitasking (i.e. give control to uC/OS-III)  */

    while (DEF_ON) {                                            /* Should Never Get Here.                               */
        ;
    }
}


/*
*********************************************************************************************************
*                                            STARTUP TASK
*
* Description : This is an example of a startup task.  As mentioned in the book's text, you MUST
*               initialize the ticker only once multitasking has started.
*
* Arguments   : p_arg   is the argument passed to 'StartupTask()' by 'OSTaskCreate()'.
*
* Returns     : none
*
* Notes       : 1) The first line of code is used to prevent a compiler warning because 'p_arg' is not
*                  used.  The compiler should not generate any code for this statement.
*********************************************************************************************************
*/

static  void  StartupTask (void *p_arg)
{
    OS_ERR  os_err;


   (void)p_arg;


    OS_TRACE_INIT();                                            /* Initialize the uC/OS-III Trace recorder              */

    BSP_OS_TickEnable();                                        /* Enable the tick timer and interrupt                  */

    BSP_LED_Init();                                             /* Initialize LEDs                                      */

#if OS_CFG_STAT_TASK_EN > 0u
    OSStatTaskCPUUsageInit(&os_err);                            /* Compute CPU capacity with no task running            */
#endif

#ifdef CPU_CFG_INT_DIS_MEAS_EN
    CPU_IntDisMeasMaxCurReset();
#endif

    while (DEF_TRUE) {                                          /* Task body, always written as an infinite loop.       */
        BSP_LED_Toggle();
        OSTimeDlyHMSM(0u, 0u, 0u, 500u,
                      OS_OPT_TIME_HMSM_STRICT,
                      &os_err);
    }
}
