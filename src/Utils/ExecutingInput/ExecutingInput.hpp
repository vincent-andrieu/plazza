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

class ExecutingInput {
  public:
    ExecutingInput();
    ~ExecutingInput();
    void setFunctionCall(std::string, std::function<void()>);
    bool callFunction(std::string);

  private:
    std::unordered_map<std::string, std::function<void()>> _functList;
};

#endif