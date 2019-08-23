/*
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2019-xx-xx
  * @brief   多任务 切换2个led
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
*                                            包含的文件
*********************************************************************************************************
*/
//ucosiii系统相关
#include  <cpu.h>
#include  <lib_mem.h>
#include  <os.h>
#include  <bsp_os.h>
#include  <bsp_clk.h>
#include  <bsp_int.h>
#include  "os_app_hooks.h"
#include  "app_cfg.h"
//板级驱动
#include "bsp.h" 


/*
*********************************************************************************************************
*                                         任务控制块TCB
*********************************************************************************************************
*/

static  OS_TCB       AppTaskStartTCB;
static  OS_TCB       AppTaskLed1TCB;
static  OS_TCB       AppTaskLed2TCB;

/*
*********************************************************************************************************
*                                            任务堆栈
*********************************************************************************************************
*/
static  CPU_STK      AppTaskStartStk[APP_TASK_START_STK_SIZE];
static  CPU_STK      AppTaskLed1Stk[APP_TASK_LED1_STK_SIZE];
static  CPU_STK      AppTaskLed2Stk[APP_TASK_LED2_STK_SIZE];

/*
*********************************************************************************************************
*                                            函数原型
*********************************************************************************************************
*/

static  void  AppTaskStart (void  *p_arg);
static  void  AppTaskLed1  ( void * p_arg );
static  void  AppTaskLed2  ( void * p_arg );

/*
*********************************************************************************************************
* 函数名 : main
* 描述   : 标准的C函数入口
* 形参   : 无
* 返回值 : 无
*********************************************************************************************************
*/
int  main (void)
{
    OS_ERR  err;


    BSP_ClkInit();                       /* 初始化系统时钟       */
    BSP_IntInit();                       /* 初始化RAM中断向量表. */
    BSP_OS_TickInit();                   /* 初始化内核计时器     */
															
    Mem_Init();                          /* 初始化内存管理模块   */
    CPU_IntDis();                        /* 禁用所有中断         */
    CPU_Init();                          /* 初始化uC/CPU相关     */

    OSInit(&err);                        /*初始化uC / OS-III     */
    if (err != OS_ERR_NONE) {
        while (1);
    }

    App_OS_SetAllHooks(); //设置所有应用程序钩子函数

	/* 创建起始任务 */
    OSTaskCreate((OS_TCB     *)&AppTaskStartTCB,//任务控制块地址
                 (CPU_CHAR   *)"App Task Start",//任务名称
                 (OS_TASK_PTR ) AppTaskStart, //任务函数
                 (void       *) 0, //传递给任务函数（形参p_arg）的实参
                 (OS_PRIO     ) APP_TASK_START_PRIO, //任务的优先级
                 (CPU_STK    *)&AppTaskStartStk[0], //任务堆栈的基地址
                 (CPU_STK_SIZE) APP_TASK_START_STK_SIZE / 10,//任务堆栈空间剩下1/10时限制其增长
                 (CPU_STK_SIZE) APP_TASK_START_STK_SIZE, //任务堆栈空间（单位：sizeof(CPU_STK)）
                 (OS_MSG_QTY  ) 5u, //任务可接收的最大消息数
                 (OS_TICK     ) 0u, //任务的时间片节拍数（0表默认值OSCfg_TickRate_Hz/10）
                 (void       *) 0,  //任务扩展（0表不扩展）
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR), //任务选项
                 (OS_ERR     *)&err);     
    if (err != OS_ERR_NONE) {
        while (1);
    }

    OSStart(&err);  //启动多任务管理（交由uC/OS-III控制）

    while (DEF_ON) {                                           
        ;
    }
}


/*
*********************************************************************************************************
* 函数名 ：AppTaskStart
* 描述   : 这是一个启动任务，在多任务系统启动后，必须初始化滴答计数器(在 BSP_Init 中实现)。
* 形参   : p_arg   是OSTaskCreate()在创建该任务时传递过来的形参。
* 返回值 : 无
* 注意   : 1) 第一行代码 (void)p_arg; 是为了防止编译器报错，因为形参p_arg并没有用到
*********************************************************************************************************
*/

static  void  AppTaskStart (void *p_arg)
{
    OS_ERR  err;
	
   (void)p_arg;

    OS_TRACE_INIT();                               //初始化uC / OS-III跟踪记录器

    BSP_OS_TickEnable();                           //启用滴答计时器和中断
    BSP_Init();                                    //板级初始化

#if OS_CFG_STAT_TASK_EN > 0u
    OSStatTaskCPUUsageInit(&err);                  //无需任务运行即可计算CPU容量
#endif

#ifdef CPU_CFG_INT_DIS_MEAS_EN
    CPU_IntDisMeasMaxCurReset();
#endif

 /* 创建Led1任务 */
    OSTaskCreate((OS_TCB     *)&AppTaskLed1TCB,//任务控制块地址
                 (CPU_CHAR   *)"App Task Led1",//任务名称
                 (OS_TASK_PTR ) AppTaskLed1,   //任务函数
                 (void       *) 0,             //传递给任务函数（形参p_arg）的实参
                 (OS_PRIO     ) APP_TASK_LED1_PRIO,//任务的优先级
                 (CPU_STK    *)&AppTaskLed1Stk[0],//任务堆栈的基地址
                 (CPU_STK_SIZE) APP_TASK_LED1_STK_SIZE / 10, //任务堆栈空间剩下1/10时限制其增长
                 (CPU_STK_SIZE) APP_TASK_LED1_STK_SIZE, //任务堆栈空间（单位：sizeof(CPU_STK)）
                 (OS_MSG_QTY  ) 5u, //任务可接收的最大消息数
                 (OS_TICK     ) 0u, //任务的时间片节拍数（0表默认值OSCfg_TickRate_Hz/10）
                 (void       *) 0,  //任务扩展（0表不扩展）
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR), //任务选项
                 (OS_ERR     *)&err);                                       //返回错误类型


    /* 创建Led2任务 */
    OSTaskCreate((OS_TCB     *)&AppTaskLed2TCB,//任务控制块地址
                 (CPU_CHAR   *)"App Task Led2",//任务名称
                 (OS_TASK_PTR ) AppTaskLed2,   //任务函数
                 (void       *) 0,             //传递给任务函数（形参p_arg）的实参
                 (OS_PRIO     ) APP_TASK_LED2_PRIO,//任务的优先级
                 (CPU_STK    *)&AppTaskLed2Stk[0], //任务堆栈的基地址
                 (CPU_STK_SIZE) APP_TASK_LED2_STK_SIZE / 10, //任务堆栈空间剩下1/10时限制其增长
                 (CPU_STK_SIZE) APP_TASK_LED2_STK_SIZE, //任务堆栈空间（单位：sizeof(CPU_STK)）
                 (OS_MSG_QTY  ) 5u,//任务可接收的最大消息数
                 (OS_TICK     ) 0u,//任务的时间片节拍数（0表默认值OSCfg_TickRate_Hz/10）
                 (void       *) 0, //任务扩展（0表不扩展）
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR), //任务选项
                 (OS_ERR     *)&err);     
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
        OSTimeDly ( 5000, OS_OPT_TIME_DLY, & err );  //延时5s
    }
		
}



