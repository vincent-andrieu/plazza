/*
 * EPITECH PROJECT, 2021
 * Stock
 * File description:
 * Stock.cpp - Created: 28/04/2021
 */

#include "Stock/Stock.hpp"
#include "enumPizza.hpp"

template <typename IngredientType> Stock<IngredientType>::Stock(double restockTime) : _restockTime(restockTime)
{
}

template <typename IngredientType>
Stock<IngredientType>::Stock(double restockTime, const std::vector<IngredientType> &stackableIngredients)
    : _restockTime(restockTime)
{
    for (const auto &stackableIngredient : stackableIngredients) {
        _stock.template emplace(std::make_pair(stackableIngredient, DEFAULT_STOCK));
    }
}

template <typename IngredientType> void Stock<IngredientType>::addIngredient(const IngredientType &ingredient)
{
    try {
        _stock.at(ingredient);
    } catch (const std::out_of_range &my_exception) {
        _stock.emplace(std::make_pair(ingredient, DEFAULT_STOCK));
    }
}

template <typename IngredientType> bool Stock<IngredientType>::isRestockTime() const
{
    return (_restockClock.getElapsedTimeDouble() > _restockTime);
}

template <typename IngredientType> void Stock<IngredientType>::restock()
{
    std::lock_guard<std::mutex> my_lock(_mutex);

    _restockClock.setElapsedTime();
    for (auto &item : _stock) {
        item.second += RESTOCK_NBR;
    }
}

template <typename IngredientType> bool Stock<IngredientType>::takeIngredients(IngredientType ingredient, size_t nbr)
{
    std::lock_guard<std::mutex> my_lock(_mutex);

    if (this->_stock[ingredient] < nbr)
        return false;
    this->_stock[ingredient] -= nbr;
    return true;
}

template <typename IngredientType> const std::unordered_map<IngredientType, size_t> Stock<IngredientType>::getStockList()
{
    std::lock_guard<std::mutex> my_lock(_mutex);
    const std::unordered_map<IngredientType, size_t> tempStock(this->_stock);

    return tempStock;
}

template class Stock<enum Pizzeria::PizzaIngredient>;