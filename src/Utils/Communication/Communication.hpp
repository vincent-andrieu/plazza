/*
 * EPITECH PROJECT, 2021
 * Communication
 * File description:
 * Communication.hpp - Created: 22/04/2021
 */

#ifndef COMMUNICATION_HPP
#define COMMUNICATION_HPP

#include <sys/msg.h>
#include "Plazza.hpp"
#include "Serializer/Serializer.hpp"

#define FILES_FOLDER_PERMISSIONS 0766
#define FILES_ROOT               "/tmp/plazza/"
#define IPC_PERMISSION           0666

class Communication {
  public:
    Communication() = default;
    explicit Communication(const string &filename);
    Communication(const Communication &communication);
    ~Communication() = default;

    void operator<<(const Serializer &object) const;
    void operator>>(Serializer &object) const;

    Communication &operator=(const Communication &communication) = default;

    void write(const Serializer &object) const;
    void read(Serializer &object) const;
    msgqnum_t getQueueSize(int msqId = -1) const;

  private:
    static void _removeQueue(const int msqId);

    key_t _key;
};

#endif