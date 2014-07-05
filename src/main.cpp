/* Includes ------------------------------------------------------------------*/
#include "HAL_STM32F4_Class.h"
#include "stm32f4xx.h"
#include "stm32f4bsp.h"
#include <stdio.h>

uint32_t delay_cnt = 200;
//STM32F4GPIO& hal = g_STM32F4GPIO;
const HAL_STM32F4& hal = AP_HAL_STM32F4;
/* Private function prototypes -----------------------------------------------*/
void Delay(__IO uint32_t nCount);
void ChangeDelay(void);
/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
int main(void)
{
		printf("run in main\n");
		//gpio_driver.pinMode(0,1);
//		STM32F4GPIO loc_io;
//		HAL_STM32F4 hal;
//		int a=100;
		/*!< At this stage the microcontroller clock setting is already configured, 
		  this is done through SystemInit() function which is called from startup
		  file (startup_stm32f4xx.s) before to branch to application main.
		  To reconfigure the default setting of SystemInit() function, refer to
		  system_stm32f4xx.c file
		 */
//		hal.init();
		Stm32f4BspInit();
		systickConfig();
//		loc_io.pinMode(0,1);
//		g_STM32F4GPIO.pinMode(0,1);
		//hal.pinMode(0,1);
		//hal.init();
		hal.p_gpio_driver->pinMode(0,1);
		hal.p_gpio_driver->pinMode(1,1);
		hal.p_gpio_driver->pinMode(2,1);
		hal.p_gpio_driver->pinMode(3,1);

		bspPinMode(4, 0);
		bspITAttach(4, EXTI_Trigger_Falling, Stm32f4BspReboot); 

		BSP_ENTER_CRITICAL();
		systickDelay_ms(1);
		BSP_EXIT_CRITICAL();


		while (1)
		{
		//		ITM_SendChar(0x42);
				printf("the final answer is %d\n",42);
				/* PD12 to be toggled */
				hal.p_gpio_driver->write(0,1);
//				loc_io.write(0,1);
//				g_STM32F4GPIO.write(0,1);
//				gpio_driver.write(0,1);

				/* Insert delay */
				systickDelay_ms(delay_cnt);

				/* PD13 to be toggled */
				hal.p_gpio_driver->write(1,1);

				/* Insert delay */
				systickDelay_ms(delay_cnt);

				/* PD14 to be toggled */
				hal.p_gpio_driver->write(2,1);

				/* Insert delay */
				systickDelay_ms(delay_cnt);

				/* PD15 to be toggled */
				hal.p_gpio_driver->write(3,1);

				/* Insert delay */
				systickDelay_ms(delay_cnt);

				hal.p_gpio_driver->write(0,0);
				hal.p_gpio_driver->write(1,0);
				hal.p_gpio_driver->write(2,0);
				hal.p_gpio_driver->write(3,0);
//				loc_io.write(0,0);
//				g_STM32F4GPIO.write(0,0);
//				gpio_driver.write(0,0);
//				gpio_driver.write(1,0);
//				gpio_driver.write(2,0);
//				gpio_driver.write(3,0);

				/* Insert delay */
				systickDelay_ms(1000);
				//ChangeDelay();
//				p->Add(delay_cnt,a);
//				delay_cnt = p->Result();
		}
}

/**
 * @brief  Delay Function.
 * @param  nCount:specifies the Delay time length.
 * @retval None
 */
void Delay(__IO uint32_t nCount)
{
		while(nCount--)
		{
		}
}

void ChangeDelay(void)
{
		delay_cnt += 200;
		if(delay_cnt >= 3000)
				delay_cnt = 200;
}


#ifdef  USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{ 
		/* User can add his own implementation to report the file name and line number,
ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

		/* Infinite loop */
		while (1)
		{
		}
}
#endif

/**
 * @}
 */ 

/**
 * @}
 */ 

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
