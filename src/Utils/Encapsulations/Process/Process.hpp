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
    ~Process() = default;

    Process &operator=(const Process &process) = default;
    [[nodiscard]] bool operator==(const Process &process) const;

    [[nodiscard]] bool isParent() const;
    [[nodiscard]] bool isChild() const;
    [[nodiscard]] int waitChild() const;
    void killChild() const;
    void send(const Serializer &object) const;
    [[nodiscard]] bool receive(Serializer &object) const;
    void waitingReceive(Serializer &object);

  private:
    pid_t _parentPid;
    bool _isParent;
    pid_t _childPid;
    bool _isChild;
    Communication _communication;
};

#endif