/*
 * GPIOx_AV.h
 *
 *  Created on: Jun 6, 2023
 *      Author: David Zavala, Serret Esparza Jaime
 *
 *	References: 	STM32L452_ReferenceManual.pdf
 *			pag. 68 - 70, pag. 274 - 275
 */

#ifndef GPIOx_AV_H_
#define GPIOx_AV_H_

// LIBRARIES
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

// BOUNDARY ADDRESSES
#define GPIOA		0x48000000
#define GPIOB		0x48000400
#define GPIOC		0x48000800
#define GPIOD		0x48000C00
#define GPIOE 		0x48001000
#define GPIOH  		0x48001C00

// OFFSET
#define GPIO_MODER_R(x)		(*((volatile unsigned long *)((x)|0x00UL)))
#define GPIO_OTYPER_R(x)	(*((volatile unsigned long *)((x)|0x04UL)))
#define GPIO_OSPEEDR_R(x)	(*((volatile unsigned long *)((x)|0x08UL)))
#define GPIO_PUPDR_R(x)		(*((volatile unsigned long *)((x)|0x0CUL)))
#define GPIO_IDR_R(x)		(*((volatile unsigned long *)((x)|0x10UL)))
#define GPIO_ODR_R(x)		(*((volatile unsigned long *)((x)|0x14UL)))
#define GPIO_BSRR_R(x)		(*((volatile unsigned long *)((x)|0x18UL)))
#define GPIO_LCKR_R(x)		(*((volatile unsigned long *)((x)|0x1CUL)))
#define GPIO_AFRL_R(x)		(*((volatile unsigned long *)((x)|0x20UL)))
#define GPIO_AFRH_R(x)		(*((volatile unsigned long *)((x)|0x24UL)))
#define GPIO_BRR_R(x)		(*((volatile unsigned long *)((x)|0x28UL)))


#endif /* GPIOx_AV_H_ */
