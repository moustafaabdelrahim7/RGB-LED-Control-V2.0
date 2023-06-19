#include "port.h"
#include "mcu_hw.h"
#include "services.h"



#define PORT_LOCK_VALUE							(uint32_t)(0x4C4F434B)
#define BIT_MASKING_OFFSET					(uint8_t)(2)
#define PCTL_PIN_MASK								(uint32_t)(0x0000000F)
#define PCTL_PIN_BIT_NUM						(uint8_t)(4)
#define MIN_PCTL_VAL								(uint8_t)(1)
#define MAX_PCTL_VAL								(uint8_t)(15)


void GPIO_INIT_PIN(const str_port_config_t*str_port_configPTR)
{
	uint8_t u8_lv_PinCounter=0;
	if(str_port_configPTR!=NULL)
	{
			for(u8_lv_PinCounter=0;	u8_lv_PinCounter<port_pin_num;	u8_lv_PinCounter++)
			{
					enu_port_num_t	port_num=str_port_configPTR[u8_lv_PinCounter].enu_port_num;
					
					enu_port_pin_num_t	pin_num=str_port_configPTR[u8_lv_PinCounter].enu_port_pin_num;
					
				
							set_bit(RCGCGPIO,port_num);
					
					/*set the direction*/
					if(	str_port_configPTR[u8_lv_PinCounter].enu_port_pin_direction	==	PIN_OUTPUT)
					{
						
								set_bit(GPIODIR(port_num),pin_num);
								
								/*configure the pin level*/
								if(	str_port_configPTR[u8_lv_PinCounter].enu_port_pin_level	==	PIN_HIGH)
								{
									set_bit(GPIODATA(port_num),pin_num);
								}
								else if( str_port_configPTR[u8_lv_PinCounter].enu_port_pin_level	==	PIN_LOW)
								{
									clear_bit(GPIODATA(port_num),pin_num);
								}
								else
								{
									/*error handlin*/
								}
								
								/*define o/p current*/
								switch (str_port_configPTR[u8_lv_PinCounter].enu_port_pin_output_current)
								{
										case PIN_CUR_2MA:
										{
											set_bit(GPIODR2R(port_num),pin_num);
											break;
										}
											
										case PIN_CUR_4MA:
										{
											set_bit(GPIODR4R(port_num),pin_num);
											break;
										}
										
										case PIN_CUR_8MA:
										{
											set_bit(GPIODR8R(port_num),pin_num);
											break;
										}
										
										default:
										{
											/*error handline*/
											break;
										}
								}
					}
					else if(str_port_configPTR[u8_lv_PinCounter].enu_port_pin_direction	==	PIN_INPUT)
					{
								clear_bit(GPIODIR(port_num),pin_num);
								switch	(str_port_configPTR[u8_lv_PinCounter].enu_port_pin_internal_attach)
								{
									case PIN_PUR:
									{
											
										clear_bit(GPIOPDR(port_num),pin_num);
										clear_bit(GPIOODR(port_num),pin_num);
										set_bit(GPIOPUR(port_num),pin_num);
									
										break;
										
									}
									case PIN_PDR:
									{
										clear_bit(GPIOODR(port_num),pin_num);
										clear_bit(GPIOPUR(port_num),pin_num);
										set_bit(GPIOPDR(port_num),pin_num);
										break;
									}
									case PIN_ODR:
									{
										set_bit(GPIOODR(port_num),pin_num);
										break;
									}
									case INVALID_PIN_ATTACH:
									{
										break;	/*HANDLE ERROR*/
									}
								
								}
									/*configure the pin level*/
								if(	str_port_configPTR[u8_lv_PinCounter].enu_port_pin_level	==	PIN_HIGH)
								{
									set_bit(GPIODATA(port_num),pin_num);
								}
								else if( str_port_configPTR[u8_lv_PinCounter].enu_port_pin_level	==	PIN_LOW)
								{
									clear_bit(GPIODATA(port_num),pin_num);
								}
								else
								{
									/*error handlin*/
								}

					}
					else
					{
						/*handle error*/
						break;
					}
				
					
					
					/*configure pin mode*/
					if(str_port_configPTR[u8_lv_PinCounter].enu_port_pin_mode	==	PORT_PIN_DEN)
					{
							/*disable alternative func*/
							clear_bit(GPIOAFSEL(port_num),pin_num);
							/*enable digital moode*/
							set_bit(GPIODEN(port_num),pin_num);
							/*disable analog moode*/
							clear_bit(GPIOAMSEL(port_num),pin_num);

					}
					else if(str_port_configPTR[u8_lv_PinCounter].enu_port_pin_mode	==	PORT_PIN_ANEN)
					{
						/*hanlde the analog cases */
					}
					else
					{
						/*handle error*/
						break;
					}
					
					/*HANDLING GPIO INTERRUPT*/
					if(str_port_configPTR[u8_lv_PinCounter].enu_port_PIN_INT_SENSE !=PIN_NO_INTERRUPT)
					{
							/*configuring all possabiliteis of sense control*/
							switch (str_port_configPTR[u8_lv_PinCounter].enu_port_PIN_INT_SENSE)
							{
									case PIN_FALLING_EDGE:
									{
										/*choosing edge sensitive */
										clear_bit(GPIOIS(port_num),pin_num);
										/*to be able to choose one type of edges*/
										clear_bit(GPIOIBE(port_num),pin_num);
										/*to choose the right edge*/
										clear_bit(GPIOIEV(port_num),pin_num);
										break;
									}
									case PIN_RISING_EDGE:
									{
										/*choosing edge sensitive */
										clear_bit(GPIOIS(port_num),pin_num);
										/*to be able to choose one type of edges*/
										clear_bit(GPIOIBE(port_num),pin_num);
										/*to choose the right edge*/
										set_bit(GPIOIEV(port_num),pin_num);
										break;
									}
									case PIN_BOTH_EDGES:
									{
										/*choosing edge sensitive */
										clear_bit(GPIOIS(port_num),pin_num);
										/*to choose both edges*/
										set_bit(GPIOIBE(port_num),pin_num);
										break;
									}
									case PIN_LOW_LEVEL:
									{
										/*choosing level sensitive */
										set_bit(GPIOIS(port_num),pin_num);
										/*to be able to choose one type of level*/
										clear_bit(GPIOIBE(port_num),pin_num);
										/*to choose the right level*/
										clear_bit(GPIOIEV(port_num),pin_num);
										break;
									}
									case PIN_HIGH_LEVEL:
									{
										/*choosing level sensitive */
										set_bit(GPIOIS(port_num),pin_num);
										/*to be able to choose one type of level*/
										clear_bit(GPIOIBE(port_num),pin_num);
										/*to choose the right edge*/
										set_bit(GPIOIEV(port_num),pin_num);
										break;
									}
									case PIN_NO_INTERRUPT:
									{
										/*do nothing*/
										break;
									}
									default:
									{
										/*eroor handling*/
										break;
									
									}
								
							}
					
							GPIO_INTERRUPT_SET_MASKING(port_num,pin_num);
					}
					else
					{
						/*do nothing*/
					}
					/*TO SENT INTERRPUT TO INTERRUPT CONTROLLER*/
				
			}
	}
	else
	{
		/*error hadling*/
	}

}



