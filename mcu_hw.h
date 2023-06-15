
#include	"services.h"
#define GPIO_APB


#ifdef GPIO_APB

#define GPIO_OFFSET(x)					(x<4?((0x40004000)+((x)*0x1000)):((0x40024000)+((x-4)*0x1000)))

#elif GPIO_AHB
#error "not supported"

#else
#error "please chose a bus for GPIO"
#define GPIO_OFFSET 0X40004000

#endif 




#define GPIODATA(x)		*( (volatile uint32_t*) (GPIO_OFFSET(x)+ 0x3FC))
#define GPIODIR(x)		*( (volatile uint32_t*) (GPIO_OFFSET(x)+ 0x400))
#define GPIOIS(x)			*( (volatile uint32_t*) (GPIO_OFFSET(x)+ 0x404))		
#define GPIOIBE(x)		*( (volatile uint32_t*) (GPIO_OFFSET(x)+ 0x408))
#define GPIOIEV(x)		*( (volatile uint32_t*) (GPIO_OFFSET(x)+ 0x40C))
#define GPIOIM(x)			*( (volatile uint32_t*) (GPIO_OFFSET(x)+ 0x410))
#define GPIORIS(x)		*( (volatile uint32_t*) (GPIO_OFFSET(x)+ 0x414))
#define GPIOMIS(x)		*( (volatile uint32_t*) (GPIO_OFFSET(x)+ 0x418))
#define GPIOICR(x)		*( (volatile uint32_t*) (GPIO_OFFSET(x)+ 0x41C))
#define GPIOAFSEL(x)	*( (volatile uint32_t*) (GPIO_OFFSET(x)+ 0x420))
#define GPIODR2R(x)		*( (volatile uint32_t*) (GPIO_OFFSET(x)+ 0x500))
#define GPIODR4R(x)		*( (volatile uint32_t*) (GPIO_OFFSET(x)+ 0x504))
#define GPIODR8R(x)		*( (volatile uint32_t*) (GPIO_OFFSET(x)+ 0x508))
#define GPIOODR(x)		*( (volatile uint32_t*) (GPIO_OFFSET(x)+ 0x50C))
#define GPIOPUR(x)		*( (volatile uint32_t*) (GPIO_OFFSET(x)+ 0x510))
#define GPIOPDR(x)		*( (volatile uint32_t*) (GPIO_OFFSET(x)+ 0x514))
#define GPIOSLR(x)		*( (volatile uint32_t*) (GPIO_OFFSET(x)+ 0x518))
#define GPIODEN(x)		*( (volatile uint32_t*) (GPIO_OFFSET(x)+ 0x51C))
#define GPIOLOCK(x)		*( (volatile uint32_t*) (GPIO_OFFSET(x)+ 0x520))
#define GPIOCR(x)			*( (volatile uint32_t*) (GPIO_OFFSET(x)+ 0x524))
#define GPIOAMSEL(x)	*( (volatile uint32_t*) (GPIO_OFFSET(x)+ 0x528))
#define RCGCGPIO			*( (volatile uint32_t*) ( (0x400FE000)+  (0x608)))
#define STCTRL			*( (volatile uint32_t*) ( ( 0xE000E000)+  (0x010)))
#define STRELOAD			*( (volatile uint32_t*) ( (  0xE000E000)+  (0x014)))
#define STCURRENT			*( (volatile uint32_t*) ( ( 0xE000E000)+  (0x018)))
	
#define CLK_SRC		2
#define INTEN			1
#define ENABLE		0
#define COUNT			16