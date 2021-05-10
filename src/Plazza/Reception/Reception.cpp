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

Reception::Reception(double multiplier, std::function<void()> statusFunc, std::function<void()> quitFunc)
    : _bakingMultiplier(multiplier), _logger(LOG_FILE_PATH)
{
    this->_otherCommand.setFunctionCall("STATUS", statusFunc);
    this->_otherCommand.setFunctionCall("QUIT", quitFunc);
}

void Reception::sendOrder(const Order<AProduct<PizzaType, PizzaSize, PizzaIngredient>> &order)
{
    PizzaSize size = order.getOrder().getSize();
    PizzaType type = order.getOrder().getType();
    std::unordered_map<string, PizzaSize>::const_iterator size_it =
        std::find_if(PizzaSizeList.begin(), PizzaSizeList.end(), [size](const auto &params) {
            return params.second == size;
        });
    std::unordered_map<string, PizzaType>::const_iterator type_it =
        std::find_if(PizzaNames.begin(), PizzaNames.end(), [type](const auto &params) {
            return params.second == type;
        });
    string to_write;

    if (size_it == PizzaSizeList.end() || type_it == PizzaNames.end()) {
        this->_logger.writeLog("Data not correctly defined");
        return;
    }
    to_write = "Size: " + size_it->first + " Type: " + type_it->first + "\n";
    this->_logger.writeLog(to_write);
}

void Reception::sendKitchenStatus(const KitchenStatus<PizzaType, PizzaSize, PizzaIngredient> &kitchenStatus)
{
    std::string tab = "\t";
    std::queue<Order<AProduct<PizzaType, PizzaSize, PizzaIngredient>>> finish(kitchenStatus.getFinishedOrders());
    std::queue<Order<AProduct<PizzaType, PizzaSize, PizzaIngredient>>> pending(kitchenStatus.getPendingOrders());
    std::unordered_map<PizzaIngredient, size_t> stock(kitchenStatus.getStock());
    std::unordered_map<string, PizzaSize>::const_iterator size_it;
    std::unordered_map<string, PizzaType>::const_iterator type_it;
    std::string to_write = "";

    this->_logger.writeLog("kitchen status:");
    this->_logger.writeLog(tab + std::string("finish order:"));
    while (finish.size()) {
        const Order<AProduct<PizzaType, PizzaSize, PizzaIngredient>> tmp = finish.front();
        finish.pop();
        size_it = std::find_if(PizzaSizeList.begin(), PizzaSizeList.end(), [tmp](const auto &params) {
            return params.second == tmp.getOrder().getSize();
        });
        type_it = std::find_if(PizzaNames.begin(), PizzaNames.end(), [tmp](const auto &params) {
            return params.second == tmp.getOrder().getType();
        });
        if (size_it == PizzaSizeList.end() || type_it == PizzaNames.end())
            to_write = "data wrong";
        else
            to_write = std::string("type: ") + type_it->first + std::string(" size: ") + size_it->first;
        this->_logger.writeLog(tab + tab + to_write);
    }

    this->_logger.writeLog(tab + std::string("pending order:"));
    while (pending.size()) {
        const Order<AProduct<PizzaType, PizzaSize, PizzaIngredient>> tmp = pending.front();
        pending.pop();
        size_it = std::find_if(PizzaSizeList.begin(), PizzaSizeList.end(), [tmp](const auto &params) {
            return params.second == tmp.getOrder().getSize();
        });
        type_it = std::find_if(PizzaNames.begin(), PizzaNames.end(), [tmp](const auto &params) {
            return params.second == tmp.getOrder().getType();
        });
        if (size_it == PizzaSizeList.end() || type_it == PizzaNames.end())
            to_write = "data wrong";
        else
            to_write = std::string("type: ") + type_it->first + std::string(" size: ") + size_it->first;
        this->_logger.writeLog(tab + tab + to_write);
    }

    this->_logger.writeLog(tab + std::string("stock:"));
    for (auto &q : stock) {
        try {
            to_write = PizzaIngredientListName.at(q.first) + std::string(": ") + std::to_string(q.second);
        } catch (const std::out_of_range & e) {
            to_write = std::string("Internal error: ") + e.what();
        }
        this->_logger.writeLog(tab + tab + to_write);
    }
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
    if (words.size() != 3) {
        if (words.size() == 1) {
            if (!this->_otherCommand.callFunction(words[0]))
                throw ReceptionError("Invalid command arguments");
            else
                return;
        } else {
            throw ReceptionError("Invalid command arguments");
        }
    }

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