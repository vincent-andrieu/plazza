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
    : _bakingMultiplier(bakingTime), _cooksPerKitchen(cooksPerKitchen), _restockTime(restockTime), _reception(bakingTime)
{
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Restaurant<ProductType, ProductSize, ProductIngredientType>::lunchTime()
{
    string input = "lol";
    std::unique_ptr<CoreDisplay<ProductType, ProductSize, ProductIngredientType>> core =
        std::make_unique<CoreDisplay<ProductType, ProductSize, ProductIngredientType>>(
            Vector(1400, 900), Vector(9.95, 21.6), 300);

    core->setPrompt("$> ");
    while (this->isOpen() && core->isRunning()) {
        core->clear();
        core->printPrompt();
        core->printKitchen(this->_kitchens);
        input = core->getLine();
        if (input.length()) {
            try {
                this->_reception.receiveCommands(input);
                core->setError("");
            } catch (const ReceptionError &e) {
                core->setError(string(e.getComponent()) + ": " + string(e.what()));
            }
        }
        core->printError();
        Pizza pizza;
        Order<IProduct<ProductType, ProductSize, ProductIngredientType>> order(pizza);
        if (this->_reception.getOrder(order)) {
            this->_distributeOrder(order);
        }
        this->_retreiveOrders();
        core->update();
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
        this->_sendOrder(this->_kitchens[selectedKitchenIndex], order);
    } else {
        this->_newKitchen(order);
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
    kitchenManage.kitchen.send(CommunicationType(ECommunicationType::ORDER_PIZZA));
    kitchenManage.kitchen.send(order);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Restaurant<ProductType, ProductSize, ProductIngredientType>::_retreiveOrders()
{
    for (KitchenManage<ProductType, ProductSize, ProductIngredientType> &kitchenManage : this->_kitchens)
        this->_retreiveOrder(kitchenManage);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Restaurant<ProductType, ProductSize, ProductIngredientType>::_retreiveOrder(
    KitchenManage<ProductType, ProductSize, ProductIngredientType> &kitchenManage)
{
    CommunicationType commType;

    if (kitchenManage.kitchen.receive(commType) == false)
        return;
    switch (commType.getType()) {
        case ECommunicationType::ORDER_PIZZA: {
            Pizza pizza = Pizza();
            Order<IProduct<ProductType, ProductSize, ProductIngredientType>> order(pizza);

            kitchenManage.kitchen.waitingReceive(order);
            this->_reception.sendOrder(order);

            kitchenManage.orders.remove_if([order](Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &elemOrder) {
                return order.getOrder() == elemOrder.getOrder();
            });
        } break;

        default: break;
    };
}

template class Restaurant<PizzaType, PizzaSize, PizzaIngredient>;