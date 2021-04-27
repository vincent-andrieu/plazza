/*
 * EPITECH PROJECT, 2021
 * Kitchen
 * File description:
 * Kitchen.cpp - Created: 27/04/2021
 */

#include "Kitchen/Kitchen.hpp"

Kitchen::Kitchen(double bakingTime, size_t cooksPerKitchen, size_t restockTime)
    : _isCooking(true), _bakingTime(bakingTime), _cooksPerKitchen(cooksPerKitchen), _restockTime(restockTime)
{
    // TODO: Create threads per cooks
}

void Kitchen::cook()
{
    while (this->isCooking()) {
        Order &order = this->receiveOrder();
        this->addPendingOrder(order);
        this->sendFinishOrders();
        // TODO: Add restock
    }
}

bool Kitchen::isCooking() const
{
    return this->_isCooking;
}

Order &Kitchen::receiveOrder() const
{
    Order order;

    this->receive(order);
    return order;
}

void Kitchen::addPendingOrder(const Order order)
{
    this->_pendingOrders.push(order);
}

void Kitchen::sendFinishOrders()
{
    while (!this->_finishedOrders.empty()) {
        this->send(this->_finishedOrders.front());
        this->_finishedOrders.pop();
    }
}