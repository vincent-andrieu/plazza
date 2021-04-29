/*
 * EPITECH PROJECT, 2021
 * DisplayManage
 * File description:
 * DisplayManage.cpp - Created: 21/04/2021
 */

#include "CoreDisplay.hpp"

CoreDisplay::CoreDisplay(std::string filepath, Vector screenSize, Vector screenScale, std::size_t maxLen) :
_prompt(""), _maxLen(maxLen), _line(""),
_loader(std::make_unique<DLLib<IDisplayModule>>(filepath))
{
    this->_loader->getEntryPoint()->open(screenSize, screenScale);
}

CoreDisplay::~CoreDisplay()
{
    this->_loader->getEntryPoint()->close();
    this->_loader.reset();
}

void CoreDisplay::setPrompt(std::string prompt)
{
    this->_prompt = prompt;
}

void CoreDisplay::printPrompt() const
{
    std::string to_display = this->_prompt + this->_line;

    to_display = to_display.substr(0, this->_maxLen);
    this->_loader->getEntryPoint()->putText(IDisplayModule::Color::WHITE, Coord(0, 0), to_display);
}

void CoreDisplay::printKitchen(std::vector<std::unique_ptr<IKitchen>> kitchenList)
{
    std::vector<std::unique_ptr<IKitchen>>::iterator it = kitchenList.begin();

    for (; it != kitchenList.end(); it++) {
        (void) it;
    }
}

void CoreDisplay::printDetailledKitchen(std::unique_ptr<IKitchen> kitchen)
{
    (void) kitchen;
}

std::string CoreDisplay::getLine() const
{
    return this->_line;
}

void CoreDisplay::setLine(std::string line)
{
    this->_line = line;
}