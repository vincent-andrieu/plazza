/*
 * EPITECH PROJECT, 2021
 * Fantasia
 * File description:
 * Fantasia.hpp
 */

#ifndef PIZZA_FANTASIA_HPP
#define PIZZA_FANTASIA_HPP

#include "Product/Pizza/Pizza.hpp"

namespace Pizzeria
{
    class FantasiaPizza : public Pizza {
      public:
        FantasiaPizza(PizzaSize size, long multiplier);
        ~FantasiaPizza() override = default;
    };
} // namespace Pizzeria

#endif