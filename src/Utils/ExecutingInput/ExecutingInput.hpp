/*
** EPITECH PROJECT, 2021
** Plazza
** File description:
** ExecutingInput.hpp
*/

#ifndef EXECUTINGINPUT_HPP
#define EXECUTINGINPUT_HPP

#include <vector>
#include <fstream>
#include <functional>
#include <unordered_map>
#include "Plazza.hpp"

class ExecutingInput {
  public:
    ExecutingInput();
    ~ExecutingInput();
    void setFunctionCall(string, std::function<void()>);
    bool callFunction(string);

  private:
    std::unordered_map<string, std::function<void()>> _functList;
};

#endif