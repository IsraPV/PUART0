 /*  							TEST UART2 TRANSMISION
 *Baud Rate: 		9600 b/s
 * Data L: 			8 bits
 * Stop bit: 		1 bits
 * Over sampling:	16
 * Parity: 			Disable
 * Mode: 			Single Byte Tx/Rx
 * PA2: 			Tx
 * PA3:				Rx
 * -Dvaid Zavala
*/
//******************************************************************************************//
//************************************** LIBRARYS ******************************************//
//******************************************************************************************//
#include <stdint.h>
#include "UARTx_AV.h"
#include "RCC_AV.h"
#include "GPIOx_AV.h"

//******************************************************************************************//
//*************************************** DEFINES ******************************************//
//******************************************************************************************//
#define DELAY 				400
#define SIZE_MSG 20


void sendStringUART2(char *msg);

//******************************************************************************************//
//********************************** BASIC CONFIGURATION************************************//
//******************************************************************************************//
int main(void)
{
	char msg[SIZE_MSG] = "hola";
	msg[4]= 0XD;
	msg[5]= 0XA;
	int i;
	RCC_AHB2ENR  |= 0X00000002;																//Activate clock Port B
	GPIO_MODER_R(GPIOB) &= ~0x0C000000;														//CLean MODER13
	GPIO_MODER_R(GPIOB) |=  0x04000000;														//LED PB13 as output

//******************************************************************************************//
//***********************************USART2 CONFIGURATION***********************************//
//******************************************************************************************//
	RCC_AHB2ENR  		|= 0X00000001;														//Activate clock Port A
	GPIO_MODER_R(GPIOA) &= ~0x000000F0;														//Clean MODER PA2 and PA3
	GPIO_MODER_R(GPIOA) |= 0x000000A0;														//Alternate Function mode in PA2 and PA3
	GPIO_AFRL_R(GPIOA)  |= 0x00007700;														//AF07 at PA2 and PA3

	RCC_APB1ENR1 |= 0X00020000;																//Activate clock USART2
	USART_CR1_R(UART2_BASE)  = 0x00000000;													//Clean USART2 configuration (Disable USART2)
	USART_CR1_R(UART2_BASE) |=0x00000001;													//Enable USART-2
	USART_BRR_R(UART2_BASE)	|= 0x000001A0;													//Configure BaudRate
	USART_CR1_R(UART2_BASE) |=0x0000000C;													//Activate Transmitter & Receiver
//******************************************************************************************//
//************************************ INFINITE CYCLE **************************************//
//******************************************************************************************//
	while(1)
	{
		/* Esta inicialización del puerto debe mejorarse
		con el uso de las estructuras*/
		for(i=0;i<=DELAY;i++);
		GPIO_ODR_R(GPIOB) = 0x2000; 														//USER LED ON
		for(i=0;i<=DELAY;i++);
		GPIO_ODR_R(GPIOB) &= ~0X2000; 														//USER LED OFF
		sendStringUART2(msg);


		for(i=0;i<=DELAY;i++);
		GPIO_ODR_R(GPIOB) = 0x2000; 														//USER LED ON
		for(i=0;i<=DELAY;i++);
		GPIO_ODR_R(GPIOB) &= ~0X2000; 														//USER LED OFF
		sendStringUART2(msg);
		//	USART_TDR_R(UART2_BASE) = 0xAB;
		//while (!(USART_ISR_R(UART2_BASE) & 0x80));											//Wait to end of transmission
	}
}

void sendStringUART2(char *msg)
{
    while(*msg)
    {
		//Wait to end of transmission
    	 USART_TDR_R(UART2_BASE) = *msg++;
    	 while (!(USART_ISR_R(UART2_BASE) & 0x80));
    }
}

