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
#include "Product/Pizza/Factory/Factory.hpp"

using namespace Pizzeria;

Reception::Reception(double multiplier) : _bakingMultiplier(multiplier)
{
}

void Reception::sendOrder(const Order<AProduct<PizzaType, PizzaSize, PizzaIngredient>> &order) const
{
    (void) order;
    // TODO: Print msg & save it in log file
}

void Reception::receiveCommands(
    const string &commands, std::queue<Order<AProduct<PizzaType, PizzaSize, PizzaIngredient>>> &orderList)
{
    stringstream ss(commands);
    string segment;

    while (std::getline(ss, segment, COMMAND_DELIMITER)) {
        this->_writePizzasCommand(segment, orderList);
    }
}

void Reception::_writePizzasCommand(
    const string &cmd, std::queue<Order<AProduct<PizzaType, PizzaSize, PizzaIngredient>>> &orderList)
{
    stringstream ss(cmd);
    string word;
    std::vector<string> words;

    while (ss >> word)
        words.push_back(word);
    if (words.size() != 3)
        throw ReceptionError("Invalid command arguments");

    const size_t nbr = _getNbr(words[2]);
    for (size_t i = 0; i < nbr; i++) {
        const AProduct<PizzaType, PizzaSize, PizzaIngredient> product =
            Factory::callFactory(this->_getType(words[0]), this->_getSize(words[1]), this->_bakingMultiplier);

        orderList.push(Order<AProduct<PizzaType, PizzaSize, PizzaIngredient>>(product));
    }
}

PizzaType Reception::_getType(const string &type)
{
    string upper_type(type);

    std::transform(upper_type.begin(), upper_type.end(), upper_type.begin(), ::toupper);
    if (PizzaNames.find(upper_type) == PizzaNames.end())
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
    if (std::tolower(nbr[0]) != 'x')
        throw ReceptionError("Invalid number syntax");

    stringstream ss(nbr.substr(1, nbr.size() - 1));
    size_t result;

    if (ss >> result)
        return result;
    throw ReceptionError("Invalid number");
}