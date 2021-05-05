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
#include "Error/Error.hpp"
#include "Kitchen/Kitchen.hpp"
#include "Reception/Reception.hpp"
#include "CoreDisplay/CoreDisplay.hpp"

#include <memory>

using namespace Pizzeria;

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
class Restaurant : public IRestaurant<ProductType, ProductSize, ProductIngredientType> {
  public:
    Restaurant(double bakingMultiplier, size_t cooksPerKitchen, double restockTime);
    ~Restaurant() override = default;

    void lunchTime() override;
    [[nodiscard]] bool isOpen() const override;

  protected:
    void _newKitchen(const Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &order) override;
    void _distributeOrder(const Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &order) override;
    void _sendOrder(KitchenManage<ProductType, ProductSize, ProductIngredientType> &kitchen,
        const Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &order) override;
    void _retreiveOrders() override;

  private:
    void _retreiveOrder(KitchenManage<ProductType, ProductSize, ProductIngredientType> &kitchenManage);

    bool _isOpen{true};
    double _bakingMultiplier;
    size_t _cooksPerKitchen;
    double _restockTime;
    std::vector<KitchenManage<ProductType, ProductSize, ProductIngredientType>> _kitchens;
    Reception _reception;
};

#endif