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
#include "enumPizza.hpp"

#define COMMAND_DELIMITER ';'

namespace Pizzeria
{
    class Reception : IReception<PizzaType, PizzaSize, PizzaIngredient> {
      public:
        Reception(double multiplier);
        ~Reception() override = default;
        void sendOrder(const Order<AProduct<PizzaType, PizzaSize, PizzaIngredient>> &order) const override;
        void receiveCommands(const string &cmd,
            std::queue<std::unique_ptr<Order<AProduct<PizzaType, PizzaSize, PizzaIngredient>>>> &orderList) override;

      private:
        void _writePizzasCommand(
            const string &cmd, std::queue<std::unique_ptr<Order<AProduct<PizzaType, PizzaSize, PizzaIngredient>>>> &orderList);
        [[nodiscard]] static PizzaType _getType(const string &type);
        [[nodiscard]] static PizzaSize _getSize(const string &size);
        [[nodiscard]] static size_t _getNbr(const string &nbr);

        // std::queue<Order<AProduct<PizzaType, PizzaSize, PizzaIngredient>>> _pendingOrders;
        double _bakingMultiplier;
    };
} // namespace Pizzeria

#endif