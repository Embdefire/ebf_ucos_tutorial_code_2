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
*                                          MIMXRT1050 SERIES
*
* Filename : bsp_int.h
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                                 MODULE
*
* Note(s) : (1) This header file is protected from multiple pre-processor inclusion through use of the
*               BSP present pre-processor macro definition.
*********************************************************************************************************
*/

#ifndef  BSP_INT_PRESENT
#define  BSP_INT_PRESENT


/*
*********************************************************************************************************
*                                            INCLUDE FILES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                     EXTERNAL C LANGUAGE LINKAGE
*
* Note(s) : (1) C++ compilers MUST 'extern'ally declare ALL C function prototypes & variable/object
*               declarations for correct C language linkage.
*********************************************************************************************************
*/

#ifdef __cplusplus
extern  "C" {                                                   /* See Note #1.                        */
#endif


/*
*********************************************************************************************************
*                                               DEFINES
*
* Note(s) : (1) The Cortex-M "Vector Table Offset Register" section states the following:
*
*               You must align the offset to the number of exception entries in the vector table. The
*               minimum alignment is 32 words, enough for up to 16 interrupts. For more interrupts,
*               adjust the alignment by rounding up to the next power of two. For example, if you require
*               21 interrupts, the alignment must be on a 64-word boundary because the required table
*               size is 37 words, and the next power of two is 64. See your vendor documentation for the
*               alignment details for your device.
*********************************************************************************************************
*/

#define  ARMV7M_CORE_EXCS             16u

#define  INT_ID_MAX_NBR              160u      /* Max. number of ext. interrupt sources. (Check MCU RM)*/

                                               /* 176 VTOR entries; 256 is the next power of 2         */
#define  INT_VTOR_TBL_SIZE         (INT_ID_MAX_NBR + ARMV7M_CORE_EXCS)
#define  INT_VTOR_TBL_ALIGNMENT    (0x400uL)   /* 256 * 4 = 1024 words. See note 1                     */


/*
*********************************************************************************************************
*                                              DATA TYPES
*********************************************************************************************************
*/

                                               /* ------ MIMXRT1050 Specific Interrupt Numbers ------- */
typedef  enum  bsp_int_id {
  INT_ID_DMA0_DMA16           =   0u,          /* DMA channel 0/16 transfer complete                   */
  INT_ID_DMA1_DMA17           =   1u,          /* DMA channel 1/17 transfer complete                   */
  INT_ID_DMA2_DMA18           =   2u,          /* DMA channel 2/18 transfer complete                   */
  INT_ID_DMA3_DMA19           =   3u,          /* DMA channel 3/19 transfer complete                   */
  INT_ID_DMA4_DMA20           =   4u,          /* DMA channel 4/20 transfer complete                   */
  INT_ID_DMA5_DMA21           =   5u,          /* DMA channel 5/21 transfer complete                   */
  INT_ID_DMA6_DMA22           =   6u,          /* DMA channel 6/22 transfer complete                   */
  INT_ID_DMA7_DMA23           =   7u,          /* DMA channel 7/23 transfer complete                   */
  INT_ID_DMA8_DMA24           =   8u,          /* DMA channel 8/24 transfer complete                   */
  INT_ID_DMA9_DMA25           =   9u,          /* DMA channel 9/25 transfer complete                   */
  INT_ID_DMA10_DMA26          =  10u,          /* DMA channel 10/26 transfer complete                  */
  INT_ID_DMA11_DMA27          =  11u,          /* DMA channel 11/27 transfer complete                  */
  INT_ID_DMA12_DMA28          =  12u,          /* DMA channel 12/28 transfer complete                  */
  INT_ID_DMA13_DMA29          =  13u,          /* DMA channel 13/29 transfer complete                  */
  INT_ID_DMA14_DMA30          =  14u,          /* DMA channel 14/30 transfer complete                  */
  INT_ID_DMA15_DMA31          =  15u,          /* DMA channel 15/31 transfer complete                  */
  INT_ID_DMA_ERROR            =  16u,          /* DMA error interrupt channels 0-15 / 16-31            */
  INT_ID_CTI0_ERROR           =  17u,          /* CTI0_Error                                           */
  INT_ID_CTI1_ERROR           =  18u,          /* CTI1_Error                                           */
  INT_ID_CORE                 =  19u,          /* CorePlatform exception IRQ                           */
  INT_ID_LPUART1              =  20u,          /* LPUART1 TX interrupt and RX interrupt                */
  INT_ID_LPUART2              =  21u,          /* LPUART2 TX interrupt and RX interrupt                */
  INT_ID_LPUART3              =  22u,          /* LPUART3 TX interrupt and RX interrupt                */
  INT_ID_LPUART4              =  23u,          /* LPUART4 TX interrupt and RX interrupt                */
  INT_ID_LPUART5              =  24u,          /* LPUART5 TX interrupt and RX interrupt                */
  INT_ID_LPUART6              =  25u,          /* LPUART6 TX interrupt and RX interrupt                */
  INT_ID_LPUART7              =  26u,          /* LPUART7 TX interrupt and RX interrupt                */
  INT_ID_LPUART8              =  27u,          /* LPUART8 TX interrupt and RX interrupt                */
  INT_ID_LPI2C1               =  28u,          /* LPI2C1 interrupt                                     */
  INT_ID_LPI2C2               =  29u,          /* LPI2C2 interrupt                                     */
  INT_ID_LPI2C3               =  30u,          /* LPI2C3 interrupt                                     */
  INT_ID_LPI2C4               =  31u,          /* LPI2C4 interrupt                                     */
  INT_ID_LPSPI1               =  32u,          /* LPSPI1 single interrupt vector for all sources       */
  INT_ID_LPSPI2               =  33u,          /* LPSPI2 single interrupt vector for all sources       */
  INT_ID_LPSPI3               =  34u,          /* LPSPI3 single interrupt vector for all sources       */
  INT_ID_LPSPI4               =  35u,          /* LPSPI4  single interrupt vector for all sources      */
  INT_ID_CAN1                 =  36u,          /* CAN1 interrupt                                       */
  INT_ID_CAN2                 =  37u,          /* CAN2 interrupt                                       */
  INT_ID_FLEXRAM              =  38u,          /* FlexRAM address out of range Or access hit IRQ       */
  INT_ID_KPP                  =  39u,          /* Keypad nterrupt                                      */
  INT_ID_TSC_DIG              =  40u,          /* TSC interrupt                                        */
  INT_ID_GPR_IRQ              =  41u,          /* GPR interrupt                                        */
  INT_ID_LCDIF                =  42u,          /* LCDIF interrupt                                      */
  INT_ID_CSI                  =  43u,          /* CSI interrupt                                        */
  INT_ID_PXP                  =  44u,          /* PXP interrupt                                        */
  INT_ID_WDOG2                =  45u,          /* WDOG2 interrupt                                      */
  INT_ID_SNVS_HP_WRAPPER      =  46u,          /* SRTC Consolidated Interrupt. Non TZ                  */
  INT_ID_SNVS_HP_WRAPPER_TZ   =  47u,          /* SRTC Security Interrupt. TZ                          */
  INT_ID_SNVS_LP_WRAPPER      =  48u,          /* ON-OFF button press shorter than 5 secs (pulse event)*/
  INT_ID_CSU                  =  49u,          /* CSU interrupt                                        */
  INT_ID_DCP                  =  50u,          /* DCP_IRQ interrupt                                    */
  INT_ID_DCP_VMI              =  51u,          /* DCP_VMI_IRQ interrupt                                */
  INT_ID_RSVD0                =  52u,
  INT_ID_TRNG                 =  53u,          /* TRNG interrupt                                       */
  INT_ID_SJC                  =  54u,          /* SJC interrupt                                        */
  INT_ID_BEE                  =  55u,          /* BEE interrupt                                        */
  INT_ID_SAI1                 =  56u,          /* SAI1 interrupt                                       */
  INT_ID_SAI2                 =  57u,          /* SAI1 interrupt                                       */
  INT_ID_SAI3_RX              =  58u,          /* SAI3 interrupt                                       */
  INT_ID_SAI3_TX              =  59u,          /* SAI3 interrupt                                       */
  INT_ID_SPDIF                =  60u,          /* SPDIF interrupt                                      */
  INT_ID_PMU                  =  61u,          /* Event on either the 1.1, 2.5 or 3.0 regulators       */
  INT_ID_RSVD1                =  62u,
  INT_ID_ANATOP_TAMP_LOW_HIGH =  63u,          /* TempSensor Low or high interrupt                     */
  INT_ID_ANATOP_TEMP_PANIC    =  64u,          /* TempSensor Panic interrupt                           */
  INT_ID_USB_PHY1             =  65u,          /* USBPHY (UTMI0), Interrupt                            */
  INT_ID_USB_PHY2             =  66u,          /* USBPHY (UTMI0), Interrupt                            */
  INT_ID_ADC1                 =  67u,          /* ADC1 interrupt                                       */
  INT_ID_ADC2                 =  68u,          /* ADC2 interrupt                                       */
  INT_ID_DCDC                 =  69u,          /* DCDC interrupt                                       */
  INT_ID_RSVD2                =  70u,
  INT_ID_RSVD3                =  71u,
  INT_ID_GPIO1_INT0           =  72u,          /* Active HIGH Interrupt from INT0 from GPIO            */
  INT_ID_GPIO1_INT1           =  73u,          /* Active HIGH Interrupt from INT1 from GPIO            */
  INT_ID_GPIO1_INT2           =  74u,          /* Active HIGH Interrupt from INT2 from GPIO            */
  INT_ID_GPIO1_INT3           =  75u,          /* Active HIGH Interrupt from INT3 from GPIO            */
  INT_ID_GPIO1_INT4           =  76u,          /* Active HIGH Interrupt from INT4 from GPIO            */
  INT_ID_GPIO1_INT5           =  77u,          /* Active HIGH Interrupt from INT5 from GPIO            */
  INT_ID_GPIO1_INT6           =  78u,          /* Active HIGH Interrupt from INT6 from GPIO            */
  INT_ID_GPIO1_INT7           =  79u,          /* Active HIGH Interrupt from INT7 from GPIO            */
  INT_ID_GPIO1_Combined_0_15  =  80u,          /* Combined intr indication for GPIO1 signal 0 to 15    */
  INT_ID_GPIO1_Combined_16_31 =  81u,          /* Combined intr indication for GPIO1 signal 16 to 31   */
  INT_ID_GPIO2_Combined_0_15  =  82u,          /* Combined intr indication for GPIO2 signal 0 to 15    */
  INT_ID_GPIO2_Combined_16_31 =  83u,          /* Combined intr indication for GPIO2 signal 16 to 31   */
  INT_ID_GPIO3_Combined_0_15  =  84u,          /* Combined intr indication for GPIO3 signal 0 to 15    */
  INT_ID_GPIO3_Combined_16_31 =  85u,          /* Combined intr indication for GPIO3 signal 16 to 31   */
  INT_ID_GPIO4_Combined_0_15  =  86u,          /* Combined intr indication for GPIO4 signal 0 to 15    */
  INT_ID_GPIO4_Combined_16_31 =  87u,          /* Combined intr indication for GPIO4 signal 16 to 31   */
  INT_ID_GPIO5_Combined_0_15  =  88u,          /* Combined intr indication for GPIO5 signal 0 to 15    */
  INT_ID_GPIO5_Combined_16_31 =  89u,          /* Combined intr indication for GPIO5 signal 16 to 31   */
  INT_ID_FLEXIO1              =  90u,          /* FLEXIO1 interrupt                                    */
  INT_ID_FLEXIO2              =  91u,          /* FLEXIO2 interrupt                                    */
  INT_ID_WDOG1                =  92u,          /* WDOG1 interrupt                                      */
  INT_ID_RTWDOG               =  93u,          /* RTWDOG interrupt                                     */
  INT_ID_EWM                  =  94u,          /* EWM interrupt                                        */
  INT_ID_CCM_1                =  95u,          /* CCM IRQ1 interrupt                                   */
  INT_ID_CCM_2                =  96u,          /* CCM IRQ2 interrupt                                   */
  INT_ID_GPC                  =  97u,          /* GPC interrupt                                        */
  INT_ID_SRC                  =  98u,          /* SRC interrupt                                        */
  INT_ID_RSVD4                =  99u,
  INT_ID_GPT1                 = 100u,          /* GPT1 interrupt                                       */
  INT_ID_GPT2                 = 101u,          /* GPT2 interrupt                                       */
  INT_ID_PWM1_0               = 102u,          /* PWM1 capture 0, compare 0, or reload 0 interrupt     */
  INT_ID_PWM1_1               = 103u,          /* PWM1 capture 1, compare 1, or reload 0 interrupt     */
  INT_ID_PWM1_2               = 104u,          /* PWM1 capture 2, compare 2, or reload 0 interrupt     */
  INT_ID_PWM1_3               = 105u,          /* PWM1 capture 3, compare 3, or reload 0 interrupt     */
  INT_ID_PWM1_FAULT           = 106u,          /* PWM1 fault or reload error interrupt                 */
  INT_ID_RSVD5                = 107u,
  INT_ID_FLEXSPI              = 108u,          /* FlexSPI0 interrupt                                   */
  INT_ID_SEMC                 = 109u,          /* Reserved interrupt                                   */
  INT_ID_USDHC1               = 110u,          /* USDHC1 interrupt                                     */
  INT_ID_USDHC2               = 111u,          /* USDHC2 interrupt                                     */
  INT_ID_USB_OTG2             = 112u,          /* USBO2 USB OTG2                                       */
  INT_ID_USB_OTG1             = 113u,          /* USBO2 USB OTG1                                       */
  INT_ID_ENET                 = 114u,          /* ENET interrupt                                       */
  INT_ID_ENET_1588_Timer      = 115u,          /* ENET_1588_Timer interrupt                            */
  INT_ID_XBAR1_IRQ_0_1        = 116u,          /* XBAR1 interrupt                                      */
  INT_ID_XBAR1_IRQ_2_3        = 117u,          /* XBAR1 interrupt                                      */
  INT_ID_ADC_ETC_IRQ0         = 118u,          /* ADCETC IRQ0 interrupt                                */
  INT_ID_ADC_ETC_IRQ1         = 119u,          /* ADCETC IRQ1 interrupt                                */
  INT_ID_ADC_ETC_IRQ2         = 120u,          /* ADCETC IRQ2 interrupt                                */
  INT_ID_ADC_ETC_ERROR_IRQ    = 121u,          /* ADCETC Error IRQ interrupt                           */
  INT_ID_PIT                  = 122u,          /* PIT interrupt                                        */
  INT_ID_ACMP1                = 123u,          /* ACMP interrupt                                       */
  INT_ID_ACMP2                = 124u,          /* ACMP interrupt                                       */
  INT_ID_ACMP3                = 125u,          /* ACMP interrupt                                       */
  INT_ID_ACMP4                = 126u,          /* ACMP interrupt                                       */
  INT_ID_RSVD6                = 127u,
  INT_ID_RSVD7                = 128u,
  INT_ID_ENC1                 = 129u,          /* ENC1 interrupt                                       */
  INT_ID_ENC2                 = 130u,          /* ENC2 interrupt                                       */
  INT_ID_ENC3                 = 131u,          /* ENC3 interrupt                                       */
  INT_ID_ENC4                 = 132u,          /* ENC4 interrupt                                       */
  INT_ID_TMR1                 = 133u,          /* TMR1 interrupt                                       */
  INT_ID_TMR2                 = 134u,          /* TMR2 interrupt                                       */
  INT_ID_TMR3                 = 135u,          /* TMR3 interrupt                                       */
  INT_ID_TMR4                 = 136u,          /* TMR4 interrupt                                       */
  INT_ID_PWM2_0               = 137u,          /* PWM2 capture 0, compare 0, or reload 0 interrupt     */
  INT_ID_PWM2_1               = 138u,          /* PWM2 capture 1, compare 1, or reload 0 interrupt     */
  INT_ID_PWM2_2               = 139u,          /* PWM2 capture 2, compare 2, or reload 0 interrupt     */
  INT_ID_PWM2_3               = 140u,          /* PWM2 capture 3, compare 3, or reload 0 interrupt     */
  INT_ID_PWM2_FAULT           = 141u,          /* PWM2 fault or reload error interrupt                 */
  INT_ID_PWM3_0               = 142u,          /* PWM3 capture 0, compare 0, or reload 0 interrupt     */
  INT_ID_PWM3_1               = 143u,          /* PWM3 capture 1, compare 1, or reload 0 interrupt     */
  INT_ID_PWM3_2               = 144u,          /* PWM3 capture 2, compare 2, or reload 0 interrupt     */
  INT_ID_PWM3_3               = 145u,          /* PWM3 capture 3, compare 3, or reload 0 interrupt     */
  INT_ID_PWM3_FAULT           = 146u,          /* PWM3 fault or reload error interrupt                 */
  INT_ID_PWM4_0               = 147u,          /* PWM4 capture 0, compare 0, or reload 0 interrupt     */
  INT_ID_PWM4_1               = 148u,          /* PWM4 capture 1, compare 1, or reload 0 interrupt     */
  INT_ID_PWM4_2               = 149u,          /* PWM4 capture 2, compare 2, or reload 0 interrupt     */
  INT_ID_PWM4_3               = 150u,          /* PWM4 capture 3, compare 3, or reload 0 interrupt     */
  INT_ID_PWM4_FAULT           = 151u,          /* PWM4 fault or reload error interrupt                 */
  INT_ID_RSVD8                = 152u,
  INT_ID_RSVD9                = 153u,
  INT_ID_RSVD10               = 154u,
  INT_ID_RSVD11               = 155u,
  INT_ID_RSVD12               = 156u,
  INT_ID_RSVD13               = 157u,
  INT_ID_RSVD14               = 158u,
  INT_ID_RSVD15               = 159u
} BSP_INT_ID;


typedef enum bsp_int_type {                    /* Types of Interrupt.                                  */
    INT_IRQ,                                   /* Normal interrupt request.                            */
} BSP_INT_TYPE;


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void  BSP_IntInit   (void);

void  BSP_IntEnable (BSP_INT_ID     int_id);

void  BSP_IntDisable(BSP_INT_ID     int_id);

void  BSP_IntClear  (BSP_INT_ID     int_id);

void  BSP_IntVectSet(BSP_INT_ID     int_id,
                     CPU_INT08U     int_prio,
                     BSP_INT_TYPE   int_type,
                     CPU_FNCT_VOID  isr_handler);


/*
*********************************************************************************************************
*                                   EXTERNAL C LANGUAGE LINKAGE END
*********************************************************************************************************
*/

#ifdef __cplusplus
}                                                               /* End of 'extern'al C lang linkage.   */
#endif


/*
*********************************************************************************************************
*                                              MODULE END
*********************************************************************************************************
*/

#endif                                                          /* End of module include.              */
