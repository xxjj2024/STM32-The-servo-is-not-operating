#include "stm32f10x.h"     // STM32 ��׼��ͷ�ļ�
#include "OLED.h"          // OLED ����������ǰ׼���ã�
#include "Delay.h"         // ����ʱ����
 
int main(void)
{
    // OLED ��ʼ��
    OLED_Init();
    OLED_ShowString(1, 1, "HSE Check...");
 
    // ��λ RCC ʱ������
    RCC_DeInit();
 
    // �� HSE���ⲿ����
    RCC_HSEConfig(RCC_HSE_ON);
 
    // �ȴ� HSE �������
    ErrorStatus HSEStatus = RCC_WaitForHSEStartUp();
 
    // ������������ʾ
    if (HSEStatus == SUCCESS)
    {
        OLED_ShowString(2, 1, "HSE OK");     // �ɹ�
    }
    else
    {
        OLED_ShowString(2, 1, "HSE FAIL");   // ʧ��
    }
 
    while (1)
    {
        // ѭ���ȴ�
    }
}
