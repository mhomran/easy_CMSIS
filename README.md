# CMSIS

<q>The CMSIS is a set of tools, APIs, frameworks, and work flows that help to simplify software re-use, reduce the learning curve for microcontroller developers, speed-up project build and debug, and thus reduce the time to market for new applications.</q>

CMSIS is open-source and collaboratively developed on GitHub.

<img src="imgs/Overview.png"> </img>

## Why CMSIS ?

- CMSIS reduces the learning curve, development costs, and time-to-market. Developers can write software quicker through a variety of easy-to-use, standardized software interfaces.
- Consistent software interfaces improve the software portability and re-usability. Generic software libraries and interfaces provide consistent software framework.
- It provides interfaces for debug connectivity, debug peripheral views, software delivery, and device support to reduce time-to-market for <strong>new microcontroller</strong> deployment.
- It allows to use the compiler of your choice, as it is compiler independent and thus supported by mainstream compilers.
- It enhances program debugging with peripheral information for debuggers and ITM channels for printf-style output.
- CMSIS is delivered in CMSIS-Pack format which enables fast software delivery, simplifies updates, and enables consistent integration into development tools.
- CMSIS-Zone will simplify system resource and partitioning as it manages the configuration of multiple processors, memory areas, and peripherals.
- Continuous integration is common practice for most software developers nowadays. CMSIS-Build supports these workflows and makes continuous testing and validation easier.

## CMSIS naming convention

- <strong>CAPITAL</strong> names to identify Core Registers, Peripheral Registers, and CPU Instructions.
- <strong>CamelCase</strong> names to identify function names and interrupt functions.
- <strong>Namespace_</strong> prefixes avoid clashes with user identifiers and provide functional groups (i.e. for peripherals, RTOS, or DSP Library).

## CMSIS Core

CMSIS-Core (Cortex-M) implements the basic run-time system for a Cortex-M device and gives the user access to the processor core and the device peripherals. In detail it defines:

- Hardware Abstraction Layer (HAL) for Cortex-M processor registers with standardized definitions for the SysTick, NVIC, System Control Block registers, MPU registers, FPU registers, and core access functions.
- System exception names to interface to system exceptions without having compatibility issues.
- Methods to organize header files that makes it easy to learn new Cortex-M microcontroller products and improve software portability. This includes naming conventions for device-specific interrupts.
- Methods for system initialization to be used by each MCU vendor. For example, the standardized SystemInit() function is essential for configuring the clock system of the device.
- Intrinsic functions used to generate CPU instructions that are not supported by standard C functions.
- A variable to determine the system clock frequency which simplifies the setup the SysTick timer.

### Files structure 

<img src="imgs/CMSIS_CORE_Files.png">

### Example 1: STM32CubeHAL for STM32F407VG 

<img src="imgs/stm32f4_cmsis_core.png">
<img src="imgs/stm32f4_cmsis_core_fs.jpg">

