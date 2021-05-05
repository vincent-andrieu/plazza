/*
 * EPITECH PROJECT, 2021
 * Pizza
 * File description:
 * Pizza.cpp
 */

#include "Product/Pizza/Pizza.hpp"

using namespace Pizzeria;

Pizza::Pizza(const PizzaType type, const PizzaSize size, const size_t timeSec, const std::vector<PizzaIngredient> &ingredients)
{
    setType(type);
    setSize(size);
    setIngredients(ingredients);
    setPreparationTime(timeSec);
}