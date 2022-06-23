#include "stm8s.h"

void main(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // FREQ MCU 16MHz
    GPIO_Init(GPIOB, GPIO_PIN_0, GPIO_MODE_IN_PU_NO_IT);
    GPIO_Init(GPIOB, GPIO_PIN_1, GPIO_MODE_IN_PU_NO_IT);
    GPIO_Init(GPIOD, GPIO_PIN_6, GPIO_MODE_OUT_PP_LOW_SLOW);

    while (1)
    {
        if (GPIO_ReadInputPin(GPIOB, GPIO_PIN_1) == RESET)
        {
            GPIO_WriteReverse(GPIOD, GPIO_PIN_6);
            for (uint32_t i = 0; i < 1000; i++);
        }
    }
}
