/*
 * EPITECH PROJECT, 2021
 * KitchenStatus
 * File description:
 * KitchenStatus.cpp - Created: 06/05/2021
 */

#include "Kitchen/KitchenStatus/KitchenStatus.hpp"

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
KitchenStatus<ProductType, ProductSize, ProductIngredientType>::KitchenStatus(
    const std::queue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> pendingOrders,
    const std::queue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> finishedOrders,
    const std::unordered_map<ProductIngredientType, size_t> stock)
    : Serializer(sizeof(KitchenStatus)), _pendingOrders(pendingOrders), _finishedOrders(finishedOrders), _stock(stock)
{
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
const std::queue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> &
KitchenStatus<ProductType, ProductSize, ProductIngredientType>::getPendingOrders() const
{
    return this->_pendingOrders;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
const std::queue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> &
KitchenStatus<ProductType, ProductSize, ProductIngredientType>::getFinishedOrders() const
{
    return this->_finishedOrders;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
const std::unordered_map<ProductIngredientType, size_t> &
KitchenStatus<ProductType, ProductSize, ProductIngredientType>::getStock() const
{
    return this->_stock;
}

template class KitchenStatus<Pizzeria::PizzaType, Pizzeria::PizzaSize, Pizzeria::PizzaIngredient>;