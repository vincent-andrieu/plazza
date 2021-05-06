/*
 * EPITECH PROJECT, 2021
 * Interfaces
 * File description:
 * RestaurantInterface.hpp - Created: 26/04/2021
 */

#ifndef RESTAURANT_INTERFACE_HPP
#define RESTAURANT_INTERFACE_HPP

#include <list>
#include "Kitchen/Kitchen.hpp"
#include "Order/Order.hpp"
#include "Product/AProduct.hpp"
#include "Kitchen/KitchenStatus/KitchenStatus.hpp"

template <typename ProductType, typename ProductSize, typename ProductIngredientType> struct KitchenManage {
    const Kitchen<ProductType, ProductSize, ProductIngredientType> &kitchen;
    std::list<Order<AProduct<ProductType, ProductSize, ProductIngredientType>>> orders;
    KitchenStatus<ProductType, ProductSize, ProductIngredientType> kitchenStatus;
};

template <typename ProductType, typename ProductSize, typename ProductIngredientType> class IRestaurant {
  public:
    virtual ~IRestaurant() = default;

    virtual void lunchTime() = 0;
    [[nodiscard]] virtual bool isOpen() const = 0;
    virtual void close() = 0;
    virtual void askKitchensStatus() const = 0;

  protected:
    virtual void _newKitchen(const Order<AProduct<ProductType, ProductSize, ProductIngredientType>> &order) = 0;
    virtual void _distributeOrder(const Order<AProduct<ProductType, ProductSize, ProductIngredientType>> &order) = 0;
    virtual void _sendOrder(KitchenManage<ProductType, ProductSize, ProductIngredientType> &kitchen,
        const Order<AProduct<ProductType, ProductSize, ProductIngredientType>> &order) = 0;
    virtual void _retreiveOrders() = 0;
};

#endif