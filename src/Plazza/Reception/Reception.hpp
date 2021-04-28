/*
 * EPITECH PROJECT, 2021
 * Reception
 * File description:
 * Reception.hpp - Created: 26/04/2021
 */

#ifndef RECEPTION_HPP
#define RECEPTION_HPP

#include <vector>
#include "Interfaces/ReceptionInterface.hpp"

class Reception : IReception {
  public:
    Reception();
    ~Reception();
    bool doesGetPendingOrders() const;
    Order getOrder();
    void sendOrder(const Order &order) const;

  protected:
    void receiveCommand();

  private:
    std::vector<Order> _pendingOrders
};

#endif