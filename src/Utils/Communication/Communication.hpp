/*
 * EPITECH PROJECT, 2021
 * Communication
 * File description:
 * Communication.hpp - Created: 22/04/2021
 */

#ifndef COMMUNICATION_HPP
#define COMMUNICATION_HPP

#include "Plazza.hpp"
#include "Serializer/Serializer.hpp"

#define FIFO_FOLDER_PERMISSIONS 0766
#define FIFO_ROOT               "/tmp/plazza/"
#define FIFO_PERMISSIONS        0666

class Communication {
  public:
    Communication();
    Communication(const string &filename);
    Communication(const Communication &communication);
    ~Communication();

    Communication &operator=(const Communication &communication);

    void write(const Serializer &object) const;
    void read(const Serializer &object) const;

  private:
    string _filepath;
};

#endif