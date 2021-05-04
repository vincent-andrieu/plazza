/*
 * EPITECH PROJECT, 2021
 * Americana
 * File description:
 * Americana.hpp
 */

#ifndef PIZZA_AMERICANA_HPP
#define PIZZA_AMERICANA_HPP

#include "Product/Pizza/Pizza.hpp"

class Americana final : public Pizza {
  public:
    Americana(PizzaSize size, long multiplier);
    ~Americana() override = default;
};

#endif