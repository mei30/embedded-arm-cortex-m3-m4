/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>

#define USART3_IRQNO 39

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	uint32_t* pISPR1 = (uint32_t*)0XE000E204;

	*pISPR1 |= (1 << (USART3_IRQNO % 32 ));

	uint32_t* pISER1 = (uint32_t*)0XE000E104;

	*pISER1 |= (1 << (USART3_IRQNO % 32 ));


    /* Loop forever */
	for(;;);
}

void USART3_IRQHandler(void)
{
	printf("is USART isr");
}

