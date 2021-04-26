/*
 * EPITECH PROJECT, 2021
 * Factory
 * File description:
 * Factory.hpp
 */

#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <vector>
#include <memory>
#include <functional>
#include <unordered_map>
#include "Error/Error.hpp"
#include "Interfaces/ProductInterface.hpp"

class Factory {
    public:
        Factory();
        ~Factory();
        std::unique_ptr<IProduct<PizzaIngredient>> callFactory(const PizzaType type, const PizzaSize size, const long multiplier);

    private:
        std::unordered_map <PizzaType, std::function<std::unique_ptr<IProduct<PizzaIngredient>>(const PizzaSize size, const long multiplier)>> _list;
};

#endif