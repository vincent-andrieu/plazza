/*
** EPITECH PROJECT, 2021
** Plazza
** File description:
** UserInput.cpp
*/

#include "UserInput.hpp"

UserInput::UserInput() : _input("")
{
}

UserInput::~UserInput()
{
    this->_input.clear();
}

void UserInput::reset()
{
    this->_input = "";
}

void UserInput::runInput(std::shared_ptr<IDisplayModule> module)
{
    for (auto it = this->_link.begin(); it != this->_link.end(); it++) {
        if (module->isKeyPress(it->first) && this->_input.length() < USERMAXLEN) {
            this->_input += it->second;
        }
    }
    if (this->_input.length() && module->isKeyPress(IDisplayModule::KeyList::BACK_SPACE))
        this->_input.pop_back();
}

std::string UserInput::getInput() const
{
    return this->_input;
}

void UserInput::setInputState(std::string line)
{
    this->_input = line;
}