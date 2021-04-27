/*
 * EPITECH PROJECT, 2021
 * Restaurant
 * File description:
 * Restaurant.cpp - Created: 27/04/2021
 */

#include "Restaurant.hpp"

Restaurant::Restaurant(double bakingTime, size_t cooksPerKitchen, size_t restockTime)
    : _isOpen(true), _bakingTime(bakingTime), _cooksPerKitchen(cooksPerKitchen), _restockTime(restockTime)
{
}

void Restaurant::distributeOrder(const Order &order)
{
    KitchenManage &selectedKitchen;
    size_t maxOrders = this->_cooksPerKitchen * 2;

    for (KitchenManage &kitchen : this->_kitchens) {
        if (kitchen.orders.size() < maxOrders) {
            maxOrders = kitchen.orders.size();
            selectedKitchen = kitchen;
        }
    }
    if (maxOrders < this->_cooksPerKitchen * 2) {
        sendOrder(selectedKitchen, order);
    } else {
        newKitchen(order);
    }
}

void Restaurant::newKitchen(const Order &order)
{
    Kitchen kitchen(this->_bakingTime, this->_cooksPerKitchen, this->_restockTime);
    KitchenManage kitchenManage;

    kitchenManage.kitchen = kitchen;
    if (kitchen.isParent())
        this->sendOrder(kitchenManage, order);
    else if (kitchen.isChild())
        kitchen.cook();
}

void Restaurant::sendOrder(KitchenManage &kitchenManage, const Order &order)
{
    kitchenManage.order.push(order);
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