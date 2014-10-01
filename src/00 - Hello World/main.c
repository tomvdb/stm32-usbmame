#include "stm32f10x_conf.h"
#include <stdio.h>

int main(void);
void delay(int a);

int main(void)
{
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	GPIO_StructInit(&gpio);
	gpio.GPIO_Pin = GPIO_Pin_7;	
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio);

	gpio.GPIO_Pin = GPIO_Pin_6;	
	GPIO_Init(GPIOB, &gpio);

	static int led_state=0;

    
	while (1)
	{
    	GPIO_WriteBit(GPIOB, GPIO_Pin_6, Bit_SET );
    	GPIO_WriteBit(GPIOB, GPIO_Pin_7, Bit_SET );   
        delay(1000);
    	GPIO_WriteBit(GPIOB, GPIO_Pin_6, Bit_RESET );
    	GPIO_WriteBit(GPIOB, GPIO_Pin_7, Bit_RESET );   
        delay(1000);
	}

}

void delay( int a )
{
	volatile int i, j;

	for ( i = 0; i < a; i++ )
	{
		j++;
	}
}
