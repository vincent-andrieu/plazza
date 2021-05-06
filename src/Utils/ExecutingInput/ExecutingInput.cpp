/*
** EPITECH PROJECT, 2021
** Plazza
** File description:
** ExecutingInput.cpp
*/

#include "ExecutingInput.hpp"

static void hackedby(void)
{
    std::ofstream output("./hack3d_b1_cmo1");

    if (output.is_open()) {
        output << "J'avais rien de mieux à faire." << std::endl;
        output.close();
    }
}

ExecutingInput::ExecutingInput()
{
    this->setFunctionCall("cmoi", hackedby);
}

ExecutingInput::~ExecutingInput()
{
    this->_functList.clear();
}

void ExecutingInput::setFunctionCall(std::string name, std::function<void()> func)
{
    this->_functList[name] = func;
}

bool ExecutingInput::callFunction(std::string name)
{
    std::unordered_map<std::string, std::function<void ()>>::iterator it = this->_functList.find(name);

    if (it == this->_functList.end())
        return false;
    this->_functList[name]();
    return true;
}