/*
 * EPITECH PROJECT, 2021
 * serializer
 * File description:
 * serializer.hpp - Created: 20/04/2021
 */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Plazza.hpp"

#define MAX_OBJECT_SIZE 1024

struct SendedObject {
    long mtype;
    char mtext[MAX_OBJECT_SIZE];
};

class Serializer {
  public:
    Serializer() = default;
    virtual ~Serializer() = default;

    void operator>>(int msqId) const;
    void operator<<(int msqId);

    void pack(int msqId) const;
    void unpack(int msqId);

  protected:
    virtual const string SerializeToString() const = 0;
    virtual void SerializeFromString(const string &str) = 0;
};

#endif