/*
** EPITECH PROJECT, 2021
** AProduct.cpp.c
** File description:
** Implementation of abstract product
*/

#include "AProduct.hpp"

template <typename Type, typename Size, typename IngredientType>
[[nodiscard]] Type AProduct<Type, Size, IngredientType>::getType() const
{
    return _type;
}

template <typename Type, typename Size, typename IngredientType> void AProduct<Type, Size, IngredientType>::setType(Type type)
{
    _type = type;
}

template <typename Type, typename Size, typename IngredientType>
[[nodiscard]] Size AProduct<Type, Size, IngredientType>::getSize() const
{
    return _size;
}

template <typename Type, typename Size, typename IngredientType> void AProduct<Type, Size, IngredientType>::setSize(Size size)
{
    _size = size;
}

template <typename Type, typename Size, typename IngredientType>
[[nodiscard]] size_t AProduct<Type, Size, IngredientType>::getPreparationTime() const
{
    return _preparationTime;
}

template <typename Type, typename Size, typename IngredientType>
void AProduct<Type, Size, IngredientType>::setPreparationTime(size_t preparationTime)
{
    _preparationTime = preparationTime;
}

template <typename Type, typename Size, typename IngredientType>
[[nodiscard]] const std::vector<IngredientType> &AProduct<Type, Size, IngredientType>::getIngredients() const
{
    return _ingredients;
}

template <typename Type, typename Size, typename IngredientType>
void AProduct<Type, Size, IngredientType>::setIngredients(const std::vector<IngredientType> &ingredients)
{
    _ingredients = ingredients;
}

template <typename Type, typename Size, typename IngredientType>
[[nodiscard]] bool AProduct<Type, Size, IngredientType>::isFinished()
{
    return _finished;
}

template <typename Type, typename Size, typename IngredientType> void AProduct<Type, Size, IngredientType>::setFinished()
{
    _finished = true;
}