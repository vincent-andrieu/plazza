/*
 * EPITECH PROJECT, 2021
 * Factory
 * File description:
 * Factory.cpp
 */

#include "Factory/Factory.hpp"
#include "Pizza/PizzaType/Americana/Americana.hpp"
#include "Pizza/PizzaType/Margarita/Margarita.hpp"
#include "Pizza/PizzaType/Fantasia/Fantasia.hpp"
#include "Pizza/PizzaType/Regina/Regina.hpp"

Factory::Factory() : _list()
{
    this->_list = {
        {
            PizzaType::Americana, [](const PizzaSize size, const long multiplier) {
                return std::make_unique<Americana>(size, multiplier);
            }
        },
        {
            PizzaType::Margarita, [](const PizzaSize size, const long multiplier) {
                return std::make_unique<Margarita>(size, multiplier);
            }
        },
        {
            PizzaType::Fantasia, [](const PizzaSize size, const long multiplier) {
                return std::make_unique<Fantasia>(size, multiplier);
            }
        },
        {
            PizzaType::Regina, [](const PizzaSize size, const long multiplier) {
                return std::make_unique<Regina>(size, multiplier);
            }
        },
    };
}

Factory::~Factory()
{
    this->_list.clear();
}

std::unique_ptr<IProduct<PizzaIngredient>> Factory::callFactory(const PizzaType type, const PizzaSize size, const long multiplier)
{
    if (this->_list.find(type) != this->_list.end())
        return this->_list[type](size, multiplier);
    else
        throw FactoryError("No match", "Factory");
}