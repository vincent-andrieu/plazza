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

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
class Kitchen : public IKitchen<ProductType, ProductSize, ProductIngredientType> {
  public:
    Kitchen(double bakingMultiplier, size_t cooksPerKitchen, size_t restockTime);
    ~Kitchen() override = default;
    void cook() override;
    bool isCooking() const override;

  protected:
    void receiveOrder() const override;
    void addPendingOrder(const Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &order) override;
    void sendFinishedOrders() override;

  private:
    Stock _stock;
    bool _isCooking = true;
    double _bakingMultiplier;
    size_t _cooksPerKitchen;
    LockedQueue<Order<IProduct<ProductType, ProductSize, ProductIngredientType>>> _pendingOrders;
    LockedQueue<Order<IProduct<ProductType, ProductSize, ProductIngredientType>>> _finishedOrders;
};

#endif