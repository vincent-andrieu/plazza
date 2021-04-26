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
    Serializer();
    Serializer(std::size_t size);

    void pack(std::ofstream &file) const;
    void unpack(std::ifstream &file) const;

  private:
    std::size_t _size;
};

#endif