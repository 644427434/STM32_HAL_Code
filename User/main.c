#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include <stdio.h>

int main(void){
	
	LED_Init();

	//使能GPIOC的外设时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	//配置GPIO模式
	GPIO_InitTypeDef GPIO_InitStructure;
	//设置输出模式
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //指定GPIO口的工作方式
	//
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;       //指定GPIO口
	//
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//指定GPIO的工作速度
	//使用GPIO_Init使能
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	//将某端口置高电平
	GPIO_SetBits(GPIOC, GPIO_Pin_13);
	//将某端口置为低电平
	GPIO_ResetBits(GPIOC, GPIO_Pin_13);
	while(1){
		//使用按位与的方式实现流水灯效果
		int i = 0;
		for(; i < 7; i++){
			//根据写的位来决定输出高低电平
			GPIO_WriteBit(GPIOC, GPIO_Pin_13, (BitAction)(0x01 << i));
		}

	}

	return 0;
}
