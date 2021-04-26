/*
 * EPITECH PROJECT, 2021
 * Reception
 * File description:
 * Reception.hpp - Created: 26/04/2021
 */

#ifndef RECEPTION_HPP
#define RECEPTION_HPP

#include "Interfaces/ReceptionInterface.hpp"

class Reception : IReception {
  public:
    ~IReception();
    bool isOpen() const;
    Order getOrder() const;
    void sayStatus();

  protected:
    void receiveCommand();
};

#endif