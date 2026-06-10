

#ifndef __TIM_H
#define __TIM_H

#define TIMx                TIM3
#define TIMx_CLK_ENABLE()   __HAL_RCC_TIM3_CLK_ENABLE()
#define TIMx_IRQn           TIM3_IRQn
#define TIMx_IRQHandler     TIM3_IRQHandler


void timx_base_init(void);

#endif /* __TIM_H */