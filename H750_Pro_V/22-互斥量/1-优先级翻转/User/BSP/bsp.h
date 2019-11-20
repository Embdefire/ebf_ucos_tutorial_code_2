/*
  ******************************************************************************
  * @file    bsp.h
  * @author  fire
  * @version V1.0
  * @date    2016-xx-xx
  * @brief   系统初始化相关
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 STM32H750 开发板  
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************************
*/

#ifndef  BSP_H_
#define  BSP_H_


/*
*********************************************************************************************************
*                                     EXTERNAL C LANGUAGE LINKAGE
*
* Note(s) : (1) C++ compilers MUST 'extern'ally declare ALL C function prototypes & variable/object
*               declarations for correct C language linkage.
*********************************************************************************************************
*/

#ifdef __cplusplus
extern  "C" {                                  /* See Note #1.                                         */
#endif


/*
*********************************************************************************************************
*                                              包含的文件
*********************************************************************************************************
*/
#include  <cpu_core.h>


/*
*********************************************************************************************************
*                                               数据类型
*********************************************************************************************************
*/
 /* 系统时钟标识符. */
typedef  enum  bsp_clk_id {
    BSP_CLK_ID_SYSCLK,
    BSP_CLK_ID_HCLK,
    BSP_CLK_ID_PCLK1,
    BSP_CLK_ID_PCLK2,
} BSP_CLK_ID;


/*
*********************************************************************************************************
*                                             函数原型
*********************************************************************************************************
*/

void  BSP_Init(void);
void  BSP_OSTickInit (void);
void  BSP_SystemClkCfg(void);
CPU_INT32U  BSP_ClkFreqGet  (BSP_CLK_ID  clk_id);

#ifdef __cplusplus
}                                              /* End of 'extern'al C lang linkage.                    */
#endif


/*
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*/

#endif                                                          /* End of module include.                               */

