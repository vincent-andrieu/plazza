/*
 * EPITECH PROJECT, 2021
 * Restaurant
 * File description:
 * Restaurant.cpp - Created: 27/04/2021
 */

#include "Restaurant.hpp"

Restaurant::Restaurant(double bakingTime, size_t cooksPerKitchen, size_t restockTime)
    : _isOpen(true), _bakingMultiplier(bakingTime), _cooksPerKitchen(cooksPerKitchen), _restockTime(restockTime)
{
}

void Restaurant::lunchTime()
{
    while (this->isOpen()) {
        const Order order = this->_reception.getOrder();
        this->distributeOrder(order);
        this->retreiveOrders();
    }
}

bool Restaurant::isOpen() const
{
    this->_isOpen;
}

void Restaurant::distributeOrder(const Order &order)
{
    size_t selectedKitchenIndex;
    size_t maxOrders = this->_cooksPerKitchen * 2;

    for (size_t i = 0; i < this->_kitchens.size(); i++) {
        if (this->_kitchens[i].orders.size() < maxOrders) {
            maxOrders = this->_kitchens[i].orders.size();
            selectedKitchenIndex = i;
        }
    }
    if (maxOrders < this->_cooksPerKitchen * 2) {
        sendOrder(this->_kitchens[selectedKitchenIndex], order);
    } else {
        newKitchen(order);
    }
}

void Restaurant::newKitchen(const Order &order)
{
    Kitchen kitchen(this->_bakingMultiplier, this->_cooksPerKitchen, this->_restockTime);
    KitchenManage kitchenManage = {kitchen, {}};

    if (kitchen.isParent())
        this->sendOrder(kitchenManage, order);
    else if (kitchen.isChild())
        kitchen.cook();
}

void Restaurant::sendOrder(KitchenManage &kitchenManage, const Order &order)
{
    kitchenManage.orders.push_back(order);
    kitchenManage.kitchen.send(order);
}

void Restaurant::retreiveOrders() const
{
    for (const KitchenManage &kitchenManage : this->_kitchens)
        this->_retreiveOrder(kitchenManage.kitchen);
}

void Restaurant::_retreiveOrder(const Kitchen &kitchen) const
{
    Order order;

    kitchen.receive(order);
    this->_reception.sendOrder(order);
}