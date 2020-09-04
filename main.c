/*
 * main.c
 *
 *  Created on: 24 Aug 2020
 *      Author: ahmed alaa
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_int.h"
#include "RCC_interface.h"
#include "STk_interface.h"
#include "LEDMatrix_Interface.h"

//AHMED
u8 DataArray[26]={0, 56, 20, 56, 0,				//A
				  0, 56, 16, 56, 0,				//H
				  0, 48, 8,  16, 8, 48, 0,		//M
				  0, 62, 42, 0,					//E
				  0, 60, 36, 24, 0};	//D

void main()
{
	/*initiat clock*/
	RCC_voidInitSysClock();


	RCC_voidEnableClock(RCC_APB2, 2); // Enable clock for GPIOA
	RCC_voidEnableClock(RCC_APB2, 3); // Enable clock for GPIOA


	//init systick

	MSTK_VoidInit();


	/*Init LEDmatrix*/
	HLEDMRX_VoidInit();





	while(1)
	{
		/*Send data to ledMatrix*/
		HLEDMRX_VoidDisplay(DataArray);

	}
}

//void EXTI0_IRQHandler(void)
//{
//	MGPIO_VoidSetPinValue(GPIOA,PIN0,HIGH);
//	MNVIC_VoidSetPendingFlag(7);			//Set pending flag for EXTI 1
//	MGPIO_VoidSetPinValue(GPIOA,PIN1,HIGH);
//
//}
//
//void EXTI1_IRQHandler(void)
//{
//	MGPIO_VoidSetPinValue(GPIOA,PIN2,HIGH);
//}
