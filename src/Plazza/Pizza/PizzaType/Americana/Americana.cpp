/*
 * EPITECH PROJECT, 2021
 * Americana
 * File description:
 * Americana.cpp
 */

#include "Americana.hpp"

Americana::Americana(PizzaSize size, long multiplier)
: Pizza<PizzaIngredient>(PizzaType::Americana, size, multiplier * 2, {
    PizzaIngredient::DOE,
    PizzaIngredient::TOMATOE,
    PizzaIngredient::GRUYERE,
    PizzaIngredient::STEAK,
})
{
}