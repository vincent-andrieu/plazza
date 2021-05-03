/*
 * EPITECH PROJECT, 2021
 * Kitchen
 * File description:
 * Kitchen.cpp - Created: 27/04/2021
 */

#include "Kitchen/Kitchen.hpp"
#include "TransportObjects/CommunicationType/CommunicationType.hpp"

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
        this->receiveOrder();
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
void Kitchen<ProductType, ProductSize, ProductIngredientType>::receiveOrder() const
{
    CommunicationType commType;

    this->receive(commType);

    switch (commType.getType()) {
        case ECommunicationType::ORDER:
            Order<IProduct<ProductType, ProductSize, ProductIngredientType>> order;

            this->waitingReceive(order);
            this->addPendingOrder(order);
            break;

        case ECommunicationType::STATUS:
            // TODO: Send back kitchen status
            break;

        default: break;
    };
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