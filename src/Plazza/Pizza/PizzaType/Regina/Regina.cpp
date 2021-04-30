/*
 * EPITECH PROJECT, 2021
 * Regina
 * File description:
 * Regina.cpp
 */

#include "Regina.hpp"

using namespace Pizzeria;

Regina::Regina(PizzaSize size, long multiplier)
    : Pizza(PizzaType::Regina, size, multiplier * 2,
        {
            PizzaIngredient::DOE,
            PizzaIngredient::TOMATOE,
            PizzaIngredient::GRUYERE,
            PizzaIngredient::HAM,
            PizzaIngredient::MUSHROOMS,
        })
{
}