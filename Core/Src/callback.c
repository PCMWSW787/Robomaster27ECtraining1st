//
// Created by Siwei Wang on 2026/10/1.
//
#include "main.h"
#include "tim.h"
#include "gpio.h"


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == KEY_Pin)
    {
        requested_mode++;
        requested_mode %= 3;
        if (requested_mode == 1 || requested_mode == 2) tick = 0;
    }
}