/*
 * EPITECH PROJECT, 2021
 * Reception
 * File description:
 * Reception.cpp - Created: 27/04/2021
 */

#include "Reception/Reception.hpp"
#include "Error/Error.hpp"
#include "enumPizza.hpp"
#include "Order/Order.hpp"
#include "Product/Pizza/Factory/Factory.hpp"

using namespace Pizzeria;

Reception::Reception(double multiplier) : _bakingMultiplier(multiplier), _logger(std::make_unique<Logger>("./log_plazza"))
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

void Reception::sendOrder(const Order<IProduct<PizzaType, PizzaSize, PizzaIngredient>> &order)
{
    PizzaSize size = order.getOrder().getSize();
    PizzaType type = order.getOrder().getType();
    std::unordered_map<std::string, PizzaSize>::const_iterator size_it = std::find_if(PizzaSizeList.begin(), PizzaSizeList.end(), [size](const auto &params) {return params.second == size;});
    std::unordered_map<std::string, PizzaType>::const_iterator type_it = std::find_if(PizzaNames.begin(), PizzaNames.end(), [type](const auto &params) {return params.second == type;});
    std::string to_write = "";

    if (size_it == PizzaSizeList.end() || type_it == PizzaNames.end()) {
        this->_logger->writeLog("Data not correctly defined");
        return;
    }
    to_write = std::string("Size: ") + size_it->first + std::string(" Type: ") + type_it->first + std::string("\n");
    this->_logger->writeLog(to_write);
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
    for (size_t i = 0; i < nbr; i++) {
        const std::unique_ptr<IProduct<PizzaType, PizzaSize, PizzaIngredient>> &product =
            Factory::callFactory(this->_getType(words[0]), this->_getSize(words[1]), this->_bakingMultiplier);
        this->_pendingOrders.push(Order<IProduct<PizzaType, PizzaSize, PizzaIngredient>>(*product.get()));
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