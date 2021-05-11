/*
 * EPITECH PROJECT, 2021
 * Fantasia
 * File description:
 * Fantasia.cpp
 */

#include "Fantasia.hpp"

using namespace Pizzeria;

FantasiaPizza::FantasiaPizza(PizzaSize size, double multiplier)
    : Pizza(PizzaType::Fantasia, size, multiplier * 4,
        {
            PizzaIngredient::DOE,
            PizzaIngredient::TOMATOE,
            PizzaIngredient::EGGPLANT,
            PizzaIngredient::CHIEF_LOVE,
            PizzaIngredient::GOAT_CHEESE,
        })
{
}