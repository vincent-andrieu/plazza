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

class Translator {
  public:
    static const string EnumToString(PizzaType);
    static const string EnumToString(PizzaSize);

    static PizzaType StringToType(string src);
    static PizzaSize StringToSize(string src);

  private:
    string _input;
};

#endif