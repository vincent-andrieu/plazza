/*
 * EPITECH PROJECT, 2021
 * Margarita
 * File description:
 * Margarita.hpp
 */

#ifndef PIZZA_MARGARITA_HPP
#define PIZZA_MARGARITA_HPP

#include "Product/Pizza/Pizza.hpp"

namespace Pizzeria
{
    class MargaritaPizza : public Pizza {
      public:
        MargaritaPizza(PizzaSize size, double multiplier);
        ~MargaritaPizza() override = default;
    };
} // namespace Pizzeria

#endif