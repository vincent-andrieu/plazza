/*
 * EPITECH PROJECT, 2021
 * Order
 * File description:
 * Order.cpp - Created: 28/04/2021
 */

#include "Order/Order.hpp"

template <typename T> Order<T>::Order(std::shared_ptr<T> object) : Serializer(sizeof(Order)), _object(object)
{
}

template <typename T> const std::shared_ptr<T> &Order<T>::getOrder() const
{
    return _object;
}

template class Order<IProduct<PizzaType, PizzaSize, PizzaIngredient>>;