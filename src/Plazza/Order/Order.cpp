/*
 * EPITECH PROJECT, 2021
 * Order
 * File description:
 * Order.cpp - Created: 28/04/2021
 */

#include "Order/Order.hpp"
#include "Product/AProduct.hpp"
#include "enumPizza.hpp"

using namespace Pizzeria;

template <typename T> Order<T>::Order(const T object) : Serializer(sizeof(Order)), _object(object)
{
}

template <typename T> const T &Order<T>::getOrder() const
{
    return _object;
}

template class Order<AProduct<PizzaType, PizzaSize, PizzaIngredient>>;