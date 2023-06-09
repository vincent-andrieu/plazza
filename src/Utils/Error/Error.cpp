/*
 * EPITECH PROJECT, 2021
 * Error
 * File description:
 * Error.cpp - Created: 21/04/2021
 */

#include <cstring>
#include <cerrno>
#include "Error.hpp"

const string getErrnoMsg(const string &name)
{
    const string error = strerror(errno);

    if (name.empty())
        return error;
    return name + ": " + error;
}

ManageError::ManageError(string const &message, string const &component) : _component(component), _message(message)
{
}

const char *ManageError::what() const noexcept
{
    return this->_message.c_str();
}

string const &ManageError::getComponent() const
{
    return this->_component;
}

ProcessError::ProcessError(string const &message, string const &component) : ManageError(message, component)
{
}

ThreadsError::ThreadsError(string const &message, string const &component) : ManageError(message, component)
{
}

MutexError::MutexError(string const &message, string const &component) : ManageError(message, component)
{
}

CommunicationError::CommunicationError(string const &message, string const &component) : ManageError(message, component)
{
}

SerializerError::SerializerError(string const &message, string const &component) : ManageError(message, component)
{
}

FactoryError::FactoryError(string const &message, string const &component) : ManageError(message, component)
{
}

ReceptionError::ReceptionError(string const &message, string const &component) : ManageError(message, component)
{
}

CookError::CookError(const string &message, const string &component) : ManageError(message, component)
{
}