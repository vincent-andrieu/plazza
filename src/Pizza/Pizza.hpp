/*
 * EPITECH PROJECT, 2021
 * Pizza
 * File description:
 * Pizza.hpp
 */

#ifndef MUTEX_HPP
#define MUTEX_HPP

#include <vector>
#include "ProductInterface.hpp"

template <typename T>
class Pizza : public IProduct<T>
{
  public:
    Pizza(PizzaType type, PizzaSize size, size_t timeSec, std::vector<T> ingredients);
    ~Pizza();
    PizzaType getType() const;
    PizzaSize getSize() const;
    size_t getPreparationTime() const;
    std::vector<T> getIngredientsList() const;

  private:
    PizzaType _type;
    PizzaSize _size;
    bool _finished;
    std::vector<T> _ingredients;
    size_t _timeSec;
};

#endif