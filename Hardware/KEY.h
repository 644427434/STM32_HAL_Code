#ifndef __KEY_H
#define __KEY_H

typedef enum
{
  FALSE = 0,
  TRUE = !FALSE
} bool;


void Key_Init(void);
bool getKeyState(GPIO_TypeDef* GPIOX, uint16_t GPIO_Pin_X);

#endif