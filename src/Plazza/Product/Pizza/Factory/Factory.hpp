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
#include "Product/AProduct.hpp"

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
        static AProduct<PizzaType, PizzaSize, PizzaIngredient> callFactory(
            const PizzaType type, const PizzaSize size, const size_t multiplier);
    };
} // namespace Pizzeria

#endif