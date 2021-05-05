/*
 * EPITECH PROJECT, 2021
 * Stock
 * File description:
 * Stock.cpp - Created: 28/04/2021
 */

#include "Stock/Stock.hpp"

template <typename IngredientType> Stock<IngredientType>::Stock(double restockTime) : _restockTime(restockTime)
{
    for (const auto &ingredient : _stock)
        this->_stock[ingredient.first] = DEFAULT_STOCK;

    time(&this->_restockClock);
}

template <typename IngredientType> void Stock<IngredientType>::restock()
{
    if (difftime(time(nullptr), this->_restockClock) >= this->_restockTime) {
        this->_mutex.lock();
        for (const auto &ingredient : _stock)
            this->_stock[ingredient.first] += RESTOCK_NBR;

        time(&this->_restockClock);
        this->_mutex.unlock();
    }
}

/**
 * @brief Return true if can take ingredients. Otherwise return false.
 *
 * @param ingredient
 * @param nbr
 * @return bool
 */
template <typename IngredientType> bool Stock<IngredientType>::takeIngredients(IngredientType ingredient, size_t nbr)
{
    this->_mutex.lock();
    if (this->_stock[ingredient] < nbr)
        return false;

    this->_stock[ingredient] -= nbr;
    this->_mutex.unlock();
    return true;
}

template class Stock<PizzaIngredient>;