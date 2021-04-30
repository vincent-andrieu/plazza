/*
 * EPITECH PROJECT, 2021
 * DisplayManage
 * File description:
 * DisplayManage.cpp - Created: 21/04/2021
 */

#include "CoreDisplay.hpp"

using namespace Pizzeria;

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
CoreDisplay<ProductType, ProductSize, ProductIngredientType>::CoreDisplay(
    std::string filepath, Vector screenSize, Vector screenScale, std::size_t maxLen)
    : _maxLen(maxLen), _loader(std::make_unique<DLLib<IDisplayModule>>(filepath)), _input(std::make_unique<UserInput>())
{
    this->_loader->setEntryPoint("entryPoint");
    this->_loader->getEntryPoint()->open(screenSize, screenScale);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
CoreDisplay<ProductType, ProductSize, ProductIngredientType>::~CoreDisplay()
{
    this->_loader->getEntryPoint()->close();
    this->_loader.reset();
    this->_input.reset();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::setPrompt(std::string prompt)
{
    this->_prompt = prompt;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::printPrompt() const
{
    std::string to_display = this->_prompt + this->_input->getInput();

    to_display = to_display.substr(0, this->_maxLen);
    this->_loader->getEntryPoint()->putText(IDisplayModule::Color::WHITE, Coord(0, 0), to_display);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::printKitchen(
    std::vector<std::unique_ptr<IKitchen<ProductType, ProductSize, ProductIngredientType>>> kitchenList)
{
    typename std::vector<std::unique_ptr<IKitchen<ProductType, ProductSize, ProductIngredientType>>>::iterator it =
        kitchenList.begin();

    for (; it != kitchenList.end(); it++) {
        (void) it;
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::printDetailledKitchen(
    std::unique_ptr<IKitchen<ProductType, ProductSize, ProductIngredientType>> kitchen)
{
    (void) kitchen;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
std::string CoreDisplay<ProductType, ProductSize, ProductIngredientType>::getLine() const
{
    std::string input = this->_input->getInput();
    std::size_t pos = input.find('|');
    std::string exec;

    if (pos == std::string::npos)
        return std::string("");
    exec = input.substr(0, pos - 1);
    this->_input->setInputState(input.substr(pos + 1, input.length()));
    return exec;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::setLine(std::string line)
{
    this->_input->setInputState(line);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::update()
{
    this->_loader->getEntryPoint()->displayScreen();
    this->_loader->getEntryPoint()->refreshScreen();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::clear()
{
    this->_input->runInput(this->_loader->getEntryPoint());
    this->_loader->getEntryPoint()->clearScreen();
}