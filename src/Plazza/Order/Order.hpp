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

template <typename T> class Order : public Serializer {
  public:
    explicit Order(T object);
    ~Order() = default;

    const T &getOrder() const;

  private:
    T _object;
};

#endif