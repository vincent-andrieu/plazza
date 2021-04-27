/*
 * EPITECH PROJECT, 2021
 * Kitchen
 * File description:
 * Kitchen.hpp - Created: 27/04/2021
 */

#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include "Interfaces/KitchenInterface.hpp"
#include "Encapsulations/Processes/Processes.hpp"
#include "Cook/Cook.hpp"

class Kitchen : public IKitchen, public Process {
  public:
    Kitchen(double bakingTime, size_t cooksPerKitchen, size_t restockTime);
    ~Kitchen();
    void cook();
    bool isCooking();

  protected:
    void receiveOrder();
    bool isOrderReady(Order order);
    void sendOrder();
    void assignOrder(Order order, Cook cook);
    void retreiveOrder();
    void restock();

    std::deque<Cook> workers;
};

#endif