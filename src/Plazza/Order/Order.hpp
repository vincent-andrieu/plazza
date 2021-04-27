/*
 * EPITECH PROJECT, 2021
 * include
 * File description:
 * Order.hpp - Created: 26/04/2021
 */

#ifndef ORDER_HPP
#define ORDER_HPP

#include "Interfaces/FoodInterface.hpp"
#include "Serializer/Serializer.hpp"

class Order : public IFood, public Serializer {
};

#endif