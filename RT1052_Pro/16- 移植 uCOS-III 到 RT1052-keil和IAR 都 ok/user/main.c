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
#include "./led/bsp_led.h" 

/*
*********************************************************************************************************
*                                            LOCAL DEFINES
*********************************************************************************************************
*/
/*
*********************************************************************************************************
*                                           模块禁能/使能
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                            任务优先级
*********************************************************************************************************
*/

#define  APP_TASK_START_PRIO                2u
#define  APP_TASK_LED1_PRIO                 3u
#define  APP_TASK_LED2_PRIO                 3u
#define  APP_TASK_LED3_PRIO                 3u
/*
*********************************************************************************************************
*                                            任务堆栈大小
*********************************************************************************************************
*/
#define  APP_TASK_START_STK_SIZE            256u
#define  APP_TASK_LED1_STK_SIZE             512u
#define  APP_TASK_LED2_STK_SIZE             512u
#define  APP_TASK_LED3_STK_SIZE             512u
/*
*********************************************************************************************************
*                                           跟踪/调试配置
*********************************************************************************************************
*/

#ifndef  TRACE_LEVEL_OFF
#define  TRACE_LEVEL_OFF                        0u
#endif

#ifndef  TRACE_LEVEL_INFO
#define  TRACE_LEVEL_INFO                       1u
#endif

#ifndef  TRACE_LEVEL_DBG
#define  TRACE_LEVEL_DBG                        2u
#endif

#define  APP_TRACE_LEVEL                        TRACE_LEVEL_OFF
#define  APP_TRACE                              printf
/*
*********************************************************************************************************
*                                         任务控制块TCB
*********************************************************************************************************
*/

//static  OS_TCB       AppTaskStartTCB;
static  OS_TCB       AppTaskLed1TCB;
static  OS_TCB       AppTaskLed2TCB;
/*
*********************************************************************************************************
*                                            任务堆栈
*********************************************************************************************************
*/
//static  CPU_STK      AppTaskStartStk[APP_TASK_START_STK_SIZE];
static  CPU_STK      AppTaskLed1Stk[APP_TASK_LED1_STK_SIZE];
static  CPU_STK      AppTaskLed2Stk[APP_TASK_LED2_STK_SIZE];

/*
*********************************************************************************************************
*                                            函数原型
*********************************************************************************************************
*/

//static  void  AppTaskStart (void  *p_arg);
static  void  AppTaskLed1  ( void * p_arg );
static  void  AppTaskLed2  ( void * p_arg );

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
    OS_ERR  err;


   (void)p_arg;


    OS_TRACE_INIT();                                            /* Initialize the uC/OS-III Trace recorder              */

    BSP_OS_TickEnable();                                        /* Enable the tick timer and interrupt                  */

    LED_GPIO_Config();                                             /* Initialize LEDs                                      */

#if OS_CFG_STAT_TASK_EN > 0u
    OSStatTaskCPUUsageInit(&err);                            /* Compute CPU capacity with no task running            */
#endif

#ifdef CPU_CFG_INT_DIS_MEAS_EN
    CPU_IntDisMeasMaxCurReset();
#endif

//    while (DEF_TRUE) {                                          /* Task body, always written as an infinite loop.       */
//        //CORE_BOARD_LED_TOGGLE;
//      RGB_RED_LED_TOGGLE;
//        OSTimeDlyHMSM(0u, 0u, 0u, 500u,
//                      OS_OPT_TIME_HMSM_STRICT,
//                      &os_err);
//    }
    
     /* 创建Led1任务 */
    OSTaskCreate((OS_TCB     *)&AppTaskLed1TCB,                             //任务控制块地址
                 (CPU_CHAR   *)"App Task Led1",                             //任务名称
                 (OS_TASK_PTR ) AppTaskLed1,                                //任务函数
                 (void       *) 0,                                          //传递给任务函数（形参p_arg）的实参
                 (OS_PRIO     ) APP_TASK_LED1_PRIO,                         //任务的优先级
                 (CPU_STK    *)&AppTaskLed1Stk[0],                          //任务堆栈的基地址
                 (CPU_STK_SIZE) APP_TASK_LED1_STK_SIZE / 10,                //任务堆栈空间剩下1/10时限制其增长
                 (CPU_STK_SIZE) APP_TASK_LED1_STK_SIZE,                     //任务堆栈空间（单位：sizeof(CPU_STK)）
                 (OS_MSG_QTY  ) 5u,                                         //任务可接收的最大消息数
                 (OS_TICK     ) 0u,                                         //任务的时间片节拍数（0表默认值OSCfg_TickRate_Hz/10）
                 (void       *) 0,                                          //任务扩展（0表不扩展）
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR), //任务选项
                 (OS_ERR     *)&err);                                       //返回错误类型


    /* 创建Led2任务 */
    OSTaskCreate((OS_TCB     *)&AppTaskLed2TCB,                             //任务控制块地址
                 (CPU_CHAR   *)"App Task Led2",                             //任务名称
                 (OS_TASK_PTR ) AppTaskLed2,                                //任务函数
                 (void       *) 0,                                          //传递给任务函数（形参p_arg）的实参
                 (OS_PRIO     ) APP_TASK_LED2_PRIO,                         //任务的优先级
                 (CPU_STK    *)&AppTaskLed2Stk[0],                          //任务堆栈的基地址
                 (CPU_STK_SIZE) APP_TASK_LED2_STK_SIZE / 10,                //任务堆栈空间剩下1/10时限制其增长
                 (CPU_STK_SIZE) APP_TASK_LED2_STK_SIZE,                     //任务堆栈空间（单位：sizeof(CPU_STK)）
                 (OS_MSG_QTY  ) 5u,                                         //任务可接收的最大消息数
                 (OS_TICK     ) 0u,                                         //任务的时间片节拍数（0表默认值OSCfg_TickRate_Hz/10）
                 (void       *) 0,                                          //任务扩展（0表不扩展）
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR), //任务选项
                 (OS_ERR     *)&err);                                       //返回错误类型
								 
		//OSTaskDel ( & AppTaskStartTCB, & err );                             //删除起始任务
		while(1)
		{
			OSTimeDly ( 1000, OS_OPT_TIME_DLY, & err );  //延时1s
		}
}


/*
*********************************************************************************************************
*                                          LED1 任务
*********************************************************************************************************
*/

static  void  AppTaskLed1 ( void * p_arg )
{
    OS_ERR      err;


   (void)p_arg;                                      //没有用到形参，防止编译器报错
    
    LED_RGBOFF;                                      //关闭RGB LED
    
    while (DEF_TRUE)                                 //任务体，通常都写成一个死循环
    {                                               
        LED1_TOGGLE;                                 //LED1闪烁
        OSTimeDly ( 1000, OS_OPT_TIME_DLY, & err );  //延时1s
    }
		
		
}


/*
*********************************************************************************************************
*                                          LED2 任务
*********************************************************************************************************
*/

static  void  AppTaskLed2 ( void * p_arg )
{
    OS_ERR      err;


   (void)p_arg;                                      //没有用到形参，防止编译器报错
    
    LED_RGBOFF;                                      //关闭RGB LED
    
    while (DEF_TRUE)                                 //任务体，通常都写成一个死循环
    {                                               
        LED2_TOGGLE;                                 //LED2闪烁
        OSTimeDly ( 1000, OS_OPT_TIME_DLY, & err );  //延时5s
    }
		
		
}


