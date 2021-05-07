/*
** EPITECH PROJECT, 2021
** Plazza
** File description:
** Translator.hpp
*/

#ifndef TRANSLATOR_HPP
#define TRANSLATOR_HPP

#include <iostream>
#include <algorithm>
#include "enumPizza.hpp"

using namespace Pizzeria;

template<typename Type, typename Size>  class Translator {
  public:
    static std::string EnumToString(Type);
    static std::string EnumToString(Size);

    static Type StringToType(std::string src);
    static Size StringToSize(std::string src);

  private:
    std::string _input;
};

#endif