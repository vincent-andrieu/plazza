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
#include "Product/Pizza/Factory/Factory.hpp"

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
Kitchen<ProductType, ProductSize, ProductIngredientType>::Kitchen(
    double bakingMultiplier, size_t cooksPerKitchen, double restockTime)
    : _lastAct(std::chrono::system_clock::now()), _stock(restockTime), _bakingMultiplier(bakingMultiplier),
      _cooksPerKitchen(cooksPerKitchen),
      _cooks(cooksPerKitchen,
          Cook<ProductType, ProductSize, ProductIngredientType>(_stock, _pendingOrders, _finishedOrders, [this]() {
              this->_sendStatus();
          }))
{
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
int Kitchen<ProductType, ProductSize, ProductIngredientType>::cook()
{
    this->_cooksStartCooking();
    while (this->isCooking()) {
        this->_receiveOrder();
        this->_sendFinishedOrders();
        this->_stock.restock();
        this->_destroyManage();
    }
    this->_cooksStopCooking();
    this->send(CommunicationType(ECommunicationType::KILL_CHILD));
    return EXIT_SUCCESS;
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
            Order<Product<ProductType, ProductSize, ProductIngredientType>> *order =
                new Order<Product<ProductType, ProductSize, ProductIngredientType>>();

            this->waitingReceive(*order);
            Product<ProductType, ProductSize, ProductIngredientType> product(
                Factory::callFactory(order->getOrder().getType(), order->getOrder().getSize(), this->_bakingMultiplier));
            order->setOrder(product);
            this->_addPendingOrder(*order);
        } break;

        case ECommunicationType::STATUS: this->_sendStatus(); break;

        default: break;
    };
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Kitchen<ProductType, ProductSize, ProductIngredientType>::_addPendingOrder(
    const Order<Product<ProductType, ProductSize, ProductIngredientType>> &order)
{
    this->_pendingOrders.push(order);
    this->_sendStatus();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Kitchen<ProductType, ProductSize, ProductIngredientType>::_sendFinishedOrders()
{
    bool doesUpdate = !this->_finishedOrders.empty();

    while (!this->_finishedOrders.empty()) {
        this->_communicationMutex.lock();
        this->send(CommunicationType(ECommunicationType::ORDER_PIZZA));
        this->send(this->_finishedOrders.getFront());
        this->_communicationMutex.unlock();
    }
    if (doesUpdate)
        this->_sendStatus();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Kitchen<ProductType, ProductSize, ProductIngredientType>::_sendStatus()
{
    this->_communicationMutex.lock();
    this->send(CommunicationType(ECommunicationType::STATUS));
    this->send(KitchenStatus<ProductType, ProductSize, ProductIngredientType>(
        this->_pendingOrders, this->_stock.getStockList(), this->getCookingOrders()));
    this->_communicationMutex.unlock();
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

    if (!this->_pendingOrders.empty() || !this->_finishedOrders.empty() || this->_isCookersCooking()) {
        this->_lastAct = std::chrono::system_clock::now();
    } else if (elapsedTime >= 5) {
        this->_isCooking = false;
    }
    if (!this->parentExists())
        this->_isCooking = false;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Kitchen<ProductType, ProductSize, ProductIngredientType>::_cooksStartCooking()
{
    for (auto &cook : _cooks) {
        cook.startWorking();
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Kitchen<ProductType, ProductSize, ProductIngredientType>::_cooksStopCooking()
{
    for (auto &cook : _cooks) {
        cook.stopWorking();
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
bool Kitchen<ProductType, ProductSize, ProductIngredientType>::_isCookersCooking() const
{
    for (const Cook<ProductType, ProductSize, ProductIngredientType> &cook : this->_cooks)
        if (cook.isCooking())
            return true;
    return false;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
const std::vector<Order<Product<ProductType, ProductSize, ProductIngredientType>>>
Kitchen<ProductType, ProductSize, ProductIngredientType>::getCookingOrders() const
{
    std::vector<Order<Product<ProductType, ProductSize, ProductIngredientType>>> isCookingOrders;

    for (const Cook<ProductType, ProductSize, ProductIngredientType> &cook : this->_cooks)
        if (cook.isCooking())
            isCookingOrders.push_back(Order<Product<ProductType, ProductSize, ProductIngredientType>>(cook.getCookingProduct()));

    return isCookingOrders;
}

template class Kitchen<Pizzeria::PizzaType, Pizzeria::PizzaSize, Pizzeria::PizzaIngredient>;