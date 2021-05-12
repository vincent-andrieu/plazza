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
    Order(const Order<T> &order);
    explicit Order(T object);
    ~Order() = default;

    const T *operator->() const;

    const T &getOrder() const;
    void setOrder(T &object);

  protected:
    const string SerializeToString() const override;
    void SerializeFromString(const string &str) override;

  private:
    T _object;
};

#endif