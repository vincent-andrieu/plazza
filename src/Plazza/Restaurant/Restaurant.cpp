/*
 * EPITECH PROJECT, 2021
 * Restaurant
 * File description:
 * Restaurant.cpp - Created: 27/04/2021
 */

#include "Restaurant.hpp"
#include "TransportObjects/CommunicationType/CommunicationType.hpp"
#include "Product/Pizza/Pizza.hpp"

using namespace Pizzeria;

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
Restaurant<ProductType, ProductSize, ProductIngredientType>::Restaurant(
    double bakingTime, size_t cooksPerKitchen, size_t restockTime)
    : _bakingMultiplier(bakingTime), _cooksPerKitchen(cooksPerKitchen), _restockTime(restockTime),
      _reception(
          bakingTime,
          [this]() {
              return this->askKitchensStatus();
          },
          [this]() {
              this->close();
          })
{
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Restaurant<ProductType, ProductSize, ProductIngredientType>::lunchTime()
{
    string input;
    CoreDisplay<ProductType, ProductSize, ProductIngredientType> core(Vector(1400, 900), Vector(9.95, 21.6), 300);
    std::queue<Order<AProduct<PizzaType, PizzaSize, PizzaIngredient>>> currentOrderQueue;

    core.setPrompt("$> ");
    while (this->isOpen() && core.isRunning()) {
        core.clear();
        core.printPrompt();
        // core.printKitchen(this->_kitchens);
        input = core.getLine();
        if (input.length()) {
            try {
                this->_reception.receiveCommands(input, currentOrderQueue);
                core.setError("");
            } catch (const ReceptionError &e) {
                core.setError(e.getComponent() + ": " + e.what());
            }
        }
        core.printError();
        while (!currentOrderQueue.empty()) {
            this->_distributeOrder(currentOrderQueue.front());
            currentOrderQueue.pop();
        }
        this->_retreiveOrders();
        core.update();
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
bool Restaurant<ProductType, ProductSize, ProductIngredientType>::isOpen() const
{
    return this->_isOpen;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Restaurant<ProductType, ProductSize, ProductIngredientType>::close()
{
    this->_isOpen = false;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Restaurant<ProductType, ProductSize, ProductIngredientType>::_distributeOrder(
    const Order<AProduct<ProductType, ProductSize, ProductIngredientType>> &order)
{
    std::_List_iterator<KitchenManage<ProductType, ProductSize, ProductIngredientType>> selectedKitchenIndex;
    size_t maxOrders = this->_cooksPerKitchen * 2;

    for (std::_List_iterator<KitchenManage<ProductType, ProductSize, ProductIngredientType>> it = this->_kitchens.begin();
         it != this->_kitchens.end(); it++) {
        if (it->orders.size() < maxOrders) {
            maxOrders = it->orders.size();
            selectedKitchenIndex = it;
        }
    }
    if (maxOrders < this->_cooksPerKitchen * 2) {
        this->_sendOrder(*selectedKitchenIndex, order);
    } else {
        this->_newKitchen(order);
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Restaurant<ProductType, ProductSize, ProductIngredientType>::_newKitchen(
    const Order<AProduct<ProductType, ProductSize, ProductIngredientType>> &order)
{
    Kitchen<ProductType, ProductSize, ProductIngredientType> kitchen(
        this->_bakingMultiplier, this->_cooksPerKitchen, this->_restockTime);
    KitchenManage<ProductType, ProductSize, ProductIngredientType> kitchenManage = {
        kitchen, {}, KitchenStatus<ProductType, ProductSize, ProductIngredientType>()};

    if (kitchen.isParent()) {
        this->_sendOrder(kitchenManage, order);
        this->_kitchens.push_back(kitchenManage);
    } else if (kitchen.isChild())
        kitchen.cook();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Restaurant<ProductType, ProductSize, ProductIngredientType>::_sendOrder(
    KitchenManage<ProductType, ProductSize, ProductIngredientType> &kitchenManage,
    const Order<AProduct<ProductType, ProductSize, ProductIngredientType>> &order)
{
    kitchenManage.orders.push_back(order);
    kitchenManage.kitchen.send(CommunicationType(ECommunicationType::ORDER_PIZZA));
    kitchenManage.kitchen.send(order);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Restaurant<ProductType, ProductSize, ProductIngredientType>::askKitchensStatus() const
{
    for (const KitchenManage<ProductType, ProductSize, ProductIngredientType> &kitchenManage : this->_kitchens) {
        kitchenManage.kitchen.send(CommunicationType(ECommunicationType::STATUS));
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Restaurant<ProductType, ProductSize, ProductIngredientType>::_retreiveOrders()
{
    for (std::_List_iterator<KitchenManage<ProductType, ProductSize, ProductIngredientType>> it = this->_kitchens.begin();
         it != this->_kitchens.end(); it++) {
        if (this->_retreiveOrder(*it))
            this->_kitchens.erase(it);
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
bool Restaurant<ProductType, ProductSize, ProductIngredientType>::_retreiveOrder(
    KitchenManage<ProductType, ProductSize, ProductIngredientType> &kitchenManage)
{
    CommunicationType commType;

    if (kitchenManage.kitchen.receive(commType) == false)
        return false;
    switch (commType.getType()) {
        case ECommunicationType::ORDER_PIZZA: {
            Pizza pizza = Pizza();
            Order<AProduct<ProductType, ProductSize, ProductIngredientType>> order(pizza);

            kitchenManage.kitchen.waitingReceive(order);
            this->_reception.sendOrder(order);

            kitchenManage.orders.remove_if([order](Order<AProduct<ProductType, ProductSize, ProductIngredientType>> &elemOrder) {
                return order.getOrder() == elemOrder.getOrder();
            });
        } break;

        case ECommunicationType::STATUS: {
            kitchenManage.kitchen.waitingReceive(kitchenManage.kitchenStatus);
            this->_reception.sendKitchenStatus(kitchenManage.kitchenStatus);
        } break;

        case ECommunicationType::KILL_CHILD: {
            kitchenManage.kitchen.killChild();
            return true;
        } break;
        default: break;
    };
    return false;
}

template class Restaurant<PizzaType, PizzaSize, PizzaIngredient>;