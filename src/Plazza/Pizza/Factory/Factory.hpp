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
    static std::unique_ptr<IProduct<PizzaIngredient>> callFactory(enum PizzaType type, enum PizzaSize size, long multiplier);

  private:
    static const std::unordered_map<enum PizzaType,
        std::function<std::unique_ptr<IProduct<PizzaIngredient>>(const enum PizzaSize size, const long multiplier)>>
        _list;
};

#endif