/*
 * EPITECH PROJECT, 2021
 * Reception
 * File description:
 * Reception.hpp - Created: 26/04/2021
 */

#ifndef RECEPTION_HPP
#define RECEPTION_HPP

#include <queue>
#include "Interfaces/ReceptionInterface.hpp"

#define COMMAND_DELIMITER ';'

class Reception : IReception {
  public:
    Reception();
    ~Reception();
    bool doesGetPendingOrders() const;
    const Order getOrder();
    void sendOrder(const Order &order) const;

  protected:
    void receiveCommands(const string cmd);

  private:
    void _writePizzasCommand(const string cmd);
    PizzaType _getType(const string type);
    PizzaSize _getSize(const string size);
    size_t _getNbr(const string nbr);

    std::queue<Order> _pendingOrders;
};

#endif