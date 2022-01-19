#include "stm8s.h"

void main(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // FREQ MCU 16MHz
    GPIO_Init(GPIOC, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_SLOW);

    while (1)
    {
        GPIO_WriteReverse(GPIOC, GPIO_PIN_5);
        for (uint32_t i = 0; i < 100000; i++)
            ;
    }
}
