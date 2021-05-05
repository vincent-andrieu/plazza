/*
 * EPITECH PROJECT, 2021
 * Regina
 * File description:
 * Regina.hpp
 */

#ifndef PIZZA_REGINA_HPP
#define PIZZA_REGINA_HPP

#include "Product/Pizza/Pizza.hpp"

namespace Pizzeria
{
    class ReginaPizza : public Pizza {
      public:
        ReginaPizza(PizzaSize size, long multiplier);
        ~ReginaPizza() override = default;
    };
} // namespace Pizzeria

#endif