#include <AP_HAL.h>
#include <AP_HAL_STM32F4.h>
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
		DigitalSource led_io_0(0);
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

		led_io_0.mode(1);
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
				led_io_0.write(1);

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

				led_io_0.write(0);
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
/*
const AP_HAL::HAL& hal = AP_HAL_BOARD_DRIVER;

AP_HAL::DigitalSource *a_led;
AP_HAL::DigitalSource *b_led;
AP_HAL::DigitalSource *c_led;

void loop (void) {
    hal.scheduler->delay(1000);
    hal.gpio->write(0, 1);

    a_led->write(1);
    b_led->write(0);
    c_led->write(1);

    hal.scheduler->delay(1000);
    hal.gpio->write(0, 0);

    a_led->write(0);
    b_led->write(1);
    c_led->write(0);
}

void setup (void) {
    hal.gpio->pinMode(0, GPIO_OUTPUT);
    hal.gpio->write(0, 0);

    a_led = hal.gpio->channel(1);
    b_led = hal.gpio->channel(2);
    c_led = hal.gpio->channel(3);

    a_led->mode(GPIO_OUTPUT);
    b_led->mode(GPIO_OUTPUT);
    c_led->mode(GPIO_OUTPUT);

    a_led->write(0);
    b_led->write(0);
    c_led->write(0);
}

int main (void) 
{
		hal.init(0, NULL);			
		setup();
        hal.scheduler->system_initialized(); 
        for(;;)
				loop();
        return 0;
}*/
