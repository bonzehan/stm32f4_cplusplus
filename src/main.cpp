/**
 ******************************************************************************
 * @file    IO_Toggle/main.c 
 * @author  MCD Application Team
 * @version V1.0.0
 * @date    19-September-2011
 * @brief   Main program body
 ******************************************************************************
 * @attention
 *
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 *
 * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
 ******************************************************************************  
 */ 

/* Includes ------------------------------------------------------------------*/
#include "HAL_STM32F4_Class.h"
#include "stm32f4xx.h"
#include "stm32f4bsp.h"
#include "testclass.h"
#include "digiio.h"
#include <stdio.h>

/** @addtogroup STM32F4_Discovery_Peripheral_Examples
 * @{
 */

/** @addtogroup IO_Toggle
 * @{
 */ 

/* Private typedef -----------------------------------------------------------*/
GPIO_InitTypeDef  GPIO_InitStructure;

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint32_t delay_cnt = 200;
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
		Person* p = new Person();
		DigitalSource led_io_1(1);
		DigitalSource led_io_2(2);
		DigitalSource led_io_3(3);
		int a=100;
		/*!< At this stage the microcontroller clock setting is already configured, 
		  this is done through SystemInit() function which is called from startup
		  file (startup_stm32f4xx.s) before to branch to application main.
		  To reconfigure the default setting of SystemInit() function, refer to
		  system_stm32f4xx.c file
		 */
		Stm32f4BspInit();
		systickConfig();
		hal.init(0, NULL);
		hal._gpio_driver->pinMode(0,1);

		led_io_1.mode(1);
		led_io_2.mode(1);
		led_io_3.mode(1);
		bspPinMode(4, 0);

		bspITAttach(4, EXTI_Trigger_Falling, Stm32f4BspReboot); 

		BSP_ENTER_CRITICAL();
		systickDelay_ms(1);
		BSP_EXIT_CRITICAL();


		while (1)
		{
				/* PD12 to be toggled */
				hal._gpio_driver->write(0,1);

				/* Insert delay */
				systickDelay_ms(delay_cnt);

				/* PD13 to be toggled */
				led_io_1.write(1);

				/* Insert delay */
				systickDelay_ms(delay_cnt);

				/* PD14 to be toggled */
				led_io_2.write(1);

				/* Insert delay */
				systickDelay_ms(delay_cnt);

				/* PD15 to be toggled */
				led_io_3.write(1);

				/* Insert delay */
				systickDelay_ms(delay_cnt);

				hal._gpio_driver->write(0,0);
				led_io_1.write(0);
				led_io_2.write(0);
				led_io_3.write(0);

				/* Insert delay */
				systickDelay_ms(1000);
				//ChangeDelay();
				p->Add(delay_cnt,a);
				delay_cnt = p->Result();
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
