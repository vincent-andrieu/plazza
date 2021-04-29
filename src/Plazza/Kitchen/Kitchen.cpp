/*
 * EPITECH PROJECT, 2021
 * Kitchen
 * File description:
 * Kitchen.cpp - Created: 27/04/2021
 */

#include "Kitchen/Kitchen.hpp"

Kitchen::Kitchen(double bakingMultiplier, size_t cooksPerKitchen, size_t restockTime)
    : _stock(restockTime), _isCooking(true), _bakingMultiplier(bakingMultiplier), _cooksPerKitchen(cooksPerKitchen)
{
    // TODO: Create threads per cooks
}

Kitchen::~Kitchen() = default;

void Kitchen::cook()
{
    while (this->isCooking()) {
        const Order &order = this->receiveOrder();
        this->addPendingOrder(order);
        this->sendFinishedOrders();
        this->_stock.restock();
    }
}

bool Kitchen::isCooking() const
{
    return this->_isCooking;
}

Order Kitchen::receiveOrder() const
{
    Order order;

    this->receive(order);
    return order;
}

void Kitchen::addPendingOrder(const Order &order)
{
    this->_pendingOrders.mutex.lock();
    this->_pendingOrders.queue.push(order);
    this->_pendingOrders.mutex.unlock();
}

void Kitchen::sendFinishedOrders()
{
    this->_finishedOrders.mutex.lock();
    while (!this->_finishedOrders.queue.empty()) {
        this->send(this->_finishedOrders.queue.front());
        this->_finishedOrders.queue.pop();
    }
    this->_finishedOrders.mutex.unlock();
}