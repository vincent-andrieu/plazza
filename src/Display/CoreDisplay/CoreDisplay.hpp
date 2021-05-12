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
#include "ListDir/ListDir.hpp"
#include "UserInput/UserInput.hpp"
#include "Interfaces/CoreDisplayInterface.hpp"
#include "Interfaces/DisplayModuleInterface.hpp"
#include "Interfaces/RestaurantInterface.hpp"

using namespace Pizzeria;

namespace Pizzeria
{
    template <typename ProductType, typename ProductSize, typename ProductIngredientType>
    class CoreDisplay : public ICoreDisplay<ProductType, ProductSize, ProductIngredientType> {
      public:
        CoreDisplay(Vector screenSize, Vector screenScale, std::size_t maxLen = 30);
        ~CoreDisplay();
        void setPrompt(string prompt);
        void printPrompt();
        void setError(string error);
        void printError();
        void printKitchen(
            std::vector<std::unique_ptr<KitchenManage<ProductType, ProductSize, ProductIngredientType>>> &kitchenList);
        [[nodiscard]] string getLine() const;
        void setLine(string line);
        bool isRunning();
        void update();
        void clear();

      protected:
        void _printDetailledKitchen(std::unique_ptr<KitchenManage<ProductType, ProductSize, ProductIngredientType>> &kitchen);

      private:
        void _libraryDisplaySwitch();
        void _kitchenSwitch();

      private:
        string _error;
        string _prompt;
        std::size_t _maxLen;
        std::unique_ptr<UserInput> _input{nullptr};
        std::unordered_map<size_t, std::unique_ptr<DLLib<IDisplayModule>>> _dirName;
        size_t _pos;
        size_t _kitechToPrint;
        Vector _screenSize;
        Vector _screenScale;
    };
} // namespace Pizzeria

#endif