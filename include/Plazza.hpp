/*
 * EPITECH PROJECT, 2021
 * include
 * File description:
 * Plazza.hpp - Created: 21/04/2021
 */

#ifndef PLAZZA_HPP
#define PLAZZA_HPP

#include <iostream>
#include <sstream>
#include <memory>
#include <string>

#define PRIORITORY_LIB "arcade_ncurse.so"
#define LOG_FILE_PATH  "./log_plazza"
#define EXIT_SUCCESS   0
#define EXIT_ERROR     84

typedef std::string string;
typedef std::size_t size_t;
typedef std::stringstream stringstream;
#define charette_ptr(T) std::shared_ptr<T>
#define toString(str)   std::to_string(str)
#define toInteger(str)  std::stoi(str)
#define toSize_t(str)   std::stoul(str)

#endif