#include <inttypes.h>
#include "stm32f4xx.h" // File name depends on device used

#define LED_GREEN  12
#define LED_ORANGE 13
#define LED_RED    14
#define LED_BLUE   15
#define DELAY_COUNT_1MS 		 1250U
#define DELAY_COUNT_1S  		(1000U * DELAY_COUNT_1MS)

void led_on(uint8_t led_no);
void led_off(uint8_t led_no);
void led_init_all(void);

uint32_t volatile msTicks;                       // Counter for millisecond Interval
 
void SysTick_Handler (void) {                    // SysTick Interrupt Handler
  msTicks++;                                     // Increment Counter
}
 
void delay (uint32_t delay_period_ms)  {
  uint32_t end = msTicks + delay_period_ms;
 
  while (msTicks < end);            
}
 

 
void Device_Initialization (void)  {             // Configure & Initialize MCU
  led_init_all();

  if (SysTick_Config(SystemCoreClock / 1000)) { // SysTick 1mSec
    //error
    while(1);
  }
  __enable_irq();
}

// The processor clock is initialized by CMSIS startup + system file
void main (void) {                               // user application starts here
  Device_Initialization ();                      // Configure & Initialize MCU
  while (1)  {                                   // Endless Loop (the Super-Loop)
    led_on(LED_GREEN);
    delay(1000);                                
    led_off(LED_GREEN);
    delay(1000);                               
  }
}

void led_init_all(void)
{

	uint32_t *pRccAhb1enr = (uint32_t*)0x40023830;
	uint32_t *pGpiodModeReg = (uint32_t*)0x40020C00;


	*pRccAhb1enr |= ( 1 << 3);
	//configure LED_GREEN
	*pGpiodModeReg |= ( 1 << (2 * LED_GREEN));
	*pGpiodModeReg |= ( 1 << (2 * LED_ORANGE));
	*pGpiodModeReg |= ( 1 << (2 * LED_RED));
	*pGpiodModeReg |= ( 1 << (2 * LED_BLUE));

  led_off(LED_GREEN);
  led_off(LED_ORANGE);
  led_off(LED_RED);
  led_off(LED_BLUE);
}

void led_on(uint8_t led_no)
{
  uint32_t *pGpiodDataReg = (uint32_t*)0x40020C14;
  *pGpiodDataReg |= ( 1 << led_no);
}

void led_off(uint8_t led_no)
{
  uint32_t *pGpiodDataReg = (uint32_t*)0x40020C14;
  *pGpiodDataReg &= ~( 1 << led_no);
}
