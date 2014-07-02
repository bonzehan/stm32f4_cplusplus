#ifndef _STM32F4BSP_H_
#define _STM32F4BSP_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx.h"
#include "systick.h"
#include "bspgpio.h"

#define configMAX_MASKABLE_PRIORITY (5 << (8 - 4))
#define BSP_ENTER_CRITICAL() SET_INTERRUPT_MASK()
#define BSP_EXIT_CRITICAL() CLEAR_INTERRUPT_MASK()

void Stm32f4BspInit(void);

void SET_INTERRUPT_MASK(void);
void CLEAR_INTERRUPT_MASK(void);

void Stm32f4BspReboot(void);

#ifdef __cplusplus
}
#endif

#endif


