/*
 * EPITECH PROJECT, 2021
 * Regina
 * File description:
 * Regina.hpp
 */

#ifndef PIZZA_REGINA_HPP
#define PIZZA_REGINA_HPP

#include "Product/Pizza/Pizza.hpp"

class Regina : public Pizza {
  public:
    Regina(PizzaSize size, long multiplier);
    ~Regina() override = default;
};

#endif