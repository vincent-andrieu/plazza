/*
 * EPITECH PROJECT, 2021
 * Kitchen
 * File description:
 * Kitchen.cpp - Created: 27/04/2021
 */

#include "Kitchen/Kitchen.hpp"

Kitchen::Kitchen(double bakingTime, size_t cooksPerKitchen, size_t restockTime)
    : _isCooking(true), _bakingTime(bakingTime), _cooksPerKitchen(cooksPerKitchen), _stock(restockTime)
{
    // TODO: Create threads per cooks
}

void Kitchen::cook()
{
    while (this->isCooking()) {
        Order &order = this->receiveOrder();
        this->addPendingOrder(order);
        this->sendFinishOrders();
        this->_stock.restock();
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
    this->_pendingOrders.mutex.lock();
    this->_pendingOrders.queue.push(order);
    this->_pendingOrders.mutex.unlock();
}

void Kitchen::sendFinishOrders()
{
    this->_finishedOrders.mutex.lock();
    while (!this->_finishedOrders.queue.empty()) {
        this->send(this->_finishedOrders.queue.front());
        this->_finishedOrders.queue.pop();
    }
    this->_finishedOrders.mutex.unlock();
}