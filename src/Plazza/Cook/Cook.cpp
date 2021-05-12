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
    LockedQueue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> &orderReceivePlace,
    LockedQueue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> &deliveryPlace)
    : _stockPlace(stockPlace), _orderReceivePlace(orderReceivePlace), _deliveryPlace(deliveryPlace)
{
}
template <typename ProductType, typename ProductSize, typename ProductIngredientType>
Cook<ProductType, ProductSize, ProductIngredientType>::~Cook()
{
    _isWorking = false;
    if (_thread.joinable()) {
        _thread.join();
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
Cook<ProductType, ProductSize, ProductIngredientType>::Cook(const Cook<ProductType, ProductSize, ProductIngredientType> &rhs)
    : _isWorking(rhs.isWorking()), _isCooking(rhs.isCooking()), _cookingProduct(rhs.getCookingProduct()),
      _stockPlace(rhs.getStockPlace()), _orderReceivePlace(rhs.getOrderReceivePlace()), _deliveryPlace(rhs.getDeliveryPlace()),
      _thread(std::thread())
{
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Cook<ProductType, ProductSize, ProductIngredientType>::startWorking()
{
    _isWorking = true;
    _thread = std::thread(&Cook::work, this);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Cook<ProductType, ProductSize, ProductIngredientType>::work()
{
    Product<ProductType, ProductSize, ProductIngredientType> order;

    while (_isWorking) {
        try {
            order = _receiveOrder().getOrder();
        } catch (...) {
            continue;
        }
        this->_cook(order);
        if (this->_cookingProduct.isFinished())
            _deliverOrder();
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
bool Cook<ProductType, ProductSize, ProductIngredientType>::isCooking() const
{
    return _isCooking;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
bool Cook<ProductType, ProductSize, ProductIngredientType>::isWorking() const
{
    return _isWorking;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Cook<ProductType, ProductSize, ProductIngredientType>::stopWorking()
{
    _isWorking = false;
    if (_thread.joinable())
        _thread.join();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Cook<ProductType, ProductSize, ProductIngredientType>::_cook(Product<ProductType, ProductSize, ProductIngredientType> &order)
{
    this->_isCooking = true;
    _cookingTime.resetStartingPoint();
    this->_cookingProduct = order;
    this->_getIngredients(_cookingProduct.getIngredients());
    this->_cookingProduct.setFinished();
    do {
        _cookingTime.setElapsedTime();
    } while (_cookingTime.getElapsedTimeDouble() < _cookingProduct.getPreparationTime());
    this->_isCooking = false;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Cook<ProductType, ProductSize, ProductIngredientType>::_getIngredients(const std::vector<ProductIngredientType> &ingredients)
{
    std::vector<ProductIngredientType> my_ingredients(ingredients);

    while (!my_ingredients.empty()) {
        my_ingredients.erase(std::remove_if(my_ingredients.begin(), my_ingredients.end(),
                                 [this](ProductIngredientType const &p) {
                                     return this->_pickIngredientInStock(p);
                                 }),
            my_ingredients.end());
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
bool Cook<ProductType, ProductSize, ProductIngredientType>::_hasFinishedCooking() const
{
    return _cookingProduct.isFinished();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
Order<Product<ProductType, ProductSize, ProductIngredientType>>
Cook<ProductType, ProductSize, ProductIngredientType>::_receiveOrder() const
{
    return _orderReceivePlace.getFront();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Cook<ProductType, ProductSize, ProductIngredientType>::_deliverOrder()
{
    if (!_cookingProduct.isFinished())
        throw CookError("Product not finished");

    Order<Product<ProductType, ProductSize, ProductIngredientType>> my_delivery(_cookingProduct);
    _deliveryPlace.push(my_delivery);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
bool Cook<ProductType, ProductSize, ProductIngredientType>::_pickIngredientInStock(const ProductIngredientType &ingredient)
{
    return _stockPlace.takeIngredients(ingredient, 1);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
const Product<ProductType, ProductSize, ProductIngredientType> &
Cook<ProductType, ProductSize, ProductIngredientType>::getCookingProduct() const
{
    return _cookingProduct;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
Stock<ProductIngredientType> &Cook<ProductType, ProductSize, ProductIngredientType>::getStockPlace() const
{
    return _stockPlace;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
LockedQueue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> &
Cook<ProductType, ProductSize, ProductIngredientType>::getOrderReceivePlace() const
{
    return _orderReceivePlace;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
LockedQueue<Order<Product<ProductType, ProductSize, ProductIngredientType>>> &
Cook<ProductType, ProductSize, ProductIngredientType>::getDeliveryPlace() const
{
    return _deliveryPlace;
}

template class Cook<Pizzeria::PizzaType, Pizzeria::PizzaSize, Pizzeria::PizzaIngredient>;