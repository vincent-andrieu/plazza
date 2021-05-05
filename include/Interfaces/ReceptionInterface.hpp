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
#include "Product/AProduct.hpp"

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
class IReception : public CommandInterpreter {
  public:
    virtual ~IReception() = default;
    virtual void sendOrder(const Order<AProduct<ProductType, ProductSize, ProductIngredientType>> &order) const = 0;
    virtual void receiveCommands(const string &cmd,
        std::queue<std::unique_ptr<Order<AProduct<ProductType, ProductSize, ProductIngredientType>>>> &orderList) = 0;
};

#endif