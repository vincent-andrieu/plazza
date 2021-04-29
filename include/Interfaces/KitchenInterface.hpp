/*
 * EPITECH PROJECT, 2021
 * Interfaces
 * File description:
 * KitchenInterface.hpp - Created: 26/04/2021
 */

#ifndef KITCHEN_INTERFACE_HPP
#define KITCHEN_INTERFACE_HPP

#include "Encapsulations/Process/Process.hpp"
#include "Order/Order.hpp"
#include "Encapsulations/Process/Process.hpp"

class IKitchen : public Process {
  public:
    virtual ~IKitchen() = default;
    virtual void cook() = 0;                          // while work
    [[nodiscard]] virtual bool isCooking() const = 0; // while is true, loop

  protected:
    [[nodiscard]] virtual Order receiveOrder() = 0; // from pipe
    virtual void addPendingOrder(const Order &order) = 0;
    virtual void sendFinishedOrders() = 0;
};

#endif