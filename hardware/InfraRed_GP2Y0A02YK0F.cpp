#include "InfraRed_GP2Y0A02YK0F.h"

InfraRed_GP2Y0A02YK0F::InfraRed_GP2Y0A02YK0F(double object_distance) : distance_to_object(object_distance) {}

// Функция для симуляции чтения аналогового значения с выхода датчика
int InfraRed_GP2Y0A02YK0F::read_analog_value() const
{
    double voltage = calculate_output_voltage();
    int analog_value = voltage_to_analog(voltage);
    std::cout << "Measured analog value: " << analog_value << std::endl;
    return analog_value;
}

// Функция для получения расстояния до объекта на основе аналогового значения с выхода датчика
double InfraRed_GP2Y0A02YK0F::get_distance(int analog_value) const
{
    double voltage = analog_to_voltage(analog_value);
    double distance = calculate_distance_from_voltage(voltage);
    std::cout << "Calculated distance: " << distance << " cm" << std::endl;
    return distance;
}

// Функция для вычисления напряжения на выходе датчика на основе расстояния до объекта
double InfraRed_GP2Y0A02YK0F::calculate_output_voltage() const
{
    const double k = 29.988;
    const double b = 0.1304;
    return k / (distance_to_object + b);
}

// Функция для вычисления расстояния на основе напряжения на выходе датчика
double InfraRed_GP2Y0A02YK0F::calculate_distance_from_voltage(double voltage) const
{
    const double k = 29.988;
    const double b = 0.1304;
    return k / voltage - b;
}

// Функция для преобразования напряжения в аналоговое значение
int InfraRed_GP2Y0A02YK0F::voltage_to_analog(double voltage) const
{
    const double v_ref = 5.0;
    const int max_analog_value = 1023;
    return static_cast<int>(voltage / v_ref * max_analog_value);
}

// Функция для преобразования аналогового значения в напряжение
double InfraRed_GP2Y0A02YK0F::analog_to_voltage(int analog_value) const
{
    const double v_ref = 5.0;
    const int max_analog_value = 1023;
    return static_cast<double>(analog_value) / max_analog_value * v_ref;
}