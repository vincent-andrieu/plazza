/*
 * EPITECH PROJECT, 2021
 * DisplayManage
 * File description:
 * DisplayManage.hpp - Created: 21/04/2021
 */

#ifndef DISPLAYMANAGE_HPP
#define DISPLAYMANAGE_HPP

#include <iostream>
#include "Interfaces/ICoreDisplay.hpp"

template <typename ProductType, typename ProductSize, typename ProductIngredientType>
class CoreDisplay : public ICoreDisplay<ProductType, ProductSize, ProductIngredientType> {
  public:
    CoreDisplay(std::string filepath);
    ~CoreDisplay();

  private:
};

#endif