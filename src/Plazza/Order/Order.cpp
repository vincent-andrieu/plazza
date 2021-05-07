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

template <typename T> Order<T>::Order(const T &object) : _object(object)
{
}

template <typename T> const T &Order<T>::getOrder() const
{
    return _object;
}

template <typename T> const string Order<T>::_SerializeToString() const
{
    return "";
}

template <typename T> void Order<T>::_SerializeFromString(const string str)
{
    (void) str;
}

template class Order<AProduct<PizzaType, PizzaSize, PizzaIngredient>>;