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
#include "Interfaces/ProductInterface.hpp"

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
class IReception : public CommandInterpreter {
  public:
    virtual ~IReception() = default;
    [[nodiscard]] virtual bool doesGetPendingOrders() const = 0;
    [[nodiscard]] virtual bool getOrder(Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &order) = 0;
    virtual void sendOrder(const Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &order) = 0;
    virtual void receiveCommands(const string &cmd) = 0;
};

#endif