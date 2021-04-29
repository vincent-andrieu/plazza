/*
 * EPITECH PROJECT, 2021
 * interfaces
 * File description:
 * ICoreDisplay.hpp
 */

#ifndef ICOREDISPLAY_HPP
#define ICOREDISPLAY_HPP

#include <memory>
#include <vector>
#include "KitchenInterface.hpp"
#include "ICommandInterpreter.hpp"

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
class ICoreDisplay : public ICommandInterpreter {
  public:
    virtual ~ICoreDisplay() = default;
    virtual void setPrompt(std::string prompt) = 0;
    virtual void printPrompt() const = 0;
    virtual void printKitchen(
        std::vector<std::unique_ptr<IKitchen<ProductType, ProductSize, ProductIngredientType>>> kitchenList) = 0;
    virtual void printDetailledKitchen(std::unique_ptr<IKitchen<ProductType, ProductSize, ProductIngredientType>> kitchen) = 0;
};

#endif