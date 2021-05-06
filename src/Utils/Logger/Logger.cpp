/*
 * EPITECH PROJECT, 2021
 * Logger
 * File description:
 * Logger.cpp - Created: 21/04/2021
 */

#include "Logger.hpp"

Logger::Logger(std::string filepath) : _nbLog(0), _output(std::ofstream(filepath))
{
    if (!this->_output.is_open())
        throw std::invalid_argument("Logger");
}

Logger::~Logger()
{
    this->_output.close();
}

void Logger::writeLog(std::string log)
{
    std::string tmp = "";
    std::chrono::time_point<std::chrono::system_clock> now_time = std::chrono::system_clock::now();
    std::time_t now_time_print = std::chrono::system_clock::to_time_t(now_time);
    std::string to_write = std::to_string(this->_nbLog++) + std::string(". ");

    tmp = std::ctime(&now_time_print);
    tmp.pop_back();
    to_write += tmp + std::string(": ") + log;
    this->_output << to_write << std::endl;
}