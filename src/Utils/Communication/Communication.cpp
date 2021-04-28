/*
 * EPITECH PROJECT, 2021
 * Communication
 * File description:
 * Communication.cpp - Created: 22/04/2021
 */

#include <sys/stat.h>
#include <fstream>
#include "Error/Error.hpp"
#include "Communication/Communication.hpp"
#include "Serializer/Serializer.hpp"

Communication::Communication()
{
}

Communication::Communication(const string &filename)
{
    mkdir(FIFO_ROOT, FIFO_FOLDER_PERMISSIONS);
    this->_filepath = FIFO_ROOT + filename;

    if (mkfifo(this->_filepath.c_str(), FIFO_PERMISSIONS) == -1 && errno != EEXIST)
        throw CommunicationError(getErrnoMsg());
}

Communication::Communication(const Communication &copy)
{
    this->_filepath = copy._filepath;
}


void Communication::write(const Serializer &object) const
{
    std::ofstream file(this->_filepath, std::ios::out | std::ios::binary);

    if (file.is_open()) {
        object >> file;
        file.close();
    } else
        throw CommunicationError("Fail to open file to write: " + this->_filepath);
}

void Communication::read(const Serializer &object) const
{
    std::ifstream file(this->_filepath, std::ios::in | std::ios::binary);

    if (file.is_open()) {
        object << file;
        file.close();
    } else
        throw CommunicationError("Fail to open file to read: " + this->_filepath);
}