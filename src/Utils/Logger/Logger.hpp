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
#include "Plazza.hpp"

class Logger {
  public:
    Logger(const string filepath);
    ~Logger();
    void writeLog(const string log);

  private:
    size_t _nbLog;
    std::ofstream _output;
};

#endif