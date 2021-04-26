/*
 * EPITECH PROJECT, 2021
 * Americana
 * File description:
 * Americana.hpp
 */

#ifndef PIZZA_AMERICANA_HPP
#define PIZZA_AMERICANA_HPP

#include "Pizza/Pizza.hpp"

class Americana : public Pizza<PizzaIngredient>
{
    public:
        Americana(PizzaSize size, long multiplier);
        ~Americana();
};

#endif