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
            order = receiveOrder().getOrder();
        } catch ([[maybe_unused]] const CookError &my_e) {
            continue;
        }
        cook(order);
        deliverOrder();
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
void Cook<ProductType, ProductSize, ProductIngredientType>::cook(Product<ProductType, ProductSize, ProductIngredientType> order)
{
    _isCooking = true;
    _cookingProduct = order;
    getIngredients(_cookingProduct.getIngredients());
    _cookingProduct.setFinished();
    _isCooking = false;
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Cook<ProductType, ProductSize, ProductIngredientType>::getIngredients(const std::vector<ProductIngredientType> &ingredients)
{
    auto my_ingredients(ingredients);

    for (auto iterator = my_ingredients.begin(); !my_ingredients.empty() && _isWorking; ++iterator) {
        if (iterator == my_ingredients.end())
            iterator = my_ingredients.begin();
        if (pickIngredientInStock(*iterator))
            my_ingredients.erase(iterator);
    }
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
bool Cook<ProductType, ProductSize, ProductIngredientType>::hasFinishedCooking() const
{
    //    if (!_cookingProduct)
    //        throw CookError("No cooking product");
    return _cookingProduct.isFinished();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
Order<Product<ProductType, ProductSize, ProductIngredientType>>
Cook<ProductType, ProductSize, ProductIngredientType>::receiveOrder() const
{
    if (_orderReceivePlace.empty())
        throw CookError("No order received");
    return _orderReceivePlace.getFront();
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
void Cook<ProductType, ProductSize, ProductIngredientType>::deliverOrder()
{
    if (!_cookingProduct.isFinished())
        throw CookError("Product not finished");

    Order<Product<ProductType, ProductSize, ProductIngredientType>> my_delivery(_cookingProduct);
    _deliveryPlace.push(my_delivery);
}

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
bool Cook<ProductType, ProductSize, ProductIngredientType>::pickIngredientInStock(const ProductIngredientType &ingredient)
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