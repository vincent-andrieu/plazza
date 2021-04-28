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
#include "enumPizza.hpp"

class Order : public IFood, public Serializer {
  public:
    Order();
    Order(PizzaType type, PizzaSize size);
    ~Order();

  private:
    PizzaType _type;
    PizzaSize _size;
};

#endif