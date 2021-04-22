/*
 * EPITECH PROJECT, 2021
 * Processes
 * File description:
 * Processes.hpp - Created: 21/04/2021
 */

#ifndef PROCESSES_HPP
#define PROCESSES_HPP

#include "Plazza.hpp"
#include <unistd.h>

class Processes {
  public:
    Processes();
    ~Processes();

    bool isParent() const;
    bool isChild() const;
    int waitChild() const;
    void killChild() const;
    void send(const string &msg) const;
    string receive() const;

  private:
    pid_t _parentPid;
    bool _isParent;
    pid_t _childPid;
    bool _isChild;
};

#endif