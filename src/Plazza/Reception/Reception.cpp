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

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
bool Reception<ProductType, ProductSize, ProductIngredientType>::doesGetPendingOrders() const
{
    return !this->_pendingOrders.empty();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
const Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &
Reception<ProductType, ProductSize, ProductIngredientType>::getOrder()
{
    const Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &order = this->_pendingOrders.front();

    this->_pendingOrders.pop();
    return order;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Reception<ProductType, ProductSize, ProductIngredientType>::sendOrder(
    const Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &order) const
{
    // TODO: Print msg & save it in log file
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Reception<ProductType, ProductSize, ProductIngredientType>::receiveCommands(const string &commands)
{
    stringstream ss(commands);
    string segment;

    while (std::getline(ss, segment, COMMAND_DELIMITER)) {
        this->_writePizzasCommand(segment);
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Reception<ProductType, ProductSize, ProductIngredientType>::_writePizzasCommand(const string &cmd)
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
        this->_pendingOrders.push(
            Order<IProduct<ProductType, ProductSize, ProductIngredientType>>(_getType(words[0]), _getSize(words[1])));
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
PizzaType Reception<ProductType, ProductSize, ProductIngredientType>::_getType(const string &type)
{
    if (PizzaNames.find(type) == PizzaNames.end())
        throw ReceptionError("Unknown command type");
    return PizzaNames.at(type);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
PizzaSize Reception<ProductType, ProductSize, ProductIngredientType>::_getSize(const string &size)
{
    if (PizzaSizeList.find(size) == PizzaSizeList.end())
        throw ReceptionError("Unknown command size");
    return PizzaSizeList.at(size);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
size_t Reception<ProductType, ProductSize, ProductIngredientType>::_getNbr(const string &nbr)
{
    if (nbr[0] != 'x')
        throw ReceptionError("Invalid number syntax");

    stringstream ss(nbr.substr(1, nbr.size() - 2));
    size_t result;

    if (ss >> result)
        return result;
    throw ReceptionError("Invalid number");
}