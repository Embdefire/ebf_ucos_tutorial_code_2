#ifndef OS_CFG_APP_H
#define OS_CFG_APP_H

/* ------------------ 其他配置 ------------------- */
#define  OS_CFG_ISR_STK_SIZE                         256u       /*ISR堆栈的大小*/

#define  OS_CFG_MSG_POOL_SIZE                         32u       /* 支持的最大消息数量*/

#define  OS_CFG_TASK_STK_LIMIT_PCT_EMPTY              10u      	/*检查堆栈的剩余大小（百分百形式此处是10%*/

/* -------------------- 空闲任务 --------------------- */
#define  OS_CFG_IDLE_TASK_STK_SIZE                    64u       /* 空闲任务堆栈大小*/


/* ------------------ 统计任务 ------------------ */
#define  OS_CFG_STAT_TASK_PRIO  ((OS_PRIO)(OS_CFG_PRIO_MAX-2u)) /* 优先级*/
#define  OS_CFG_STAT_TASK_RATE_HZ                     10u       /* 执行率（1至10 Hz）*/
#define  OS_CFG_STAT_TASK_STK_SIZE                   128u       /* 堆栈大小（CPU_STK元素的数量）*/


/* ---------------------- 时钟节拍任务 ----------------------- */
#define  OS_CFG_TICK_RATE_HZ                        1000u       /*系统的时钟节拍(一般为10 到 1000 Hz)*/
#define  OS_CFG_TICK_TASK_PRIO                         1u       /*时钟节拍任务的优先级    */
#define  OS_CFG_TICK_TASK_STK_SIZE                   128u       /*时钟节拍任务的堆栈大小 */


/* --------------------- 定时器任务 ----------------------- */
#define  OS_CFG_TMR_TASK_PRIO   ((OS_PRIO)(OS_CFG_PRIO_MAX-3u)) /*“计时器任务”的优先级*/
#define  OS_CFG_TMR_TASK_RATE_HZ                       1u       /*定时器的频率*/
#define  OS_CFG_TMR_TASK_STK_SIZE                    128u       /*定时器任务的堆栈大小*/

#endif
