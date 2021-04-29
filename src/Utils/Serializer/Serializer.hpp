/*
 * EPITECH PROJECT, 2021
 * serializer
 * File description:
 * serializer.hpp - Created: 20/04/2021
 */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Plazza.hpp"

class Serializer {
  public:
    Serializer() = default;
    explicit Serializer(size_t size);

    void operator>>(std::ofstream &file) const;
    void operator<<(std::ifstream &file) const;

    void pack(std::ofstream &file) const;
    void unpack(std::ifstream &file) const;

  private:
    size_t _size;
};

#endif