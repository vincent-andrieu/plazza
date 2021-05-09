/*
 * EPITECH PROJECT, 2021
 * serializer
 * File description:
 * serializer.hpp - Created: 20/04/2021
 */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Plazza.hpp"

#define MAX_OBJECT_SIZE 64

struct SendedObject {
    long mtype;
    char mtext[MAX_OBJECT_SIZE];
};

class Serializer {
  public:
    Serializer() = default;

    void operator>>(const int msqId) const;
    void operator<<(const int msqId);

    void pack(const int msqId) const;
    void unpack(const int msqId);

  protected:
    virtual const string _SerializeToString() const = 0;
    virtual void _SerializeFromString(const string str) = 0;
};

#endif