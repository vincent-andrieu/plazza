/*
 * EPITECH PROJECT, 2021
 * Americana
 * File description:
 * Americana.hpp
 */

#ifndef PIZZA_AMERICANA_HPP
#define PIZZA_AMERICANA_HPP

#include "Product/Pizza/Pizza.hpp"

namespace Pizzeria
{
    class AmericanaPizza final : public Pizza {
      public:
        AmericanaPizza(PizzaSize size, long multiplier);
        ~AmericanaPizza() override = default;
    };
} // namespace Pizzeria

#endif