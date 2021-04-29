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

class ICoreDisplay : public ICommandInterpreter {
    public :
        virtual ~ICoreDisplay() = default;
        virtual void setPrompt(std::string prompt) = 0;
        virtual void printPrompt() const = 0;
        virtual void printKitchen(std::vector<std::shared_ptr<IKitchen>> kitchenList) = 0;
        virtual void printDetailledKitchen(std::shared_ptr<IKitchen> kitchen) = 0;
        virtual std::string getLine() const = 0;
        virtual void setLine(std::string line) = 0;
        virtual void update() = 0;
        virtual void clear() = 0;
};

#endif