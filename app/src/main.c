#include "stm8s.h"

int was_pressed(int);
void display_update(int);
void delay(int);

int prev_states[2];
int curr_states[2];
int tones[12];
int decoder[12];
int index;

extern int prev_states[2] = {0, 0,};
extern int curr_states[2] = {0, 0,};
extern int index = 0;

extern int tones[12] = {
    245,    //C   261 Hz
    231,    //C#  277 Hz
    218,    //D   293 Hz
    206,    //D#  311 Hz
    195,    //E   329 Hz
    183,    //F   349 Hz
    173,    //F#  369 Hz
    163,    //G   392 Hz
    154,    //G#  415 Hz
    145,    //A   440 Hz
    137,    //A#  466 Hz
    130,    //H   493 Hz
};


void display_upate(int index)
{
    int sharp = 0b00010011;

    int decoder[12] = {
        0b10001101,     //C
        0b10001101,     //C pro C#
        0b10000001,     //D
        0b10000001,     //D pro D#
        0b00001101,     //E
        0b00011101,     //F
        0b00011101,     //F pro F#
        0b00000101,     //G
        0b00000101,     //G pro G#
        0b00010001,     //A
        0b00010001,     //A pro A#
        0b00010011,     //H
    };

    GPIO_WriteLow(GPIOG, GPIO_PIN_2);
    GPIO_WriteLow(GPIOG, GPIO_PIN_3);
    if(index == 0 || index == 2 || index == 4 || index == 5 || index == 7 || index == 9 || index == 11)
    {
        GPIO_WriteHigh(GPIOG, GPIO_PIN_2);
        GPIO_Write(GPIOC, decoder[index]);
        delay(500);
    }
    else
    {
        GPIO_WriteHigh(GPIOG, GPIO_PIN_2);
        GPIO_Write(GPIOC, decoder[index]);
        delay(500);
        GPIO_WriteLow(GPIOG, GPIO_PIN_2);
        GPIO_WriteHigh(GPIOG, GPIO_PIN_3);
        GPIO_Write(GPIOC, sharp);
        delay(500);
    }
}

int was_pressed(int button_number)
{

    if (GPIO_ReadInputPin(GPIOB, GPIO_PIN_1) == RESET)
    {
        curr_states[0] = 1;
    }
    else
    {
        curr_states[0] = 0;
    }

    if (GPIO_ReadInputPin(GPIOB, GPIO_PIN_2) == RESET)
    {
        curr_states[1] = 1;
    }
    else
    {
        curr_states[1] = 0;
    }


    if (prev_states[button_number] == 0 && curr_states[button_number] == 1)
    {
        prev_states[button_number] = curr_states[button_number];
        return 1;
    }
    else
    {
        prev_states[button_number] = curr_states[button_number];
        return 0;
    }
}

void delay(int range)
{
    for (int i = 0; i < range; i++);
}

void main(void)
{
    int ARR_counter = 0;

    EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOB, EXTI_SENSITIVITY_FALL_ONLY);
    ITC_SetSoftwarePriority(ITC_IRQ_PORTB, ITC_PRIORITYLEVEL_0);
    enableInterrupts();

    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
    TIM4_TimeBaseInit(TIM4_PRESCALER_1, 250);
    TIM4_Cmd(ENABLE);

    GPIO_Init(GPIOB, GPIO_PIN_0, GPIO_MODE_IN_PU_NO_IT);
    GPIO_Init(GPIOB, GPIO_PIN_1, GPIO_MODE_IN_PU_NO_IT);
    GPIO_Init(GPIOB, GPIO_PIN_2, GPIO_MODE_IN_PU_NO_IT);
    GPIO_Init(GPIOD, GPIO_PIN_6, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(GPIOC, GPIO_PIN_ALL, GPIO_MODE_OUT_PP_HIGH_SLOW);
    GPIO_Init(GPIOG, GPIO_PIN_2, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(GPIOG, GPIO_PIN_3, GPIO_MODE_OUT_PP_LOW_SLOW);

    while (1)
    {
        if(TIM4_GetFlagStatus(TIM4_FLAG_UPDATE) == SET)
        {
            TIM4_ClearFlag(TIM4_FLAG_UPDATE);
            ARR_counter += 1;
            if(GPIO_ReadInputPin(GPIOB, GPIO_PIN_0) == RESET && ARR_counter == tones[index])
            {
                GPIO_WriteReverse(GPIOD, GPIO_PIN_6);
                ARR_counter = 0;
            }
        }

        if(was_pressed(0) == 1)
        {
            index += 1;
            if (index > 11)
            {index = 0;}          
           
        }

        if(was_pressed(1) == 1)
        {
            index -= 1;
            if (index < 0)
            {index = 11;}              
        }
        
        // display_upate(index);
    }
}