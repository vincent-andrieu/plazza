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
    class Margarita : public Pizza {
      public:
        Margarita(PizzaSize size, long multiplier);
        ~Margarita() override = default;
    };
} // namespace Pizzeria

#endif