/*
 * EPITECH PROJECT, 2021
 * KitchenStatus
 * File description:
 * KitchenStatus.hpp - Created: 06/05/2021
 */

#ifndef KITCHEN_STATUS_HPP
#define KITCHEN_STATUS_HPP

#include <queue>
#include <string>
#include "Order/Order.hpp"
#include "Product/Pizza/Factory/Factory.hpp"
#include "Product/Product.hpp"
#include "Translator/Translator.hpp"

using namespace Pizzeria;

template <typename ProductType, typename ProductSize, typename ProductIngredientType> class KitchenStatus : public Serializer {
  public:
    KitchenStatus() = default;
    KitchenStatus(const std::queue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> &pendingOrders,
        const std::queue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> &finishedOrders,
        const std::unordered_map<ProductIngredientType, size_t> &stock);

    const std::queue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> &getPendingOrders() const;
    const std::queue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> &getFinishedOrders() const;
    const std::unordered_map<ProductIngredientType, size_t> &getStock() const;

  protected:
    const string SerializeToString() const;
    void SerializeFromString(const string &str);

  private:
    std::queue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> _pendingOrders;
    std::queue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> _finishedOrders;
    std::unordered_map<ProductIngredientType, size_t> _stock;
};

#endif