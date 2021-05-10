/*
 * EPITECH PROJECT, 2021
 * Kitchen
 * File description:
 * Kitchen.hpp - Created: 27/04/2021
 */

#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include <queue>
#include <mutex>
#include <chrono>
#include "enumPizza.hpp"
#include "Interfaces/KitchenInterface.hpp"
#include "Stock/Stock.hpp"
#include "Encapsulations/Process/Process.hpp"

using namespace Pizzeria;

template <typename T> struct LockedQueue {
    std::queue<T> queue;
    std::mutex mutex;
};

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
class Kitchen : public IKitchen<ProductType, ProductSize, ProductIngredientType>, public Process {
  public:
    Kitchen(double bakingMultiplier, size_t cooksPerKitchen, size_t restockTime);
    ~Kitchen() override = default;
    int cook() override;
    [[nodiscard]] bool isCooking() const override;
    [[nodiscard]] size_t getNbCooks() const override;
    [[nodiscard]] double getBakingMultiplier() const override;

  protected:
    void _receiveOrder() override;
    void _addPendingOrder(const Order<AProduct<ProductType, ProductSize, ProductIngredientType>> &order) override;
    void _sendFinishedOrders() override;
    void _sendStatus() override;

  private:
    void _destroyManage();

  private:
    std::chrono::time_point<std::chrono::system_clock> _lastAct;
    Stock<ProductIngredientType> _stock;
    bool _isCooking{true};
    double _bakingMultiplier;
    size_t _cooksPerKitchen;
    LockedQueue<Order<AProduct<ProductType, ProductSize, ProductIngredientType>>> _pendingOrders;
    LockedQueue<Order<AProduct<ProductType, ProductSize, ProductIngredientType>>> _finishedOrders;
};

#endif