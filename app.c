#include "app.h"

extern const str_port_config_t	str_port_config_arr[4];
uint8_t u8_gv_Counter=1;

void app_start(void)
{
if((BUTTON_READ(PORT_PIN_4,PORT_F)))
			{
				SYS_TICK_ENABLE(SYSTEM_CLK,SYS_TICK_WITH_INT,1000);
					
					if(u8_gv_Counter==1)
					{
							LED_ON(PORT_F,PORT_PIN_1);
					}
					else if(u8_gv_Counter==2)
					{
						LED_ON(PORT_F,PORT_PIN_3);
					
					}
					else if(u8_gv_Counter==3)
					{
						LED_ON(PORT_F,PORT_PIN_2);
					
					}
					else if(u8_gv_Counter==4)
					{
						LED_ON(PORT_F,PORT_PIN_1);
						LED_ON(PORT_F,PORT_PIN_3);
						LED_ON(PORT_F,PORT_PIN_2);
					
					}
			
			}
}
/*************************************************************************/

void app_init(void)
{
	LED_INIT(str_port_config_arr);
	BUTTON_INIT(str_port_config_arr);
	SYS_TICK_Set_CallBack(Task_Handler);

}


/*************************************************************************/

void Task_Handler(void)
{

	LED_OFF(PORT_F,PORT_PIN_1);
	LED_OFF(PORT_F,PORT_PIN_3);
	LED_OFF(PORT_F,PORT_PIN_2);
	u8_gv_Counter++;
	SYS_TICK_Disable();
	if(u8_gv_Counter==5)
	{
		u8_gv_Counter=1;
	}
}
	
	