/*
 * EPITECH PROJECT, 2021
 * Kitchen
 * File description:
 * Kitchen.cpp - Created: 27/04/2021
 */

#include "Kitchen/Kitchen.hpp"
#include "TransportObjects/CommunicationType/CommunicationType.hpp"
#include "Product/Pizza/Pizza.hpp"
#include "Kitchen/KitchenStatus/KitchenStatus.hpp"

using namespace Pizzeria;

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
        this->_receiveOrder();
        this->_sendFinishedOrders();
        this->_stock.restock();
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
bool Kitchen<ProductType, ProductSize, ProductIngredientType>::isCooking() const
{
    return this->_isCooking;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Kitchen<ProductType, ProductSize, ProductIngredientType>::_receiveOrder()
{
    CommunicationType commType;

    if (!this->receive(commType))
        return;

    switch (commType.getType()) {
        case ECommunicationType::ORDER_PIZZA: {
            Pizza pizza = Pizza();
            Order<AProduct<ProductType, ProductSize, ProductIngredientType>> order(pizza);

            this->waitingReceive(order);
            this->_addPendingOrder(order);
            break;
        }

        case ECommunicationType::STATUS: {
            this->_pendingOrders.mutex.lock();
            this->_finishedOrders.mutex.lock();
            this->send(KitchenStatus<ProductType, ProductSize, ProductIngredientType>(
                this->_pendingOrders.queue, this->_finishedOrders.queue, this->_stock.getStockList()));
            this->_pendingOrders.mutex.unlock();
            this->_finishedOrders.mutex.unlock();
            break;
        }

        default: break;
    };
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Kitchen<ProductType, ProductSize, ProductIngredientType>::_addPendingOrder(
    const Order<AProduct<ProductType, ProductSize, ProductIngredientType>> &order)
{
    this->_pendingOrders.mutex.lock();
    this->_pendingOrders.queue.push(order);
    this->_pendingOrders.mutex.unlock();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Kitchen<ProductType, ProductSize, ProductIngredientType>::_sendFinishedOrders()
{
    this->_finishedOrders.mutex.lock();
    while (!this->_finishedOrders.queue.empty()) {
        this->send(CommunicationType(ECommunicationType::ORDER_PIZZA));
        this->send(this->_finishedOrders.queue.front());
        this->_finishedOrders.queue.pop();
    }
    this->_finishedOrders.mutex.unlock();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
size_t Kitchen<ProductType, ProductSize, ProductIngredientType>::getNbCooks() const
{
    return this->_cooksPerKitchen;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
double Kitchen<ProductType, ProductSize, ProductIngredientType>::getBakingMultiplier() const
{
    return this->_bakingMultiplier;
}

template class Kitchen<PizzaType, PizzaSize, PizzaIngredient>;