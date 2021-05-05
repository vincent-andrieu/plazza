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

template <typename IngredientType> class Stock {
  public:
    explicit Stock(double restockTime);
    ~Stock() = default;

    void restock();
    bool takeIngredients(IngredientType ingredient, double nbr);

  private:
    double _restockTime;
    std::time_t _restockClock; // TODO use std::chrono
    std::unordered_map<IngredientType, double> _stock;
    std::mutex _mutex;
};

#endif