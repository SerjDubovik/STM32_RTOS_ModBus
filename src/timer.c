#include "timer.h"
#include "main.h"
#include "stm32f10x.h"



void init_timer2(void)						// Настройка таймера 2. Общий для отсчётов задержек
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->CR1 |= TIM_CR1_ARPE;
	TIM2->CR1 |= TIM_CR1_DIR;

	TIM2->PSC = 71;							// 72MHz/(PSC+1)	один тик  - 1 мкс
	TIM2->ARR = 249;

	TIM2->DIER |= TIM_DIER_UIE;
	TIM2->CR1 |= TIM_CR1_CEN;

	//NVIC_SetPriority (TIM2_IRQn, 2);		// задаем приоритет прерывания

	NVIC_EnableIRQ (TIM2_IRQn);
}







