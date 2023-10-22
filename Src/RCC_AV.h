/*
 * RCC_AV.h
 *
 *  Created on: Jun 1, 2023
 *      Author: David Zavala
 */

#ifndef RCC_AV_H_
#define RCC_AV_H_

#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define RCC_Base 	0x40021000UL

#define RCC_CR			(*((volatile unsigned long *)(RCC_Base|0x00UL)))
#define RCC_AHB1ENR		(*((volatile unsigned long *)(RCC_Base|0x48UL)))
#define RCC_AHB2ENR		(*((volatile unsigned long *)(RCC_Base|0x4CUL)))
#define RCC_AHB3ENR		(*((volatile unsigned long *)(RCC_Base|0x50UL)))
#define RCC_APB1ENR1	(*((volatile unsigned long *)(RCC_Base|0x58UL)))
#define RCC_APB1ENR2	(*((volatile unsigned long *)(RCC_Base|0x5CUL)))
#define RCC_APB2ENR		(*((volatile unsigned long *)(RCC_Base|0x60UL)))

#endif /* RCC_AV_H_ */
