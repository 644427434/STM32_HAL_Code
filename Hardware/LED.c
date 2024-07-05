#include "stm32f10x.h"
#include "LED.h"

void LED_Init(void){
    //使能APB2时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    //初始化一个结构体，用于LED IO的配置
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2; // A的1和2口上的GPIO被激活
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //工作频率50MHz

    GPIO_Init(GPIOA, &GPIO_InitStructure);

}