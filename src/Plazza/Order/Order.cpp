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
    std::string serial = Translator<PizzaType, PizzaSize>::EnumToString(this->_object.getType());

    serial += " ";
    serial += Translator<PizzaType, PizzaSize>::EnumToString(this->_object.getSize());
    return serial;
}

template <typename T> void Order<T>::_SerializeFromString(const string str)
{
    stringstream ss(str);
    std::string word;

    ss >> word;
    this->_object.setType(Translator<PizzaType, PizzaSize>::StringToType(word));
    ss >> word;
    this->_object.setSize(Translator<PizzaType, PizzaSize>::StringToSize(word));
}

template class Order<AProduct<PizzaType, PizzaSize, PizzaIngredient>>;