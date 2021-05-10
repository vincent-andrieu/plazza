/*
 * EPITECH PROJECT, 2021
 * KitchenStatus
 * File description:
 * KitchenStatus.cpp - Created: 06/05/2021
 */

#include "Kitchen/KitchenStatus/KitchenStatus.hpp"

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
KitchenStatus<ProductType, ProductSize, ProductIngredientType>::KitchenStatus(
    const std::queue<Order<AProduct<ProductType, ProductSize, ProductIngredientType>>> pendingOrders,
    const std::queue<Order<AProduct<ProductType, ProductSize, ProductIngredientType>>> finishedOrders,
    const std::unordered_map<ProductIngredientType, size_t> stock)
    : _pendingOrders(pendingOrders), _finishedOrders(finishedOrders), _stock(stock)
{
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
const std::queue<Order<AProduct<ProductType, ProductSize, ProductIngredientType>>> &
KitchenStatus<ProductType, ProductSize, ProductIngredientType>::getPendingOrders() const
{
    return this->_pendingOrders;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
const std::queue<Order<AProduct<ProductType, ProductSize, ProductIngredientType>>> &
KitchenStatus<ProductType, ProductSize, ProductIngredientType>::getFinishedOrders() const
{
    return this->_finishedOrders;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
const std::unordered_map<ProductIngredientType, size_t> &
KitchenStatus<ProductType, ProductSize, ProductIngredientType>::getStock() const
{
    return this->_stock;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
const string KitchenStatus<ProductType, ProductSize, ProductIngredientType>::_SerializeToString() const
{
    std::string serial = "";
    std::queue<Order<AProduct<ProductType, ProductSize, ProductIngredientType>>> finish(this->_finishedOrders);
    std::queue<Order<AProduct<ProductType, ProductSize, ProductIngredientType>>> pending(this->_pendingOrders);
    std::unordered_map<ProductIngredientType, size_t> stock(this->_stock);
    std::unordered_map<string, PizzaSize>::const_iterator size_it;
    std::unordered_map<string, PizzaType>::const_iterator type_it;

    while (finish.size()) {
        const Order<AProduct<ProductType, ProductSize, ProductIngredientType>> tmp = finish.front();
        finish.pop();
        size_it = std::find_if(PizzaSizeList.begin(), PizzaSizeList.end(), [tmp](const auto &params) {
            return params.second == tmp.getOrder().getSize();
        });
        type_it = std::find_if(PizzaNames.begin(), PizzaNames.end(), [tmp](const auto &params) {
            return params.second == tmp.getOrder().getType();
        });
        serial += (type_it->first + std::string(" ") + size_it->first + std::string(" ")
            + std::to_string(tmp.getOrder().getPreparationTime()));
        if (finish.size())
            serial += "|";
    }
    serial += "-";
    while (pending.size()) {
        const Order<AProduct<ProductType, ProductSize, ProductIngredientType>> tmp = pending.front();
        pending.pop();
        size_it = std::find_if(PizzaSizeList.begin(), PizzaSizeList.end(), [tmp](const auto &params) {
            return params.second == tmp.getOrder().getSize();
        });
        type_it = std::find_if(PizzaNames.begin(), PizzaNames.end(), [tmp](const auto &params) {
            return params.second == tmp.getOrder().getType();
        });
        serial += (type_it->first + std::string(" ") + size_it->first + std::string(" ")
            + std::to_string(tmp.getOrder().getPreparationTime()));
        if (pending.size())
            serial += "|";
    }
    serial += "-";
    for (auto &q : stock) {
        serial += PizzaIngredientListName.at(q.first) + std::string(":") + std::to_string(q.second);
        serial += "|";
    }
    return serial;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void KitchenStatus<ProductType, ProductSize, ProductIngredientType>::_SerializeFromString(const string str)
{
    std::istringstream lineStream(str);
    std::string finish = "";
    std::string pending = "";
    std::string stock = "";
    std::string tmp = "";
    stringstream ss;
    std::string word;
    ProductIngredientType ingredient;
    std::unordered_map<PizzaIngredient, string>::const_iterator ingred_it;
    PizzaSize tmp_size;
    PizzaType tmp_type;

    std::getline(lineStream, finish, '-');
    std::getline(lineStream, pending, '-');
    std::getline(lineStream, stock, '-');
    lineStream = std::istringstream(finish);
    while (std::getline(lineStream, tmp, '|')) {
        ss = stringstream(tmp);
        ss >> word;
        tmp_type = Translator::StringToType(word);
        ss >> word;
        tmp_size = Translator::StringToSize(word);
        ss >> word;
        this->_finishedOrders.push(
            Order<AProduct<PizzaType, PizzaSize, PizzaIngredient>>(Factory::callFactory(tmp_type, tmp_size, std::stoull(word))));
    }
    lineStream = std::istringstream(pending);
    while (std::getline(lineStream, tmp, '|')) {
        ss = stringstream(tmp);
        ss >> word;
        tmp_type = Translator::StringToType(word);
        ss >> word;
        tmp_size = Translator::StringToSize(word);
        ss >> word;
        this->_finishedOrders.push(
            Order<AProduct<PizzaType, PizzaSize, PizzaIngredient>>(Factory::callFactory(tmp_type, tmp_size, std::stoull(word))));
    }
    lineStream = std::istringstream(stock);
    while (std::getline(lineStream, tmp, '|')) {
        word = "";
        for (auto x : str) {
            if (x == ':') {
                ingred_it =
                    std::find_if(PizzaIngredientListName.begin(), PizzaIngredientListName.end(), [word](const auto &params) {
                        return params.second == word;
                    });
                ingredient = ingred_it->first;
                word = "";
            } else {
                word += x;
            }
        }
        this->_stock[ingredient] = std::stoull(word);
    }
}

template class KitchenStatus<PizzaType, PizzaSize, PizzaIngredient>;