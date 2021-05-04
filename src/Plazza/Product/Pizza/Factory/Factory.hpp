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

#include "enumPizza.hpp"

#include "Product/Pizza/PizzaType/Americana/Americana.hpp"
#include "Product/Pizza/PizzaType/Margarita/Margarita.hpp"
#include "Product/Pizza/PizzaType/Fantasia/Fantasia.hpp"
#include "Product/Pizza/PizzaType/Regina/Regina.hpp"

namespace Pizzeria
{
    class Factory {
      public:
        Factory() = default;
        ~Factory() = default;
        static std::unique_ptr<IProduct<PizzaType, PizzaSize, PizzaIngredient>> callFactory(
            enum PizzaType type, enum PizzaSize size, long multiplier);

      private:
        static const std::unordered_map<enum PizzaType,
            std::function<std::unique_ptr<IProduct<PizzaType, PizzaSize, PizzaIngredient>>(
                const enum PizzaSize size, const long multiplier)>>
            _list;
    };
} // namespace Pizzeria

#endif