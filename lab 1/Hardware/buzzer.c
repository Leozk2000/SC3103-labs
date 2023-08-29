#include "buzzer.h"

int BUZ_Count=7000;

//Buzer initialization
void BUZ_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);    //Enable APB Clock
	
  GPIO_InitStructure.GPIO_Pin =  BUZ_PIN;                  //LED Pin
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;            //Push pull output
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;        //100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(BUZ_PORT, &GPIO_InitStructure);                    //Initialize BUZ GPIO
	GPIO_SetBits(BUZ_PORT,BUZ_PIN);
}

void BUZ_task(void *pvParameters)
{
    while(1)
    {
      BUZ=~BUZ;        //0 on, 1 off   		
      vTaskDelay(BUZ_Count); //Delay 
    }
}  
