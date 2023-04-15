#include "UltraSonic_HC_SR04.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>

UltraSonic_HC_SR04::UltraSonic_HC_SR04(double object_distance) : distance_to_object(object_distance) {}

// Функция для симуляции отправки сигнала с пина Trig
void UltraSonic_HC_SR04::trigger_signal()
{
    auto start_time = std::chrono::steady_clock::now();
    echo_received = false;
    std::cout << "Trigger signal sent." << std::endl;
    simulate_echo_signal();
    auto end_time = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    calculate_distance(duration);
}

// Функция для получения расстояния
double UltraSonic_HC_SR04::get_distance() const
{
    return calculated_distance;
}

// Функция для симуляции получения эхо-сигнала
void UltraSonic_HC_SR04::simulate_echo_signal()
{
    int delay = calculate_echo_delay();
    std::this_thread::sleep_for(std::chrono::microseconds(delay));
    echo_received = true;
    std::cout << "Echo signal received." << std::endl;
}

// Функция для вычисления задержки эхо-сигнала на основе расстояния до объекта
int UltraSonic_HC_SR04::calculate_echo_delay()
{
    const double speed_of_sound = 343.0; // м/с
    double time = 2.0 * distance_to_object / speed_of_sound;
    return static_cast<int>(time * 1e6);
}

// Функция для вычисления расстояния на основе времени задержки эхо-сигнала
void UltraSonic_HC_SR04::calculate_distance(int echo_delay)
{
    const double speed_of_sound = 343.0; // м/с
    calculated_distance = (echo_delay / 2.0) * (speed_of_sound / 1e6);
}