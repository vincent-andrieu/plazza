/*
 * EPITECH PROJECT, 2021
 * Pizza
 * File description:
 * Pizza.cpp
 */

#include "Product/Pizza/Pizza.hpp"

using namespace Pizzeria;

Pizza::Pizza(
    const PizzaType type, const PizzaSize size, const double preparationTime, const std::vector<PizzaIngredient> &ingredients)
    : Product(type, size, preparationTime, ingredients)
{
}