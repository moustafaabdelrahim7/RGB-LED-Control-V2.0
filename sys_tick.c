
#include "sys_tick.h" 


enu_Sys_Tick_error_t SYS_TICK_ENABLE(enu_Sys_Tick_Source_t enu_a_Sys_Tick_Source,enu_Sys_Tick_INT_t enu_a_Sys_Tick_INT,uint32_t u32_a_time_ms)
{
		if( enu_a_Sys_Tick_Source!=	INVALID_SOURCE)
		{
				switch (enu_a_Sys_Tick_Source)
				{
						case INTERNAL_OSCILLATOR_BY_FOUR:
						{
							clear_bit(STCTRL,CLK_SRC);
							break;
						}
						case SYSTEM_CLK:
						{
							set_bit(STCTRL,CLK_SRC);
							break;
						}
						default :
						{
							/*error case*/
							break;
						}
				}
		}
		else
		{
		/*handle the error type*/
		}
		if( enu_a_Sys_Tick_INT!=	INVALID_INT_OPTION)
		{
				switch (enu_a_Sys_Tick_INT)
					{
							case SYS_TICK_WITHOUT_INT:
							{
								clear_bit(STCTRL,INTEN);
								break;
							}
							case SYS_TICK_WITH_INT:
							{
								set_bit(STCTRL,INTEN);
								break;
							}
							default:
							{
								/*error case*/
								break;
							}
					}
		}
		else
		{
		/*handle the error type*/
		}
		SYS_TICK_Load_ms(u32_a_time_ms);
		set_bit(STCTRL,ENABLE);

}


/******************************************************************/
static enu_Sys_Tick_error_t SYS_TICK_Load_ms(uint32_t u32_a_time_ms)
{
	uint32_t u32_lv_time=4*1000*u32_a_time_ms;
	STRELOAD=u32_lv_time;
	
}

/*******************************************************************/
uint32_t SYS_TICK_READ_TIME(void)
{

	while(read_bit(STCTRL,COUNT)); 
	return 1;

}
/***********************************************************************/
void SYS_TICK_Disable(void)
{

	clear_bit(STCTRL,ENABLE);
}