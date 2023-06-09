/*
 * EPITECH PROJECT, 2021
 * Margarita
 * File description:
 * Margarita.cpp
 */

#include "Margarita.hpp"

using namespace Pizzeria;

MargaritaPizza::MargaritaPizza(PizzaSize size, double multiplier)
    : Pizza(PizzaType::Margarita, size, multiplier * 1,
        {
            PizzaIngredient::DOE,
            PizzaIngredient::TOMATOE,
            PizzaIngredient::GRUYERE,
        })
{
}