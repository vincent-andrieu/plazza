/*
 * EPITECH PROJECT, 2021
 * include
 * File description:
 * enumPlazza.hpp
 */

#ifndef ENUM_PLAZZA_HPP
#define ENUM_PLAZZA_HPP

enum class PizzaType
{
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8,
};

enum class PizzaSize
{
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16,
};

enum class PizzaIngredient
{
    DOE,
    TOMATOE,
    GRUYERE,
    HAM,
    MUSHROOMS,
    STEAK,
    EGGPLANT,
    GOAT_CHEESE,
    CHIEF_LOVE
};

const PizzaIngredient pizzaIngredientList[] = {
    PizzaIngredient::DOE,
    PizzaIngredient::TOMATOE,
    PizzaIngredient::GRUYERE,
    PizzaIngredient::HAM,
    PizzaIngredient::MUSHROOMS,
    PizzaIngredient::STEAK,
    PizzaIngredient::EGGPLANT,
    PizzaIngredient::GOAT_CHEESE,
    PizzaIngredient::CHIEF_LOVE,
};

#endif