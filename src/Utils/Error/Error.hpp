/*
 * EPITECH PROJECT, 2021
 * Error
 * File description:
 * Error.hpp - Created: 21/04/2021
 */

#ifndef ERROR_HPP
#define ERROR_HPP

#include <iostream>
#include <exception>

typedef std::string string;

const string getErrnoMsg(const string &name = "");

class ManageError : public std::exception {
  public:
    ManageError(string const &message, string const &component = "Unknown");
    string const &getComponent() const;
    const char *what() const noexcept override;

  protected:
    string _component;

  private:
    string _message;
};

class ProcessError : public ManageError {
  public:
    ProcessError(string const &message = "Standard", string const &component = "Process");
};

class ThreadsError : public ManageError {
  public:
    ThreadsError(string const &message = "Standard", string const &component = "Threads");
};

class MutexError : public ManageError {
  public:
    MutexError(string const &message = "Standard", string const &component = "Mutex");
};

class CommunicationError : public ManageError {
  public:
    CommunicationError(string const &message = "Standard", string const &component = "Serializer");
};

class SerializerError : public ManageError {
  public:
    SerializerError(string const &message = "Standard", string const &component = "Serializer");
};

class FactoryError : public ManageError {
  public:
    FactoryError(string const &message = "Standard", string const &component = "Factory");
};

class ReceptionError : public ManageError {
  public:
    ReceptionError(string const &message = "Standard", string const &component = "Reception");
};

class CookError : public ManageError {
  public:
    CookError(string const &message = "Standard", string const &component = "Cook");
};

#endif