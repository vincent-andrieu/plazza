/*
 * EPITECH PROJECT, 2021
 * Interfaces
 * File description:
 * KitchenInterface.hpp - Created: 26/04/2021
 */

#ifndef KITCHEN_INTERFACE_HPP
#define KITCHEN_INTERFACE_HPP

#include "Order/Order.hpp"

class IKitchen {
  public:
    virtual ~IKitchen() = default;
    virtual void cook() = 0;      // while work
    virtual bool isCooking() = 0; // while is true, loop

  protected:
    virtual void receiveOrder() = 0; // from pipe
    virtual bool isOrderReady(Order order) = 0;
    virtual void sendOrder() = 0; // through pipe
    virtual void assignOrder(Order order, Cook cook) = 0;
    virtual void restock() = 0;
};

#endif