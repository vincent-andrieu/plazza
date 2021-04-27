/*
 * EPITECH PROJECT, 2021
 * Restaurant
 * File description:
 * Restaurant.hpp - Created: 27/04/2021
 */

#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include "Interfaces/RestaurantInterface.hpp"

class Restaurant : public IRestaurant {
  public:
    Restaurant();
    ~Restaurant();
    void lunchTime();

  protected:
    void settings(double bakingTime, size_t cooksPerKitchen, size_t restockTime);
    void getOrder() const;
    void writeStatus();
    void newKitchen();
    void kitchenCook(const Kitchen &kitchen);
    void deleteKitchen();
    void retreiveOrder(const Kitchen &kitchen);
    void order(Kitchen, Order);
};

#endif