#include "timer.h"
#include "main.h"
#include "stm32f10x.h"



void init_timer2(void)						// ��������� ������� 2. ����� ��� �������� ��������
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->CR1 |= TIM_CR1_ARPE;
	TIM2->CR1 |= TIM_CR1_DIR;

	TIM2->PSC = 71;							// 72MHz/(PSC+1)	���� ���  - 1 ���
	TIM2->ARR = 249;

	TIM2->DIER |= TIM_DIER_UIE;
	TIM2->CR1 |= TIM_CR1_CEN;

	//NVIC_SetPriority (TIM2_IRQn, 2);		// ������ ��������� ����������

	NVIC_EnableIRQ (TIM2_IRQn);
}







