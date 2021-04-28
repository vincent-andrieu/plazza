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
#include "Order/Order.hpp"
#include "Stock/Stock.hpp"
#include "Encapsulations/Process/Process.hpp"
#include "Encapsulations/Mutex/Mutex.hpp"

template <typename T> struct LockedQueue {
    std::queue<T> queue;
    Mutex mutex;
};

class Kitchen : public IKitchen, public Process {
  public:
    Kitchen(double bakingTime, size_t cooksPerKitchen, size_t restockTime);
    ~Kitchen();
    void cook();
    bool isCooking() const;

  protected:
    Order &receiveOrder();
    void addPendingOrder(const Order order);
    void sendFinishOrders();
    void retreiveOrder() const;

  private:
    bool _isCooking;
    double _bakingTime;
    size_t _cooksPerKitchen;
    LockedQueue<Order> _pendingOrders;
    LockedQueue<Order> _finishedOrders;
    Stock _stock;
};

#endif