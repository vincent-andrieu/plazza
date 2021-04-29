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
    Reception() = default;
    ~Reception() override = default;
    [[nodiscard]] bool doesGetPendingOrders() const override;
    const Order &getOrder() override;
    void sendOrder(const Order &order) const override;

  protected:
    void receiveCommands(const string &cmd) override;

  private:
    void _writePizzasCommand(const string &cmd);
    [[nodiscard]] static PizzaType _getType(const string &type);
    [[nodiscard]] static PizzaSize _getSize(const string &size);
    [[nodiscard]] static size_t _getNbr(const string &nbr);

    std::queue<Order> _pendingOrders;
};

#endif