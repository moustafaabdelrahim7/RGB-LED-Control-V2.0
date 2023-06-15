/********************************************************
												Macros
***********************************************************/

#define set_bit(reg,bit)            reg=(reg|(1<<bit))
#define clear_bit(reg,bit)           reg=(reg&(~(1<<bit)))

#define read_bit(reg,bit) 								(0UL!=((reg) & (1UL <<(bit))))

//#define read_bit(reg,bit)              ((reg>>bit)&1)
#define toggel_bit(reg,bit)              reg=reg^(1<<bit)
#define write_bit(reg,bit,value)          reg=(reg&(~(1<<bit)))|(value<<bit)

#define NULL ((void *)0)
#define True		1
#define False		0


/********************************************************
												TYPEDEFS
***********************************************************/
typedef unsigned char         uint8_t;          /*           0 .. 255             */
typedef signed char           sint8_t;          /*        -128 .. +127            */
typedef unsigned short        uint16_t;         /*           0 .. 65535           */
typedef signed short          sint16_t;         /*      -32768 .. +32767          */
typedef unsigned int         uint32_t;         /*           0 .. 4294967295      */
typedef signed long           sint32_t;         /* -2147483648 .. +2147483647     */
typedef unsigned long long    uint64_t;         /*       0..18446744073709551615  */
typedef signed long long      sint64_t;
typedef float                 float32_t;
typedef double                float64_t;



//typedef enum
//{
//	FALSe=0,
//	TRUe}	Bool_t;
		