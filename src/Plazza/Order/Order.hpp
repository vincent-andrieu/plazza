/*
 * EPITECH PROJECT, 2021
 * include
 * File description:
 * Order.hpp - Created: 26/04/2021
 */

#ifndef ORDER_HPP
#define ORDER_HPP

#include "Serializer/Serializer.hpp"
#include "enumPizza.hpp"
#include "Interfaces//ProductInterface.hpp"
#include <memory>

using namespace Pizzeria;

template <typename T> class Order : public Serializer {
  public:
    explicit Order(std::shared_ptr<T> object);
    ~Order() = default;

    const std::shared_ptr<T> &getOrder() const;

  private:
    std::shared_ptr<T> _object;
};

#endif