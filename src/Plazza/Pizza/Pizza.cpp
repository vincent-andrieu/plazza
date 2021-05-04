/*
 * EPITECH PROJECT, 2021
 * Pizza
 * File description:
 * Pizza.cpp
 */

#include "Pizza/Pizza.hpp"

#include <utility>

using namespace Pizzeria;

Pizza::Pizza(PizzaType type, PizzaSize size, size_t timeSec, std::vector<PizzaIngredient> ingredients)
    : _type(type), _size(size), _ingredients(std::move(ingredients)), _timeSec(timeSec)
{
}

bool Pizza::operator==(const IProduct<PizzaType, PizzaSize, PizzaIngredient> &product) const
{
    return this->getType() == product.getType() && this->getSize() == product.getSize()
        && this->getPreparationTime() == product.getPreparationTime() && this->getIngredientList() == product.getIngredientList();
}

bool Pizza::operator!=(const IProduct<PizzaType, PizzaSize, PizzaIngredient> &product) const
{
    return this->getType() != product.getType() || this->getSize() != product.getSize()
        || this->getPreparationTime() != product.getPreparationTime() || this->getIngredientList() != product.getIngredientList();
}

PizzaType Pizza::getType() const
{
    return this->_type;
}

PizzaSize Pizza::getSize() const
{
    return this->_size;
}

size_t Pizza::getPreparationTime() const
{
    return this->_timeSec;
}

const std::vector<PizzaIngredient> &Pizza::getIngredientList() const
{
    return this->_ingredients;
}