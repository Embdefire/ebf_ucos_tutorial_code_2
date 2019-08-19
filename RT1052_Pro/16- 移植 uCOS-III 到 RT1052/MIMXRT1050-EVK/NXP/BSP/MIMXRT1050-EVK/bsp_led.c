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
*                                    MICRIUM BOARD SUPPORT PACKAGE
*                                           MIMXRT1050-EVK
*
* Filename : bsp_led.c
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                            INCLUDE FILES
*********************************************************************************************************
*/

#include  <cpu_core.h>

#include  "bsp_led.h"


/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                      LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*********************************************************************************************************
**                                         GLOBAL FUNCTIONS
*********************************************************************************************************
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                           BSP_LED_Init()
*
* Description : Initializes the required pins that control the LEDs.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_LED_Init (void)
{
    gpio_pin_config_t  led_cfg;

    CLOCK_EnableClock(kCLOCK_Iomuxc);                           /* iomuxc clock (iomuxc_clk_enable): 0x03u              */

    IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_09_GPIO1_IO09,           /* GPIO_AD_B0_09 is configured as GPIO1_IO09            */
                     0U);                                       /* SW Input On Field: Input Path is determined by       */
					                                            /* functionality                                        */

    IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_09_GPIO1_IO09,        /* GPIO_AD_B0_09 PAD functional properties :            */
                        0x10B0u);                               /* Slew Rate Field: Slow Slew Rate                      */
                                                                /* Drive Strength Field: R0/6                           */
                                                                /* Speed Field: medium(100MHz)                          */
                                                                /* Open Drain Enable Field: Open Drain Disabled         */
                                                                /* Pull / Keep Enable Field: Pull/Keeper Enabled        */
                                                                /* Pull / Keep Select Field: Keeper                     */
                                                                /* Pull Up / Down Config. Field: 100K Ohm Pull Down     */
                                                                /* Hyst. Enable Field: Hysteresis Disabled              */

                                                                /* ---------------- SETUP USER LED(D18) --------------- */
    led_cfg.direction     = kGPIO_DigitalOutput;
    led_cfg.interruptMode = kGPIO_NoIntmode;
    led_cfg.outputLogic   = 1u;

    GPIO_PinInit(USE_LED_D18_GPIO, USE_LED_D18_PIN, &led_cfg);
}


/*
*********************************************************************************************************
*                                          BSP_LED_Toggle()
*
* Description : Toggles USER LED (D18).
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_LED_Toggle (void)
{
    CPU_INT32U  pin_val;


    pin_val = (GPIO_PinRead(USE_LED_D18_GPIO, USE_LED_D18_PIN)) ^ 0x1u;
    GPIO_PinWrite(USE_LED_D18_GPIO, USE_LED_D18_PIN, pin_val);
}
