/*
 * EPITECH PROJECT, 2021
 * serializer
 * File description:
 * serializer.hpp - Created: 20/04/2021
 */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

class Serializer {
  public:
    static void pack(const int fd, void *object);
    static void unpack(const int fd, void *object);
};

#endif