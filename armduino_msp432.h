//Arduino GPIO port for MSP432 family
//software environment: GCC-ARM + CMSIS.h from ARM/TI
//
//version: v0.10
//initial release, support for MSP432 chips
//Supported functions:
//GPIO: pinMode(), digitalWrite(), digitalRead()


#ifndef _ARMDUINO_STM32F10X_H
#define _ARMDUINO_STM32F10X_H

#include "msp.h"							//we use TI's msp432

//global defines
//port/gpio oriented macros
#define GIO_SET(port, pins)					port->OUT |= (pins)				//set bits on port
#define GIO_CLR(port, pins)					port->OUT &=~(pins)				//clear bits on port
#define GIO_FLP(port, pins)					port->OUT ^= (pins)				//flip bits on port
#define GIO_GET(port, pins)					((port->IN) & (pins))			//return bits on port
//set a pin to output/input
//#define GIO_OUTPP(port, pins)				GPIO_DDR(port, pins, GPIOMODE_OUTPP)	//push-pull mode (CR1 set, CR2 cleared)	//IO_OUTPP(GPIOx, GPIO_Pins).
//#define GIO_OUTOD(port, pins)				GPIO_DDR(port, pins, GPIOMODE_OUTOD)	//open drain mode (cr1 + cr2 cleared)	//_GPIO_Init(GPIOx, GPIO_Pins, GPIO_MODE_OUT_OD_LOW_FAST)
#define GIO_OUT(port, pins)					port->DIR |= (pins)				//GIO_OUTPP(port, pins)						//_GPIO_Init(GPIOx, GPIO_Pins, GPIO_MODE_OUT_PP_LOW_FAST)
//#define GIO_INFL(port, pins)				GPIO_DDR(port, pins, GPIOMODE_INFL)		//floating input, no interrupt			//IO_INFL(GPIOx, GPIO_Pins)
//#define GIO_INPU(port, pins)				GPIO_DDR(port, pins, GPIOMODE_INPU)		//pull-up, no interrupt					//_GPIO_Init(GPIOx, GPIO_Pins, GPIO_MODE_IN_PU_NO_IT)
#define GIO_IN(port, pins)					port->DIR &=~(pins)				//GIO_INFL(port, pins)						//IO_IN(port, pins)				//_GPIO_Init(GPIOx, GPIO_Pins, GPIO_MODE_IN_FL_NO_IT)


//global variables
//GPIO defs
//16-bit GPIO types (PORTA..J)
typedef struct {
	uint16_t IN;			//input register
	uint16_t OUT;			//otput register
	uint16_t DIR;			//direction register
	uint16_t REN;			//resistor enable
	uint16_t DS;			//drive strength
	uint16_t SEL0;			//select 0
	uint16_t SEL1;			//select 1
	uint16_t SELC;			//complement selection
	uint16_t IES;			//interrupt edge select
	uint16_t IE;			//interrupt enable
	uint16_t IFG;			//interrupt flag
} GPIO_TypeDef;

//only 16-bit port fo rmat is supported - comment out the 8-bit ports
//#define GPIO0				((volatile GPIO_TypeDef *)&P0IN)
//#define GPIO1				((volatile GPIO_TypeDef *)&P1IN)
//#define GPIO2				((volatile GPIO_TypeDef *)&P2IN)
//#define GPIO3				((volatile GPIO_TypeDef *)&P3IN)
//#define GPIO4				((volatile GPIO_TypeDef *)&P4IN)
//#define GPIO5				((volatile GPIO_TypeDef *)&P5IN)
//#define GPIO6				((volatile GPIO_TypeDef *)&P6IN)
//#define GPIO7				((volatile GPIO_TypeDef *)&P7IN)
//#define GPIO8				((volatile GPIO_TypeDef *)&P8IN)
//#define GPIO9				((volatile GPIO_TypeDef *)&P9IN)
#define GPIOA				((volatile GPIO_TypeDef *)&PAIN)
#define GPIOB				((volatile GPIO_TypeDef *)&PBIN)
#define GPIOC				((volatile GPIO_TypeDef *)&PCIN)
#define GPIOD				((volatile GPIO_TypeDef *)&PDIN)
#define GPIOE				((volatile GPIO_TypeDef *)&PEIN)
#define GPIOJ				((volatile GPIO_TypeDef *)&PJIN)

//initialize the chip
void chip_init(void);
#endif