/***********************************************************************************/

void GPIO_SET_PIN	(enu_port_num_t enu_port_num,enu_port_pin_num_t enu_port_pin_num)
{
		if( (enu_port_num<INVALID_PORT_NUM) && (enu_port_pin_num<INVALID_PORT_PIN_NUM))
		{	
			set_bit(GPIODATA(enu_port_num),enu_port_pin_num);
		}
		else
		{
		/*handle error state*/	
		}

}

/**************************************************************************************/
void GPIO_CLEAR_PIN	(enu_port_num_t enu_port_num,enu_port_pin_num_t enu_port_pin_num)
{
		if( (enu_port_num<INVALID_PORT_NUM) && (enu_port_pin_num<INVALID_PORT_PIN_NUM))
		{	
			clear_bit(GPIODATA(enu_port_num),enu_port_pin_num);
		}
		else
		{
		/*handle error state*/	
		}
}


/*****************************************************************************************/
void GPIO_TOGGEL_PIN	(enu_port_num_t enu_port_num,enu_port_pin_num_t enu_port_pin_num)
{
			if( (enu_port_num<INVALID_PORT_NUM) && (enu_port_pin_num<INVALID_PORT_PIN_NUM))
			{	
				toggel_bit(GPIODATA(enu_port_num),enu_port_pin_num);
			}
			else
			{
			/*handle error state*/	
			}
}

/*****************************************************************************************/
uint8_t GPIO_READ_PIN	(enu_port_num_t enu_port_num,enu_port_pin_num_t enu_port_pin_num)
{
	uint8_t STATUS=9;
			if( (enu_port_num<INVALID_PORT_NUM) && (enu_port_pin_num<INVALID_PORT_PIN_NUM))
			{	
				 STATUS=read_bit(GPIODATA(enu_port_num),enu_port_pin_num);
			}
			else
			{
			/*handle error state*/	
			}
			return STATUS;
}

/*********************************************************************************************/


static void GPIO_INTERRUPT_SET_MASKING(enu_port_num_t enu_port_num,enu_port_pin_num_t enu_port_pin_num)
{
	set_bit(GPIOIM(enu_port_num),enu_port_pin_num);
}

/************************************************************************************************/
			
						/*TO BE USED AT THE END OF A HANDLER*/
static void GPIO_INTERRUPT_CLEAR(enu_port_num_t enu_port_num,enu_port_pin_num_t enu_port_pin_num)
{
	set_bit(GPIOICR(enu_port_num),enu_port_pin_num);
}