/*
 * EPITECH PROJECT, 2021
 * include
 * File description:
 * Plazza.hpp - Created: 21/04/2021
 */

#ifndef PLAZZA_HPP
#define PLAZZA_HPP

#include <iostream>
#include "enumPlazza.hpp"

#define EXIT_SUCCESS 0
#define EXIT_ERROR   84

typedef std::string string;

#endif

#ifdef DEBUG

#include <sstream>

typedef std::stringstream stringstream;

void dump(const string &msg);
void dump(const stringstream &ss);

#endif