/*
 * EPITECH PROJECT, 2021
 * Pizza
 * File description:
 * Pizza.cpp
 */

#include "Pizza/Pizza.hpp"

template <typename T>
Pizza<T>::Pizza(PizzaType type, PizzaSize size, size_t timeSec, std::vector<T> ingredients)
: _type(type), _size(size), _finished(false), _ingredients(ingredients), _timeSec(timeSec)
{
}

template <typename T>
Pizza<T>::~Pizza()
{
    this->_ingredients.clear();
}

template <typename T>
PizzaType Pizza<T>::getType() const
{
    return this->_type;
}

template <typename T>
PizzaSize Pizza<T>::getSize() const
{
    return this->_size;
}

template <typename T>
size_t Pizza<T>::getPreparationTime() const
{
    return this->_timeSec;
}

template <typename T> const std::vector<T> &Pizza<T>::getIngredientsList() const
{
    return this->_ingredients;
}

template class Pizza<PizzaIngredient>;