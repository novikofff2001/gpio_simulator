#pragma once

class UltraSonic_HC_SR04 {
public:
    UltraSonic_HC_SR04(double object_distance);

    // Функция для симуляции отправки сигнала с пина Trig
    void trigger_signal();

    // Функция для получения расстояния
    double get_distance() const;

private:
    double distance_to_object;
    double calculated_distance;
    bool echo_received;

    // Функция для симуляции получения эхо-сигнала
    void simulate_echo_signal();

    // Функция для вычисления задержки эхо-сигнала на основе расстояния до объекта
    int calculate_echo_delay();

    // Функция для вычисления расстояния на основе времени задержки эхо-сигнала
    void calculate_distance(int echo_delay);
};