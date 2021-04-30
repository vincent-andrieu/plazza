/*
 * EPITECH PROJECT, 2021
 * DisplayManage
 * File description:
 * DisplayManage.cpp - Created: 21/04/2021
 */

#include "CoreDisplay.hpp"

CoreDisplay::CoreDisplay(std::string filepath, Vector screenSize, Vector screenScale, std::size_t maxLen) :
_prompt(""), _maxLen(maxLen),
_loader(std::make_unique<DLLib<IDisplayModule>>(filepath)),
_input(std::make_unique<UserInput>())
{
    this->_loader->setEntryPoint("entryPoint");
    this->_loader->getEntryPoint()->open(screenSize, screenScale);
}

CoreDisplay::~CoreDisplay()
{
    this->_loader->getEntryPoint()->close();
    this->_loader.reset();
    this->_input.reset();
}

void CoreDisplay::setPrompt(std::string prompt)
{
    this->_prompt = prompt;
}

void CoreDisplay::printPrompt() const
{
    std::string to_display = this->_prompt + this->_input->getInput();

    to_display = to_display.substr(0, this->_maxLen);
    this->_loader->getEntryPoint()->putText(IDisplayModule::Color::WHITE, Coord(0, 0), to_display);
}

void CoreDisplay::printKitchen(std::vector<std::shared_ptr<IKitchen>> kitchenList)
{
    std::vector<std::shared_ptr<IKitchen>>::iterator it = kitchenList.begin();
    std::string to_display = "";
    std::size_t pos_y = 1;
    std::size_t max = 15;

    for (; it != kitchenList.end() && max; it++, pos_y += 3, max--) {
        this->_loader->getEntryPoint()->putRectOutline(IDisplayModule::Color::YELLOW, Coord(20, 3), Coord(0, pos_y));
        to_display = ((*it)->isCooking()) ? "Working" : "Pending";
        this->_loader->getEntryPoint()->putText(IDisplayModule::Color::CYAN, Coord(1, pos_y + 1), to_display);
    }
    if (it != kitchenList.end()) {
        this->_loader->getEntryPoint()->putText(IDisplayModule::Color::CYAN, Coord(0, pos_y + 1), "too much kitchen ...");
        pos_y += 3;
    }
    to_display = std::string("There are ") + std::to_string(kitchenList.size()) + std::string(" kitchens.");
    this->_loader->getEntryPoint()->putText(IDisplayModule::Color::CYAN, Coord(0, pos_y + 1), to_display);
}

void CoreDisplay::printDetailledKitchen(std::shared_ptr<IKitchen> kitchen)
{
    this->_loader->getEntryPoint()->putRectOutline(IDisplayModule::Color::WHITE, Coord(30, 30), Coord(30, 1));
    (void) kitchen;
}

std::string CoreDisplay::getLine() const
{
    std::string input = this->_input->getInput();
    std::size_t pos = input.find('|');
    std::string exec = "";

    if (pos == std::string::npos)
        return std::string("");
    exec = input.substr(0, pos - 1);
    this->_input->setInputState(input.substr(pos + 1, input.length()));
    return exec;
}

void CoreDisplay::setLine(std::string line)
{
    this->_input->setInputState(line);
}

void CoreDisplay::update()
{
    this->_loader->getEntryPoint()->displayScreen();
    this->_loader->getEntryPoint()->refreshScreen();
}

void CoreDisplay::clear()
{
    this->_input->runInput(this->_loader->getEntryPoint());
    this->_loader->getEntryPoint()->clearScreen();
}