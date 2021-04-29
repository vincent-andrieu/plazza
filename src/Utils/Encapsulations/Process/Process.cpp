/*
 * EPITECH PROJECT, 2021
 * Process
 * File description:
 * Process.cpp - Created: 21/04/2021
 */

#include <signal.h>
#include <sys/wait.h>
#include "Error/Error.hpp"
#include "Encapsulations/Process/Process.hpp"

Process::Process()
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

Process::Process(const Process &process)
{
    this->_parentPid = process._parentPid;
    this->_isParent = process._isParent;
    this->_childPid = process._childPid;
    this->_isChild = process._isChild;
    this->_communication = process._communication;
}

bool Process::operator==(const Process &process) const
{
    if (this->isParent() && process.isChild())
        return this->_parentPid == process._parentPid && this->_childPid == process._childPid;
    if (this->isChild() && process.isParent())
        return this->_childPid == process._childPid && this->_parentPid == process._parentPid;
    return false;
}

bool Process::isParent() const
{
    return this->_isParent;
}

bool Process::isChild() const
{
    return this->_isChild;
}

/**
 * @brief Wait child process and return the process exit value.
 * @throw If the child try to wait himself or if waitpid fails.
 *
 * @return int (exit value)
 */
int Process::waitChild() const
{
    int exit_value;

    if (this->isChild())
        throw ProcessError("Child can't wait himself");
    if (waitpid(this->_childPid, &exit_value, 0) == -1)
        throw ProcessError(getErrnoMsg());
    return WIFEXITED(exit_value) ? WEXITSTATUS(exit_value) : 0;
}

/**
 * @brief The child can kill himself !
 * @throw If kill fail.
 *
 */
void Process::killChild() const
{
    if (kill(this->_childPid, SIGKILL) == -1)
        throw ProcessError(getErrnoMsg());
}

void Process::send(const Serializer &object) const
{
    this->_communication.write(object);
}

bool Process::receive(Serializer &object)
{
    if (this->_communication.getQueueSize() > 0) {
        this->_communication.read(object);
        return true;
    }
    return false;
}