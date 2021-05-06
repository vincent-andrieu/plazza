/*
** EPITECH PROJECT, 2021
** Cook.cpp
** File description:
** Cooks prepare and deliver products
*/

#include "Cook.hpp"
#include "enumPizza.hpp"

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
Cook<ProductType, ProductSize, ProductIngredientType>::Cook(Stock<ProductIngredientType> &stockPlace,
    LockedQueue<Order<std::shared_ptr<IProduct<ProductType, ProductSize, ProductIngredientType>>>> &orderReceivePlace,
    LockedQueue<Order<std::shared_ptr<IProduct<ProductType, ProductSize, ProductIngredientType>>>> &deliveryPlace)
    : _stockPlace(stockPlace), _orderReceivePlace(orderReceivePlace), _deliveryPlace(deliveryPlace)
{
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Cook<ProductType, ProductSize, ProductIngredientType>::startWorking()
{
    std::shared_ptr<IProduct<ProductType, ProductSize, ProductIngredientType>> order(nullptr);
    _isWorking = true;

    while (_isWorking) {
        order = receiveOrder().getOrder();
        if (order) {
            cook(order);
            deliverOrder();
        }
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
bool Cook<ProductType, ProductSize, ProductIngredientType>::isCooking() const
{
    return _isCooking;
}
template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Cook<ProductType, ProductSize, ProductIngredientType>::stopWorking()
{
    _isWorking = false;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Cook<ProductType, ProductSize, ProductIngredientType>::cook(
    std::shared_ptr<IProduct<ProductType, ProductSize, ProductIngredientType>> order)
{
    _cookingProduct = order;

    std::vector<ProductIngredientType> my_pendingIngredients(_cookingProduct->getIngredients());

    for (auto iterator = my_pendingIngredients.begin(); !my_pendingIngredients.empty(); ++iterator) {
        if (iterator == my_pendingIngredients.end())
            iterator = my_pendingIngredients.begin();
        if (pickIngredientInStock(*iterator))
            my_pendingIngredients.erase(iterator);
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
bool Cook<ProductType, ProductSize, ProductIngredientType>::hasFinishedCooking() const
{
    if (!_cookingProduct)
        throw CookError("No cooking product");
    return _cookingProduct->isFinished();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
Order<std::shared_ptr<IProduct<ProductType, ProductSize, ProductIngredientType>>>
Cook<ProductType, ProductSize, ProductIngredientType>::receiveOrder() const
{
    return _orderReceivePlace.getFront();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Cook<ProductType, ProductSize, ProductIngredientType>::deliverOrder()
{
    if (_cookingProduct->isFinished())
        throw CookError("Product not finished");

    Order<std::shared_ptr<IProduct<ProductType, ProductSize, ProductIngredientType>>> my_delivery(_cookingProduct);
    _deliveryPlace.push(my_delivery);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
bool Cook<ProductType, ProductSize, ProductIngredientType>::pickIngredientInStock(const ProductIngredientType &ingredient)
{
    return _stockPlace.takeIngredients(ingredient, 1);
}

template class Cook<Pizzeria::PizzaType, Pizzeria::PizzaSize, Pizzeria::PizzaIngredient>;