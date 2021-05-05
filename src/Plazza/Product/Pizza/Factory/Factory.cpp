/*
 * EPITECH PROJECT, 2021
 * Factory
 * File description:
 * Factory.cpp
 */

#include "Product/Pizza/Factory/Factory.hpp"

using namespace Pizzeria;

const std::unordered_map<PizzaType,
    std::function<AProduct<PizzaType, PizzaSize, PizzaIngredient>(const PizzaSize size, const double multiplier)>>
    PizzaList{
        {PizzaType::Americana,
            [](const PizzaSize size, const double multiplier) {
                return AmericanaPizza(size, multiplier);
            }},
        {PizzaType::Margarita,
            [](const PizzaSize size, const double multiplier) {
                return MargaritaPizza(size, multiplier);
            }},
        {PizzaType::Fantasia,
            [](const PizzaSize size, const double multiplier) {
                return FantasiaPizza(size, multiplier);
            }},
        {PizzaType::Regina,
            [](const PizzaSize size, const double multiplier) {
                return ReginaPizza(size, multiplier);
            }},
    };

AProduct<PizzaType, PizzaSize, PizzaIngredient> Factory::callFactory(
    const PizzaType type, const PizzaSize size, const double multiplier)
{
    if (PizzaList.find(type) != PizzaList.end())
        return PizzaList.at(type)(size, multiplier);
    else
        throw FactoryError("No match");
}