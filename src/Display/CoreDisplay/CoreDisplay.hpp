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
#include "Interfaces/ICoreDisplay.hpp"
#include "Interfaces/IDisplayModule.hpp"
#include "Interfaces/RestaurantInterface.hpp"

using namespace Pizzeria;

namespace Pizzeria
{
    template <typename ProductType, typename ProductSize, typename ProductIngredientType>
    class CoreDisplay : public ICoreDisplay<ProductType, ProductSize, ProductIngredientType> {
      public:
        CoreDisplay(Vector screenSize, Vector screenScale, std::size_t maxLen = 30);
        ~CoreDisplay();
        void setPrompt(std::string prompt);
        void printPrompt();
        void setError(std::string error);
        void printError();
        void printKitchen(std::list<KitchenManage<ProductType, ProductSize, ProductIngredientType>> kitchenList);
        [[nodiscard]] std::string getLine() const;
        void setLine(std::string line);
        bool isRunning();
        void update();
        void clear();

      protected:
        void printDetailledKitchen(KitchenManage<ProductType, ProductSize, ProductIngredientType> kitchen);

      private:
        void libraryDisplaySwitch();
        void kitchenSwitch();

      private:
        std::string _error;
        std::string _prompt;
        std::size_t _maxLen;
        std::unique_ptr<UserInput> _input;
        std::unordered_map<size_t, std::unique_ptr<DLLib<IDisplayModule>>> _dirName;
        size_t _pos;
        size_t _kitechToPrint;
        Vector _screenSize;
        Vector _screenScale;
    };
} // namespace Pizzeria

#endif