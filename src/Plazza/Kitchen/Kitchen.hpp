/*
 * EPITECH PROJECT, 2021
 * Kitchen
 * File description:
 * Kitchen.hpp - Created: 27/04/2021
 */

#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include <queue>
#include "Interfaces/KitchenInterface.hpp"
#include "Stock/Stock.hpp"
#include "Encapsulations/Process/Process.hpp"
#include "Encapsulations/Mutex/Mutex.hpp"

template <typename T> struct LockedQueue {
    std::queue<T> queue;
    Mutex mutex;
};

class Kitchen : public IKitchen {
  public:
    Kitchen(double bakingMultiplier, size_t cooksPerKitchen, size_t restockTime);
    ~Kitchen() override;
    void cook() override;
    bool isCooking() const override;

  protected:
    Order receiveOrder() const override;
    void addPendingOrder(const Order &order) override;
    void sendFinishedOrders() override;

  private:
    Stock _stock;
    bool _isCooking;
    double _bakingMultiplier;
    size_t _cooksPerKitchen;
    LockedQueue<Order> _pendingOrders;
    LockedQueue<Order> _finishedOrders;
};

#endif