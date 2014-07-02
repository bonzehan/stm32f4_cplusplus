#include "stm32f4bsp.h"
#include "stm32f4xx.h"

static volatile uint32_t tempISER[8]={0};

void Stm32f4BspInit(void)
{
		if(RCC_GetFlagStatus(RCC_FLAG_IWDGRST) != RESET)
				RCC_ClearFlag();
}

void SET_INTERRUPT_MASK(void)
{
		uint8_t i;
		for(i=0; i<8; i++)
		{
				tempISER[i] = NVIC->ISER[i];
				NVIC->ICER[i] = 0xffffffff;
		}
}

void CLEAR_INTERRUPT_MASK(void)
{
		uint8_t i;
		for(i=0; i<8; i++)
		{
				NVIC->ISER[i] = tempISER[i];
		}
}

void Stm32f4BspReboot(void)
{
		IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
		IWDG_SetPrescaler(IWDG_Prescaler_32);
		IWDG_SetReload(1000);
		IWDG_ReloadCounter();
		IWDG_Enable();
}

