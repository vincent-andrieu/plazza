/*
** EPITECH PROJECT, 2021
** Cook.cpp
** File description:
** Cooks prepare and deliver products
*/

#include "Cook.hpp"

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
    _isWorking = true;
    std::shared_ptr<IProduct<ProductType, ProductSize, ProductIngredientType>> order(nullptr);

    while (_isWorking) {
        order = receiveOrder();
        if (order) {
            cook(order);
            deliverOrder(order);
        }
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Cook<ProductType, ProductSize, ProductIngredientType>::setStockPlace(Stock<ProductIngredientType> &stockPlace)
{
    _stockPlace = stockPlace;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Cook<ProductType, ProductSize, ProductIngredientType>::setOrderReceivePlace(
    LockedQueue<Order<std::shared_ptr<IProduct<ProductType, ProductSize, ProductIngredientType>>>> &orderReceivePlace)
{
    _orderReceivePlace = orderReceivePlace;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Cook<ProductType, ProductSize, ProductIngredientType>::setDeliveryPlace(
    LockedQueue<Order<std::shared_ptr<IProduct<ProductType, ProductSize, ProductIngredientType>>>> &deliveryPlace)
{
    _deliveryPlace = deliveryPlace;
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
    Order<std::shared_ptr<IProduct<ProductType, ProductSize, ProductIngredientType>>> order)
{
    std::shared_ptr<IProduct<ProductType, ProductSize, ProductIngredientType>> my_product = order.getOrder();
    ProductIngredientType my_ingredients;

    pickIngredientInStock(my_product->getIngredients());
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
    return _orderReceivePlace.queue;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Cook<ProductType, ProductSize, ProductIngredientType>::deliverOrder() const
{
    if (_cookingProduct->isFinished)
        throw CookError("Product not finished");
    _deliveryPlace.push(_cookingProduct);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
bool Cook<ProductType, ProductSize, ProductIngredientType>::pickIngredientInStock(const ProductIngredientType &ingredient)
{
    return _stockPlace.takeIngredients(ingredient, 1);
}