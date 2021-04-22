/*
 * EPITECH PROJECT, 2021
 * serializer
 * File description:
 * serializer.cpp - Created: 20/04/2021
 */

#include <unistd.h>
#include <stdio.h>
#include "Serializer/Serializer.hpp"
#include "Error/Error.hpp"

void Serializer::pack(const int fd, const void *object)
{
    if (write(fd, object, sizeof(object)) == -1)
        throw SerializerError(getErrnoMsg());
}

void Serializer::unpack(const int fd, void *object)
{
    if (read(fd, object, sizeof(object)) == -1)
        throw SerializerError(getErrnoMsg());
}