/*
 * EPITECH PROJECT, 2021
 * interfaces
 * File description:
 * CommandInterpreterInterface.hpp
 */

#ifndef ICOMMANDINTERPRETER_HPP
#define ICOMMANDINTERPRETER_HPP

#include <iostream>

class ICommandInterpreter {
  public:
    virtual ~ICommandInterpreter() = default;
    virtual string getLine() const = 0;
    virtual void setLine(string line) = 0;
};

#endif