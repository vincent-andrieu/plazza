/*
 * EPITECH PROJECT, 2021
 * serializer
 * File description:
 * serializer.cpp - Created: 20/04/2021
 */

#include <cstring>
#include <sys/msg.h>
#include "Serializer/Serializer.hpp"
#include "Error/Error.hpp"

Serializer::Serializer(size_t size) : _size(size)
{
    if (size > MAX_OBJECT_SIZE)
        throw SerializerError(
            "The sending object is over limit: " + std::to_string(size) + ". Limited to: " + std::to_string(MAX_OBJECT_SIZE));
}

void Serializer::operator>>(const int msqId) const
{
    this->pack(msqId);
}

void Serializer::operator<<(const int msqId)
{
    this->unpack(msqId);
}

void Serializer::pack(const int msqId) const
{
    SendedObject sendedObject;
    sendedObject.type = 1;
    memcpy(sendedObject.object, this, this->_size);
    if (msgsnd(msqId, &sendedObject, sizeof(sendedObject), 0) == -1)
        throw SerializerError(getErrnoMsg("msgsnd"));
}

void Serializer::unpack(const int msqId)
{
    SendedObject sendedObject;

    if (msgrcv(msqId, &sendedObject, sizeof(sendedObject), 1, 0) == -1)
        throw SerializerError(getErrnoMsg("msgrcv"));
    memcpy(this, sendedObject.object, this->_size);
}