/*
 * EPITECH PROJECT, 2021
 * Fantasia
 * File description:
 * Fantasia.hpp
 */

#ifndef PIZZA_FANTASIA_HPP
#define PIZZA_FANTASIA_HPP

#include "Pizza/Pizza.hpp"

class Fantasia : public Pizza {
  public:
    Fantasia(PizzaSize size, long multiplier);
    ~Fantasia() override = default;
};

#endif