/*
 * EPITECH PROJECT, 2021
 * Communication
 * File description:
 * Communication.hpp - Created: 22/04/2021
 */

#ifndef COMMUNICATION_HPP
#define COMMUNICATION_HPP

#include "Plazza.hpp"

#define FIFO_ROOT        "/tmp/"
#define FIFO_PERMISSIONS 0666

class Communication {
  public:
    Communication(const string &filename);
    ~Communication();

    void write(const void *object);
    void read(void *object);

  private:
    string _filepath;
};

#endif