/*
 * EPITECH PROJECT, 2021
 * serializer
 * File description:
 * serializer.hpp - Created: 20/04/2021
 */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Plazza.hpp"

#define MAX_OBJECT_SIZE 32

struct SendedObject {
    long type;
    char object[MAX_OBJECT_SIZE];
};

class Serializer {
  public:
    Serializer() = default;
    explicit Serializer(size_t size);

    void operator>>(const int msqId) const;
    void operator<<(const int msqId);

    void pack(const int msqId) const;
    void unpack(const int msqId);

  private:
    size_t _size;
};

#endif