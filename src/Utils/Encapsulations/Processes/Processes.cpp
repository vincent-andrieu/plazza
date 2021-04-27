/*
 * EPITECH PROJECT, 2021
 * Processes
 * File description:
 * Processes.cpp - Created: 21/04/2021
 */

#include <signal.h>
#include <sys/wait.h>
#include "Error/Error.hpp"
#include "Encapsulations/Processes/Processes.hpp"

Processes::Processes()
{
    this->_parentPid = getpid();
    pid_t pid = fork();

    if (pid == -1)
        throw ProcessError(getErrnoMsg());
    if (pid == 0) {
        this->_childPid = getpid();
        this->_isParent = false;
        this->_isChild = true;
    } else {
        this->_childPid = pid;
        this->_isParent = true;
        this->_isChild = false;
    }
    this->_communication = Communication(std::to_string(this->_childPid));
}

Processes::Processes(const Processes &processes)
{
    this->_parentPid = processes._parentPid;
    this->_isParent = processes._isParent;
    this->_childPid = processes._childPid;
    this->_isChild = processes._isChild;
    this->_communication = processes._communication;
}

Processes::~Processes()
{
}

Processes &Processes::operator=(const Processes &processes)
{
    this->_parentPid = processes._parentPid;
    this->_isParent = processes._isParent;
    this->_childPid = processes._childPid;
    this->_isChild = processes._isChild;
    this->_communication = processes._communication;

    return *this;
}

bool Processes::operator==(const Processes &processes) const
{
    if (this->isParent() && processes.isChild())
        return this->_parentPid == processes._parentPid && this->_childPid == processes._childPid;
    if (this->isChild() && processes.isParent())
        return this->_childPid == processes._childPid && this->_parentPid == processes._parentPid;
    return false;
}

bool Processes::isParent() const
{
    return this->_isParent;
}

bool Processes::isChild() const
{
    return this->_isChild;
}

/**
 * @brief Wait child process and return the process exit value. Throw an error if the child try to wait himself or if waitpid
 * fail.
 *
 * @return int (exit value)
 */
int Processes::waitChild() const
{
    int exit_value;

    if (this->isChild())
        throw ProcessError("Child can't wait himself");
    if (waitpid(this->_childPid, &exit_value, 0) == -1)
        throw ProcessError(getErrnoMsg());
    return WIFEXITED(exit_value) ? WEXITSTATUS(exit_value) : 0;
}

/**
 * @brief The child can kill himself ! An error is throw if kill fail.
 *
 */
void Processes::killChild() const
{
    if (kill(this->_childPid, SIGKILL) == -1)
        throw ProcessError(getErrnoMsg());
}

void Processes::send(const Serializer &object) const
{
    this->_communication.write(object);
}

void Processes::receive(const Serializer &object) const
{
    this->_communication.read(object);
}