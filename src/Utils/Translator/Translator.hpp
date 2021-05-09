/*
** EPITECH PROJECT, 2021
** Plazza
** File description:
** Translator.hpp
*/

#ifndef TRANSLATOR_HPP
#define TRANSLATOR_HPP

#include <algorithm>
#include "Plazza.hpp"
#include "enumPizza.hpp"

using namespace Pizzeria;

template <typename Type, typename Size> class Translator {
  public:
    static const string EnumToString(Type);
    static const string EnumToString(Size);

    static Type StringToType(string src);
    static Size StringToSize(string src);

  private:
    std::string _input;
};

#endif