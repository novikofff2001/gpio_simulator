#pragma once

#include <iostream>
#include <cmath>


class InfraRed_GP2Y0A02YK0F {
public:
    InfraRed_GP2Y0A02YK0F(double object_distance);

    // Функция для симуляции чтения аналогового значения с выхода датчика
    int read_analog_value() const;
    // Функция для получения расстояния до объекта на основе аналогового значения с выхода датчика
    double get_distance(int analog_value) const;

private:
    double distance_to_object;

    // Функция для вычисления напряжения на выходе датчика на основе расстояния до объекта
    double calculate_output_voltage() const;

    // Функция для вычисления расстояния на основе напряжения на выходе датчика
    double calculate_distance_from_voltage(double voltage) const;

    // Функция для преобразования напряжения в аналоговое значение
    int voltage_to_analog(double voltage) const;

    // Функция для преобразования аналогового значения в напряжение
    double analog_to_voltage(int analog_value) const;
};