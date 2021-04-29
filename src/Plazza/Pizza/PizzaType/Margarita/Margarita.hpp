/*
 * EPITECH PROJECT, 2021
 * Margarita
 * File description:
 * Margarita.hpp
 */

#ifndef PIZZA_MARGARITA_HPP
#define PIZZA_MARGARITA_HPP

#include "Pizza/Pizza.hpp"

class Margarita : public Pizza<PizzaIngredient>
{
    public:
        Margarita(PizzaSize size, long multiplier);
        ~Margarita() override = default;
};

#endif