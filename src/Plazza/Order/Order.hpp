/*
 * EPITECH PROJECT, 2021
 * include
 * File description:
 * Order.hpp - Created: 26/04/2021
 */

#ifndef ORDER_HPP
#define ORDER_HPP

#include "Translator/Translator.hpp"
#include "Serializer/Serializer.hpp"

template <typename T> class Order : public Serializer {
  public:
    Order() = default;
    Order(T object);
    ~Order() = default;

    const T &getOrder() const;
    void setOrder(T &object);

  protected:
    const string _SerializeToString() const;
    void _SerializeFromString(const string str);

  private:
    T _object;
};

#endif