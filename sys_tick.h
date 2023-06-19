#include "services.h"
#include "mcu_hw.h"
typedef enum
{
	INTERNAL_OSCILLATOR_BY_FOUR=0,
	SYSTEM_CLK=1,
	INVALID_SOURCE=3
}enu_Sys_Tick_Source_t;

typedef enum
{
	SYS_TICK_WITH_INT=0,
	SYS_TICK_WITHOUT_INT=1,
	INVALID_INT_OPTION=3
}enu_Sys_Tick_INT_t;

typedef enum
{
	invalid_int_type=0,
	invalid_clk_type=1,
	NULL_Call_Back=2
}enu_Sys_Tick_error_t;


enu_Sys_Tick_error_t SYS_TICK_ENABLE(enu_Sys_Tick_Source_t enu_a_Sys_Tick_Source,enu_Sys_Tick_INT_t enu_a_Sys_Tick_INT,uint32_t u32_a_time_ms);
static enu_Sys_Tick_error_t SYS_TICK_Load_ms(uint32_t u32_a_time_ms);
uint32_t SYS_TICK_READ_TIME(void);
enu_Sys_Tick_error_t SYS_TICK_Set_CallBack(void(*a_fptr)(void));

void SYS_TICK_Disable(void);