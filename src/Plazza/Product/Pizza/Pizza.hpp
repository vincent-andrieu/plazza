/*
 * EPITECH PROJECT, 2021
 * Pizza
 * File description:
 * Pizza.hpp
 */

#ifndef PIZZA_HPP
#define PIZZA_HPP

#include <vector>
#include "Product/Product.hpp"
#include "enumPizza.hpp"

namespace Pizzeria
{
    class Pizza : public Product<PizzaType, PizzaSize, PizzaIngredient> {
      public:
        Pizza() = default;
        Pizza(PizzaType type, PizzaSize size, double preparationTime, const std::vector<PizzaIngredient> &ingredients);
        ~Pizza() override = default;
    };
} // namespace Pizzeria

#endif