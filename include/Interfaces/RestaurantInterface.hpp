/*
 * EPITECH PROJECT, 2021
 * Interfaces
 * File description:
 * RestaurantInterface.hpp - Created: 26/04/2021
 */

#ifndef RESTAURANT_INTERFACE_HPP
#define RESTAURANT_INTERFACE_HPP

#include "Plazza.hpp"
#include "Interfaces/KitchenInterface.hpp"
#include "Order/Order.hpp"

class IRestaurant {
  public:
    virtual ~IRestaurant() = default;
    virtual void lunchTime() = 0;

  protected:
    virtual void settings(double bakingTime, size_t cooksPerKitchen, size_t restockTime) = 0;
    virtual void getOrder() const = 0;
    virtual void writeStatus() = 0;
    virtual void newKitchen() = 0; // fork(), if child boucle inf kitchen, if parent, kitchen can receive orders
    virtual void kitchenCook(const IKitchen &kitchen) = 0;   // while isCooking(), loop
    virtual void deleteKitchen() = 0;                        // only if parent, send message to close
    virtual void retreiveOrder(const IKitchen &kitchen) = 0; // through pipe
    virtual void order(IKitchen, Order) = 0;                 // through pipe
};

#endif