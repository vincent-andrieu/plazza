/*
 * EPITECH PROJECT, 2021
 * interfaces
 * File description:
 * PizzaInterface.hpp - Created: 20/04/2021
 */

#ifndef PIZZA_INTERFACE_HPP
#define PIZZA_INTERFACE_HPP

enum PizzaType
{
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};

enum PizzaSize
{
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

// TODO: This class must be edited, it was a test
class PizzaInterface : public Serializer {
  public:
    PizzaInterface(int nbr, int size);
    PizzaInterface();

    int _nbr;
    int _size;
};

#endif