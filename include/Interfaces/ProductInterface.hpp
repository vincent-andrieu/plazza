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
    virtual PizzaType getType() const = 0;
    virtual PizzaSize getSize() const = 0;
    virtual size_t getPreparationTime() const = 0;
    virtual std::vector<T> getIngredientsList() const = 0;
};

#endif