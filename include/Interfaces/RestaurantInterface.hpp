/*
 * EPITECH PROJECT, 2021
 * Interfaces
 * File description:
 * RestaurantInterface.hpp - Created: 26/04/2021
 */

#ifndef RESTAURANT_INTERFACE_HPP
#define RESTAURANT_INTERFACE_HPP

#include <vector>
#include "Interfaces/KitchenInterface.hpp"
#include "Order/Order.hpp"

struct KitchenManage {
    const Kitchen &kitchen;
    std::vector<Order> orders;
};

class IRestaurant {
  public:
    virtual ~IRestaurant() = default;

    virtual void lunchTime() = 0;
    virtual bool isOpen() const = 0;

  protected:
    virtual void newKitchen(const Order &order) = 0;
    virtual void distributeOrder(const Order &order) = 0;
    virtual void sendOrder(KitchenManage &kitchen, const Order &order) = 0;
    virtual void retreiveOrders() const = 0;
};

#endif