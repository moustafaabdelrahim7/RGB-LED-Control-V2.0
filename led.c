#include "led.h"


void LED_INIT(const str_port_config_t*str_port_configPTR)
{
	GPIO_INIT_PIN(str_port_configPTR);
}

/*************************************************************/

void LED_ON(enu_port_num_t enu_port_num,enu_port_pin_num_t enu_port_pin_num)
{

	GPIO_SET_PIN(enu_port_num,enu_port_pin_num);

}
/*************************************************************/

void LED_OFF(enu_port_num_t enu_port_num,enu_port_pin_num_t enu_port_pin_num)
{

	GPIO_CLEAR_PIN(enu_port_num,enu_port_pin_num);

}

/***************************************************************/

void LED_TOGGEL(enu_port_num_t enu_port_num,enu_port_pin_num_t enu_port_pin_num)
{

	GPIO_TOGGEL_PIN(enu_port_num,enu_port_pin_num);

}