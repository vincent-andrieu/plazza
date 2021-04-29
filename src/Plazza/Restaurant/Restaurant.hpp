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

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
class Restaurant : public IRestaurant<ProductType, ProductSize, ProductIngredientType> {
  public:
    Restaurant(double bakingMultiplier, size_t cooksPerKitchen, size_t restockTime);
    ~Restaurant() override = default;

    void lunchTime() override;
    [[nodiscard]] bool isOpen() const override;

  protected:
    void newKitchen(const Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &order) override;
    void distributeOrder(const Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &order) override;
    void sendOrder(KitchenManage<ProductType, ProductSize, ProductIngredientType> &kitchen,
        const Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &order) override;
    void retreiveOrders() override;

  private:
    void _retreiveOrder(const Kitchen<ProductType, ProductSize, ProductIngredientType> &kitchen);

    bool _isOpen{true};
    double _bakingMultiplier;
    size_t _cooksPerKitchen;
    size_t _restockTime;
    std::vector<KitchenManage<ProductType, ProductSize, ProductIngredientType>> _kitchens;
    Reception<ProductType, ProductSize, ProductIngredientType> _reception;
};

#endif