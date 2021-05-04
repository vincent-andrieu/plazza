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
#include "Order/Order.hpp"
#include "Pizza/Factory/Factory.hpp"

using namespace Pizzeria;

Reception::Reception(double multiplier) : _bakingMultiplier(multiplier)
{
}

bool Reception::doesGetPendingOrders() const
{
    return !this->_pendingOrders.empty();
}

bool Reception::getOrder(Order<IProduct<PizzaType, PizzaSize, PizzaIngredient>> &order)
{
    if (this->_pendingOrders.empty())
        return false;
    order.setOrder(this->_pendingOrders.front().getOrder());

    this->_pendingOrders.pop();
    return true;
}

void Reception::sendOrder(const Order<IProduct<PizzaType, PizzaSize, PizzaIngredient>> &order) const
{
    (void) order;
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

    const size_t nbr = this->_getNbr(words[2]);
    for (size_t i = 0; i < nbr; i++) {
        const std::unique_ptr<IProduct<PizzaType, PizzaSize, PizzaIngredient>> &product =
            Factory::callFactory(this->_getType(words[0]), this->_getSize(words[1]), this->_bakingMultiplier);
        this->_pendingOrders.push(Order<IProduct<PizzaType, PizzaSize, PizzaIngredient>>(*product.get()));
    }
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