/*
 * EPITECH PROJECT, 2021
 * Interfaces
 * File description:
 * RestaurantInterface.hpp - Created: 26/04/2021
 */

#ifndef RESTAURANT_INTERFACE_HPP
#define RESTAURANT_INTERFACE_HPP

#include <memory>
#include <list>
#include "Kitchen/Kitchen.hpp"
#include "Order/Order.hpp"
#include "Product/Product.hpp"
#include "Kitchen/KitchenStatus/KitchenStatus.hpp"

template <typename ProductType, typename ProductSize, typename ProductIngredientType> class KitchenManage {
  public:
    KitchenManage(const Kitchen<ProductType, ProductSize, ProductIngredientType> &kit) : kitchen(kit){};
    ~KitchenManage() = default;
    const Kitchen<ProductType, ProductSize, ProductIngredientType> &kitchen;
    std::list<Order<Product<ProductType, ProductSize, ProductIngredientType>>> orders;
    KitchenStatus<ProductType, ProductSize, ProductIngredientType> kitchenStatus;
};

template <typename ProductType, typename ProductSize, typename ProductIngredientType> class IRestaurant {
  public:
    virtual ~IRestaurant() = default;

    virtual void lunchTime() = 0;
    virtual bool isOpen() const = 0;
    virtual void close() = 0;
    virtual void askKitchensStatus() const = 0;
    virtual void askKitchenStatus(const Kitchen<ProductType, ProductSize, ProductIngredientType> &kitchen) const = 0;

  protected:
    virtual void _newKitchen(const Order<Product<ProductType, ProductSize, ProductIngredientType>> &order) = 0;
    virtual void _distributeOrder(const Order<Product<ProductType, ProductSize, ProductIngredientType>> &order) = 0;
    virtual void _sendOrder(std::unique_ptr<KitchenManage<ProductType, ProductSize, ProductIngredientType>> &kitchen,
        const Order<Product<ProductType, ProductSize, ProductIngredientType>> &order) = 0;
    virtual void _retreiveOrders() = 0;
};

#endif