/*
 * EPITECH PROJECT, 2021
 * DisplayManage
 * File description:
 * DisplayManage.hpp - Created: 21/04/2021
 */

#ifndef DISPLAYMANAGE_HPP
#define DISPLAYMANAGE_HPP

#include <iostream>
#include <algorithm>
#include "DLLib/DLLib.hpp"
#include "Interfaces/ICoreDisplay.hpp"
#include "Interfaces/IDisplayModule.hpp"

using namespace plazza;

class CoreDisplay : public ICoreDisplay {
  public:
    CoreDisplay(std::string filepath, Vector screenSize, Vector screenScale, std::size_t maxLen = 30);
    ~CoreDisplay();
    void setPrompt(std::string prompt);
    void printPrompt() const;
    void printKitchen(std::vector<std::unique_ptr<IKitchen>> kitchenList);
    void printDetailledKitchen(std::unique_ptr<IKitchen> kitchen);
    std::string getLine() const;
    void setLine(std::string line);

  private:
    std::string _prompt;
    std::size_t _maxLen;
    std::string _line;
    std::unique_ptr<DLLib<IDisplayModule>> _loader;
};

#endif