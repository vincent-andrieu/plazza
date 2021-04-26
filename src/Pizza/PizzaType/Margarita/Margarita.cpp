/*
 * EPITECH PROJECT, 2021
 * Margarita
 * File description:
 * Margarita.cpp
 */

#include "Margarita.hpp"

Margarita::Margarita(PizzaSize size, long multiplier)
: Pizza<PizzaIngredient>(PizzaType::Margarita, size, multiplier * 1, {
    PizzaIngredient::DOE,
    PizzaIngredient::TOMATOE,
    PizzaIngredient::GRUYERE,
})
{
}

Margarita::~Margarita()
{
}