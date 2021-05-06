/*
 * EPITECH PROJECT, 2021
 * Stock
 * File description:
 * Stock.hpp - Created: 28/04/2021
 */

#ifndef STOCK_HPP
#define STOCK_HPP

#include <mutex>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include "Clock/Clock.hpp"

#define DEFAULT_STOCK 5
#define RESTOCK_NBR   1

template <typename IngredientType> class Stock {
  public:
    explicit Stock(double restockTime);
    Stock(double restockTime, const std::vector<IngredientType> &stackableIngredients);
    ~Stock() = default;

    [[nodiscard]] Stock<IngredientType> &operator=(const Stock<IngredientType> &rhs);

    /**
     * @brief Add ingredient to stock
     * @details If ingredient exists in the stock, do nothing, otherwise, add it to the stackable ingredients
     *
     * @param ingredient The ingredient to be stocked
     */
    void addIngredient(const IngredientType &ingredient);

    /**
     * @brief Check whether or not it is time to restock
     * @return True if it is time to restock, false otherwise
     */
    [[nodiscard]] bool isRestockTime() const;

    /**
     * @brief Fill the stock with one more item per type of ingredient
     */
    void restock();

    /**
     * @brief Return true if can take ingredients. Otherwise return false.
     *
     * @param ingredient The ingredient to be taken
     * @param nbr The number of ingredients to be taken
     * @return bool True the ingredient was taken, false otherwise
     */
    [[nodiscard]] bool takeIngredients(IngredientType ingredient, size_t nbr);

  private:
    double _restockTime;
    Clock _restockClock;
    std::unordered_map<IngredientType, size_t> _stock;
    std::mutex _mutex;
};

#endif