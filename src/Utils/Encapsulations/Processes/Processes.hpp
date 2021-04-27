/*
 * EPITECH PROJECT, 2021
 * Processes
 * File description:
 * Processes.hpp - Created: 21/04/2021
 */

#ifndef PROCESSES_HPP
#define PROCESSES_HPP

#include <unistd.h>
#include "Plazza.hpp"
#include "Communication/Communication.hpp"

class Processes {
  public:
    Processes();
    Processes(const Processes &processes);
    ~Processes();

    Processes &operator=(const Processes &processes);
    bool operator==(const Processes &processes) const;

    bool isParent() const;
    bool isChild() const;
    int waitChild() const;
    void killChild() const;
    void send(const Serializer &object) const;
    void receive(const Serializer &object) const;

  private:
    pid_t _parentPid;
    bool _isParent;
    pid_t _childPid;
    bool _isChild;
    Communication _communication;
};

#endif