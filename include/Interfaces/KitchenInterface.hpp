/*
 * EPITECH PROJECT, 2021
 * Interfaces
 * File description:
 * KitchenInterface.hpp - Created: 26/04/2021
 */

#ifndef KITCHEN_INTERFACE_HPP
#define KITCHEN_INTERFACE_HPP

#include "CommandInterpreter/CommandInterpreter.hpp"
#include "Order/Order.hpp"

class IKitchen : CommandInterpreter {
  public:
    virtual ~IKitchen() = default;
    virtual bool isOpen() const = 0;
    virtual Order getOrder() const = 0;
    virtual void sayStatus() = 0;

  protected:
    void receiveCommand() = 0; // take from cmdLine
};

#endif