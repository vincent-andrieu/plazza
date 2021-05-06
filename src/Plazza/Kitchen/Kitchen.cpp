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
    double bakingMultiplier, size_t cooksPerKitchen, double restockTime)
    : _lastAct(std::chrono::system_clock::now()), _stock(restockTime), _bakingMultiplier(bakingMultiplier), _cooksPerKitchen(cooksPerKitchen)
{
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Kitchen<ProductType, ProductSize, ProductIngredientType>::cook()
{
    // TODO: Create threads per cooks

    while (this->isCooking()) {
        this->_receiveOrder();
        this->_sendFinishedOrders();
        this->_stock.restock();
        this->_destroyManage();
    }

    this->send(CommunicationType(ECommunicationType::KILL_CHILD));
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
    this->_pendingOrders.push(order);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Kitchen<ProductType, ProductSize, ProductIngredientType>::_sendFinishedOrders()
{
    while (!this->_finishedOrders.empty()) {
        this->send(CommunicationType(ECommunicationType::ORDER_PIZZA));
        this->send(this->_finishedOrders.getFront());
    }
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

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Kitchen<ProductType, ProductSize, ProductIngredientType>::_destroyManage()
{
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    size_t elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->_lastAct).count() / 1000;

    if (this->_pendingOrders.queue.size() || this->_finishedOrders.queue.size()) {
        this->_lastAct = std::chrono::system_clock::now();
        return;
    } else if (elapsedTime >= 5)
        this->_isCooking = false;
}

template class Kitchen<PizzaType, PizzaSize, PizzaIngredient>;