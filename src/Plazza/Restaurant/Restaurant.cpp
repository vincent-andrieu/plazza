/*
 * EPITECH PROJECT, 2021
 * Restaurant
 * File description:
 * Restaurant.cpp - Created: 27/04/2021
 */

#include "Restaurant.hpp"
#include "TransportObjects/CommunicationType/CommunicationType.hpp"

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
Restaurant<ProductType, ProductSize, ProductIngredientType>::Restaurant(
    double bakingTime, size_t cooksPerKitchen, size_t restockTime)
    : _bakingMultiplier(bakingTime), _cooksPerKitchen(cooksPerKitchen), _restockTime(restockTime)
{
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Restaurant<ProductType, ProductSize, ProductIngredientType>::lunchTime()
{
    while (this->isOpen()) {
        const Order<IProduct<ProductType, ProductSize, ProductIngredientType>> order = this->_reception.getOrder();
        this->_distributeOrder(order);
        this->_retreiveOrders();
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
bool Restaurant<ProductType, ProductSize, ProductIngredientType>::isOpen() const
{
    return this->_isOpen;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Restaurant<ProductType, ProductSize, ProductIngredientType>::_distributeOrder(
    const Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &order)
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
        _sendOrder(this->_kitchens[selectedKitchenIndex], order);
    } else {
        _newKitchen(order);
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Restaurant<ProductType, ProductSize, ProductIngredientType>::_newKitchen(
    const Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &order)
{
    Kitchen<ProductType, ProductSize, ProductIngredientType> kitchen(
        this->_bakingMultiplier, this->_cooksPerKitchen, this->_restockTime);
    KitchenManage<ProductType, ProductSize, ProductIngredientType> kitchenManage = {kitchen, {}};

    if (kitchen.isParent())
        this->_sendOrder(kitchenManage, order);
    else if (kitchen.isChild())
        kitchen.cook();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Restaurant<ProductType, ProductSize, ProductIngredientType>::_sendOrder(
    KitchenManage<ProductType, ProductSize, ProductIngredientType> &kitchenManage,
    const Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &order)
{
    kitchenManage.orders.push_back(order);
    kitchenManage.kitchen.send(CommunicationType(ECommunicationType::ORDER));
    kitchenManage.kitchen.send(order);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Restaurant<ProductType, ProductSize, ProductIngredientType>::_retreiveOrders()
{
    for (const KitchenManage<ProductType, ProductSize, ProductIngredientType> &kitchenManage : this->_kitchens)
        this->_retreiveOrder(kitchenManage.kitchen);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Restaurant<ProductType, ProductSize, ProductIngredientType>::_retreiveOrder(
    const Kitchen<ProductType, ProductSize, ProductIngredientType> &kitchen)
{
    CommunicationType commType;

    if (!kitchen.receive(commType))
        return;
    switch (commType.getType()) {
        case ECommunicationType::ORDER:
            Order<IProduct<ProductType, ProductSize, ProductIngredientType>> order;

            kitchen.waitingReceive(order);
            this->_reception.sendOrder(order);

        default: break;
    };
}