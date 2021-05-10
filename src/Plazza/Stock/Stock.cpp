/*
 * EPITECH PROJECT, 2021
 * Stock
 * File description:
 * Stock.cpp - Created: 28/04/2021
 */

#include "Stock/Stock.hpp"

template <typename IngredientType> Stock<IngredientType>::Stock(size_t restockTime) : _restockTime(restockTime)
{
    for (const IngredientType &ingredient : pizzaIngredientList)
        this->_stock[ingredient] = DEFAULT_STOCK;
    time(&this->_restockClock);
}

template <typename IngredientType> void Stock<IngredientType>::restock()
{
    if (difftime(time(nullptr), this->_restockClock) >= this->_restockTime) {
        this->_mutex.lock();
        for (const std::pair<IngredientType, size_t> &ingredient : _stock)
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

template <typename IngredientType> const std::unordered_map<IngredientType, size_t> Stock<IngredientType>::getStockList()
{
    this->_mutex.lock();
    const std::unordered_map<IngredientType, size_t> tempStock(this->_stock);
    this->_mutex.unlock();
    return tempStock;
}

template class Stock<PizzaIngredient>;