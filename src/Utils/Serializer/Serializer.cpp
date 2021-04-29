/*
 * EPITECH PROJECT, 2021
 * serializer
 * File description:
 * serializer.cpp - Created: 20/04/2021
 */

#include <fstream>
#include "Serializer/Serializer.hpp"
#include "Error/Error.hpp"

Serializer::Serializer(std::size_t size) : _size(size)
{
}

void Serializer::operator>>(std::ofstream &file) const
{
    this->pack(file);
}

void Serializer::operator<<(std::ifstream &file) const
{
    this->unpack(file);
}

void Serializer::pack(std::ofstream &file) const
{
    file.write((char *) this, this->_size);
    if (file.bad())
        throw SerializerError("Failed to pack");
}

void Serializer::unpack(std::ifstream &file) const
{
    file.read((char *) this, this->_size);
    if (file.bad())
        throw SerializerError("Failed to unpack");
}