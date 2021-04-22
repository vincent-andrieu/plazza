/*
 * EPITECH PROJECT, 2021
 * src
 * File description:
 * Plazza.cpp - Created: 22/04/2021
 */

#include "Plazza.hpp"

#ifdef DEBUG

void dump(const string &msg)
{
    std::cout << msg << std::endl;
}

void dump(const stringstream &ss)
{
    std::cout << ss.str();
}

#endif