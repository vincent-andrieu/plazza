/*
** EPITECH PROJECT, 2021
** B-OOP-400-REN-4-1-arcade-arthur.jourdan
** File description:
** Clock
*/

#include "Clock.hpp"


void Clock::resetStartingPoint()
{
    _startingPoint = std::chrono::system_clock::now();
}

void Clock::setElapsedTime()
{
    _elapsedTime = std::chrono::system_clock::now() - _startingPoint;
}

[[nodiscard]] const std::chrono::duration<double> &Clock::getElapsedTime() const
{
    return _elapsedTime;
}

[[nodiscard]] double Clock::getElapsedTimeDouble() const
{
    return _elapsedTime.count();
}