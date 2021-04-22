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

const string getErrnoMsg();

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

class ConditionalVariablesError : public ManageError {
  public:
    ConditionalVariablesError(string const &message = "Standard", string const &component = "ConditionalVariables");
};

class SerializerError : public ManageError {
  public:
    SerializerError(string const &message = "Standard", string const &component = "Serializer");
};

#endif