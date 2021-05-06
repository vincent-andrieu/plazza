/*
 * EPITECH PROJECT, 2021
 * Communication
 * File description:
 * Communication.cpp - Created: 22/04/2021
 */

#include <sys/stat.h>
#include <sys/ipc.h>
#include <fstream>
#include "Communication/Communication.hpp"
#include "Serializer/Serializer.hpp"
#include "Error/Error.hpp"

Communication::Communication(const string &filename)
{
    mkdir(FILES_ROOT, FILES_FOLDER_PERMISSIONS);
    const string filepath = FILES_ROOT + filename;
    std::ofstream outfile(filepath);

    if (!outfile.is_open())
        throw CommunicationError("Fail to create file");
    outfile.close();

    this->_key = ftok(filepath.c_str(), 65);
    if (this->_key == -1)
        throw CommunicationError(getErrnoMsg("ftok"));
}

Communication::Communication(const Communication &copy)
{
    this->_key = copy._key;
}

void Communication::operator<<(const Serializer &object) const
{
    this->write(object);
}

void Communication::operator>>(Serializer &object) const
{
    this->read(object);
}

void Communication::write(const Serializer &object) const
{
    int msqId = msgget(this->_key, IPC_PERMISSION | IPC_CREAT);

    if (msqId == -1)
        throw CommunicationError(getErrnoMsg("write => msgget"));
    object >> msqId;
}

void Communication::read(Serializer &object) const
{
    int msqId = msgget(this->_key, IPC_PERMISSION | IPC_CREAT);

    if (msqId == -1)
        throw CommunicationError(getErrnoMsg("read => msgget"));
    object << msqId;

    if (this->getQueueSize(msqId) <= 0)
        this->_removeQueue(msqId);
}

msgqnum_t Communication::getQueueSize(int msqId) const
{
    if (msqId == -1)
        msqId = msgget(this->_key, IPC_PERMISSION | IPC_CREAT);
    struct msqid_ds msq_ds;

    if (msgctl(msqId, IPC_STAT, &msq_ds) == -1)
        throw CommunicationError(getErrnoMsg("msgctl"));

    return msq_ds.msg_qnum;
}

void Communication::_removeQueue(const int msqId)
{
    if (msgctl(msqId, IPC_RMID, NULL) == -1)
        throw CommunicationError(getErrnoMsg("msgctl"));
}