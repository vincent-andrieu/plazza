/*
** EPITECH PROJECT, 2021
** Plazza
** File description:
** Translator.cpp
*/

#include "Translator.hpp"

const string Translator::EnumToString(PizzaType type)
{
    const std::unordered_map<string, Pizzeria::PizzaType>::const_iterator it =
        std::find_if(PizzaNames.begin(), PizzaNames.end(), [type](const auto &params) {
            return params.second == type;
        });
    if (it == PizzaNames.end())
        return string("yolo");
    return string(it->first);
}

const string Translator::EnumToString(PizzaSize size)
{
    const std::unordered_map<string, Pizzeria::PizzaSize>::const_iterator it =
        std::find_if(PizzaSizeList.begin(), PizzaSizeList.end(), [size](const auto &params) {
            return params.second == size;
        });
    if (it == PizzaSizeList.end())
        return string("yolo");
    return string(it->first);
}

PizzaType Translator::StringToType(string src)
{
    return PizzaNames.at(src);
}

PizzaSize Translator::StringToSize(string src)
{
    return PizzaSizeList.at(src);
}