/*
 * EPITECH PROJECT, 2021
 * Cook
 * File description:
 * Cook.hpp - Created: 26/04/2021
 */

#ifndef COOK_HPP
#define COOK_HPP

#include "Interfaces/CookInterface.hpp"

class Cook : ICook {
  public:
    ~Cook();
    bool cook(Pizza);
    Pizza getCookingPizza() const;
    Pizza getPendingPizza() const;
    std::queue<Pizza> getFinishedPizzas() const;

  private:
    Pizza _cooking;
    Pizza _pending;
    std::queue<Pizza> _finished;
};

#endif