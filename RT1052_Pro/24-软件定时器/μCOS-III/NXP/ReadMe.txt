BLINKY EXAMPLE FOR THE NXP MIMXRT1050-EVK, REVISION A5 

This example project demonstrates how to create a kernel task which blinks an LED.

MICRIUM PRODUCT VERSIONS
- uC/OS-II  v2.92.14
- uC/OS-III v3.06.02
- uC/CPU    v1.31.02
- uC/LIB    v1.38.02

IDE/COMPILER VERSIONS
- IAR/EWARM v8.20.1

HARDWARE SETUP
- Connect USB Micro-B cable to J28 to provide power.

WORKSPACE LOCATIONS
- NXP/MIMXRT1050-EVK/Blinky/<OS2|OS3>/IAR/Blinky.eww

USAGE INSTRUCTIONS
- Open the workspace in IAR.
- Press F7 to build the project and Ctrl+D to start the debug session.
- Once the debug session has started, press F5 to run the example.
- The project creates a task which blinks the green LED every 1 second.
- Now modify the call to OSTimeDlyHMSM() in StartupTask() to increase or decrease the frequency at which the green LED blinks.
- Build and run again to see the change.


Please feel free to post questions or comments related to this example project at Micrium's forum page:

https://www.micrium.com/forums/topic/nxp-mimxrt1050-evk-blinky/