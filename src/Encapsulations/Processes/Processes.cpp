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

int Processes::waitChild() const
{
    int exit_value;

    if (this->isChild())
        throw ProcessError("Child can't wait himself");
    if (waitpid(this->_childPid, &exit_value, 0) == -1)
        throw ProcessError(getErrnoMsg());
    return WIFEXITED(exit_value) ? WEXITSTATUS(exit_value) : 0;
}

void Processes::killChild() const
{
    if (kill(this->_childPid, SIGKILL) == -1)
        throw ProcessError(getErrnoMsg());
}

void Processes::send(const string &msg) const
{
    // TODO
    (void) msg;
}

string Processes::receive() const
{
    // TODO
    return "";
}