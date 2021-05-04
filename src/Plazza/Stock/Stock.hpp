/*
 * EPITECH PROJECT, 2021
 * Stock
 * File description:
 * Stock.hpp - Created: 28/04/2021
 */

#ifndef STOCK_HPP
#define STOCK_HPP

#include <ctime>
#include <mutex>
#include <unordered_map>
#include "enumPizza.hpp"

#define DEFAULT_STOCK 5
#define RESTOCK_NBR   1

using namespace Pizzeria;

template <typename IngredientType> class Stock {
  public:
    Stock(size_t restockTime);
    ~Stock() = default;

    void restock();
    bool takeIngredients(IngredientType ingredient, size_t nbr);

  private:
    size_t _restockTime;
    std::time_t _restockClock; // TODO use std::chrono
    std::unordered_map<IngredientType, size_t> _stock;
    std::mutex _mutex;
};

#endif