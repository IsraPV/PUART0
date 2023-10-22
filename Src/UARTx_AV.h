/*
 * UARTx_AV.h
 *
 *  Created on: Jun 1, 2023
 *      Author: David Zavala
 */

#ifndef UARTX_AV_H_
#define UARTX_AV_H_

#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define UART1_BASE  0x40013800
#define UART2_BASE 	0x40004400
#define UART3_BASE	0x40004800
#define UART4_BASE 	0x40004C00
#define UARTLP_BASE	0x40008000

#define USART_CR1_R(x)		(*((volatile unsigned long *)((x)|0x00UL)))
#define USART_CR2_R(x)		(*((volatile unsigned long *)((x)|0x04UL)))
#define USART_CR3_R(x)		(*((volatile unsigned long *)((x)|0x08UL)))
#define USART_BRR_R(x)		(*((volatile unsigned long *)((x)|0x0CUL)))
#define USART_GTPR_R(x)		(*((volatile unsigned long *)((x)|0x10UL)))
#define USART_RTOR_R(x)		(*((volatile unsigned long *)((x)|0x14UL)))
#define USART_RQR_R(x)		(*((volatile unsigned long *)((x)|0x18UL)))
#define USART_ISR_R(x)		(*((volatile unsigned long *)((x)|0x1CUL)))
#define USART_ICR_R(x)		(*((volatile unsigned long *)((x)|0x20UL)))
#define USART_RDR_R(x)		(*((volatile unsigned long *)((x)|0x24UL)))
#define USART_TDR_R(x)		(*((volatile unsigned long *)((x)|0x28UL)))



#endif /* UARTX_AV_H_ */
