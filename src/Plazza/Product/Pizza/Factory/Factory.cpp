/*
 * EPITECH PROJECT, 2021
 * Factory
 * File description:
 * Factory.cpp
 */

#include "Product/Pizza/Factory/Factory.hpp"

using namespace Pizzeria;

const std::unordered_map<enum PizzaType,
    std::function<std::unique_ptr<IProduct<PizzaType, PizzaSize, PizzaIngredient>>(
        const enum PizzaSize size, const long multiplier)>>
    Factory::_list{
        {PizzaType::Americana,
            [](const enum PizzaSize size, const size_t multiplier) {
                return std::make_unique<class Americana>(size, multiplier);
            }},
        {PizzaType::Margarita,
            [](const enum PizzaSize size, const size_t multiplier) {
                return std::make_unique<class Margarita>(size, multiplier);
            }},
        {PizzaType::Fantasia,
            [](const enum PizzaSize size, const size_t multiplier) {
                return std::make_unique<class Fantasia>(size, multiplier);
            }},
        {PizzaType::Regina,
            [](const enum PizzaSize size, const size_t multiplier) {
                return std::make_unique<class Regina>(size, multiplier);
            }},
};

std::unique_ptr<IProduct<PizzaType, PizzaSize, PizzaIngredient>> Factory::callFactory(
    enum PizzaType type, enum PizzaSize size, long multiplier)
{
    if (_list.find(type) != _list.end())
        return _list.at(type)(size, multiplier);
    else
        throw FactoryError("No match", "Factory");
}