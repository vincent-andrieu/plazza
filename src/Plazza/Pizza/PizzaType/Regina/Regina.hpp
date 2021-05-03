/*
 * EPITECH PROJECT, 2021
 * Regina
 * File description:
 * Regina.hpp
 */

#ifndef PIZZA_REGINA_HPP
#define PIZZA_REGINA_HPP

#include "Pizza/Pizza.hpp"

namespace Pizzeria
{
    class Regina : public Pizza {
      public:
        Regina(PizzaSize size, long multiplier);
        ~Regina() override = default;
    };
} // namespace Pizzeria

#endif