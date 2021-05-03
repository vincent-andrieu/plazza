/*
 * EPITECH PROJECT, 2021
 * DisplayManage
 * File description:
 * DisplayManage.hpp - Created: 21/04/2021
 */

#ifndef DISPLAYMANAGE_HPP
#define DISPLAYMANAGE_HPP

#include <iostream>
#include <algorithm>
#include "enumPizza.hpp"
#include "DLLib/DLLib.hpp"
#include "UserInput/UserInput.hpp"
#include "Interfaces/ICoreDisplay.hpp"
#include "Interfaces/IDisplayModule.hpp"

using namespace Pizzeria;

namespace Pizzeria
{
    template <typename ProductType, typename ProductSize, typename ProductIngredientType>
    class CoreDisplay : public ICoreDisplay<ProductType, ProductSize, ProductIngredientType> {
      public:
        CoreDisplay(std::string filepath, Vector screenSize, Vector screenScale, std::size_t maxLen = 30);
        ~CoreDisplay();
        void setPrompt(std::string prompt);
        void printPrompt() const;
        void printKitchen(std::vector<std::unique_ptr<IKitchen<ProductType, ProductSize, ProductIngredientType>>> kitchenList);
        void printDetailledKitchen(std::unique_ptr<IKitchen<ProductType, ProductSize, ProductIngredientType>> kitchen);
        [[nodiscard]] std::string getLine() const;
        void setLine(std::string line);
        void update();
        void clear();

      private:
        std::string _prompt;
        std::size_t _maxLen;
        std::unique_ptr<DLLib<IDisplayModule>> _loader;
        std::unique_ptr<UserInput> _input;
    };
} // namespace Pizzeria

#endif