/*
 * EPITECH PROJECT, 2021
 * interfaces
 * File description:
 * ICoreDisplay.hpp
 */

#ifndef ICOREDISPLAY_HPP
#define ICOREDISPLAY_HPP

#include <memory>
#include <list>
#include "KitchenInterface.hpp"
#include "ICommandInterpreter.hpp"
#include "RestaurantInterface.hpp"

namespace Pizzeria
{
    template <typename ProductType, typename ProductSize, typename ProductIngredientType>
    class ICoreDisplay : public ICommandInterpreter {
      public:
        virtual ~ICoreDisplay() = default;
        virtual void setPrompt(std::string prompt) = 0;
        virtual void printPrompt() = 0;
        virtual void printError() = 0;
        virtual void setError(std::string error) = 0;
        virtual void printKitchen(
            std::list<KitchenManage<ProductType, ProductSize, ProductIngredientType>> kitchenList) = 0;
        [[nodiscard]] std::string getLine() const override = 0;
        void setLine(std::string line) override = 0;
        virtual void update() = 0;
        virtual void clear() = 0;
        virtual bool isRunning() = 0;

    protected:
        virtual void printDetailledKitchen(
            KitchenManage<ProductType, ProductSize, ProductIngredientType> kitchen) = 0;
    };
} // namespace Pizzeria
#endif