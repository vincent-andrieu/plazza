/*
** EPITECH PROJECT, 2021
** B-OOP-400-REN-4-1-arcade-arthur.jourdan
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include <chrono>

class Clock
{
  public:
    Clock() = default;
    ~Clock() = default;

    /**
     * @brief Set elapsed time since _startingPoint
     */
    void setElapsedTime();

    /**
     * @brief Get elapsed time in seconds
     *
     * @return Time elapsed since last call to resetElapsedTime as duration
     */
    [[nodiscard]] const std::chrono::duration<double> &getElapsedTime() const;

    /**
     * @brief Get elapsed time in seconds
     *
     * @return Time elapsed since last call to resetElapsedTime as double
     */
    [[nodiscard]] double getElapsedTimeDouble() const;

    /**
     * @brief Set the elapsed time to 0
     */
    void resetStartingPoint();

  protected:
  private:
    std::chrono::time_point<std::chrono::system_clock> _startingPoint{
        std::chrono::system_clock::now()};

    std::chrono::duration<double> _elapsedTime{0};
};

#endif /* !CLOCK_HPP_ */