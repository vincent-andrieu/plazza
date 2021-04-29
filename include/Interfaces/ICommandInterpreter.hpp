/*
 * EPITECH PROJECT, 2021
 * interfaces
 * File description:
 * ICommandInterpreter.hpp
 */

#ifndef ICOMMANDINTERPRETER_HPP
#define ICOMMANDINTERPRETER_HPP

#include <iostream>

class ICommandInterpreter {
    public :
      virtual ~ICommandInterpreter() = default;
      [[nodiscard]] virtual std::string getLine() const = 0;
      virtual void setLine(std::string line) = 0;
};

#endif