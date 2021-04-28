/*
 * EPITECH PROJECT, 2021
 * Interfaces
 * File description:
 * ReceptionInterface.hpp - Created: 26/04/2021
 */

#ifndef RECEPTION_INTERFACE_HPP
#define RECEPTION_INTERFACE_HPP

#include "CommandInterpreter/CommandInterpreter.hpp"
#include "Order/Order.hpp"
#include "Plazza.hpp"

class IReception : public CommandInterpreter {
  public:
    virtual ~IReception() = default;
    virtual bool doesGetPendingOrders() const = 0;
    virtual const Order getOrder() const = 0;
    virtual void sendOrder(const Order &order) const = 0;

  protected:
    virtual void receiveCommands(const string cmd) = 0; // take from cmdLine
};

#endif