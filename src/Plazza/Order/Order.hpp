/*
 * EPITECH PROJECT, 2021
 * include
 * File description:
 * Order.hpp - Created: 26/04/2021
 */

#ifndef ORDER_HPP
#define ORDER_HPP

#include "Serializer/Serializer.hpp"

template <typename T> class Order : public Serializer {
  public:
    explicit Order(T &object);
    ~Order() = default;

    T &getOrder() const;
    void setOrder(T &object);

  private:
    T &_object;
};

#endif