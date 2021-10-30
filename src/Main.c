#include "CH57x_common.h"

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
  while (1);  // 必须加while卡住主程序
  return 0;
}
