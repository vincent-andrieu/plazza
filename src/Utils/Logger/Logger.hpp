/*
 * EPITECH PROJECT, 2021
 * Logger
 * File description:
 * Logger.hpp - Created: 21/04/2021
 */

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <ctime>
#include <chrono>
#include <memory>
#include <fstream>
#include <iostream>

class Logger {
  public:
    Logger(std::string filepath);
    ~Logger();
    void writeLog(std::string log);

  private:
    std::size_t _nbLog;
    std::ofstream _output;
};

#endif