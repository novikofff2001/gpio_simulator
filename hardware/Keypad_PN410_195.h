#include <iostream>
#include <vector>
#include <map>

class Keypad_PN410_195 {
public:
    Keypad_PN410_195();

    void press(char key);

    void print_keypad() const;

private:
    std::vector<std::vector<char>> buttons;
    std::map<char, int> key_map = {
        {'1', 0}, {'2', 0}, {'3', 0},
        {'4', 0}, {'5', 0}, {'6', 0},
        {'7', 0}, {'8', 0}, {'9', 0},
        {'*', 0}, {'0', 0}, {'#', 0}
    };
};