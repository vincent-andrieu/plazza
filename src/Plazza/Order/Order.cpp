/*
 * EPITECH PROJECT, 2021
 * Order
 * File description:
 * Order.cpp - Created: 28/04/2021
 */

#include "Order/Order.hpp"
#include "Product/Product.hpp"
#include "enumPizza.hpp"

template <typename T> Order<T>::Order(T object) : _object(object)
{
}

template <typename T> Order<T>::Order(const Order<T> &order) : _object(order.getOrder())
{
}

template <typename T> const T *Order<T>::operator->() const
{
    return &this->getOrder();
}

template <typename T> const T &Order<T>::getOrder() const
{
    return _object;
}

template <typename T> void Order<T>::setOrder(T &object)
{
    this->_object = object;
}

template <typename T> const string Order<T>::SerializeToString() const
{
    string serial = toString(this->_object.getType());

    serial += " ";
    serial += toString(this->_object.getSize());
    return serial;
}

template <typename T> void Order<T>::SerializeFromString(const string &str)
{
    stringstream ss(str);
    string word;

    ss >> word;
    this->_object.setType((PizzaType) toInteger(word));
    ss >> word;
    this->_object.setSize((PizzaSize) toInteger(word));
}

template class Order<Product<Pizzeria::PizzaType, Pizzeria::PizzaSize, Pizzeria::PizzaIngredient>>;