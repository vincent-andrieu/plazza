/*
 * EPITECH PROJECT, 2021
 * KitchenStatus
 * File description:
 * KitchenStatus.cpp - Created: 06/05/2021
 */

#include "Kitchen/KitchenStatus/KitchenStatus.hpp"

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
KitchenStatus<ProductType, ProductSize, ProductIngredientType>::KitchenStatus(
    const std::queue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> &pendingOrders,
    const std::unordered_map<ProductIngredientType, size_t> &stock,
    const std::vector<Order<Product<ProductType, ProductSize, ProductIngredientType>>> &isCookingOrders)
    : _pendingOrders(pendingOrders), _stock(stock), _isCookingOrders(isCookingOrders)
{
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
const std::queue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> &
KitchenStatus<ProductType, ProductSize, ProductIngredientType>::getPendingOrders() const
{
    return this->_pendingOrders;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
const std::queue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> &
KitchenStatus<ProductType, ProductSize, ProductIngredientType>::getFinishedOrders() const
{
    return this->_finishedOrders;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void KitchenStatus<ProductType, ProductSize, ProductIngredientType>::addFinishedOrders(
    const Order<Product<ProductType, ProductSize, ProductIngredientType>> &order)
{
    this->_finishedOrders.push(order);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
const std::vector<Order<Product<ProductType, ProductSize, ProductIngredientType>>> &
KitchenStatus<ProductType, ProductSize, ProductIngredientType>::getIsCookingOrders() const
{
    return this->_isCookingOrders;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
const std::unordered_map<ProductIngredientType, size_t> &
KitchenStatus<ProductType, ProductSize, ProductIngredientType>::getStock() const
{
    return this->_stock;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
const string KitchenStatus<ProductType, ProductSize, ProductIngredientType>::SerializeToString() const
{
    string serial;
    std::queue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> pending(this->_pendingOrders);
    std::unordered_map<ProductIngredientType, size_t> stock(this->_stock);
    std::unordered_map<string, PizzaSize>::const_iterator size_it;
    std::unordered_map<string, PizzaType>::const_iterator type_it;

    while (!pending.empty()) {
        const Order<Product<ProductType, ProductSize, ProductIngredientType>> tmp = pending.front();
        pending.pop();
        serial += (toString(tmp->getType()) + " " + toString(tmp->getSize()) + " " + toString(tmp->getPreparationTime()));
        if (!pending.empty())
            serial += "|";
    }
    serial += "-";
    for (auto &q : stock) {
        serial += toString(q.first) + ":" + toString(q.second);
        serial += "|";
    }
    serial += "-";
    for (const Order<Product<ProductType, ProductSize, ProductIngredientType>> &order : this->_isCookingOrders) {
        serial += (toString(order->getType()) + " " + toString(order->getSize()) + " " + toString(order->getPreparationTime()));
        serial += "|";
    }
    return serial;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void KitchenStatus<ProductType, ProductSize, ProductIngredientType>::SerializeFromString(const string &str)
{
    std::queue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> emptyQueue;
    std::istringstream lineStream(str);
    string pending;
    string stock;
    string isCooking;
    string tmp;
    stringstream ss;
    string word;
    ProductIngredientType ingredient;
    std::unordered_map<PizzaIngredient, string>::const_iterator ingred_it;
    PizzaSize tmp_size;
    PizzaType tmp_type;

    std::getline(lineStream, pending, '-');
    std::getline(lineStream, stock, '-');
    std::getline(lineStream, isCooking, '-');
    lineStream = std::istringstream(pending);
    this->_pendingOrders.swap(emptyQueue);
    while (std::getline(lineStream, tmp, '|')) {
        ss = stringstream(tmp);
        ss >> word;
        tmp_type = (PizzaType) toInteger(word);
        ss >> word;
        tmp_size = (PizzaSize) toInteger(word);
        ss >> word;
        this->_pendingOrders.push(
            Order<Product<PizzaType, PizzaSize, PizzaIngredient>>(Factory::callFactory(tmp_type, tmp_size, toSize_t(word))));
    }
    lineStream = std::istringstream(stock);
    while (std::getline(lineStream, tmp, '|')) {
        word = "";
        for (auto x : tmp) {
            if (x == ':') {
                ingredient = (ProductIngredientType) toInteger(word);
                word = "";
            } else {
                word += x;
            }
        }
        this->_stock[ingredient] = toSize_t(word);
    }
    lineStream = std::istringstream(isCooking);
    this->_isCookingOrders.clear();
    while (std::getline(lineStream, tmp, '|')) {
        ss = stringstream(tmp);
        ss >> word;
        tmp_type = (PizzaType) toInteger(word);
        ss >> word;
        tmp_size = (PizzaSize) toInteger(word);
        ss >> word;
        this->_isCookingOrders.push_back(
            Order<Product<PizzaType, PizzaSize, PizzaIngredient>>(Factory::callFactory(tmp_type, tmp_size, toSize_t(word))));
    }
}

template class KitchenStatus<PizzaType, PizzaSize, PizzaIngredient>;