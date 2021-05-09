/*
** EPITECH PROJECT, 2021
** Plazza
** File description:
** Translator.cpp
*/

#include "Translator.hpp"

template <typename Type, typename Size> const string Translator<Type, Size>::EnumToString(Type type)
{
    const std::unordered_map<string, Pizzeria::PizzaType>::const_iterator it =
        std::find_if(PizzaNames.begin(), PizzaNames.end(), [type](const auto &params) {
            return params.second == type;
        });
    return it->first;
}

template <typename Type, typename Size> const string Translator<Type, Size>::EnumToString(Size size)
{
    const std::unordered_map<string, Pizzeria::PizzaSize>::const_iterator it =
        std::find_if(PizzaSizeList.begin(), PizzaSizeList.end(), [size](const auto &params) {
            return params.second == size;
        });
    return it->first;
}

template <typename Type, typename Size> Type Translator<Type, Size>::StringToType(string src)
{
    return PizzaNames.at(src);
}

template <typename Type, typename Size> Size Translator<Type, Size>::StringToSize(string src)
{
    return PizzaSizeList.at(src);
}

template class Translator<PizzaType, PizzaSize>;