/*
 * EPITECH PROJECT, 2021
 * Cook.hpp
 * File description:
 * Cook.hpp - Created: 26/04/2021
 */

#ifndef COOK_HPP
#define COOK_HPP

#include <memory>
#include "Interfaces/ICook.hpp"
#include "Interfaces/ProductInterface.hpp"
#include "Encapsulations/LockedQueue/LockedQueue.hpp"
#include "Error/Error.hpp"

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
class Cook : public ICook<ProductType, ProductSize, ProductIngredientType> {
  public:
    Cook(Stock<ProductIngredientType> &stockPlace,
        LockedQueue<Order<std::shared_ptr<IProduct<ProductType, ProductSize, ProductIngredientType>>>> &orderReceivePlace,
        LockedQueue<Order<std::shared_ptr<IProduct<ProductType, ProductSize, ProductIngredientType>>>> &deliveryPlace);
    ~Cook() = default;

    /**
     * @brief Start working
     * @details Wait for order, get an one, cook, deliver
     */
    void startWorking() override;

    /**
     * @brief Set the place where the cook will search goods when needed
     * @param stockPlace The stock place
     */
    void setStockPlace(Stock<ProductIngredientType> &stockPlace) override;

    /**
     * @brief Set the place where the cook will get new order to cook
     * @param orderReceivePlace The order check place
     */
    void setOrderReceivePlace(
        LockedQueue<Order<std::shared_ptr<IProduct<ProductType, ProductSize, ProductIngredientType>>>> &orderReceivePlace)
        override;

    /**
     * @brief Set the place where the cook will deliver cooked orders
     * @param deliveryPlace The delivery place
     */
    void setDeliveryPlace(
        LockedQueue<Order<std::shared_ptr<IProduct<ProductType, ProductSize, ProductIngredientType>>>> &deliveryPlace) override;

    /**
     * @brief Check if the cook is cooking or has finished cooking but did not delivered yet
     * @return True if cooking, false otherwise
     */
    [[nodiscard]] bool isCooking() const override;

    /**
     * @brief Stop working
     */
    void stopWorking() override;

  protected:
    /**
     * @brief Start cooking a new product
     * @param type
     * @param size
     * @param ingredients
     */
    void cook(Order<std::shared_ptr<IProduct<ProductType, ProductSize, ProductIngredientType>>> order) override;

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
    [[nodiscard]] Order<std::shared_ptr<IProduct<ProductType, ProductSize, ProductIngredientType>>> receiveOrder() const override;

    /**
     * @brief Deliver cooked order
     * @param product The product to deliver
     * @return True if delivery success, false otherwise
     */
    void deliverOrder() const override;

    /**
     * @brief Get ingredient from stock
     * @param ingredient The ingredient to be taken from stock
     * @return True if ingredient was taken, false otherwise
     */
    bool pickIngredientInStock(const ProductIngredientType &ingredient) override;

  private:
    bool _isWorking{false};
    bool _isCooking{false};
    std::shared_ptr<IProduct<ProductType, ProductSize, ProductIngredientType>> _cookingProduct{nullptr};

    Stock<ProductIngredientType> &_stockPlace;
    LockedQueue<Order<std::shared_ptr<IProduct<ProductType, ProductSize, ProductIngredientType>>>> &_orderReceivePlace;
    LockedQueue<Order<std::shared_ptr<IProduct<ProductType, ProductSize, ProductIngredientType>>>> &_deliveryPlace;
};

#endif