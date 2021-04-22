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
    this->_communication = Communication("Process/" + this->_childPid);
}

Processes::~Processes()
{
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

void Processes::send(const void *object) const
{
    this->_communication.write(object);
}

void Processes::receive(void *object) const
{
    this->_communication.read(object);
}