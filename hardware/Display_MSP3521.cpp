#include "Display_MSP3521.h"

#include <iostream>
#include <stdint.h>

Display_MSP3521::Display_MSP3521(int width, int height) : screenWidth(width), screenHeight(height)
{
    buffer.resize(screenHeight, std::vector<char>(screenWidth, ' '));
}

void Display_MSP3521::begin()
{
    std::cout << "Дисплей инициализирован" << std::endl;
}

void Display_MSP3521::clear()
{
    for (unsigned int y = 0; y < screenHeight; ++y)
    {
        for (unsigned int x = 0; x < screenWidth; ++x)
        {
            buffer[y][x] = ' ';
        }
    }
}

void Display_MSP3521::drawText(unsigned int x, unsigned int y, const std::string &text)
{
    for (size_t i = 0; i < text.length(); ++i)
    {
        if (x + i < screenWidth && y < screenHeight)
        {
            buffer[y][x + i] = text[i];
        }
    }
}

void Display_MSP3521::display()
{
    auto draw_border = [this]() {
        for (unsigned int i = 0; i < screenWidth; i++) {
            std::cout << "-";
        }
        std::cout << std::endl;
    };

    auto draw_edge = []() {
        std::cout << "|";
    };

    draw_border();
    for (unsigned int y = 0; y < screenHeight; y++)
    {
        for (unsigned int x = 0; x < screenWidth; x++)
        {
            if (x == 0) {
                draw_edge();
            }

            std::cout << buffer[y][x];
            
            if (x == screenWidth - 1) {
                draw_edge();
            }
        }
        std::cout << std::endl;
    }
    draw_border();
}