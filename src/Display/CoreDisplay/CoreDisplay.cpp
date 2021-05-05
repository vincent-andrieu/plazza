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
    Vector screenSize, Vector screenScale, std::size_t maxLen)
    : _maxLen(maxLen), _input(std::make_unique<UserInput>()), _dirName(), _pos(0), _kitechToPrint(0), _screenSize(screenSize), _screenScale(screenScale)
{
    listDir lib("./lib/", "arcade_.+\\.so");
    std::vector<std::string> nameList = lib.getDirContent();
    std::vector<std::string>::iterator it = nameList.begin();

    for (size_t i = 0; it != nameList.end(); it++, i++) {
        this->_dirName[i] = std::make_unique<DLLib<IDisplayModule>>(std::string("./lib/") + *it);
        this->_dirName[i]->setEntryPoint("entryPoint");
    }
    this->_dirName[this->_pos]->getEntryPoint()->open(this->_screenSize, this->_screenScale);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
CoreDisplay<ProductType, ProductSize, ProductIngredientType>::~CoreDisplay()
{
    this->_dirName[this->_pos]->getEntryPoint()->close();
    this->_input.reset();
    this->_dirName.clear();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::setPrompt(std::string prompt)
{
    this->_prompt = prompt;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::printPrompt()
{
    std::string to_display = this->_prompt + this->_input->getInput();

    to_display = to_display.substr(0, this->_maxLen);
    this->_dirName[this->_pos]->getEntryPoint()->putText(IDisplayModule::Color::WHITE, Coord(0, 0), to_display);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::printKitchen(
    std::vector<KitchenManage<ProductType, ProductSize, ProductIngredientType>> kitchenList)
{
    typename std::vector<KitchenManage<ProductType, ProductSize, ProductIngredientType>>::iterator it =
        kitchenList.begin();
    std::string to_display = "";
    std::size_t pos_y = 1;
    std::size_t max = 15;
    size_t len = 0;

    for (; it != kitchenList.end() && max; it++, pos_y += 3, max--) {
        this->_dirName[this->_pos]->getEntryPoint()->putRectOutline(IDisplayModule::Color::YELLOW, Coord(20, 3), Coord(0, pos_y));
        to_display = (it->kitchen.isCooking()) ? "Working" : "Pending";
        this->_dirName[this->_pos]->getEntryPoint()->putText(IDisplayModule::Color::CYAN, Coord(1, pos_y + 1), to_display);
    }
    if (it != kitchenList.end()) {
        this->_dirName[this->_pos]->getEntryPoint()->putText(IDisplayModule::Color::CYAN, Coord(0, pos_y + 1), "too much kitchen ...");
        pos_y += 3;
    }
    to_display = std::string("There are ") + std::to_string(kitchenList.size()) + std::string(" kitchens.");
    this->_dirName[this->_pos]->getEntryPoint()->putText(IDisplayModule::Color::CYAN, Coord(0, pos_y + 1), to_display);
    len = kitchenList.size();
    if (len) {
        if (len >= this->_kitechToPrint)
            this->_kitechToPrint = len - 1;
        this->printDetailledKitchen(kitchenList[this->_kitechToPrint]);
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::printDetailledKitchen(
    KitchenManage<ProductType, ProductSize, ProductIngredientType> kitchen)
{
    std::string to_display = "";
    std::size_t pos_y = 4;

    this->_dirName[this->_pos]->getEntryPoint()->putRectOutline(IDisplayModule::Color::WHITE, Coord(30, 30), Coord(30, pos_y++));
    to_display = (kitchen.kitchen.isCooking()) ? "Working" : "Pending";
    this->_dirName[this->_pos]->getEntryPoint()->putText(IDisplayModule::Color::CYAN, Coord(31, pos_y++), std::string("Status: ") + to_display);
    to_display = std::to_string(kitchen.kitchen.getNbCooks());
    this->_dirName[this->_pos]->getEntryPoint()->putText(IDisplayModule::Color::CYAN, Coord(31, pos_y++), std::string("Cookers: ") + to_display);
    to_display = std::to_string(kitchen.kitchen.getBakingMultiplier());
    this->_dirName[this->_pos]->getEntryPoint()->putText(IDisplayModule::Color::CYAN, Coord(31, pos_y++), std::string("Multiplier: ") + to_display);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
std::string CoreDisplay<ProductType, ProductSize, ProductIngredientType>::getLine() const
{
    std::string input = this->_input->getInput();
    std::size_t pos = input.find('\n');
    std::string exec;

    if (pos == std::string::npos)
        return std::string("");
    exec = input.substr(0, pos);
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
    this->libraryDisplaySwitch();
    this->kitchenSwitch();
    this->_dirName[this->_pos]->getEntryPoint()->displayScreen();
    this->_dirName[this->_pos]->getEntryPoint()->refreshScreen();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::clear()
{
    this->_input->runInput(this->_dirName[this->_pos]->getEntryPoint());
    this->_dirName[this->_pos]->getEntryPoint()->clearScreen();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::libraryDisplaySwitch()
{
    if (this->_dirName[this->_pos]->getEntryPoint()->isKeyPress(IDisplayModule::KeyList::ARROW_LEFT)) {
        this->_dirName[this->_pos]->getEntryPoint()->close();
        this->_pos = (this->_pos > 0) ? this->_pos - 1 : this->_dirName.size() - 1;
    } else if (this->_dirName[this->_pos]->getEntryPoint()->isKeyPress(IDisplayModule::KeyList::ARROW_RIGHT)) {
        this->_dirName[this->_pos]->getEntryPoint()->close();
        this->_pos = (this->_pos < this->_dirName.size() - 1) ? this->_pos + 1 : 0;
    } else {
        return;
    }
    this->_dirName[this->_pos]->getEntryPoint()->open(this->_screenSize, this->_screenScale);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
bool CoreDisplay<ProductType, ProductSize, ProductIngredientType>::isRunning()
{
    return this->_dirName[this->_pos]->getEntryPoint()->isOpen();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::setError(std::string error)
{
    if (error.length() > 50)
        error = error.substr(0, 24) + std::string(" ...");
    this->_error = error;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::printError()
{
    size_t pos_y = 1;
    size_t pos_x = 30;

    if (this->_error.length()) {
        this->_dirName[this->_pos]->getEntryPoint()->putRectOutline(IDisplayModule::Color::RED, Coord(52, 3), Coord(pos_x, pos_y));
        this->_dirName[this->_pos]->getEntryPoint()->putText(IDisplayModule::Color::WHITE, Coord(pos_x + 1, pos_y + 1), this->_error);
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void CoreDisplay<ProductType, ProductSize, ProductIngredientType>::kitchenSwitch()
{
    if (this->_dirName[this->_pos]->getEntryPoint()->isKeyPress(IDisplayModule::KeyList::ARROW_DOWN)) {
        this->_kitechToPrint = (this->_kitechToPrint > 0) ? this->_kitechToPrint - 1 : 0;
    } else if (this->_dirName[this->_kitechToPrint]->getEntryPoint()->isKeyPress(IDisplayModule::KeyList::ARROW_UP)) {
        this->_kitechToPrint++;
    }
}

template class CoreDisplay<PizzaType, PizzaSize, PizzaIngredient>;