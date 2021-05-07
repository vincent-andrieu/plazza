/*
 * EPITECH PROJECT, 2021
 * Order
 * File description:
 * Order.cpp - Created: 28/04/2021
 */

#include "Order/Order.hpp"
#include "Product/Product.hpp"
#include "enumPizza.hpp"

template <typename T> Order<T>::Order(T &object) : Serializer(sizeof(Order)), _object(object)
{
}

template <typename T> Order<T> &Order<T>::operator=(const Order<T> &rhs)
{
    setOrder(rhs.getOrder());
    return *this;
}

template <typename T> T &Order<T>::getOrder() const
{
    return _object;
}

template <typename T> void Order<T>::setOrder(T &object)
{
    this->_object = object;
}

template class Order<Product<Pizzeria::PizzaType, Pizzeria::PizzaSize, Pizzeria::PizzaIngredient>>;