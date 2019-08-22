#ifndef OS_CFG_H
#define OS_CFG_H

/* -------------- 其他配置 --------------- */                                               
#define OS_CFG_APP_HOOKS_EN             DEF_ENABLED    /* 是否使用子函数*/
#define OS_CFG_ARG_CHK_EN               DEF_ENABLED    /* 是否使用参数检查*/
#define OS_CFG_CALLED_FROM_ISR_CHK_EN   DEF_ENABLED    /* 是否使用中断调用检查*/
#define OS_CFG_DBG_EN                   DEF_ENABLED    /* 是否使用debug*/
#define OS_CFG_DYN_TICK_EN              DEF_DISABLED   /* 是否使用动态勾选*/
#define OS_CFG_INVALID_OS_CALLS_CHK_EN  DEF_ENABLED    /* 是否使用检查无效的内核调用 */
#define OS_CFG_OBJ_TYPE_CHK_EN          DEF_ENABLED    /* 是否使用对象类型检查*/
#define OS_CFG_TS_EN                    DEF_ENABLED    /* 是否使用时间戳 */

#define OS_CFG_PRIO_MAX                 64u            /* 定义任务优先级的最大数量（请参阅OS_PRIO数据类型*/

#define OS_CFG_SCHED_LOCK_TIME_MEAS_EN  DEF_DISABLED   /* 是否包含（DEF_ENABLED）代码以测量调度程序锁定时间*/
#define OS_CFG_SCHED_ROUND_ROBIN_EN     DEF_ENABLED    /* 是否包含（DEF_ENABLED）循环调度的代码*/

#define OS_CFG_STK_SIZE_MIN             64u            /*最小允许任务堆栈大小*/


/* -------------- 事件标志位------------- */                                                  
#define OS_CFG_FLAG_EN                  DEF_ENABLED    /*是否使用事件标志位*/
#define OS_CFG_FLAG_DEL_EN              DEF_ENABLED    /*是否包含OSFlagDel()的代码 */
#define OS_CFG_FLAG_MODE_CLR_EN         DEF_ENABLED    /*是否包含清除事件标志位的代码 */
#define OS_CFG_FLAG_PEND_ABORT_EN       DEF_ENABLED    /*是否包含OSFlagPendAbort()的代码*/


 /* --------------- 内存管理 ----------- */                                                      
#define OS_CFG_MEM_EN                   DEF_ENABLED     /* 是否使用内存管理 */


 /* --------------- 互斥量 ------------- */                                                   
#define OS_CFG_MUTEX_EN                 DEF_ENABLED    /*是否使用互斥量 */
#define OS_CFG_MUTEX_DEL_EN             DEF_ENABLED    /*是否包含OSMutexDel()的代码*/
#define OS_CFG_MUTEX_PEND_ABORT_EN      DEF_ENABLED    /*是否包含OSMutexPendAbort()的代码 */


 /* ---------- 消息队列---------------- */                                                      
#define OS_CFG_Q_EN                     DEF_ENABLED    /*是否使用消息队列       */                  
#define OS_CFG_Q_DEL_EN                 DEF_ENABLED    /*是否包含OSQDel()的代码 */                  
#define OS_CFG_Q_FLUSH_EN               DEF_ENABLED    /*是否包含OSQFlush()的代码 */                
#define OS_CFG_Q_PEND_ABORT_EN          DEF_ENABLED    /*是否包含OSQPendAbort()的代码 */            


 /* --------------- 信号量 ------------ */                                                     
#define OS_CFG_SEM_EN                   DEF_ENABLED    /*是否使用信号量  */        					
#define OS_CFG_SEM_DEL_EN               DEF_ENABLED    /*是否包含OSSemDel()的代码 */       
#define OS_CFG_SEM_PEND_ABORT_EN        DEF_ENABLED    /*是否包含OSSemPendAbort()的代码*/  
#define OS_CFG_SEM_SET_EN               DEF_ENABLED    /*是否包含OSSemSet()的代码  */      


 /* ----------- 任务管理 -------------- */                                                     
#define OS_CFG_STAT_TASK_EN             DEF_ENABLED    /*是否使用任务统计功能 */
#define OS_CFG_STAT_TASK_STK_CHK_EN     DEF_ENABLED    /*从统计任务中检查任务堆栈 */

#define OS_CFG_TASK_CHANGE_PRIO_EN      DEF_ENABLED    /*是否包含OSTaskChangePrio()代码*/
#define OS_CFG_TASK_DEL_EN              DEF_ENABLED    /*是否包含OSTaskDel()代码*/
#define OS_CFG_TASK_IDLE_EN             DEF_ENABLED    /*是否使用空闲任务*/
#define OS_CFG_TASK_PROFILE_EN          DEF_ENABLED    /*是否使用OS_TCB中的变量用来分析*/
#define OS_CFG_TASK_Q_EN                DEF_ENABLED    /*是否包含OSTaskQXXXX()代码*/
#define OS_CFG_TASK_Q_PEND_ABORT_EN     DEF_ENABLED    /*是否包含OSTaskQPendAbort()代码*/
#define OS_CFG_TASK_REG_TBL_SIZE        1u             /*任务特定寄存器的数量*/
#define OS_CFG_TASK_STK_REDZONE_EN      DEF_DISABLED   /*是否使用堆栈 redzone */
#define OS_CFG_TASK_STK_REDZONE_DEPTH   8u             /*堆栈redzone的深度*/
#define OS_CFG_TASK_SEM_PEND_ABORT_EN   DEF_ENABLED    /*是否包含OSTaskSemPendAbort()代码*/
#define OS_CFG_TASK_SUSPEND_EN          DEF_ENABLED    /*是否包含OSTaskSuspend()和OSTaskResume()代码 */
#define OS_CFG_TASK_TICK_EN             DEF_ENABLED    /*是否包含（DEF_ENABLED）内核tick任务*/


/* ------- 任务本地存储管理 ------- */                                                   
#define OS_CFG_TLS_TBL_SIZE             0u             /* 是否包含任务本地存储（TLS）寄存器的代码（DEF_ENABLED）*/


 /* -------- 时间管理 ------------- */                                                     
#define OS_CFG_TIME_DLY_HMSM_EN         DEF_ENABLED    /*是否包含OSTimeDlyHMSM()的代码*/
#define OS_CFG_TIME_DLY_RESUME_EN       DEF_ENABLED    /*是否包含OSTimeDlyResume()的代码*/


 /* ---------- 定时器管理 -------- */                                                     
#define OS_CFG_TMR_EN                   DEF_ENABLED    /*是否使用定时器 */
#define OS_CFG_TMR_DEL_EN               DEF_ENABLED    /*是否支持OSTmrDel()*/


/*-----------跟踪录音机-----------*/                       
#define OS_CFG_TRACE_EN                 DEF_DISABLED   /*是否使用 uC/OS-III 跟踪仪器*/
#define OS_CFG_TRACE_API_ENTER_EN       DEF_DISABLED   /*是否使用 uC/OS-III Trace API进入检测*/
#define OS_CFG_TRACE_API_EXIT_EN        DEF_DISABLED   /*是否使用 uC/OS-III Trace API退出检测*/


#endif
