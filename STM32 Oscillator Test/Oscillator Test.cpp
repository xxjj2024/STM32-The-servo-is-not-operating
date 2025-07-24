#include "stm32f10x.h"     // STM32 标准库头文件
#include "OLED.h"          // OLED 驱动（需提前准备好）
#include "Delay.h"         // 简单延时函数
 
int main(void)
{
    // OLED 初始化
    OLED_Init();
    OLED_ShowString(1, 1, "HSE Check...");
 
    // 复位 RCC 时钟设置
    RCC_DeInit();
 
    // 打开 HSE（外部晶振）
    RCC_HSEConfig(RCC_HSE_ON);
 
    // 等待 HSE 起振完成
    ErrorStatus HSEStatus = RCC_WaitForHSEStartUp();
 
    // 根据起振结果显示
    if (HSEStatus == SUCCESS)
    {
        OLED_ShowString(2, 1, "HSE OK");     // 成功
    }
    else
    {
        OLED_ShowString(2, 1, "HSE FAIL");   // 失败
    }
 
    while (1)
    {
        // 循环等待
    }
}
