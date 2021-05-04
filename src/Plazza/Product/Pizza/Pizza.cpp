/*
 * EPITECH PROJECT, 2021
 * Pizza
 * File description:
 * Pizza.cpp
 */

#include "Product/Pizza/Pizza.hpp"

#include <utility>

Pizza::Pizza(const PizzaType type, const PizzaSize size, const size_t timeSec, const std::vector<PizzaIngredient> &ingredients)
{
    setType(type);
    setSize(size);
    setIngredients(ingredients);
    setPreparationTime(timeSec);
}

bool Pizza::operator==(const IProduct &product) const
{
    return this->getType() == product.getType() && this->getSize() == product.getSize()
        && this->getPreparationTime() == product.getPreparationTime() && this->getIngredients() == product.getIngredients();
}

bool Pizza::operator!=(const IProduct &product) const
{
    return this->getType() != product.getType() || this->getSize() != product.getSize()
        || this->getPreparationTime() != product.getPreparationTime() || this->getIngredients() != product.getIngredients();
}