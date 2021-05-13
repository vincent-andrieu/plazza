/*
** EPITECH PROJECT, 2021
** Product.cpp.c
** File description:
** Implementation of abstract product
*/

#include "Product/Product.hpp"
#include "Product/Pizza/Pizza.hpp"

template <typename Type, typename Size, typename Ingredient>
Product<Type, Size, Ingredient>::Product(
    const Type &type, const Size &size, double preparationTime, const std::vector<Ingredient> &ingredients)
    : _type(type), _size(size), _preparationTime(preparationTime), _ingredients(ingredients)
{
}

template <typename Type, typename Size, typename Ingredient>
Product<Type, Size, Ingredient>::Product(const Product<Type, Size, Ingredient> &src)
    : _type(src.getType()), _size(src.getSize()), _preparationTime(src.getPreparationTime()), _ingredients(src.getIngredients()),
      _finished(src.isFinished())
{
}

template <typename Type, typename Size, typename Ingredient>
Product<Type, Size, Ingredient> &Product<Type, Size, Ingredient>::operator=(const Product<Type, Size, Ingredient> &rhs)
{
    this->_type = rhs._type;
    this->_size = rhs._size;
    this->_preparationTime = rhs._preparationTime;
    this->_ingredients = rhs._ingredients;
    this->_finished = rhs._finished;

    return *this;
}

template <typename Type, typename Size, typename Ingredient>
bool Product<Type, Size, Ingredient>::operator==(const IProduct<Type, Size, Ingredient> &product) const
{
    return this->getType() == product.getType() && this->getSize() == product.getSize();
}

template <typename Type, typename Size, typename Ingredient>
bool Product<Type, Size, Ingredient>::operator!=(const IProduct<Type, Size, Ingredient> &product) const
{
    return this->getType() != product.getType() || this->getSize() != product.getSize();
}

template <typename Type, typename Size, typename Ingredient> [[nodiscard]] Type Product<Type, Size, Ingredient>::getType() const
{
    return _type;
}

template <typename Type, typename Size, typename Ingredient> void Product<Type, Size, Ingredient>::setType(Type type)
{
    _type = type;
}

template <typename Type, typename Size, typename Ingredient> [[nodiscard]] Size Product<Type, Size, Ingredient>::getSize() const
{
    return _size;
}

template <typename Type, typename Size, typename Ingredient> void Product<Type, Size, Ingredient>::setSize(Size size)
{
    _size = size;
}

template <typename Type, typename Size, typename Ingredient>
[[nodiscard]] double Product<Type, Size, Ingredient>::getPreparationTime() const
{
    return _preparationTime;
}

template <typename Type, typename Size, typename Ingredient>
void Product<Type, Size, Ingredient>::setPreparationTime(double preparationTime)
{
    _preparationTime = preparationTime;
}

template <typename Type, typename Size, typename Ingredient>
[[nodiscard]] const std::vector<Ingredient> &Product<Type, Size, Ingredient>::getIngredients() const
{
    return _ingredients;
}

template <typename Type, typename Size, typename Ingredient>
void Product<Type, Size, Ingredient>::setIngredients(const std::vector<Ingredient> &ingredients)
{
    _ingredients = ingredients;
}

template <typename Type, typename Size, typename Ingredient>
[[nodiscard]] bool Product<Type, Size, Ingredient>::isFinished() const
{
    return _finished;
}

template <typename Type, typename Size, typename Ingredient> void Product<Type, Size, Ingredient>::setFinished()
{
    _finished = true;
}

template class Product<Pizzeria::PizzaType, Pizzeria::PizzaSize, Pizzeria::PizzaIngredient>;