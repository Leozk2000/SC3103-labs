#include "show.h"


uint8_t string_buffer[20];
uint8_t seconds=0;
void show_task(void *pvParameters)
{
   u32 lastWakeTime = getSysTickCnt();
   while(1)
    {	

			vTaskDelayUntil(&lastWakeTime, F2T(RATE_50_HZ));

			oled_show();    
    }
}  

void oled_show(void)
{  
     //To DO
	 OLED_Refresh_Gram();
	OLED_Display_On();
	OLED_ShowString(0,0,"ZHI KAI");
	 
	
	for(;;){
		
		
		seconds++;
		sprintf(string_buffer , "%d", seconds);
		OLED_ShowString(20,20,string_buffer);
		OLED_Refresh_Gram();
		vTaskDelay(1000);
		
		
	}
	 //call some function in oled to display something

	 OLED_Refresh_Gram(); //refresh the OLED RAM

	  		
	}

