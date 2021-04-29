/*
 * EPITECH PROJECT, 2021
 * interfaces
 * File description:
 * ProductInterface.hpp
 */

#ifndef PRODUCT_INTERFACE_HPP
#define PRODUCT_INTERFACE_HPP

#include "enumPizza.hpp"

template <typename T> class IProduct {
  public:
    virtual ~IProduct() = default;
    [[nodiscard]] virtual PizzaType getType() const = 0;
    [[nodiscard]] virtual PizzaSize getSize() const = 0;
    [[nodiscard]] virtual size_t getPreparationTime() const = 0;
    virtual const std::vector<T> &getIngredientsList() const = 0;
};

#endif