#include "Keypad_PN410_195.h"

Keypad_PN410_195::Keypad_PN410_195()
{
    buttons = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
        {'*', '0', '#'}};
}

// Функция для симуляции нажатия кнопки
void Keypad_PN410_195::press(char key)
{
    if (key_map.count(key) > 0)
    {
        key_map[key]++;
        std::cout << "Button '" << key << "' pressed: " << key_map[key] << " times." << std::endl;
    }
    else
    {
        std::cout << "Invalid button." << std::endl;
    }
}

// Функция для вывода состояния клавиатуры
void Keypad_PN410_195::print_keypad() const
{
    for (const auto &row : buttons)
    {
        for (const auto &button : row)
        {
            std::cout << button << ' ';
        }
        std::cout << std::endl;
    }
}
