/*
** EPITECH PROJECT, 2021
** Product.cpp.c
** File description:
** Implementation of abstract product
*/

#include "Product/Product.hpp"
#include "Product/Pizza/Pizza.hpp"

template <typename Type, typename Size, typename IngredientType>
bool Product<Type, Size, IngredientType>::operator==(const IProduct<Type, Size, IngredientType> &product) const
{
    return this->getType() == product.getType() && this->getSize() == product.getSize()
        && this->getPreparationTime() == product.getPreparationTime() && this->getIngredients() == product.getIngredients();
}

template <typename Type, typename Size, typename IngredientType>
bool Product<Type, Size, IngredientType>::operator!=(const IProduct<Type, Size, IngredientType> &product) const
{
    return this->getType() != product.getType() || this->getSize() != product.getSize()
        || this->getPreparationTime() != product.getPreparationTime() || this->getIngredients() != product.getIngredients();
}

template <typename Type, typename Size, typename IngredientType>
[[nodiscard]] Type Product<Type, Size, IngredientType>::getType() const
{
    return _type;
}

template <typename Type, typename Size, typename IngredientType> void Product<Type, Size, IngredientType>::setType(Type type)
{
    _type = type;
}

template <typename Type, typename Size, typename IngredientType>
[[nodiscard]] Size Product<Type, Size, IngredientType>::getSize() const
{
    return _size;
}

template <typename Type, typename Size, typename IngredientType> void Product<Type, Size, IngredientType>::setSize(Size size)
{
    _size = size;
}

template <typename Type, typename Size, typename IngredientType>
[[nodiscard]] double Product<Type, Size, IngredientType>::getPreparationTime() const
{
    return _preparationTime;
}

template <typename Type, typename Size, typename IngredientType>
void Product<Type, Size, IngredientType>::setPreparationTime(double preparationTime)
{
    _preparationTime = preparationTime;
}

template <typename Type, typename Size, typename IngredientType>
[[nodiscard]] const std::vector<IngredientType> &Product<Type, Size, IngredientType>::getIngredients() const
{
    return _ingredients;
}

template <typename Type, typename Size, typename IngredientType>
void Product<Type, Size, IngredientType>::setIngredients(const std::vector<IngredientType> &ingredients)
{
    _ingredients = ingredients;
}

template <typename Type, typename Size, typename IngredientType>
[[nodiscard]] bool Product<Type, Size, IngredientType>::isFinished() const
{
    return _finished;
}

template <typename Type, typename Size, typename IngredientType> void Product<Type, Size, IngredientType>::setFinished()
{
    _finished = true;
}

template class Product<Pizzeria::PizzaType, Pizzeria::PizzaSize, Pizzeria::PizzaIngredient>;