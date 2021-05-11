/*
 * EPITECH PROJECT, 2021
 * Interfaces
 * File description:
 * CookInterface.hpp - Created: 26/04/2021
 */

#ifndef COOK_INTERFACE_HPP
#define COOK_INTERFACE_HPP

#include <memory>
#include <queue>
#include "Product/Product.hpp"
#include "Stock/Stock.hpp"
#include "Order/Order.hpp"

template <typename ProductType, typename ProductSize, typename ProductIngredientType> class ICook {
  public:
    virtual ~ICook() = default;

    /**
     * @brief Start working
     * @details Start thread
     */
    virtual void startWorking() = 0;

    /**
     * @brief Start working
     * @details Wait for order, get an one, cook, deliver
     */
    virtual void work() = 0;

    /**
     * @brief Check if the cook is cooking or has finished cooking but did not delivered yet
     * @return True if cooking, false otherwise
     */
    [[nodiscard]] virtual bool isCooking() const = 0;

    /**
     * @brief Check if the cook is working
     * @return True if Working, false otherwise
     */
    [[nodiscard]] virtual bool isWorking() const = 0;

    /**
     * @brief Stop working
     */
    virtual void stopWorking() = 0;

  protected:
    /**
     * @brief Start cooking a new product
     * @param type
     * @param size
     * @param ingredients
     */
    virtual void cook(Product<ProductType, ProductSize, ProductIngredientType> order) = 0;

    /**
     * @brief check if has finished cooking
     * @throw If not cooking or finished cooking
     * @return True if finished cooking, false otherwise
     */
    [[nodiscard]] virtual bool hasFinishedCooking() const = 0;

    /**
     * @brief Take order from order place
     * @return The order that is to be cooked
     */
    [[nodiscard]] virtual Order<Product<ProductType, ProductSize, ProductIngredientType>> receiveOrder() const = 0;

    /**
     * @brief Deliver cooked order
     * @param product The product to deliver
     * @return True if delivery success, false otherwise
     */
    virtual void deliverOrder() = 0;

    /**
     * @brief Get ingredient from stock
     * @param ingredient The ingredient to be taken from stock
     * @return True if ingredient was taken, false otherwise
     */
    virtual bool pickIngredientInStock(const ProductIngredientType &ingredient) = 0;
};

#endif