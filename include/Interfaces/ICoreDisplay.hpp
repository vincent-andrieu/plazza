/*
 * EPITECH PROJECT, 2021
 * interfaces
 * File description:
 * ICoreDisplay.hpp
 */

#ifndef ICOREDISPLAY_HPP
#define ICOREDISPLAY_HPP

#include <vector>
#include "KitchenInterface.hpp"
#include "ICommandInterpreter.hpp"

class ICoreDisplay : public ICommandInterpreter {
    public :
        virtual ~ICoreDisplay() = default;
        virtual void setPrompt(std::string prompt) = 0;
        virtual void printPrompt() const = 0;
        virtual void printKitchen(std::vector<IKitchen> kitchenList) = 0;
        virtual void printDetailledKitchen(IKitchen kitchen) = 0;
};

#endif