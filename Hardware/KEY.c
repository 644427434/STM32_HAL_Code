#include "stm32f10x.h"
#include "KEY.h"
#include "Delay.h"



void Key_Init(void){
    //使能APB2时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    //初始化一个结构体，用于LED IO的配置
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //上拉输入
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2; // A的1和2口上的GPIO被激活
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //工作频率50MHz,输入模式下，工作频率参数无意义

    GPIO_Init(GPIOB, &GPIO_InitStructure);
}


bool getKeyState(GPIO_TypeDef* GPIOX, uint16_t GPIO_Pin_X){
    if(GPIO_ReadInputDataBit(GPIOX, GPIO_Pin_X) == 0){
        Delay_ms(20);
        while (GPIO_ReadInputDataBit(GPIOX, GPIO_Pin_X) == 0);
        Delay_ms(20);
        return TRUE;
    }else{
        return FALSE;
    }
}