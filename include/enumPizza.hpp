/*
 * EPITECH PROJECT, 2021
 * include
 * File description:
 * enumPlazza.hpp
 */

#ifndef ENUM_PLAZZA_HPP
#define ENUM_PLAZZA_HPP

#include <unordered_map>
#include "Plazza.hpp"

enum class PizzaType
{
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8,
};

const std::unordered_map<string, PizzaType> PizzaNames = {
    {"Regina", PizzaType::Regina},
    {"Margarita", PizzaType::Margarita},
    {"Americana", PizzaType::Americana},
    {"Fantasia", PizzaType::Fantasia},
};

enum class PizzaSize
{
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16,
};
typedef PizzaSize FoodSize;

const std::unordered_map<string, PizzaSize> PizzaSizeList = {
    {"S", PizzaSize::S},
    {"M", PizzaSize::M},
    {"L", PizzaSize::L},
    {"XL", PizzaSize::XL},
    {"XXL", PizzaSize::XXL},
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