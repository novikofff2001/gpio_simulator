#pragma once

#include <vector>
#include <string>

class Display_MSP3521 {
public:
    Display_MSP3521(int width, int height);

    void begin();
    void clear();
    void drawText(unsigned int x, unsigned int y, const std::string& text);
    void display();

private:
    unsigned int screenWidth;
    unsigned int screenHeight;
    std::vector<std::vector<char>> buffer;
};