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
*                                      APPLICATION CONFIGURATION
*
* Filename : app_cfg.h
*********************************************************************************************************
*/

#ifndef  _APP_CFG_H_
#define  _APP_CFG_H_


/*
*********************************************************************************************************
*                                            INCLUDE FILES
*********************************************************************************************************
*/

#include  <stdarg.h>
#include  <stdio.h>



/*
*********************************************************************************************************
*                                           模块禁能/使能
*********************************************************************************************************
*/
#define  APP_CFG_SERIAL_EN                          DEF_DISABLED   

/*
*********************************************************************************************************
*                                            任务优先级
*********************************************************************************************************
*/
#define  APP_TASK_START_PRIO                        2            //任务优先级

#define  APP_TASK_POST_PRIO                         3
#define  APP_TASK_PEND_PRIO                         3
/*
*********************************************************************************************************
*                                            任务堆栈大小
*********************************************************************************************************
*/

#define  APP_TASK_START_STK_SIZE                    128          //任务堆栈空间（单位：sizeof(CPU_STK)）

#define  APP_TASK_POST_STK_SIZE                    512 
#define  APP_TASK_PEND_STK_SIZE                     512 
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
#define  APP_TRACE                              PRINTF

#define  APP_TRACE_INFO(x)               ((APP_TRACE_LEVEL >= TRACE_LEVEL_INFO)  ? (void)(APP_TRACE x) : (void)0)
#define  APP_TRACE_DBG(x)                ((APP_TRACE_LEVEL >= TRACE_LEVEL_DBG)   ? (void)(APP_TRACE x) : (void)0)

#endif

