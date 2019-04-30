#include <includes.h>

/**************************************************************
*                       定义任务控制块
**************************************************************/
static  OS_TCB   AppTaskStartTCB;


/**************************************************************
*                      定义任务栈
**************************************************************/
static  CPU_STK  AppTaskStartStk[APP_TASK_START_STK_SIZE];


/*************************************************************
*                    函数声明
*************************************************************/
static  void  AppTaskStart  (void *p_arg);


int  main (void)
{
    OS_ERR  err;

    /* 初始化系统*/
    OSInit(&err);                                               

    /* 创建任务 */
    OSTaskCreate((OS_TCB     *)&AppTaskStartTCB,                
                 (CPU_CHAR   *)"App Task Start",
                 (OS_TASK_PTR ) AppTaskStart,
                 (void       *) 0,
                 (OS_PRIO     ) APP_TASK_START_PRIO,
                 (CPU_STK    *)&AppTaskStartStk[0],
                 (CPU_STK_SIZE) APP_TASK_START_STK_SIZE / 10,
                 (CPU_STK_SIZE) APP_TASK_START_STK_SIZE,
                 (OS_MSG_QTY  ) 5u,
                 (OS_TICK     ) 0u,
                 (void       *) 0,
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR     *)&err);
                 
    /* 开启调度*/
    OSStart(&err);                                              
		
		
}


/***********************************************************************
  * @ 函数名  ： AppTaskStart
  * @ 功能说明： 为了方便管理，所有的任务创建函数都放在这个函数里面
  * @ 参数    ： 无  
  * @ 返回值  ： 无
  **********************************************************************/

static  void  AppTaskStart (void *p_arg)
{
    CPU_INT32U  cpu_clk_freq;
    CPU_INT32U  cnts;
    OS_ERR      err;


   (void)p_arg;
    /* 开发板硬件初始化 */
    BSP_Init();          
  
    CPU_Init();

    cpu_clk_freq = BSP_CPU_ClkFreq();                           
    cnts = cpu_clk_freq / (CPU_INT32U)OSCfg_TickRate_Hz;        
    OS_CPU_SysTickInit(cnts);                                   
     
    /* 内存初始化*/
    Mem_Init();                                                
#if OS_CFG_STAT_TASK_EN > 0u
    OSStatTaskCPUUsageInit(&err);                               
#endif

    CPU_IntDisMeasMaxCurReset();

    /* 死循环 */
    while (DEF_TRUE) 
    {                                          
			macLED1_TOGGLE ();
			OSTimeDly ( 5000, OS_OPT_TIME_DLY, & err );
    }
		
		
}




