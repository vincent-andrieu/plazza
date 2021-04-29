/*
 * EPITECH PROJECT, 2021
 * Order
 * File description:
 * Order.cpp - Created: 28/04/2021
 */

#include "Order/Order.hpp"

Order::Order() : Serializer(sizeof(Order))
{
}

Order::Order(PizzaType type, PizzaSize size) : Serializer(sizeof(Order)), _type(type), _size(size)
{
}

Order::~Order()
{
}