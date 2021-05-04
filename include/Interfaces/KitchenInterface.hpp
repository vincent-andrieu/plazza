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
#include "Interfaces/ProductInterface.hpp"

template <typename ProductType, typename ProductSize, typename ProductIngredientType> class IKitchen {
  public:
    virtual ~IKitchen() = default;
    virtual void cook() = 0;                          // while work
    [[nodiscard]] virtual bool isCooking() const = 0; // while is true, loop
    [[nodiscard]] virtual size_t getNbCooks() const = 0;
    [[nodiscard]] virtual double getBakingMultiplier() const = 0;

  protected:
    virtual void _receiveOrder() = 0; // from pipe
    virtual void _addPendingOrder(const Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &order) = 0;
    virtual void _sendFinishedOrders() = 0;
};

#endif