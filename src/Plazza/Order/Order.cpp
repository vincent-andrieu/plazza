/*
 * EPITECH PROJECT, 2021
 * Order
 * File description:
 * Order.cpp - Created: 28/04/2021
 */

#include "Order/Order.hpp"
#include "Interfaces/ProductInterface.hpp"
#include "Product/AProduct.hpp"
#include "enumPizza.hpp"
#include <memory>

using namespace Pizzeria;

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

template class Order<AProduct<PizzaType, PizzaSize, PizzaIngredient>>;
template class Order<std::shared_ptr<IProduct<PizzaType, PizzaSize, PizzaIngredient>>>;