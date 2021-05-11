/*
 * EPITECH PROJECT, 2021
 * Cook.hpp
 * File description:
 * Cook.hpp - Created: 26/04/2021
 */

#ifndef COOK_HPP
#define COOK_HPP

#include <memory>
#include <vector>
#include <thread>
#include "Interfaces/ICook.hpp"
#include "Product/Product.hpp"
#include "Encapsulations/LockedQueue/LockedQueue.hpp"
#include "Error/Error.hpp"

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
class Cook : public ICook<ProductType, ProductSize, ProductIngredientType> {
  public:
    Cook(Stock<ProductIngredientType> &stockPlace,
        LockedQueue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> &orderReceivePlace,
        LockedQueue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> &deliveryPlace);
    ~Cook();

    Cook(const Cook<ProductType, ProductSize, ProductIngredientType> &rhs);

    /**
     * @brief Start working
     * @details Start thread
     */
    void startWorking() override;

    /**
     * @brief Work
     * @details Wait for order, get an one, cook, deliver
     */
    void work() override;

    /**
     * @brief Check if the cook is cooking or has finished cooking but did not delivered yet
     * @return True if cooking, false otherwise
     */
    [[nodiscard]] bool isCooking() const override;

    /**
     * @brief Check if the cook is working
     * @return True if Working, false otherwise
     */
    [[nodiscard]] bool isWorking() const override;

    /**
     * @brief Stop working
     */
    void stopWorking() override;

    [[nodiscard]] const Product<ProductType, ProductSize, ProductIngredientType> &getCookingProduct() const;
    [[nodiscard]] Stock<ProductIngredientType> &getStockPlace() const;
    [[nodiscard]] LockedQueue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> &getOrderReceivePlace() const;
    [[nodiscard]] LockedQueue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> &getDeliveryPlace() const;

  protected:
    /**
     * @brief Start cooking a new product
     * @param type
     * @param size
     * @param ingredients
     */
    void cook(Product<ProductType, ProductSize, ProductIngredientType> order) override;

    void getIngredients(const std::vector<ProductIngredientType> &ingredients);

    /**
     * @brief check if has finished cooking
     * @throw If not cooking or finished cooking
     * @return True if finished cooking, false otherwise
     */
    [[nodiscard]] bool hasFinishedCooking() const override;

    /**
     * @brief Take order from order place
     * @return The order that is to be cooked
     */
    [[nodiscard]] Order<Product<ProductType, ProductSize, ProductIngredientType>> receiveOrder() const override;

    /**
     * @brief Deliver cooked order
     * @param product The product to deliver
     * @return True if delivery success, false otherwise
     */
    void deliverOrder() override;

    /**
     * @brief Get ingredient from stock
     * @param ingredient The ingredient to be taken from stock
     * @return True if ingredient was taken, false otherwise
     */
    bool pickIngredientInStock(const ProductIngredientType &ingredient) override;

  private:
    bool _isWorking{false};
    bool _isCooking{false};
    Product<ProductType, ProductSize, ProductIngredientType> _cookingProduct;
    Stock<ProductIngredientType> &_stockPlace;
    LockedQueue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> &_orderReceivePlace;
    LockedQueue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> &_deliveryPlace;

    std::thread _thread;
};

#endif