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

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
class Reception : IReception<ProductType, ProductSize, ProductIngredientType> {
  public:
    Reception() = default;
    ~Reception() override = default;
    [[nodiscard]] bool doesGetPendingOrders() const override;
    const Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &getOrder() override;
    void sendOrder(const Order<IProduct<ProductType, ProductSize, ProductIngredientType>> &order) const override;

  protected:
    void receiveCommands(const string &cmd) override;

  private:
    void _writePizzasCommand(const string &cmd);
    [[nodiscard]] static PizzaType _getType(const string &type);
    [[nodiscard]] static PizzaSize _getSize(const string &size);
    [[nodiscard]] static size_t _getNbr(const string &nbr);

    std::queue<Order<IProduct<ProductType, ProductSize, ProductIngredientType>>> _pendingOrders;
};

#endif