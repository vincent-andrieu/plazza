/*
 * EPITECH PROJECT, 2021
 * Stock
 * File description:
 * Stock.cpp - Created: 28/04/2021
 */

#include "Stock/Stock.hpp"

Stock::Stock(size_t restockTime) : _restockTime(restockTime)
{
    for (const PizzaIngredient ingredient : pizzaIngredientList)
        this->_stock[ingredient] = DEFAULT_STOCK;

    time(&this->_restockClock);
}

Stock::~Stock()
{
}

void Stock::restock()
{
    if (difftime(time(NULL), this->_restockClock) >= this->_restockTime) {
        this->_mutex.lock();
        for (const PizzaIngredient ingredient : pizzaIngredientList)
            this->_stock[ingredient] += RESTOCK_NBR;

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
bool Stock::takeIngredients(PizzaIngredient ingredient, size_t nbr)
{
    this->_mutex.lock();
    if (this->_stock[ingredient] < nbr)
        return false;

    this->_stock[ingredient] -= nbr;
    this->_mutex.unlock();
    return true;
}