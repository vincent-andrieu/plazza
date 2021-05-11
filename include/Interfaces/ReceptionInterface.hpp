/*
 * EPITECH PROJECT, 2021
 * Interfaces
 * File description:
 * ReceptionInterface.hpp - Created: 26/04/2021
 */

#ifndef RECEPTION_INTERFACE_HPP
#define RECEPTION_INTERFACE_HPP

#include <memory>
#include "CommandInterpreter/CommandInterpreter.hpp"
#include "Order/Order.hpp"
#include "Plazza.hpp"
#include "Product/Product.hpp"
#include "Kitchen/KitchenStatus/KitchenStatus.hpp"

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
class IReception : public CommandInterpreter {
  public:
    virtual ~IReception() = default;
    virtual void sendOrder(const Order<Product<ProductType, ProductSize, ProductIngredientType>> &order) = 0;
    virtual void sendKitchenStatus(const KitchenStatus<PizzaType, PizzaSize, PizzaIngredient> &kitchenStatus) = 0;
    virtual void sendKitchenClosed() = 0;
    virtual void receiveCommands(
        const string &cmd, std::queue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> &orderList) = 0;
};

#endif