/*
 * EPITECH PROJECT, 2021
 * Process
 * File description:
 * Process.hpp - Created: 21/04/2021
 */

#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <unistd.h>
#include "Plazza.hpp"
#include "Communication/Communication.hpp"

class Process {
  public:
    Process();
    Process(const Process &process);
    ~Process();

    Process &operator=(const Process &process);
    bool operator==(const Process &process) const;

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