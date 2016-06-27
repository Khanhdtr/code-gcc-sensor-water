
#include <stdlib.h>
#include <string.h>

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/gpio.h>
#include "debug.h"
#include "cdcacm.h"
#include "tick.h"
#include "onewire.he"


static void clock_init(void);
static void gpio_setup(void);

/* Output for printf */
int _write(int file, char *ptr, int len);
int _write(int file, char *ptr, int len)
{
  int i;
  if(file == STDOUT_FILENO || file == STDERR_FILENO)
  {
    for (i = 0; i < len; i++)
    {
      if (ptr[i] == '\n')
      {
        cdcacm_input('\r');
      }
      cdcacm_input(ptr[i]);
    }
    return i;
  }
  errno = EIO;
  return -1;
}



int main(void)
{
  uint32_t mainTick;
  clock_init();
  tick_init();

  cdcacm_init();
  mainTick = tick_get();
 // BTN_Init();
//  BTN_Interrupts();
//  if (SysTick_Config(SystemCoreClock / 1000))  while (1);
   INFO("TEST USB OK\r\n");
//    ds18b20_init(GPIOC, GPIO_Pin_6, TIM2);
   int i;
  while(1)
  {
//      ds18b20_read_temperature_all();
//ds18b20_wait_for_conversion();
      INFO("TEST USB\r\n");
      for (i = 0; i < 800000; i++)	/* Wait a bit. */
		 	__asm__("nop");
 //     printf("%d---\r\n", ds18b20_get_precission());
 //     ds18b20_convert_temperature_all();

    cdcacm_manage();
    //if(tick_expire_ms(&mainTick, 1000))
    {
    }
  }
}

static void clock_init(void)
{
  rcc_clock_setup_in_hse_8mhz_out_72mhz();
  rcc_periph_clock_enable(RCC_GPIOA);
  rcc_periph_clock_enable(RCC_GPIOB);
  rcc_periph_clock_enable(RCC_GPIOC);
  rcc_periph_clock_enable(RCC_GPIOD);
  //rcc_periph_clock_enable(RCC_USART2);
  rcc_periph_clock_enable(RCC_AFIO);
  //rcc_periph_clock_enable(RCC_I2C2);
  gpio_primary_remap(AFIO_MAPR_SWJ_CFG_JTAG_OFF_SW_ON, 0);
}


void SysTick_Handler(void)
{
  delay_decrement();
}

//void EXTI0_IRQHandler(void)
//{
 // static u8 i = 0;

//    if (EXTI_GetITStatus(EXTI_Line0) != RESET)
//    {
  //      unsigned int j = 0;
 //       while (j != 200000) ++j;
//    if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) != Bit_RESET) {
//      return;
 //   }

//      i = (i + 1) % 4;
 //   ds18b20_set_precission(i);
//        EXTI_ClearITPendingBit(EXTI_Line0);
 //   }
//}