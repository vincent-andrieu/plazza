/*
 * EPITECH PROJECT, 2021
 * Kitchen
 * File description:
 * Kitchen.cpp - Created: 27/04/2021
 */

#include "Kitchen/Kitchen.hpp"

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
Kitchen<ProductType, ProductSize, ProductIngredientType>::Kitchen(
    double bakingMultiplier, size_t cooksPerKitchen, size_t restockTime)
    : _stock(restockTime), _bakingMultiplier(bakingMultiplier), _cooksPerKitchen(cooksPerKitchen)
{
    // TODO: Create threads per cooks
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Kitchen<ProductType, ProductSize, ProductIngredientType>::cook()
{
    while (this->isCooking()) {
        const Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &order = this->receiveOrder();
        this->addPendingOrder(order);
        this->sendFinishedOrders();
        this->_stock.restock();
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
bool Kitchen<ProductType, ProductSize, ProductIngredientType>::isCooking() const
{
    return this->_isCooking;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
Order<IProduct<ProductType, ProductSize, ProductIngredientType>>
Kitchen<ProductType, ProductSize, ProductIngredientType>::receiveOrder() const
{
    Order<IProduct<ProductType, ProductSize, ProductIngredientType>> order;

    this->receive(order);
    return order;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Kitchen<ProductType, ProductSize, ProductIngredientType>::addPendingOrder(
    const Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &order)
{
    this->_pendingOrders.mutex.lock();
    this->_pendingOrders.queue.push(order);
    this->_pendingOrders.mutex.unlock();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Kitchen<ProductType, ProductSize, ProductIngredientType>::sendFinishedOrders()
{
    this->_finishedOrders.mutex.lock();
    while (!this->_finishedOrders.queue.empty()) {
        this->send(this->_finishedOrders.queue.front());
        this->_finishedOrders.queue.pop();
    }
    this->_finishedOrders.mutex.unlock();
}