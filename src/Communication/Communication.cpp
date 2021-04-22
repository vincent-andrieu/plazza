/*
 * EPITECH PROJECT, 2021
 * Communication
 * File description:
 * Communication.cpp - Created: 22/04/2021
 */

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "Error/Error.hpp"
#include "Communication/Communication.hpp"
#include "Serializer/Serializer.hpp"

Communication::Communication(const string &filename)
{
    this->_filepath = FIFO_ROOT + filename;

    if (mkfifo(this->_filepath.c_str(), FIFO_PERMISSIONS) == -1)
        throw CommunicationError(getErrnoMsg());
}

Communication::~Communication()
{
}

void Communication::write(const void *object)
{
    int fd = open(this->_filepath.c_str(), O_WRONLY);

    if (fd == -1)
        throw CommunicationError(getErrnoMsg());

    Serializer::pack(fd, object);

    if (close(fd) == -1)
        throw CommunicationError(getErrnoMsg());
}

void Communication::read(void *object)
{
    int fd = open(this->_filepath.c_str(), O_RDONLY);

    if (fd == -1)
        throw CommunicationError(getErrnoMsg());

    Serializer::unpack(fd, object);

    if (close(fd) == -1)
        throw CommunicationError(getErrnoMsg());
}