#include "RotaryEncoder_PN410_117.h"

RotaryEncoder_PN410_117::RotaryEncoder_PN410_117() 
                            : position(0), button_pressed(false) {}

// Функция для симуляции вращения энкодера
void RotaryEncoder_PN410_117::rotate(int steps)
{
    position += steps;
    update_signals(steps > 0);
    std::cout << "Encoder rotated. Position: " << position << std::endl;
}

// Функция для симуляции нажатия кнопки
void RotaryEncoder_PN410_117::press_button()
{
    button_pressed = !button_pressed;
    if (button_pressed)
    {
        std::cout << "Button pressed." << std::endl;
    }
    else
    {
        std::cout << "Button released." << std::endl;
    }
}

// Функция для получения текущего значения сигнала канала A
bool RotaryEncoder_PN410_117::get_channel_a() const
{
    return channel_a;
}

// Функция для получения текущего значения сигнала канала B
bool RotaryEncoder_PN410_117::get_channel_b() const
{
    return channel_b;
}

// Функция для обновления сигналов каналов A и B на основе направления вращения
void RotaryEncoder_PN410_117::update_signals(bool clockwise)
{
    if (clockwise)
    {
        channel_a = !channel_a;
        channel_b = channel_a;
    }
    else
    {
        channel_b = !channel_b;
        channel_a = channel_b;
    }
}