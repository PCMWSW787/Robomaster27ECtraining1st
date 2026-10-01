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
        static uint32_t last_key_tick = 0;
        static uint8_t has_last_key_tick = 0;
        uint32_t now = HAL_GetTick();
        if (!has_last_key_tick || (now - last_key_tick) >= 30)
        {
            has_last_key_tick = 1;
            last_key_tick = now;
            requested_mode = (requested_mode + 1) % 3;
            if (requested_mode == 1 || requested_mode == 2) tick = 0;
        }
    }
}