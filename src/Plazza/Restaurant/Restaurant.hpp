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
    ~Restaurant() override = default;

    void lunchTime() override;
    [[nodiscard]] bool isOpen() const override;

  protected:
    void newKitchen(const Order &order) override;
    void distributeOrder(const Order &order) override;
    void sendOrder(KitchenManage &kitchen, const Order &order) override;
    void retreiveOrders() const override;

  private:
    void _retreiveOrder(const Kitchen &kitchen) const;

    bool _isOpen{true};
    double _bakingMultiplier;
    size_t _cooksPerKitchen;
    size_t _restockTime;
    std::vector<KitchenManage> _kitchens;
    Reception _reception;
};

#endif