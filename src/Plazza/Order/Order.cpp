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
    string serial = std::to_string(this->_object.getType());

    serial += " ";
    serial += std::to_string(this->_object.getSize());
    serial += " ";
    serial += std::to_string(this->_object.getPreparationTime());
    return serial;
}

template <typename T> void Order<T>::_SerializeFromString(const string str)
{
    stringstream ss(str);
    string word;
    size_t preparationTime;

    ss >> word;
    this->_object.setType((PizzaType) std::stoi(word));
    ss >> word;
    this->_object.setSize((PizzaSize) std::stoi(word));
    ss >> preparationTime;
    this->_object.setPreparationTime(preparationTime);
}

template class Order<AProduct<PizzaType, PizzaSize, PizzaIngredient>>;