/*
 * EPITECH PROJECT, 2021
 * Restaurant
 * File description:
 * Restaurant.hpp - Created: 27/04/2021
 */

#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include "Interfaces/RestaurantInterface.hpp"
#include "Order/Order.hpp"
#include "Kitchen/Kitchen.hpp"
#include "Reception/Reception.hpp"

class Restaurant : public IRestaurant {
  public:
    Restaurant(double bakingMultiplier, size_t cooksPerKitchen, size_t restockTime);
    ~Restaurant();

    void lunchTime();
    bool isOpen() const;

  protected:
    void newKitchen(const Order &order);
    void distributeOrder(const Order &order);
    void sendOrder(KitchenManage &kitchen, const Order &order);
    void retreiveOrders();

  private:
    void _retreiveOrder(Kitchen &kitchen);

    bool _isOpen;
    double _bakingMultiplier;
    size_t _cooksPerKitchen;
    size_t _restockTime;
    std::vector<KitchenManage> _kitchens;
    Reception _reception;
};

#endif