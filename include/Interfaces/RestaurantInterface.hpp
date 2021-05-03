/*
 * EPITECH PROJECT, 2021
 * Interfaces
 * File description:
 * RestaurantInterface.hpp - Created: 26/04/2021
 */

#ifndef RESTAURANT_INTERFACE_HPP
#define RESTAURANT_INTERFACE_HPP

#include <vector>
#include "Kitchen/Kitchen.hpp"
#include "Order/Order.hpp"

template <typename ProductType, typename ProductSize, typename ProductIngredientType> struct KitchenManage {
    const Kitchen<ProductType, ProductSize, ProductIngredientType> &kitchen;
    std::vector<Order<IProduct<ProductType, ProductSize, ProductIngredientType>>> orders;
};

template <typename ProductType, typename ProductSize, typename ProductIngredientType> class IRestaurant {
  public:
    virtual ~IRestaurant() = default;

    virtual void lunchTime() = 0;
    [[nodiscard]] virtual bool isOpen() const = 0;

  protected:
    virtual void _newKitchen(const Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &order) = 0;
    virtual void _distributeOrder(const Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &order) = 0;
    virtual void _sendOrder(KitchenManage<ProductType, ProductSize, ProductIngredientType> &kitchen,
        const Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &order) = 0;
    virtual void _retreiveOrders() = 0;
};

#endif