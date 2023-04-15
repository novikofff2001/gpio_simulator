#include <iostream>
#include <functional>

class RotaryEncoder_PN410_117 {
public:
    RotaryEncoder_PN410_117();

    void rotate(int steps);

    void press_button();

    bool get_channel_a() const;

    bool get_channel_b() const;

private:
    int position;
    bool channel_a;
    bool channel_b;
    bool button_pressed;

    void update_signals(bool clockwise);
};