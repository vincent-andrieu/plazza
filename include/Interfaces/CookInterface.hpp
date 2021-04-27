/*
 * EPITECH PROJECT, 2021
 * Interfaces
 * File description:
 * CookInterface.hpp - Created: 26/04/2021
 */

#ifndef COOK_INTERFACE_HPP
#define COOK_INTERFACE_HPP

#include <queue>
#include "Pizza/Pizza.hpp"

class ICook {
  public:
    virtual ~ICook() = default;
    virtual bool cook(Pizza pizza) = 0; // {if has 2 pizzas, return false, if not, put pizza in pending}
    virtual Pizza getCookingPizza() const = 0;
    virtual Pizza getPendingPizza() const = 0;
    virtual std::queue<Pizza> getFinishedPizzas() const = 0;
};

#endif