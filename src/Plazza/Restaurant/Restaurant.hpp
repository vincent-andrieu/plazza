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

using namespace Pizzeria;

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
class Restaurant : public IRestaurant<ProductType, ProductSize, ProductIngredientType> {
  public:
    Restaurant(double bakingMultiplier, size_t cooksPerKitchen, double restockTime);
    ~Restaurant() override;

    void lunchTime() override;
    [[nodiscard]] bool isOpen() const override;
    void close() override;
    void askKitchensStatus() const override;
    void askKitchenStatus(const Kitchen<ProductType, ProductSize, ProductIngredientType> &kitchen) const override;

  protected:
    void _newKitchen(const Order<Product<ProductType, ProductSize, ProductIngredientType>> &order) override;
    void _distributeOrder(const Order<Product<ProductType, ProductSize, ProductIngredientType>> &order) override;
    void _sendOrder(std::unique_ptr<KitchenManage<ProductType, ProductSize, ProductIngredientType>> &kitchen,
        const Order<Product<ProductType, ProductSize, ProductIngredientType>> &order) override;
    void _retreiveOrders() override;

  private:
    bool _retreiveOrder(std::unique_ptr<KitchenManage<ProductType, ProductSize, ProductIngredientType>> &kitchenManage);

    bool _isOpen{true};
    double _bakingMultiplier;
    size_t _cooksPerKitchen;
    double _restockTime;
    std::vector<std::unique_ptr<KitchenManage<ProductType, ProductSize, ProductIngredientType>>> _kitchens;
    Reception _reception;
};

#endif