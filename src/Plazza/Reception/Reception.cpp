/*
 * EPITECH PROJECT, 2021
 * Reception
 * File description:
 * Reception.cpp - Created: 27/04/2021
 */

#include <algorithm>
#include "Reception/Reception.hpp"
#include "Error/Error.hpp"
#include "enumPizza.hpp"

bool Reception::doesGetPendingOrders() const
{
    return !this->_pendingOrders.empty();
}

const Order &Reception::getOrder()
{
    const Order &order = this->_pendingOrders.front();

    this->_pendingOrders.pop();
    return order;
}

void Reception::sendOrder(const Order &order) const
{
    // TODO: Print msg & save it in log file
}

void Reception::receiveCommands(const string &commands)
{
    stringstream ss(commands);
    string segment;

    while (std::getline(ss, segment, COMMAND_DELIMITER)) {
        this->_writePizzasCommand(segment);
    }
}

void Reception::_writePizzasCommand(const string &cmd)
{
    stringstream ss(cmd);
    string word;
    std::vector<string> words;

    while (ss >> word)
        words.push_back(word);
    if (words.size() != 3)
        throw ReceptionError("Invalid command arguments");

    const size_t nbr = _getNbr(words[2]);
    for (size_t i = 0; i < nbr; i++)
        this->_pendingOrders.push(Order(_getType(words[0]), _getSize(words[1])));
}

PizzaType Reception::_getType(const string &type)
{
    if (PizzaNames.find(type) == PizzaNames.end())
        throw ReceptionError("Unknown command type");
    return PizzaNames.at(type);
}

PizzaSize Reception::_getSize(const string &size)
{
    if (PizzaSizeList.find(size) == PizzaSizeList.end())
        throw ReceptionError("Unknown command size");
    return PizzaSizeList.at(size);
}

size_t Reception::_getNbr(const string &nbr)
{
    if (nbr[0] != 'x')
        throw ReceptionError("Invalid number syntax");

    stringstream ss(nbr.substr(1, nbr.size() - 2));
    size_t result;

    if (ss >> result)
        return result;
    throw ReceptionError("Invalid number");
}