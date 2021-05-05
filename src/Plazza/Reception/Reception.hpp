/*
 * EPITECH PROJECT, 2021
 * Reception
 * File description:
 * Reception.hpp - Created: 26/04/2021
 */

#ifndef RECEPTION_HPP
#define RECEPTION_HPP

#include <queue>
#include <algorithm>
#include <memory>
#include "enumPizza.hpp"
#include "Logger/Logger.hpp"
#include "Interfaces/ReceptionInterface.hpp"

#define COMMAND_DELIMITER ';'

using namespace Pizzeria;

namespace Pizzeria
{
    class Reception : IReception<PizzaType, PizzaSize, PizzaIngredient> {
      public:
        Reception(double multiplier);
        ~Reception() override = default;
        [[nodiscard]] bool doesGetPendingOrders() const override;
        [[nodiscard]] bool getOrder(Order<IProduct<PizzaType, PizzaSize, PizzaIngredient>> &order) override;
        void sendOrder(const Order<IProduct<PizzaType, PizzaSize, PizzaIngredient>> &order) override;
        void receiveCommands(const string &cmd) override;

      private:
        void _writePizzasCommand(const string &cmd);
        [[nodiscard]] static PizzaType _getType(const string &type);
        [[nodiscard]] static PizzaSize _getSize(const string &size);
        [[nodiscard]] static size_t _getNbr(const string &nbr);

        std::queue<Order<IProduct<PizzaType, PizzaSize, PizzaIngredient>>> _pendingOrders;
        double _bakingMultiplier;
        std::unique_ptr<Logger> _logger;
    };
} // namespace Pizzeria

#endif