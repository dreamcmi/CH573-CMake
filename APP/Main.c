#include "CH57x_common.h"
#include "CH57xBLE_LIB.h"
#include "printf.h"

void DebugInit(void)
{
  GPIOA_SetBits(GPIO_Pin_9);
  GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);
  GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA);
  UART1_DefInit();
}

int main()
{
  SetSysClock(CLK_SOURCE_PLL_60MHz);
  /* 配置串口调试 */
  DebugInit();
  printf("Start @ChipID=%02X\n", R8_CHIP_ID);
  printf("%s\n", VER_LIB);
  float f = 0.123456;
  printf("%0.2f\n",f);
  while (1)
    ; // 必须加while卡住主程序
  return 0;
}


/*=====实现printf接口 默认uart1=====*/
void _putchar(char character)
{
  uint8_t buff = (uint8_t)character;
  while (R8_UART1_TFC == UART_FIFO_SIZE)
    ;
  R8_UART1_THR = buff;
}
/*=================================*/