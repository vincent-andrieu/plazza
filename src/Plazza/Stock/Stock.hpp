/*
 * EPITECH PROJECT, 2021
 * Stock
 * File description:
 * Stock.hpp - Created: 28/04/2021
 */

#ifndef STOCK_HPP
#define STOCK_HPP

#include <ctime>
#include <unordered_map>
#include "enumPizza.hpp"
#include "Encapsulations/Mutex/Mutex.hpp"

#define DEFAULT_STOCK 5
#define RESTOCK_NBR   1

class Stock {
  public:
    Stock(size_t restockTime);
    ~Stock();

    void restock();
    bool takeIngredients(PizzaIngredient ingredient, size_t nbr);

  private:
    size_t _restockTime;
    std::time_t _restockClock;
    std::unordered_map<PizzaIngredient, size_t> _stock;
    Mutex _mutex;
};

#endif