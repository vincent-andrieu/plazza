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
    SendedObject sendedObject{0, {0}};
    const string str = this->SerializeToString();

    if (str.size() > MAX_OBJECT_SIZE)
        throw SerializerError("The sending string is over limit: " + std::to_string(str.size())
            + ". Limited to: " + std::to_string(MAX_OBJECT_SIZE));
    memset(&sendedObject, 0, sizeof(sendedObject));
    sendedObject.mtype = 1;
    strcpy(sendedObject.mtext, str.c_str());
    if (msgsnd(msqId, &sendedObject, str.size(), 0) == -1)
        throw SerializerError(getErrnoMsg("msgsnd"));
}

void Serializer::unpack(const int msqId)
{
    SendedObject sendedObject{0, {0}};

    memset(&sendedObject, 0, sizeof(sendedObject));
    if (msgrcv(msqId, &sendedObject, sizeof(sendedObject), 1, 0) == -1)
        throw SerializerError(getErrnoMsg("msgrcv"));
    this->SerializeFromString(string(sendedObject.mtext));
}