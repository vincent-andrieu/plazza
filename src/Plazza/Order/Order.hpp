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
    explicit Order(const T &object);
    ~Order() = default;

    const T &getOrder() const;

  protected:
    const string _SerializeToString() const;
    void _SerializeFromString(const string str);

  private:
    const T _object;
};

#endif