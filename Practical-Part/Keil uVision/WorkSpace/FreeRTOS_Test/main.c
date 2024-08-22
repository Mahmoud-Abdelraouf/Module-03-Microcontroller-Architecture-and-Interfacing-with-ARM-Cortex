#include "FreeRTOS.h"
#include "task.h"
#include "time.h"

void task1(void *pv);

int main(void)
{
	int x = 50;
	TaskHandle_t y;
	xTaskCreate(task1,"Ultasonic",10, &x, 1, &y);
	
	
	
	 vTaskDelete(y);
	
	vTaskDelay(500);

	for(;;);
}


void task1(void *pv)
{
	/**< void Setup */
	*(int *)pv  =50;
	
	/**< void loop */
	while(1)
	{
	
	
	
	}
}