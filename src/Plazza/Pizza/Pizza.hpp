/*
 * EPITECH PROJECT, 2021
 * Pizza
 * File description:
 * Pizza.hpp
 */

#ifndef PIZZA_HPP
#define PIZZA_HPP

#include <vector>
#include "Interfaces/ProductInterface.hpp"
#include "enumPizza.hpp"

namespace Pizzeria
{
    class Pizza : public IProduct<PizzaType, PizzaSize, PizzaIngredient> {
      public:
        Pizza() = default;
        Pizza(PizzaType type, PizzaSize size, size_t timeSec, std::vector<PizzaIngredient> ingredients);
        ~Pizza() override = default;

        [[nodiscard]] bool operator==(const IProduct &product) const;
        [[nodiscard]] bool operator!=(const IProduct &product) const;

        [[nodiscard]] PizzaType getType() const override;
        [[nodiscard]] PizzaSize getSize() const override;
        [[nodiscard]] size_t getPreparationTime() const override;
        [[nodiscard]] const std::vector<PizzaIngredient> &getIngredientList() const override;

      private:
        PizzaType _type;
        PizzaSize _size;
        bool _finished = false;
        std::vector<PizzaIngredient> _ingredients;
        size_t _timeSec;
    };
} // namespace Pizzeria

#endif